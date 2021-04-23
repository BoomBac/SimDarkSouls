// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SIMDARKSOULS_API SMenuHUDWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMenuHUDWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
private:
	//开始界面指针
	TSharedPtr<class SMenuWidget> StartMenu;
};
