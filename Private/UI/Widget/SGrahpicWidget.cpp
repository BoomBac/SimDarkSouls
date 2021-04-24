// Fill out your copyright notice in the Description page of Project Settings.


#include "SGrahpicWidget.h"
#include "International.h"
#include "Singleton.h"
#include "SlateOptMacros.h"
#include "Style.h"
#include "Widgets/SCanvas.h"
#include "MenuWidgetStyle.h"
#include "Components/TimelineComponent.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Input/SEditableText.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SGrahpicWidget::Construct(const FArguments& InArgs)
{
	FTimeline Timeline;
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
			//跨区域联机配对
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
					.VAlign(VAlign_Bottom)
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
					.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("Grahpic1")))
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
							//SNew(SListView<>)
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
			//召唤记号可见性
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
				.VAlign(VAlign_Bottom)
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
				.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("Grahpic2")))
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
						.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("Unlimit")))
						.Justification(ETextJustify::Center)
						.Margin(FMargin{0.f,18.f,0.f,0.f})
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
			//以暗号进行配对
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
					.VAlign(VAlign_Bottom)
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
					.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("Grahpic3")))
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
						.VAlign(VAlign_Bottom)
						.HAlign(HAlign_Fill)
						.Content()
						[
							SNew(SEditableText)
							.Font(Style::GetMenuStyle()->ChineseFont_20)
							.Justification(ETextJustify::Center)
							.HintText(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("UnSet")))
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
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
