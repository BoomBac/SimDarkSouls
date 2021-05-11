// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class SIMDARKSOULS_API AGameHUD : public AHUD
{
	GENERATED_BODY()
public:
	AGameHUD();
	virtual void BeginPlay() override;
private:
	TSharedPtr<class SGameHUDWidget> GameHUDWidget;
	UPROPERTY()
	class ASDSGameMode* GM;
};
