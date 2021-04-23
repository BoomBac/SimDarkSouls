// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SIMDARKSOULS_API SOptionMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SOptionMenuWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	//顶部选项卡
	TSharedPtr<SButton> Left;
	TSharedPtr<SButton> Controller;
	TSharedPtr<SButton> Sound;
	TSharedPtr<SButton> Graphic;
	TSharedPtr<SButton> MultiPlayer;
	TSharedPtr<SButton> Right;
};
