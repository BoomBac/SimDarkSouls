// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/TimelineComponent.h"
#include "Widgets/SCompoundWidget.h"


/**
 * 
 */
//DECLARE_DYNAMIC_DELEGATE(FOnTimelineEvent)

class SIMDARKSOULS_API SMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMenuWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	//暴露给时间轴的函数组
	void TimeLineTitle(FLinearColor value);
	void TimeLineFinish();
	void funcf(float value);
private:

	//scrollbox
	void SetScrollGruopVisibility(EVisibility bV);
	//logo menu
	TSharedPtr<class SLogoMenuWidget> LogoMenu;
	TSharedPtr<class SScrollBox> ScrollBox;
	TSharedPtr<class SImage> ScrollUp;
	TSharedPtr<class SImage> ScrollDown;
	//uiscaler属性
	TAttribute<float> UIScaler;
	float GetUIScaler() const;
	//title属性
	FSlateColor TitleColor;
	TAttribute<FSlateColor> TAtitleColor;
	FSlateColor GetTitleColor() const;
	FOnTimelineEventStatic Event_TLFinsh;
};


