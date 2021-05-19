// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardData.h"
#include "BossBlackboard.generated.h"

/**
 * 
 */
UCLASS()
class SIMDARKSOULS_API UBossBlackboard : public UBlackboardData
{
	GENERATED_BODY()
public:
	virtual void PostLoad() override;
};
