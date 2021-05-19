// Fill out your copyright notice in the Description page of Project Settings.


#include "NotifyAttackStart.h"

#include "AnimBoss.h"
#include "AnimInst.h"
#include "AttackComponent.h"
#include "BossCharacter.h"
#include "DevelopTool.h"
#include "PlayerCharacter.h"


void UNotifyAttackStart::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{	
	auto OwnerActor = MeshComp->GetOwner();
	if(Cast<APlayerCharacter>(OwnerActor)->StaticClass() == APlayerCharacter::StaticClass())
	{
		UAnimInst* anim = Cast<UAnimInst>(MeshComp->GetAnimInstance());
		if (anim)
		{
			anim->Character->AttackComponent->bDetectenable = true;
			return;
		}
	}
	if(Cast<ABossCharacter>(OwnerActor)->StaticClass() ==ABossCharacter::StaticClass())
	{
		ABossCharacter* boss = Cast<ABossCharacter>(OwnerActor);
		if(boss)
		{
			Cast<ABossCharacter>(OwnerActor)->AttackComponent->bDetectenable = true;
			Cast<ABossCharacter>(OwnerActor)->bCanSetRotation = false;
		}
	}
}
