// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "BossController.generated.h"

/**
 * 
 */
class UBehaviorTree;
UCLASS()
class SIMDARKSOULS_API ABossController : public AAIController
{
	GENERATED_BODY()
public:
	ABossController();
	UPROPERTY()
	class ABossCharacter* BossCharacter;
private:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
	UPROPERTY()
	class UBehaviorTree* BTAsset;
};
