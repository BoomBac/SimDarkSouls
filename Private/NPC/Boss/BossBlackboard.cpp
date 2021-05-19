// Fill out your copyright notice in the Description page of Project Settings.


#include "BossBlackboard.h"

#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Float.h"

void UBossBlackboard::PostLoad()
{
	Super::PostLoad();
	
	FBlackboardEntry Distance;
	Distance.EntryName = FName("Distance");
	UBlackboardKeyType_Float* DistanceKeyType_Float = NewObject<UBlackboardKeyType_Float>();	
	Distance.KeyType = DistanceKeyType_Float;

	FBlackboardEntry bCanAttack;
	bCanAttack.EntryName = FName("CanAttack");
	UBlackboardKeyType_Bool* CanAttackKeyType_Bool = NewObject<UBlackboardKeyType_Bool>();
	bCanAttack.KeyType = CanAttackKeyType_Bool;

	Keys.Add(Distance);
	Keys.Add(bCanAttack);
}
