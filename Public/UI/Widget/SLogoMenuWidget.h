// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

DECLARE_DELEGATE_OneParam(FScrllVisiblity,EVisibility)
/**
 * 
 */
class SIMDARKSOULS_API SLogoMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SLogoMenuWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	FScrllVisiblity ScrllVisiblity;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
};
