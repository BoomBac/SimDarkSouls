// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
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
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	//把手持物品组件绑定到第三人称模型右手插槽上
	RighetHandIbject->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("Weapon"));
	LeftHandObject->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("Shield"));
	//添加Actor到HandObject
//	RighetHandIbject->SetChildActorClass(AWeaponObject::SpawnHandWeapon(0));
}

void APlayerCharacter::GetMoveForward(float value)
{
	MoveForward = value;
	
	if(MoveForward!=0&&!bIsViewLocked)
	{
		//RotationFromXVector
		MoveRotation = MoveDirection.Rotation();
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
	bIsRun = true;
}
void APlayerCharacter::unRun()
{
	bIsRun = false;
}

void APlayerCharacter::ViewLock()
{
	bIsViewLocked = true;
}

void APlayerCharacter::CalculateAnimData()
{
	auto ControlRotation = PlayerController->GetControlRotation();
	auto direction = MoveForward * UKismetMathLibrary::GetForwardVector(FRotator{0.f,ControlRotation.Yaw,0.f})+
		MoveRight * UKismetMathLibrary::GetRightVector(FRotator{0.f,ControlRotation.Yaw,0.f});
	MoveDirection = UKismetMathLibrary::Normal(direction);
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	CalculateAnimData();
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
	PlayerInputComponent->BindAction("Run",IE_Released,this,&APlayerCharacter::unRun);
	PlayerInputComponent->BindAction("ViewLock",IE_Pressed,this,&APlayerCharacter::ViewLock);
}

