// Fill out your copyright notice in the Description page of Project Settings.


#include "ServiceUpdateData.h"

#include "BossCharacter.h"
#include "BossController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

void UServiceUpdateData::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	OwnerComp.GetBlackboardComponent()->SetValueAsFloat(Distance.SelectedKeyName,
		UKismetMathLibrary::Vector_Distance(Cast<ABossCharacter>(Cast<ABossController>(OwnerComp.GetOwner())->GetPawn())->GetActorLocation(),
		UGameplayStatics::GetPlayerCharacter(GWorld,0)->GetActorLocation()));
}
