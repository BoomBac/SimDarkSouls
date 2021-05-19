// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "AnimInst.h"
#include "AttackComponent.h"
#include "DevelopTool.h"
#include "PlayController.h"
#include "WeaponObject.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "WeaponObject.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = (USceneComponent*)GetCapsuleComponent();
	//初始化模型
	const ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshObject(TEXT("SkeletalMesh'/Game/Characters/GKnight/Meshes/SK_GothicKnight_VA.SK_GothicKnight_VA'"));
	GetMesh()->SetSkeletalMesh(MeshObject.Object);
	bUseControllerRotationYaw = false;
	GetCapsuleComponent()->SetCollisionProfileName(FName("PlayerProfile"));
	GetMesh()->SetRelativeLocation(FVector{0.f,0.f,-90.f});
	GetMesh()->SetRelativeRotation(FRotator{0.f,-90.f,0.f});
	GetMesh()->SetupAttachment(RootComponent);
	//设置碰撞属性
	GetMesh()->SetCollisionObjectType(ECC_Pawn);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionResponseToAllChannels(ECR_Ignore);

	//获取第三人称的动作蓝图
	ConstructorHelpers::FClassFinder<UAnimInstance> StaticAnimFirst(TEXT("AnimBlueprint'/Game/Characters/Animation/ABP_Character.ABP_Character_C'"));
	GetMesh()->AnimClass = StaticAnimFirst.Class;
	//初始化动作蓝图
	
	//摄像机手臂
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	//设置距离
	CameraBoom->TargetArmLength = 300.f;
	//设置偏移
	CameraBoom->TargetOffset = FVector(0.f, 0.f, 60.f);
	//绑定Controller的旋转
	CameraBoom->bUsePawnControlRotation = true;

	//初始化第三人称摄像机
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdCamera"));
	Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	//设置ThirdCamera不跟随控制器的旋转
	Camera->bUsePawnControlRotation = false;
	//实例手上物品
	RighetHandIbject = CreateDefaultSubobject<UChildActorComponent>(TEXT("RightHand"));
	LeftHandObject = CreateDefaultSubobject<UChildActorComponent>(TEXT("LeftHand"));
	bIsViewLocked = false;
	bIsFalling = false;
	bIsRun = false;
	//实例化攻击检测组件
	AttackComponent = CreateDefaultSubobject<UAttackComponent>(TEXT("AttackComp"));
	AttackComponent->OnHitted.BindUFunction(this,FName("OnHitted"));

	PlayerCombatState = EPlayerState::Normal;
}



void APlayerCharacter::GetMoveForward(float value)
{
	MoveForward = value;

	if(MoveForward!=0&&!bIsViewLocked)
	{
		//RotationFromXVector
		MoveRotation = MoveDirection.Rotation();
		//蒙太奇播放时，锁住操作
		if(Animation->Montage_IsPlaying(nullptr)) return;
		SetActorRotation(
			FRotator(0.f,FMath::RInterpTo(GetActorRotation(),MoveRotation,GWorld->DeltaTimeSeconds,10.f).Yaw,0.f));
	}
}

void APlayerCharacter::GetMoveRight(float value)
{
	MoveRight = value;

	if(MoveRight!=0&&!bIsViewLocked)
	{
		//RotationFromXVector
		MoveRotation = MoveDirection.Rotation();
		//蒙太奇播放时，锁住操作
		if(Animation->Montage_IsPlaying(nullptr)) return;
		SetActorRotation(
			FRotator(0.f,FMath::RInterpTo(GetActorRotation(),MoveRotation,GWorld->DeltaTimeSeconds,10.f).Yaw,0.f));
	}
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void APlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void APlayerCharacter::Run()
{
	//耐力测试
	if(DSPlayerState->GetStateInfo().pp.currnt<=0.f) return;
	if(FMath::Abs(MoveForward)+FMath::Abs(MoveRight)>0)
	{
		bIsRun = true;
		FTimerDelegate TimerDelegate = FTimerDelegate::CreateUFunction(this,FName("ReducePP"),10.f);
		GetWorld()->GetTimerManager().SetTimer(Runhandle,TimerDelegate,0.1f,true);
	}
	else
	{
		Animation->Dodge();
	}	
}
void APlayerCharacter::unRun()
{
	bIsRun = false;
	GetWorld()->GetTimerManager().ClearTimer(Runhandle);
}

void APlayerCharacter::ViewLock()
{
	bIsViewLocked = true;
}

void APlayerCharacter::Attack()
{
	//耐力测试
	if(DSPlayerState->GetStateInfo().pp.currnt<=220.f) return;
	
	Animation->Attack();
	DSPlayerState->GetStateInfo().pp.currnt-=220.f;
	DSPlayerState->UpdatePPMaterial.ExecuteIfBound(2.f);
}

void APlayerCharacter::Roll()
{
	//耐力测试
	if(DSPlayerState->GetStateInfo().pp.currnt<=180.f) return;
	
	DSPlayerState->GetStateInfo().pp.currnt -=180.f;
	DSPlayerState->UpdatePPMaterial.ExecuteIfBound(2.f);
	if(!bIsViewLocked)
	{
		Animation->Roll(0);
		return;
	}
	int Direction = 0;
	// 0f 1b 2r 3l
	if(MoveForward==1) Direction = 0;
	else 
	{
		if(MoveForward==-1) Direction = 1;
		else
		{
			if(MoveRight==1) Direction = 2;
			else
			{
				if(MoveRight==-1) Direction = 3;
			}
		}
	}
	Animation->Roll(Direction);
}

void APlayerCharacter::CalculateAnimData()
{
	auto ControlRotation = DSPlayerController->GetControlRotation();
	auto direction = MoveForward * UKismetMathLibrary::GetForwardVector(FRotator{0.f,ControlRotation.Yaw,0.f})+
		MoveRight * UKismetMathLibrary::GetRightVector(FRotator{0.f,ControlRotation.Yaw,0.f});
	MoveDirection = UKismetMathLibrary::Normal(direction);
	
}

void APlayerCharacter::OnHitted(FAttackInfo AttackInfo)
{
}
//耐力恢复
void APlayerCharacter::RecoverPP()
{
	if(DSPlayerState->GetStateInfo().pp.currnt<DSPlayerState->GetStateInfo().pp.min)
	{
		DSPlayerState->GetStateInfo().pp.currnt = 0.f;
		GetWorld()->GetTimerManager().ClearTimer(PPRecoverHandle);
		bRecoverHandleSet=false;
		return;
	}
	if(DSPlayerState->GetStateInfo().pp.currnt>DSPlayerState->GetStateInfo().pp.max)
	{
		DSPlayerState->GetStateInfo().pp.currnt = DSPlayerState->GetStateInfo().pp.max;
		return;
	}
	DSPlayerState->GetStateInfo().pp.currnt +=DSPlayerState->GetStateInfo().pp.RecoverSpeed/10.f;
}
// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	DSPlayerController = Cast<APlayController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	DSPlayerState = Cast<APlayeState>(DSPlayerController->PlayerState);
	//这句放在构造时，调用动画实例的函数会报空
	Animation = Cast<UAnimInst>(GetMesh()->AnimScriptInstance);
	//把手持物品组件绑定到第三人称模型右手插槽上
	RighetHandIbject->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("Weapon"));
	LeftHandObject->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("Shield"));
	//添加Actor到HandObject
	RighetHandIbject->SetChildActorClass(AWeaponObject::SpawnHandWeapon(1));
	LeftHandObject->SetChildActorClass(AWeaponObject::SpawnHandWeapon(2));
	//设置背景材质更新
	DSPlayerState->UpdatePPMaterial.ExecuteIfBound(0.f);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CalculateAnimData();
	//攻击检测
	AttackComponent->AttackDetect(GetMesh(),FName("Weapon"),FName("WeaponPeek"),ETraceTypeQuery::TraceTypeQuery3,CurrentInfo);
	DHelper::Debug(FString::SanitizeFloat(DSPlayerState->GetStateInfo().pp.currnt),0.f);
	//耐力恢复
	if(DSPlayerState->GetStateInfo().pp.currnt<=DSPlayerState->GetStateInfo().pp.max&&!bRecoverHandleSet)
	{
		FTimerDelegate TimerDelegate;
		TimerDelegate.BindUFunction(this,FName("RecoverPP"));
		GetWorld()->GetTimerManager().SetTimer(PPRecoverHandle,TimerDelegate,0.1,true,0.f);
		bRecoverHandleSet = true;
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward",this,&APlayerCharacter::GetMoveForward);
	PlayerInputComponent->BindAxis("MoveRight",this,&APlayerCharacter::GetMoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAction("Run",IE_Pressed,this,&APlayerCharacter::Run);
	PlayerInputComponent->BindAction("Run",IE_DoubleClick,this,&APlayerCharacter::Roll);
	PlayerInputComponent->BindAction("Run",IE_Released,this,&APlayerCharacter::unRun);
	PlayerInputComponent->BindAction("ViewLock",IE_Pressed,this,&APlayerCharacter::ViewLock);
	PlayerInputComponent->BindAction("Attack",IE_Pressed,this,&APlayerCharacter::Attack);
}

void APlayerCharacter::ReducePP(float ReduceRate)
{
	DSPlayerState->GetStateInfo().pp.currnt-=ReduceRate;
	DSPlayerState->UpdatePPMaterial.ExecuteIfBound(0.f);
}

