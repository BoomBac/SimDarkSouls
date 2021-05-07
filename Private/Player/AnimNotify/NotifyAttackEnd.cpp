// Fill out your copyright notice in the Description page of Project Settings.


#include "NotifyAttackEnd.h"

#include "AnimInst.h"

void UNotifyAttackEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if(auto c = Cast<UAnimInst>(MeshComp->GetAnimInstance()))
		c ->bCanAttack = true;
}
