// Fill out your copyright notice in the Description page of Project Settings.


#include "SLogoMenuWidget.h"


#include "DevelopTool.h"
#include "International.h"
#include "MenuWidgetStyle.h"
#include "Singleton.h"
#include "SlateOptMacros.h"
#include "Style.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SLogoMenuWidget::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SCanvas)
		+SCanvas::Slot()
		.HAlign(EHorizontalAlignment::HAlign_Center)
		.VAlign(EVerticalAlignment::VAlign_Center)
		.Position(FVector2D{960.f,820.f})
		.Size(FVector2D{450.f,30.f})
		[
		    SNew(SImage)
		    .Image(&Style::GetMenuStyle()->YellowForLogo)
		]
		+SCanvas::Slot()
		.HAlign(EHorizontalAlignment::HAlign_Center)
		.VAlign(EVerticalAlignment::VAlign_Center)
		.Position(DHelper::PositionConvert(FVector2D{0.f,280.f}))
		.Size(FVector2D{250.f,35.f})
		[		
			SNew(STextBlock)
			.Font(Style::GetMenuStyle()->ChineseFont_20)
			.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("PAK")))
			.Justification(ETextJustify::Center)
		]

	];
}
FReply SLogoMenuWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	//设置滚动栏显示
	ScrllVisiblity.ExecuteIfBound(EVisibility::Visible);
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
