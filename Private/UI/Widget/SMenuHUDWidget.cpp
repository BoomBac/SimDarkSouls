// Fill out your copyright notice in the Description page of Project Settings.



#include "UI/Widget/SMenuHUDWidget.h"

#include "SlateOptMacros.h"
#include "SLogoMenuWidget.h"
#include "SMenuWidget.h"
#include "SOptionMenuWidget.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Layout/SConstraintCanvas.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMenuHUDWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
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
			SNew(SOptionMenuWidget)
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
