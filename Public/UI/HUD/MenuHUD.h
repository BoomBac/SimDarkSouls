// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
DECLARE_DELEGATE(FUpdateUIText)
UCLASS()
class SIMDARKSOULS_API AMenuHUD : public AHUD
{
	GENERATED_BODY()
public:
	AMenuHUD();
	TSharedPtr<class SMenuHUDWidget> MenuHUDWidget;
	//更新ui文本语种，绑定RemoveW()，在internatinal调用
	FUpdateUIText UpdateUIText;
private:
	void RemoveW();
	
};
