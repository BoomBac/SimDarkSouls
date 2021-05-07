// Fill out your copyright notice in the Description page of Project Settings.


#include "NotifyRollEnd.h"

#include "AnimInst.h"


void UNotifyRollEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if(auto c = Cast<UAnimInst>(MeshComp->GetAnimInstance()))
		c ->bCanRoll = true;
}
