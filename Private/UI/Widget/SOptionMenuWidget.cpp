// Fill out your copyright notice in the Description page of Project Settings.


#include "SOptionMenuWidget.h"

#include "DevelopTool.h"
#include "MenuWidgetStyle.h"
#include "SlateOptMacros.h"
#include "Style.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBackgroundBlur.h"
#include "Widgets/Layout/SWrapBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SOptionMenuWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SCanvas)
		+SCanvas::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Size(FVector2D{1920.f,1080.f})
		.Position(FVector2D{960.f,540.f})
		[
			SNew(SBackgroundBlur)
			.BlurStrength(3.f)
		]
		+SCanvas::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Size(FVector2D{1340.f,830.f})
		.Position(FVector2D{960.f,540.f})
		[
			SNew(SImage)
			.Image(&Style::GetMenuStyle()->OptionBack)
		]
		+SCanvas::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Size(FVector2D{1294.f,600.f})
		.Position(DHelper::PositionConvert(FVector2D{9.7f,64.5f}))
		[
			SNew(SImage)
			.Image(&Style::GetMenuStyle()->OptionFront)
		]
		+SCanvas::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Size(FVector2D{636.f,104.f})
		.Position(DHelper::PositionConvert(FVector2D{-332.f,-280.f}))
		[
			//left按钮
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			.Padding(FMargin{0.f})
			.FillWidth(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(Left,SButton)
				.ButtonStyle(&Style::GetMenuStyle()->OptionArrowIcon)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Content()
				[
					SNew(SWrapBox)
					+SWrapBox::Slot()
					.Padding(FMargin{25.f,0.f,0.f,0.f})
					.HAlign(HAlign_Fill)
					[
						SNew(SImage)
						.Image(&Style::GetMenuStyle()->OptionArrow)
						.RenderTransformPivot(FVector2D{0.5f,0.5f})
						.RenderTransform(FTransform2D{FQuat2D{-PI/2.f},FVector2D{0.f,0.f}})
					]
					+SWrapBox::Slot()
					.FillEmptySpace(true)
					.HAlign(HAlign_Fill)
					[
						SNew(STextBlock)
						.Text(FText::FromString(TEXT("左")))
						.Font(Style::GetMenuStyle()->ChineseFont_20)
						.ColorAndOpacity(FLinearColor{0.68f,0.55f,0.36f,1.f})

					]
				]
			]
			//sound
			+SHorizontalBox::Slot()
			.Padding(FMargin{10.f,0.f,10.f,0.f})
			.FillWidth(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(Sound,SButton)
				.ButtonStyle(&Style::GetMenuStyle()->OptionIcon)
			]
			//control
			+SHorizontalBox::Slot()
			.Padding(FMargin{10.f,0.f,20.f,0.f})
			.FillWidth(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(Controller,SButton)
				.ButtonStyle(&Style::GetMenuStyle()->OptionIcon)
			]
			//graphic
			+SHorizontalBox::Slot()
			.Padding(FMargin{0.f,0.f,20.f,0.f})
			.FillWidth(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(Graphic,SButton)
				.ButtonStyle(&Style::GetMenuStyle()->OptionIcon)
			]
			//multiplayer
			+SHorizontalBox::Slot()
			.Padding(FMargin{0.f,0.f,10.f,0.f})
			.FillWidth(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(MultiPlayer,SButton)	
				.ButtonStyle(&Style::GetMenuStyle()->OptionIcon)			
			]
			//right
			+SHorizontalBox::Slot()
			.Padding(FMargin{0.f})
			.FillWidth(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(Right,SButton)
				.ButtonStyle(&Style::GetMenuStyle()->OptionArrowIcon)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Content()
				[
					SNew(SWrapBox)
					+SWrapBox::Slot()
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock)
						.Text(FText::FromString(TEXT("右")))
						.Font(Style::GetMenuStyle()->ChineseFont_20)
						.ColorAndOpacity(FLinearColor{0.68f,0.55f,0.36f,1.f})				
					]
					+SWrapBox::Slot()
					.VAlign(VAlign_Center)
					[
						SNew(SImage)
						.Image(&Style::GetMenuStyle()->OptionArrow)
						.RenderTransformPivot(FVector2D{0.5f,0.5f})
						.RenderTransform(FTransform2D{FQuat2D{PI/2.f},FVector2D{0.f,0.f}})
					]
				]
			]
		]
		
		
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
