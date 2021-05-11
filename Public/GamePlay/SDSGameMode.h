// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SDSGameMode.generated.h"
class APlayeState;
class APlayController;
class APlayerCharacter;
/**
 * 
 */
UCLASS()
class SIMDARKSOULS_API ASDSGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	ASDSGameMode();
	APlayeState* SPState;
	APlayController* SPController;
	APlayerCharacter* SPCharacter;
	virtual void BeginPlay() override;
private:
	void InitialPlayer();
};
