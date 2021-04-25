// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"

/**
 * 
 */
struct STLFloat
{
	FTimeline Timeline;
	FOnTimelineFloatStatic TimelineFunc;
	UCurveFloat* TimelineCurve;
};
struct STLVector
{
	FTimeline Timeline;
	FOnTimelineVectorStatic TimelineFunc;
	UCurveVector* TimelineCurve;
};
struct STLLinearColor
{
	FTimeline Timeline;
	FOnTimelineLinearColorStatic TimelineFunc;
	UCurveLinearColor* TimelineCurve;
};


class SIMDARKSOULS_API TimeLineHandle
{
public:
	TimeLineHandle();
	static void Initialize();

	static TSharedPtr<TimeLineHandle> Get();

	FOnTimelineFloatStatic& AddTimeLineF(FName Key, const TCHAR* CurvePath);
	FOnTimelineVectorStatic& AddTimeLineV(FName Key, const TCHAR* CurvePath);
	FOnTimelineLinearColorStatic& AddTimeLineL(FName Key, const TCHAR* CurvePath);

	TSharedPtr<STLFloat> GetTimeLineF(FName key);
	TSharedPtr<STLVector> GetTimeLineV(FName key);
	TSharedPtr<STLLinearColor> GetTimeLineL(FName key);
private:
	//创建实例方法
	static TSharedRef<TimeLineHandle> Create();
	//单例指针
	static TSharedPtr<TimeLineHandle> TLHandleInstance;

	TMap<FName,TSharedPtr<STLFloat>> TlFloatMap;
	TMap<FName,TSharedPtr<STLVector>> TlVectorMap;
	TMap<FName,TSharedPtr<STLLinearColor>> TlLinearColorMap;
};
