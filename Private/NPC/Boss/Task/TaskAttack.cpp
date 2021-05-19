// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskAttack.h"

#include "BossCharacter.h"
#include "BossController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "SimDarkSouls/SimDarkSouls.h"

EBTNodeResult::Type UTaskAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BossCharacter = Cast<ABossCharacter>(Cast<ABossController>(OwnerComp.GetOwner())->BossCharacter);
	if(BossCharacter)
	{
		BossCharacter->Attack(OwnerComp.GetBlackboardComponent()->GetValueAsFloat(Distance.SelectedKeyName));
		return EBTNodeResult::Succeeded;
	}
	else
		UE_LOG(LogAI,Error,TEXT("Boss Character is null"))
		return EBTNodeResult::Failed;
}
