// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeLineHandle.h"
#include "Curves/CurveVector.h"
#include "Curves/CurveLinearColor.h"

TSharedPtr<TimeLineHandle> TimeLineHandle::TLHandleInstance = nullptr;

TimeLineHandle::TimeLineHandle()
{
}

void TimeLineHandle::Initialize()
{
	if(!TLHandleInstance.IsValid())
		TLHandleInstance = Create();
}

TSharedPtr<TimeLineHandle> TimeLineHandle::Get()
{
	Initialize();
	return TLHandleInstance;
}

FOnTimelineFloatStatic& TimeLineHandle::AddTimeLineF(FName Key, const TCHAR* CurvePath)
{
	TSharedPtr<STLFloat> timeline = MakeShareable(new STLFloat());
	//加载蓝图中的曲线资源
	ConstructorHelpers::FObjectFinder<UCurveFloat> fcurve(CurvePath);
	timeline->TimelineCurve = fcurve.Object;
	TlFloatMap.Add(Key,timeline);
	return timeline->TimelineFunc;
}

FOnTimelineVectorStatic& TimeLineHandle::AddTimeLineV(FName Key, const TCHAR* CurvePath)
{
	TSharedPtr<STLVector> timeline = MakeShareable(new STLVector());
	ConstructorHelpers::FObjectFinder<UCurveVector> lcurve(CurvePath);
	timeline->TimelineCurve = lcurve.Object;
	TlVectorMap.Add(Key,timeline);
	return timeline->TimelineFunc;
}

FOnTimelineLinearColorStatic& TimeLineHandle::AddTimeLineL(FName Key, const TCHAR* CurvePath)
{
	TSharedPtr<STLLinearColor> timeline = MakeShareable(new STLLinearColor());
	const ConstructorHelpers::FObjectFinder<UCurveLinearColor> lurve(CurvePath);
	timeline->TimelineCurve = lurve.Object;
	TlLinearColorMap.Add(Key,timeline);
	return timeline->TimelineFunc;
}

TSharedPtr<STLFloat> TimeLineHandle::GetTimeLineF(FName key)
{
	//将曲线和代理绑定到时间轴上
	TlFloatMap.Find(key)->Get()->Timeline.AddInterpFloat(TlFloatMap.Find(key)->Get()->TimelineCurve,TlFloatMap.Find(key)->Get()->TimelineFunc);
	return TlFloatMap.Find(key)->ToSharedRef();
}

TSharedPtr<STLLinearColor> TimeLineHandle::GetTimeLineL(FName key)
{
	TlLinearColorMap.Find(key)->Get()->Timeline.AddInterpLinearColor(TlLinearColorMap.Find(key)->Get()->TimelineCurve,TlLinearColorMap.Find(key)->Get()->TimelineFunc);
	return TlLinearColorMap.Find(key)->ToSharedRef();
}

TSharedPtr<STLVector> TimeLineHandle::GetTimeLineV(FName key)
{
	TlVectorMap.Find(key)->Get()->Timeline.AddInterpVector(TlVectorMap.Find(key)->Get()->TimelineCurve,TlVectorMap.Find(key)->Get()->TimelineFunc);
	return TlVectorMap.Find(key)->ToSharedRef();
}

TSharedRef<TimeLineHandle> TimeLineHandle::Create()
{
	TSharedRef<TimeLineHandle> TLH = MakeShareable(new TimeLineHandle());
	return TLH;
}
