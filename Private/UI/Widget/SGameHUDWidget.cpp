// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameHUDWidget.h"

#include "SGameDefaultWidget.h"
#include "SlateOptMacros.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Layout/SDPIScaler.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SGameHUDWidget::Construct(const FArguments& InArgs)
{
	UIScalar.Bind(this,&SGameHUDWidget::GetUIScaler);
	ChildSlot
	[
		SNew(SDPIScaler).DPIScale(UIScalar)
		[
			SNew(SCanvas)
			+SCanvas::Slot()
			//插槽枢轴点位置
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			//大小和位置
			.Size(FVector2D{1920.f,1080.f})
			.Position(FVector2D{960.f,540.f})
			[
				SAssignNew(DefaultHud,SGameDefaultWidget)
			]
		]
	];
}
//uscaler绑定函数
float SGameHUDWidget::GetUIScaler() const
{
	FVector2D Result(1920.f, 1080.f);
	if (GEngine && GEngine->GameViewport) {
		GEngine->GameViewport->GetViewportSize(Result);
	}
	return Result.Y/1080.f;
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
