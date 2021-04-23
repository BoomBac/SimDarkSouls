// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "Widgets/SCompoundWidget.h"


/**
 * 
 */
class SIMDARKSOULS_API SMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMenuWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	
private:

	void InitializeAnimation();

	//logo menu
	TSharedPtr<class SLogoMenuWidget> LogoMenu;
	TSharedPtr<class SScrollBox> ScrollBox;

	TAttribute<float> UIScaler;
	float GetUIScaler() const;
};
