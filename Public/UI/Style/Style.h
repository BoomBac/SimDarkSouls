// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
struct FMenuStyle;
struct FGameStyle;

class SIMDARKSOULS_API Style
{
public:
	static void Initialize();
	static FName GetStyleSetName();
	static void ShutDown();
	static const ISlateStyle& Get();
	static const FMenuStyle* GetMenuStyle();
	static const FGameStyle* GetGameStyle();
private:
	static TSharedRef<class FSlateStyleSet> Create();
	static TSharedPtr<FSlateStyleSet> StyleInstance;
	static TSharedPtr<FMenuStyle> MenuStyle;
	static TSharedPtr<FGameStyle> GameStyle;
};
