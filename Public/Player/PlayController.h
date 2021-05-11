// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"
#include "PlayController.generated.h"

/**
 * 
 */
UCLASS()
class SIMDARKSOULS_API APlayController : public APlayerController
{
	GENERATED_BODY()
public:
	APlayController();
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	//test
	void AddHP();
	void SubHP();
	//
	class APlayeState* SPState;
};
