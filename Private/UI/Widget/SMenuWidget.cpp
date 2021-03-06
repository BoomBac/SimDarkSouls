// Fill out your copyright notice in the Description page of Project Settings.


#include "SMenuWidget.h"

#include "DevelopTool.h"
#include "FunctionalUIScreenshotTest.h"
#include "International.h"
#include "MenuWidgetStyle.h"
#include "Singleton.h"
#include "SlateOptMacros.h"
#include "Style.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Images/SImage.h"
#include "SLogoMenuWidget.h"
#include "SOptionMenuWidget.h"
#include "TimeLineHandle.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SDPIScaler.h"

//start menu

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMenuWidget::Construct(const FArguments& InArgs)
{
	//绑定ui数据元素
	UIScaler.Bind(this, &SMenuWidget::GetUIScaler);
	TAtitleColor.Bind(this,&SMenuWidget::GetTitleColor);
	OnScrolled.BindRaw(this,&SMenuWidget::Scrolled);
	//初始化时间轴组
	Event_TLFinsh.BindRaw(this,&SMenuWidget::TimeLineFinish);
	TimeLineHandle::Get()->AddTimeLineL(FName("TitleShow"),TEXT("CurveLinearColor'/Game/UI/CR_TitleColor.CR_TitleColor'")).
			BindRaw(this,&SMenuWidget::TimeLineTitle);
	TimeLineHandle::Get()->GetTimeLineL(FName("TitleShow"))->Timeline.SetTimelineFinishedFunc(Event_TLFinsh);
	TimeLineHandle::Get()->GetTimeLineL(FName("TitleShow"))->Timeline.SetPlayRate(0.8f);
	TimeLineHandle::Get()->GetTimeLineL(FName("TitleShow"))->Timeline.PlayFromStart();
	ScrollOffset = 0.1f;
	bScrollCanShow = false;
	ChildSlot
	[
		SNew(SDPIScaler)
		.DPIScale(UIScaler)
		[
			SAssignNew(RootPannel,SCanvas)
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
				.ColorAndOpacity(TAtitleColor)
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
				.Visibility(EVisibility::Hidden)
	        ]
	        +SCanvas::Slot()
	        .HAlign(HAlign_Center)
	        .VAlign(VAlign_Center)
	        .Position(DHelper::PositionConvert(FVector2D{9.f,270.f}))
	        .Size(FVector2D{240.f,200.f})
	        [
				SAssignNew(ScrollBox,SScrollBox)
				.Visibility(EVisibility::Hidden)
				.OnUserScrolled(OnScrolled)
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
						.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("Contine")))
						.ColorAndOpacity(FLinearColor{1.f,1.f,1.f,1.f})
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
					.OnClicked_Raw(this,&SMenuWidget::OnNewGameCilcked)
					.ContentPadding(FMargin{0.f,0.f,0.f,0.f})
					.Content()
					[
						SNew(STextBlock)
					.Font(Style::GetMenuStyle()->ChineseFont_20)
					.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("New")))
					.ColorAndOpacity(FLinearColor{1.f,1.f,1.f,1.f})
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
					.OnClicked_Raw(this,&SMenuWidget::OnClicked)
					.ContentPadding(FMargin{0.f,0.f,0.f,0.f})
					.Content()
					[
						SNew(STextBlock)
					.Font(Style::GetMenuStyle()->ChineseFont_20)
					.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("Setting")))
					.ColorAndOpacity(FLinearColor{1.f,1.f,1.f,1.f})
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
					.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("News")))
					.ColorAndOpacity(FLinearColor{1.f,1.f,1.f,1.f})
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
					.Text(FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),FString("Exit")))
					.ColorAndOpacity(FLinearColor{1.f,1.f,1.f,1.f})
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
	        .Position(DHelper::PositionConvert(FVector2D{0.f,140.f}))
	        .Size(FVector2D{23.f,19.f})
	        [
				SAssignNew(ScrollUp,SImage)
				.Image(&Style::GetMenuStyle()->ScrollArrow)
				.Visibility(EVisibility::Hidden)
	        ]
	        +SCanvas::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			.Position(DHelper::PositionConvert(FVector2D{0.f,390.f}))
			.Size(FVector2D{23.f,19.f})
			[
				SAssignNew(ScrollDown,SImage)
				.Image(&Style::GetMenuStyle()->ScrollArrow)
				.RenderTransformPivot(FVector2D{0.5f,0.5f})
				.RenderTransform(FTransform2D{FQuat2D{PI},FVector2D{0.f,0.f}})
				.Visibility(EVisibility::Hidden)
			]
		]
	];
	//初始化scrollbox
	ScrollBox->SetScrollBarVisibility(EVisibility::Hidden);
	ScrollBox->SetConsumeMouseWheel(EConsumeMouseWheel::WhenScrollingPossible);
	ScrollBox->SetAnimateWheelScrolling(true);
	ScrollBox->SetScrollBarThickness(FVector2D{9.f,0.f});
	LogoMenu->ScrllVisiblity.BindRaw(this,&SMenuWidget::SetScrollGruopVisibility);
}

void SMenuWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	// auto dpi = GEngine->GameViewport->GetDPIScale();
	// FVector2D MousePos{0.f,0.f};
	// GEngine->GameViewport->GetMousePosition(MousePos);
	// DHelper::Debug((MousePos/dpi).ToString(),0.f);
	// if(TimeLineHandle::Get()->GetTimeLineF(FName("TitleShow"))->TimelineFunc.IsBound())
	// 	DHelper::Debug(FString("unbind"),0.f);
	TimeLineHandle::Get()->GetTimeLineL(FName("TitleShow"))->Timeline.TickTimeline(InDeltaTime);
	if(bScrollCanShow)
	SetScrollArrowVisiblity(InDeltaTime);
}

FReply SMenuWidget::OnClicked()
{
	RootPannel->AddSlot().HAlign(HAlign_Fill).VAlign(VAlign_Fill).Size(FVector2D{1920.f,1080.f})
	[
		SNew(SOptionMenuWidget)
	];
	return FReply::Handled();
}

//uscaler绑定函数
float SMenuWidget::GetUIScaler() const
{
	FVector2D Result(1920.f, 1080.f);
	if (GEngine && GEngine->GameViewport) {
		GEngine->GameViewport->GetViewportSize(Result);
	}
	return Result.Y/1080.f;
}
//title颜色绑定函数
FSlateColor SMenuWidget::GetTitleColor() const 
{
	return TitleColor;
}

void SMenuWidget::TimeLineTitle(FLinearColor value)
{
	TitleColor = value;
}

void SMenuWidget::TimeLineFinish()
{
	LogoMenu->SetVisibility(EVisibility::Visible);
}

void SMenuWidget::funcf(float value)
{
	
};
	


void SMenuWidget::SetScrollGruopVisibility(EVisibility bV)
{
	bScrollCanShow = true;
	ScrollBox->SetVisibility(bV);
	ScrollDown->SetVisibility(bV);
	ScrollUp->SetVisibility(bV);
	LogoMenu->SetVisibility(EVisibility::Hidden);
}

void SMenuWidget::SetScrollArrowVisiblity(float alpha)
{
	if(ScrollOffset<1.f)
	{
		ScrollUp->SetVisibility(EVisibility::Hidden);
	}
	else
	{
		ScrollUp->SetVisibility(EVisibility::Visible);
	}
	if(ScrollOffset>110.f)
	{
		ScrollDown->SetVisibility(EVisibility::Hidden);
		//ScrollDown->SetColorAndOpacity(FMath::Lerp<FLinearColor>({1.f,1.f,1.f,1.f},{1.f,1.f,1.f,0.f},alpha));
	}
	else
	{
		ScrollDown->SetVisibility(EVisibility::Visible);
	}
}

void SMenuWidget::Scrolled(float value)
{
	ScrollOffset = value;
}

FReply SMenuWidget::OnNewGameCilcked() const
{
	UGameplayStatics::OpenLevel(UGameplayStatics::GetPlayerController(GWorld,0)->GetWorld(),FName("GameMap"));
	return FReply::Handled();
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION
