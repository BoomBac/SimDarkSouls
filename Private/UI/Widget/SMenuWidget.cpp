// Fill out your copyright notice in the Description page of Project Settings.


#include "SMenuWidget.h"

#include "DevelopTool.h"
#include "MenuWidgetStyle.h"
#include "SlateOptMacros.h"
#include "Style.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Images/SImage.h"
#include "SLogoMenuWidget.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SDPIScaler.h"

//start menu

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMenuWidget::Construct(const FArguments& InArgs)
{
	UIScaler.Bind(this, &SMenuWidget::GetUIScaler);
	
	InitializeAnimation();
	ChildSlot
	[
		SNew(SDPIScaler)
		.DPIScale(UIScaler)
		[
			SNew(SCanvas)
			+SCanvas::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Size(FVector2D{1920.f,1080.f})
			[
				SNew(SImage)
				.ColorAndOpacity(FLinearColor{0.f,0.f,0.f,1.f})
			]
			+SCanvas::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.Position(DHelper::PositionConvert(FVector2D{0.f,-13.5f}))
			.Size(FVector2D{1688.f,258.f})
			[
				SNew(SImage)
				.Image(&Style::GetMenuStyle()->MainTitle)
			]
			+SCanvas::Slot()
			.HAlign(HAlign_Center)
	        .VAlign(VAlign_Center)
			.Position(DHelper::PositionConvert(FVector2D{40.f,460.f}))
			.Size(FVector2D{680.f,30.f})
			[
				SNew(STextBlock)
				.Font(Style::GetMenuStyle()->EnglishFont_14)
				//Doge Souls &2021 MY SELF Entertainment Inc./ 2020-2021 MySelfSoftware.Inc
				.Text(FText::FromString(FString("Doge Souls &2021 MY SELF Entertainment Inc./ 2020-2021 MySelfSoftware.Inc")))
			]
			+SCanvas::Slot()
			.HAlign(HAlign_Fill)
	        .VAlign(VAlign_Fill)
	        .Size(FVector2D{1920.f,1080.f})
	        [
				SAssignNew(LogoMenu,SLogoMenuWidget)
	        ]
	        +SCanvas::Slot()
	        .HAlign(HAlign_Center)
	        .VAlign(VAlign_Center)
	        .Position(DHelper::PositionConvert(FVector2D{9.f,270.f}))
	        .Size(FVector2D{240.f,200.f})
	        [
				SAssignNew(ScrollBox,SScrollBox)
				//占位文本块
				+SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(STextBlock)
					.Margin(FMargin{0.f,10.f,0.f,0.f})
				]
				+SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SButton)
					.ButtonStyle(&Style::GetMenuStyle()->StartMenuButton)
					.ContentPadding(FMargin{0.f,0.f,0.f,0.f})
					.Content()
					[
						SNew(STextBlock)
						.Font(Style::GetMenuStyle()->ChineseFont_20)
						.Text(FText::FromString(TEXT("Continue")))
						.Justification(ETextJustify::Center)
					]			
				]
				//占位文本块
				+SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(STextBlock)
					.Margin(FMargin{0.f,10.f,0.f,0.f})
				]
				+SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SButton)
					.ButtonStyle(&Style::GetMenuStyle()->StartMenuButton)
					.ContentPadding(FMargin{0.f,0.f,0.f,0.f})
					.Content()
					[
						SNew(STextBlock)
					.Font(Style::GetMenuStyle()->ChineseFont_20)
					.Text(FText::FromString(TEXT("StartNewGame")))
					.Justification(ETextJustify::Center)
					]			
				]
				//占位文本块
				+SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(STextBlock)
					.Margin(FMargin{0.f,10.f,0.f,0.f})
				]
				+SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SButton)
					.ButtonStyle(&Style::GetMenuStyle()->StartMenuButton)
					.ContentPadding(FMargin{0.f,0.f,0.f,0.f})
					.Content()
					[
						SNew(STextBlock)
					.Font(Style::GetMenuStyle()->ChineseFont_20)
					.Text(FText::FromString(TEXT("SystemSetting")))
					.Justification(ETextJustify::Center)
					]			
				]
				//占位文本块
				+SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(STextBlock)
					.Margin(FMargin{0.f,10.f,0.f,0.f})
				]
				+SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SButton)
					.ButtonStyle(&Style::GetMenuStyle()->StartMenuButton)
					.ContentPadding(FMargin{0.f,0.f,0.f,0.f})
					.Content()
					[
						SNew(STextBlock)
					.Font(Style::GetMenuStyle()->ChineseFont_20)
					.Text(FText::FromString(TEXT("News")))
					.Justification(ETextJustify::Center)
					]			
				]
				//占位文本块
				+SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(STextBlock)
					.Margin(FMargin{0.f,10.f,0.f,0.f})
				]
				+SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SButton)
					.ButtonStyle(&Style::GetMenuStyle()->StartMenuButton)
					.ContentPadding(FMargin{0.f,0.f,0.f,0.f})
					.Content()
					[
						SNew(STextBlock)
					.Font(Style::GetMenuStyle()->ChineseFont_20)
					.Text(FText::FromString(TEXT("QuitGame")))
					.Justification(ETextJustify::Center)
					]			
				]
				//占位文本块
				+SScrollBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(STextBlock)
					.Margin(FMargin{0.f,10.f,0.f,0.f})
				]
	        ]
	        +SCanvas::Slot()
	        .HAlign(HAlign_Center)
	        .VAlign(VAlign_Center)
	        .Position(DHelper::PositionConvert(FVector2D{2.f,140.f}))
	        .Size(FVector2D{23.f,19.f})
	        [
				SNew(SImage)
				.Image(&Style::GetMenuStyle()->ScrollArrow)
	        ]
	        +SCanvas::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.Position(DHelper::PositionConvert(FVector2D{24.f,420.f}))
			.Size(FVector2D{23.f,19.f})
			[
				SNew(SImage)
				.Image(&Style::GetMenuStyle()->ScrollArrow)
				.RenderTransformPivot(FVector2D{0.5f,0.5f})
				.RenderTransform(FTransform2D{FQuat2D{PI},FVector2D{0.f,0.f}})
			]
		]
	];
	//初始化scrollbox
	ScrollBox->SetScrollBarVisibility(EVisibility::Hidden);
	ScrollBox->SetConsumeMouseWheel(EConsumeMouseWheel::WhenScrollingPossible);
	ScrollBox->SetAnimateWheelScrolling(true);
	ScrollBox->SetScrollBarThickness(FVector2D{9.f,0.f});
}

void SMenuWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	auto dpi = GEngine->GameViewport->GetDPIScale();
	FVector2D MousePos{0.f,0.f};
	GEngine->GameViewport->GetMousePosition(MousePos);
	DHelper::Debug((MousePos/dpi).ToString(),0.f);
}

void SMenuWidget::InitializeAnimation()
{
}

float SMenuWidget::GetUIScaler() const
{
	FVector2D Result(1920.f, 1080.f);
	if (GEngine && GEngine->GameViewport) {
		GEngine->GameViewport->GetViewportSize(Result);
	}
	return Result.Y/1080.f;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
