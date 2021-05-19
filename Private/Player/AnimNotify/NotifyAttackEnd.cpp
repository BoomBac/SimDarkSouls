// Fill out your copyright notice in the Description page of Project Settings.


#include "NotifyAttackEnd.h"

#include "AnimBoss.h"
#include "AnimInst.h"
#include "AttackComponent.h"
#include "BossCharacter.h"
#include "PlayerCharacter.h"

void UNotifyAttackEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	auto OwnerActor = MeshComp->GetOwner();
	if(Cast<APlayerCharacter>(OwnerActor)->StaticClass() == APlayerCharacter::StaticClass())
	{
		UAnimInst* anim = Cast<UAnimInst>(MeshComp->GetAnimInstance());
		if (anim)
		{
			anim->bCanAttack = true;
			anim->Character->AttackComponent->bDetectenable = false;
			return;
		}
	}
	if(Cast<ABossCharacter>(OwnerActor)->StaticClass() ==ABossCharacter::StaticClass())
	{
		if(auto boss = Cast<ABossCharacter>(OwnerActor))
		{
			boss->AttackComponent->bDetectenable = false;
			boss->bCanSetRotation = true;
		}
	}

}
