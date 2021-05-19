// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskMoveToPlayer.h"

#include "BossCharacter.h"
#include "BossController.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UTaskMoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto BossCharacter = Cast<ABossCharacter>(Cast<ABossController>(OwnerComp.GetOwner())->GetPawn());
	if(!BossCharacter) return EBTNodeResult::Failed;
	BossCharacter->Forward = 1.f;
	BossCharacter->Right = 0.f;
	if(OwnerComp.GetBlackboardComponent()->GetValueAsFloat(Distance.SelectedKeyName)<900.f)
		return EBTNodeResult::Succeeded;
	else
		return EBTNodeResult::Failed;
}
