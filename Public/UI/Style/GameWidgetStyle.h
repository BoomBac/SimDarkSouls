// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"

#include "GameWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct SIMDARKSOULS_API FGameStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FGameStyle();
	virtual ~FGameStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FGameStyle& GetDefault();
	UPROPERTY(EditAnywhere,Category="GameHUD")
	FSlateBrush HeadIcon;
	UPROPERTY(EditAnywhere,Category="GameHUD")
	FProgressBarStyle HPBarStyle;
	UPROPERTY(EditAnywhere,Category="GameHUD")
	FProgressBarStyle MPBarStyle;
	UPROPERTY(EditAnywhere,Category="GameHUD")
	FProgressBarStyle PPBarStyle;
	UPROPERTY(EditAnywhere,Category="GameHUD")
	FSlateBrush Item;
	UPROPERTY(EditAnywhere,Category="GameHUD")
	FSlateBrush ExpBack;
	UPROPERTY(EditAnywhere,Category="GameHUD")
	FSlateBrush ExpFront;
	UPROPERTY(EditAnywhere,Category="GameHUD")
	FSlateFontInfo English_12;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class UGameWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FGameStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
