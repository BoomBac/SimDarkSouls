// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"



class SProgressBar;
/**
 * 
 */


class SIMDARKSOULS_API SGameDefaultWidget : public SCompoundWidget,public FGCObject
{
public:
	SLATE_BEGIN_ARGS(SGameDefaultWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	
	//属性的最大值：当前血槽和上限,由state中的委托调用
	void SetBarLength(float HP,float MP,float PP,float limit);
	void UpdateHPMaterial();
private:
	TSharedPtr<SProgressBar> HPBar;
	TSharedPtr<SProgressBar> MPBar;
	TSharedPtr<SProgressBar> PPBar;
	TSharedPtr<SImage> MagicItem;
	TSharedPtr<SImage> LeftHandItem;
	TSharedPtr<SImage> RightHandItem;
	TSharedPtr<SImage> FrontSupplyItem;
	TSharedPtr<SImage> BackSupplyItem;
	TSharedPtr<STextBlock> ExpBlock;
	FText GetExpText() const;
	//控制三条长度
	TAttribute<FMargin> THPLength;
	TAttribute<FMargin> TMPLength;
	TAttribute<FMargin> TPPLength;
	FMargin HPLength;
	FMargin MPLength;
	FMargin PPLength;
	//返回给进度条padding
	FMargin GetHPBarLength() const;
	FMargin GetMPBarLength() const;
	FMargin GetPPBarLength() const;
	//三条百分比
	float HPPercent;
	float MPPercent;
	float PPPercent;
	//更新百分比变量
	void UpdatePercent();
	TOptional<float> GetHPPercent() const;
	//进度条材质
	UMaterialInstanceDynamic* HPBarDynamic;
	UMaterialInstanceDynamic* MPBarDynamic;
	UMaterialInstanceDynamic* PPBarDynamic;
	FTimerHandle HPBarHandle;
	
	
	void SetMatrialParm();
	
	class APlayeState* PlayeState;
	void InitialElement();
};
