// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "Styling/SlateWidgetStyleContainerBase.h"

#include "MenuWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct SIMDARKSOULS_API FMenuStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FMenuStyle();
	virtual ~FMenuStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FMenuStyle& GetDefault();
	//20号中文字体
	UPROPERTY(EditAnywhere,Category="Font")
	FSlateFontInfo ChineseFont_20;
	//14号英文字体
	UPROPERTY(EditAnywhere,Category="Font")
	FSlateFontInfo EnglishFont_14;
	//黄色闪动材质
	UPROPERTY(EditAnywhere,Category="Material")
	FSlateBrush YellowForLogo;
	//startmenu title
	UPROPERTY(EditAnywhere,Category="StartMenu")
	FSlateBrush MainTitle;
	//ScrollArrow
	UPROPERTY(EditAnywhere,Category="StartMenu")
	FSlateBrush ScrollArrow;
	//开始菜单滚动栏按钮
	UPROPERTY(EditAnywhere,Category="StartMenu")
	FButtonStyle StartMenuButton;
	//选项菜单背景
	UPROPERTY(EditAnywhere,Category="OptionMenu")
	FSlateBrush OptionBack;
	//选项菜单前景
	UPROPERTY(EditAnywhere,Category="OptionMenu")
	FSlateBrush OptionFront;
	//选项菜单上方图标
	UPROPERTY(EditAnywhere,Category="OptionMenu")
	FButtonStyle OptionIcon;
	//选项菜单上方箭头
	UPROPERTY(EditAnywhere,Category="OptionMenu")
	FSlateBrush OptionArrow;
	//选项菜单上方箭头背景按钮
	UPROPERTY(EditAnywhere,Category="OptionMenu")
	FButtonStyle OptionArrowIcon;
	//选项卡左边文字背景
	UPROPERTY(EditAnywhere,Category="OptionMenu")
	FSlateBrush LeftOptionBG;
	//选项卡右边文字背景
	UPROPERTY(EditAnywhere,Category="OptionMenu")
	FSlateBrush RightOptionBG;
	//选项进度条样式
	UPROPERTY(EditAnywhere,Category="OptionMenu")
	FProgressBarStyle BarStyle;
};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class UMenuWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FMenuStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
