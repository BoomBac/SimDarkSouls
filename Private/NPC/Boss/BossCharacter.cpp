// Fill out your copyright notice in the Description page of Project Settings.


#include "BossCharacter.h"

#include "AttackComponent.h"
#include "BossController.h"
#include "DevelopTool.h"
#include "PlayerCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "SimDarkSouls/SimDarkSouls.h"

// Sets default values
ABossCharacter::ABossCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = ABossController::StaticClass();
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshLoader
	(TEXT("SkeletalMesh'/Game/BossyEnemy/SkeletalMesh/SK_Mannequin_UE4_WithWeapon.SK_Mannequin_UE4_WithWeapon'"));
	if(MeshLoader.Succeeded()) GetMesh()->SetSkeletalMesh(MeshLoader.Object);
	GetMesh()->SetRelativeLocation(FVector{0.f,0.f,-147.f});
	GetMesh()->SetRelativeRotation(FRotator{0.f,-90.f,0.f});
	GetMesh()->SetRelativeScale3D(FVector{1.5f,1.5f,1.5f});
	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimLoader(TEXT("AnimBlueprint'/Game/BluePrint/AI/Boss/ABP_Boss.ABP_Boss_C'"));
	if(AnimLoader.Succeeded()) GetMesh()->AnimClass = AnimLoader.Class;
	static ConstructorHelpers::FObjectFinder<UDataTable> DTLoader(TEXT("DataTable'/Game/BluePrint/Data/DT_BossAttack.DT_BossAttack'"));
	if(DTLoader.Succeeded()) DTAttackInfo = DTLoader.Object;
	else UE_LOG(LogAI,Error,TEXT("DTAttack load Failed!"));
	GetCapsuleComponent()->SetCapsuleHalfHeight(143.f);
	GetCapsuleComponent()->SetCapsuleRadius(60.f);
	GetMesh()->SetCollisionProfileName(FName("EnemyProfile"));
	AttackComponent = CreateDefaultSubobject<UAttackComponent>(TEXT("AttackComp"));
	AttackComponent->OnHitted.BindUFunction(this,FName("OnHitted"));
	Forward = 0.f;
	Right = 0.f;
	bCanAttack = true;
	bCanSetRotation = true;
	Phycics = 100.f;
}

void ABossCharacter::UpdateRotation(float deltasecond)
{
	if(!bCanSetRotation) return;
	SetActorRotation(FMath::RInterpTo(GetActorRotation(),FRotator{GetActorRotation().Pitch,
		UKismetMathLibrary::MakeRotFromX(TargetPlayer->GetActorLocation()-GetActorLocation()).Yaw,GetActorRotation().Roll}	
		,deltasecond,1.f));
}

// Called when the game starts or when spawned
void ABossCharacter::BeginPlay()
{
	Super::BeginPlay();
	TargetPlayer = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GWorld,0));
}

// Called every frame
void ABossCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateRotation(DeltaTime);
	AttackComponent->AttackDetect(GetMesh(),FName("weapon"),FName("weaponpeek"),ETraceTypeQuery::TraceTypeQuery3,CurrentAttack);
}


void ABossCharacter::OnHitted(FAttackInfo AttackInfo)
{
	DHelper::Debug("boss being hit",2.f,FColor::Red);
}

void ABossCharacter::Attack(float Distance)
{
	if(GetCurrentMontage()) return;
	bCanAttack = false;
	CurrentAttack = *DTAttackInfo->FindRow<FAttackInfo>(FName("AttackRun"),TEXT("Run"));
	if(Distance<=800.f)
	{
		
		PlayAnimMontage(CurrentAttack.AttackMontage,1.5f);
		Phycics -=CurrentAttack.Phycics;
		return;
	}		
	switch (TargetPlayer->PlayerCombatState)
	{
		case EPlayerState::Normal:
			{
				CurrentAttack = *DTAttackInfo->FindRow<FAttackInfo>(FName("AttackNormal"),TEXT("Normal"));
				PlayAnimMontage(CurrentAttack.AttackMontage,1.5f);
				Phycics -=CurrentAttack.Phycics;
			}
		break;
		case  EPlayerState::Block:
			{
				CurrentAttack = *DTAttackInfo->FindRow<FAttackInfo>(FName("AttackBlock"),TEXT("Block"));
				PlayAnimMontage(CurrentAttack.AttackMontage,1.5f);
				Phycics -=CurrentAttack.Phycics;
			}
		break;
		case EPlayerState::Rigid:
			{
				CurrentAttack = *DTAttackInfo->FindRow<FAttackInfo>(FName("AttackUp"),TEXT("Up"));
				PlayAnimMontage(CurrentAttack.AttackMontage,1.5f);
				Phycics -=CurrentAttack.Phycics;
			}
		break;
		case EPlayerState::Collapse:
			{
				CurrentAttack = *DTAttackInfo->FindRow<FAttackInfo>(FName("AttackCharge"),TEXT("Charge"));
				PlayAnimMontage(CurrentAttack.AttackMontage,1.5f);
				Phycics -=CurrentAttack.Phycics;
			}
		break;
	}
}
