// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInst.h"

#include "DevelopTool.h"
#include "PlayerCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

UAnimInst::UAnimInst()
{
	WalkForward_Anim = 0.f;
	bCanCombat = false;
	bCanAttack = true;
	bCanRoll = true;
	static ConstructorHelpers::FObjectFinder<UAnimMontage> al1(TEXT("AnimMontage'/Game/Characters/Animation/Montage/Sword_AttackLight1_Montage.Sword_AttackLight1_Montage'"));
	MontageAL1 = al1.Object;
	ConstructorHelpers::FObjectFinder<UAnimMontage> al2(TEXT("AnimMontage'/Game/Characters/Animation/Montage/Sword_AttackLight2_Montage.Sword_AttackLight2_Montage'"));
	MontageAL2 =al2.Object;
	ConstructorHelpers::FObjectFinder<UAnimMontage> ah1(TEXT("AnimMontage'/Game/Characters/Animation/Montage/Sword_AttackHeavery_Montage.Sword_AttackHeavery_Montage'"));
	MontageAH1 = ah1.Object;
	ConstructorHelpers::FObjectFinder<UAnimMontage> rf(TEXT("AnimMontage'/Game/Characters/Animation/Montage/RollForward_Root_Montage.RollForward_Root_Montage'"));
	MontageRF=rf.Object;
	ConstructorHelpers::FObjectFinder<UAnimMontage> rb(TEXT("AnimMontage'/Game/Characters/Animation/Montage/RollBackward_Root_Montage.RollBackward_Root_Montage'"));
	MontageRB=rb.Object;
	ConstructorHelpers::FObjectFinder<UAnimMontage> rl(TEXT("AnimMontage'/Game/Characters/Animation/Montage/RollLeft_Root_Montage.RollLeft_Root_Montage'"));
	MontageRL=rl.Object;
	ConstructorHelpers::FObjectFinder<UAnimMontage> rr(TEXT("AnimMontage'/Game/Characters/Animation/Montage/RollRight_Root_Montage.RollRight_Root_Montage'"));
	MontageRR=rr.Object;
	static ConstructorHelpers::FObjectFinder<UAnimMontage> dodge(TEXT("AnimMontage'/Game/Characters/Animation/Montage/Sword_Dodge_Montage.Sword_Dodge_Montage'"));
	MontageDodge = dodge.Object;
}

void UAnimInst::NativeUpdateAnimation(float DeltaSeconds)
{
	
	InitCharacter();
	UpdateParameter();
}

void UAnimInst::Attack()
{
	if(Montage_IsPlaying(nullptr)&&!bCanAttack) return;
	bCanAttack = false;
	 if(!bCanCombat)
	 {
	 	Montage_Play(MontageAL1);
	 	bCanCombat = true;
	 	GetWorld()->GetTimerManager().SetTimer(CombatHandle,this,&UAnimInst::DisableCombat,0.6f);
	 }
	 else
	 {
	 	Montage_Play(MontageAL2);
	 	DisableCombat();
	 	GetWorld()->GetTimerManager().ClearTimer(CombatHandle);
	 }
}

void UAnimInst::Roll(int Direction)
{
	if(!bCanRoll) return;
	// 0f 1b 2r 3l
	bCanRoll = false;
	switch (Direction)
	{	
		case 0:
			Montage_Play(MontageRF,0.8);
		break;
		case 1:
			Montage_Play(MontageRB,0.8f);
		break;
		case 2:
			Montage_Play(MontageRR,0.8f);
		break;
		case 3:
			Montage_Play(MontageRL,0.8f);
		break;
	}
	
}

void UAnimInst::Dodge()
{
	if(!bCanRoll) return;
	bCanRoll = false;
	Montage_Play(MontageDodge);
}

void UAnimInst::DisableCombat()
{
	bCanCombat = false;
}

void UAnimInst::InitCharacter()
{
	if(!Character)
		Character = Cast<APlayerCharacter>(TryGetPawnOwner());
}

void UAnimInst::UpdateParameter()
{
	if(!Character) return;
	bisFall_Anim = Character->GetMovementComponent()->IsFalling();
	bisRun_Anim = Character->bIsRun;
	bisLock_Anim =Character->bIsViewLocked;
	if(!bisLock_Anim)
	{
		
		if(bisRun_Anim) WalkForward_Anim = FMath::Abs(Character->MoveRight)+FMath::Abs(Character->MoveForward);
		else WalkForward_Anim = FMath::Clamp(FMath::Abs(Character->MoveRight)+FMath::Abs(Character->MoveForward),0.f,0.5f);
	}
	else
	{
		WalkForward_Anim = FMath::Lerp(WalkForward_Anim,UKismetMathLibrary::Dot_VectorVector(Character->GetActorForwardVector(),Character->MoveDirection),0.05f);
		WalkRight_Anim = FMath::Lerp(WalkRight_Anim,UKismetMathLibrary::Dot_VectorVector(Character->GetActorRightVector(),Character->MoveDirection),0.05f);
	}
	FootAlpha_Anim = GetCurveValue("Foot");
}

