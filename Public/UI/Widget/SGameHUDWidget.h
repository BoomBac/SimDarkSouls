// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SIMDARKSOULS_API SGameHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SGameHUDWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	TSharedPtr<class SGameDefaultWidget> DefaultHud;

private:
	TAttribute<float> UIScalar;
	float GetUIScaler() const;
};
