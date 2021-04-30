// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInst.h"

#include "DevelopTool.h"
#include "PlayerCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

UAnimInst::UAnimInst()
{
	WalkForward_Anim = 0.f;
}

void UAnimInst::NativeUpdateAnimation(float DeltaSeconds)
{
	InitCharacter();
	UpdateParameter();
	
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
