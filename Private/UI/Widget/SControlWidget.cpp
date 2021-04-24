// Fill out your copyright notice in the Description page of Project Settings.


#include "SControlWidget.h"

#include "DevelopTool.h"
#include "International.h"
#include "MenuWidgetStyle.h"
#include "Singleton.h"
#include "SlateOptMacros.h"
#include "Style.h"
#include "Internationalization/StringTableRegistry.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Notifications/SProgressBar.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SControlWidget::Construct(const FArguments& InArgs)
{
	
	ChildSlot
	[
		SNew(SCanvas)
		+SCanvas::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		.Position(FVector2D{0.f,0.f})
		.Size(FVector2D{900.f,150.f})
		[
			SNew(SVerticalBox)
			//鼠标操作灵敏度
			+SVerticalBox::Slot()
			.Padding(FMargin{0.f})
			.FillHeight(true)
			.HAlign(HAlign_Fill)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.FillWidth(1.f)
				[
					SNew(SOverlay)
					+SOverlay::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					[
						SNew(SImage)
						.Image(&Style::GetMenuStyle()->LeftOptionBG)
					]
					+SOverlay::Slot()
					.VAlign(VAlign_Bottom)
					.HAlign(HAlign_Right)
					.Padding(FMargin{0.f,18.f,10.f,0.f})
					[
						SNew(STextBlock)
						.Font(Style::GetMenuStyle()->ChineseFont_20)						
						.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("Control1")))
					]
				]
				+SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Bottom)
				[
						SNew(SImage)
						.Image(&Style::GetMenuStyle()->OptionArrow)
						.RenderTransformPivot(FVector2D{0.5f,0.5f})
						.RenderTransform(FTransform2D{FQuat2D{-PI/2.f},FVector2D{0.f,0.f}})
				]
				+SHorizontalBox::Slot()
				.FillWidth(1.f)
				[
						SNew(SOverlay)
						+SOverlay::Slot()
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Fill)
						[
							SNew(SProgressBar)
							.Style(&Style::GetMenuStyle()->BarStyle)
							//temp
							.Percent(20.f)
						]
				]
				+SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Bottom)
				[
						SNew(SImage)
						.Image(&Style::GetMenuStyle()->OptionArrow)
						.RenderTransformPivot(FVector2D{0.5f,0.5f})
						.RenderTransform(FTransform2D{FQuat2D{PI/2.f},FVector2D{0.f,0.f}})
				]
			]
			//鼠标左右操作
			+SVerticalBox::Slot()
			.Padding(FMargin{0.f})
			.FillHeight(true)
			.HAlign(HAlign_Fill)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.FillWidth(1.f)
				[
					SNew(SOverlay)
					+SOverlay::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					[
					SNew(SImage)
					.Image(&Style::GetMenuStyle()->LeftOptionBG)
					]
					+SOverlay::Slot()
					.VAlign(VAlign_Bottom)
					.HAlign(HAlign_Right)
					.Padding(FMargin{0.f,18.f,10.f,0.f})
					[
					SNew(STextBlock)
					.Font(Style::GetMenuStyle()->ChineseFont_20)						
					.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("Control2")))
					]
				]
				+SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Bottom)
				[
					SNew(SImage)
					.Image(&Style::GetMenuStyle()->OptionArrow)
					.RenderTransformPivot(FVector2D{0.5f,0.5f})
					.RenderTransform(FTransform2D{FQuat2D{-PI/2.f},FVector2D{0.f,0.f}})
				]
				+SHorizontalBox::Slot()
				.FillWidth(1.f)
				[
					SNew(SOverlay)
					+SOverlay::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					[
						SNew(SBorder)
						.BorderImage(&Style::GetMenuStyle()->RightOptionBG)
						.VAlign(VAlign_Fill)
						.HAlign(HAlign_Fill)
						.Content()
						[
							SNew(STextBlock)
							.Font(Style::GetMenuStyle()->ChineseFont_20)
							.Justification(ETextJustify::Center)
							.Margin(FMargin{0.f,18.f,0.f,0.f})
							.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("Open")))
						]
					]
				]
				+SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Bottom)
				[
					SNew(SImage)
					.Image(&Style::GetMenuStyle()->OptionArrow)
					.RenderTransformPivot(FVector2D{0.5f,0.5f})
					.RenderTransform(FTransform2D{FQuat2D{PI/2.f},FVector2D{0.f,0.f}})
				]		
			]
			//鼠标上下操作
			+SVerticalBox::Slot()
			.Padding(FMargin{0.f})
			.FillHeight(true)
			.HAlign(HAlign_Fill)
			[
			SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.FillWidth(1.f)
				[
				SNew(SOverlay)
				+SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
				SNew(SImage)
				.Image(&Style::GetMenuStyle()->LeftOptionBG)
				]
				+SOverlay::Slot()
				.VAlign(VAlign_Bottom)
				.HAlign(HAlign_Right)
				.Padding(FMargin{0.f,18.f,10.f,0.f})
				[
				SNew(STextBlock)
				.Font(Style::GetMenuStyle()->ChineseFont_20)						
				.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("Control3")))
				]
				]
				+SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Bottom)
				[
				SNew(SImage)
				.Image(&Style::GetMenuStyle()->OptionArrow)
				.RenderTransformPivot(FVector2D{0.5f,0.5f})
				.RenderTransform(FTransform2D{FQuat2D{-PI/2.f},FVector2D{0.f,0.f}})
				]
				+SHorizontalBox::Slot()
				.FillWidth(1.f)
				[
				SNew(SOverlay)
				+SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SBorder)
					.BorderImage(&Style::GetMenuStyle()->RightOptionBG)
					.VAlign(VAlign_Fill)
					.HAlign(HAlign_Fill)
					.Content()
					[
						SNew(STextBlock)
						.Font(Style::GetMenuStyle()->ChineseFont_20)
						.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("Open")))
						.Justification(ETextJustify::Center)
						.Margin(FMargin{0.f,18.f,0.f,0.f})
					]
				]
				]
				+SHorizontalBox::Slot()
				.VAlign(VAlign_Bottom)
				.AutoWidth()
				[
				SNew(SImage)
				.Image(&Style::GetMenuStyle()->OptionArrow)
				.RenderTransformPivot(FVector2D{0.5f,0.5f})
				.RenderTransform(FTransform2D{FQuat2D{PI/2.f},FVector2D{0.f,0.f}})
				]				
			]
		]
	];
}


FReply SControlWidget::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	
	auto pos = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
	DHelper::Debug(pos.ToString(),0.f);
	return FReply::Handled();
}

FReply SControlWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	Singleton<International>::Get()->SetCulture(ECultureType::EN);
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
