// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameDefaultWidget.h"

#include "DevelopTool.h"
#include "GameWidgetStyle.h"
#include "PlayController.h"
#include "PlayeState.h"
#include "SlateOptMacros.h"
#include "Style.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Notifications/SProgressBar.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SGameDefaultWidget::Construct(const FArguments& InArgs)
{
	
	ChildSlot
	[
		SNew(SCanvas)
		//状态条
		+SCanvas::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		.Position(FVector2D{195.f,96.f})
		.Size(FVector2D{1000.f,40.f})
		[
			SNew(SVerticalBox)
			+SVerticalBox::Slot()
			.FillHeight(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(THPLength)
			[
				SAssignNew(HPBar,SProgressBar)
				.Style(&Style::GetGameStyle()->HPBarStyle)
				.FillColorAndOpacity(FLinearColor{0.18f,0.052f,0.054f,1.f})
				.Percent_Raw(this,&SGameDefaultWidget::GetHPPercent)
			]
			+SVerticalBox::Slot()
			.FillHeight(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(THPLength)
			[
				SAssignNew(MPBar,SProgressBar)
				.Style(&Style::GetGameStyle()->HPBarStyle)
				.FillColorAndOpacity(FLinearColor{0.02f,0.02f,0.093f,1.f})
				.Percent_Raw(this,&SGameDefaultWidget::GetHPPercent)
			]
			+SVerticalBox::Slot()
			.FillHeight(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(THPLength)
			[
				SAssignNew(PPBar,SProgressBar)
				.Style(&Style::GetGameStyle()->HPBarStyle)
				.FillColorAndOpacity(FLinearColor{0.036f,0.072f,0.036f,1.f})
				.Percent(PPPercent)
			]		
		]
		//头像
		+SCanvas::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Position(FVector2D{152.f,116.f})
		.Size(FVector2D{80.f,80.f})
		[
			SNew(SImage)
			.Image(&Style::GetGameStyle()->HeadIcon)
		]
		//快捷栏
		+SCanvas::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		.Position(FVector2D{200.f,656.f})
		.Size(FVector2D{104.f,155.f})
		[
			//魔法栏
			SNew(SBorder)
			.BorderImage(&Style::GetGameStyle()->Item)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Content()	
			[
				SAssignNew(MagicItem,SImage)	
			]
		]
		+SCanvas::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		.Position(FVector2D{80.f,748.f})
		.Size(FVector2D{104.f,155.f})
		[
			//左手物品
			SNew(SBorder)
			.BorderImage(&Style::GetGameStyle()->Item)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Content()	
			[
				SAssignNew(LeftHandItem,SImage)	
			]
		]
		+SCanvas::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		.Position(FVector2D{316.f,748.f})
		.Size(FVector2D{104.f,155.f})
		[
			//右手物品
			SNew(SBorder)
			.BorderImage(&Style::GetGameStyle()->Item)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Content()	
			[
				SAssignNew(RightHandItem,SImage)	
			]
		]
		+SCanvas::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		.Position(FVector2D{200.f,836.f})
		.Size(FVector2D{104.f,155.f})
		[
			//消耗品
			SNew(SBorder)
			.BorderImage(&Style::GetGameStyle()->Item)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Content()	
			[
				SAssignNew(FrontSupplyItem,SImage)	
			]
		]
		+SCanvas::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		.Position(FVector2D{324.f,916.f})
		.Size(FVector2D{42.6,62.f})
		[
			//消耗品后台
			SNew(SBorder)
			.BorderImage(&Style::GetGameStyle()->Item)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Content()	
			[
				SAssignNew(BackSupplyItem,SImage)	
			]
		]
		//经验
		+SCanvas::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Position(FVector2D{1700.f,971.5f})
		.Size(FVector2D{225.f,55.f})
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(FMargin{2.0, 4.0, 4.0, 3.5})
			[
				SNew(SImage)
				.Image(&Style::GetGameStyle()->ExpBack)
			]
			+SOverlay::Slot().HAlign(HAlign_Fill).VAlign(VAlign_Fill).Padding(FMargin{0.f})
			[
				SNew(SImage)
				.Image(&Style::GetGameStyle()->ExpFront)
			]
			+SOverlay::Slot().HAlign(HAlign_Right).VAlign(VAlign_Center).Padding(FMargin{0.0, 0.0, 10.0, 0.0})
			[
				SAssignNew(ExpBlock,STextBlock)
				.Font(Style::GetGameStyle()->English_12)
				.Text_Raw(this,&SGameDefaultWidget::GetExpText)
			]
		]
	];
	InitialElement();
}

void SGameDefaultWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	UpdatePercent();
}

void SGameDefaultWidget::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(HPBarDynamic);
	Collector.AddReferencedObject(MPBarDynamic);
	Collector.AddReferencedObject(PPBarDynamic);
}

void SGameDefaultWidget::SetBarLength(float HP, float MP, float PP,float limit)
{
	HPLength.Right = HP/limit*1000.f;
	MPLength.Right = MP/limit*1000.f;
	PPLength.Right = PP/limit*1000.f;
}
void SGameDefaultWidget::UpdatePercent()
{
	HPPercent = FMath::Lerp(HPPercent,PlayeState->GetStateInfo().hp.currnt/PlayeState->GetStateInfo().hp.max,0.03f);
	MPPercent = FMath::Lerp(MPPercent,PlayeState->GetStateInfo().mp.currnt/PlayeState->GetStateInfo().mp.max,0.03f);
	PPPercent = FMath::Lerp(PPPercent,PlayeState->GetStateInfo().pp.currnt/PlayeState->GetStateInfo().pp.max,0.03f);
}

TOptional<float> SGameDefaultWidget::GetHPPercent() const 
{
	return HPPercent;
}

FText SGameDefaultWidget::GetExpText() const
{
	return FText::FromString(FString::FromInt(PlayeState->GetStateInfo().Exp));
}

FMargin SGameDefaultWidget::GetHPBarLength() const
{
	return HPLength;
}

FMargin SGameDefaultWidget::GetMPBarLength() const
{
	return MPLength;
}

FMargin SGameDefaultWidget::GetPPBarLength() const
{
	return PPLength;
}

void SGameDefaultWidget::SetMatrialParm()
{
	DHelper::Debug(FString("setparam"),2.f);
	float Detla = HPBarDynamic->K2_GetScalarParameterValue("Percent")-PlayeState->GetStateInfo().hp.currnt/PlayeState->GetStateInfo().hp.max;
	if(FMath::Abs(Detla)<0.001f)
	{
		GWorld->GetTimerManager().ClearTimer(HPBarHandle);
	}
	else
		HPBarDynamic->SetScalarParameterValue("Percent",FMath::Lerp(HPBarDynamic->K2_GetScalarParameterValue("Percent"),
			PlayeState->GetStateInfo().hp.currnt/PlayeState->GetStateInfo().hp.max,0.01f));
}

void SGameDefaultWidget::UpdateHPMaterial()
{
	FTimerDelegate Delegate;
	Delegate.BindRaw(this,&SGameDefaultWidget::SetMatrialParm);
	float detla = HPBarDynamic->K2_GetScalarParameterValue("Percent")-PlayeState->GetStateInfo().hp.currnt/PlayeState->GetStateInfo().hp.max;
		GWorld->GetTimerManager().SetTimer(HPBarHandle,Delegate,0.01f,true,2.f);
	DHelper::Debug(FString("SetTimer"),2.f);
}

void SGameDefaultWidget::InitialElement()
{
	auto control = Cast<APlayController>(UGameplayStatics::GetPlayerController(GWorld,0));
	//初始化进度条长度，大小
	if(control)
	{
		PlayeState = Cast<APlayeState>(control->PlayerState);
		HPLength = {0.f,0.f,(1.f-PlayeState->GetStateInfo().hp.max/PlayeState->GetStateInfo().hp.limit)*1000.f,5.f};
		MPLength = {0.f,0.f,PlayeState->GetStateInfo().mp.max/PlayeState->GetStateInfo().mp.limit*1000.f,5.f};
		PPLength = {0.f,0.f,PlayeState->GetStateInfo().pp.max/PlayeState->GetStateInfo().pp.limit*1000.f,0.f};
		HPPercent = PlayeState->GetStateInfo().hp.currnt/PlayeState->GetStateInfo().hp.max;
		MPPercent = PlayeState->GetStateInfo().mp.currnt/PlayeState->GetStateInfo().mp.max;
		PPPercent = PlayeState->GetStateInfo().pp.currnt/PlayeState->GetStateInfo().pp.max;
	}
	THPLength.Bind(this,&SGameDefaultWidget::GetHPBarLength);
	TMPLength.Bind(this,&SGameDefaultWidget::GetMPBarLength);
	TPPLength.Bind(this,&SGameDefaultWidget::GetPPBarLength);
	//初始化进度条材质
	UMaterialInterface* BarMatInst = LoadObject<UMaterialInterface>(nullptr,TEXT("MaterialInstanceConstant'/Game/UI/Material/Mat_ProcessB_Inst.Mat_ProcessB_Inst'"));
	HPBarDynamic = UMaterialInstanceDynamic::Create(BarMatInst,nullptr);
	FSlateBrush* HPBrush = new FSlateBrush();
	HPBrush->DrawAs= ESlateBrushDrawType::Image;
	HPBrush->SetResourceObject(HPBarDynamic);
	HPBrush->TintColor = FLinearColor{0.138f,0.147f,0.076f,1.f};
	HPBar.Get()->SetBackgroundImage(HPBrush);
	HPBarDynamic->SetScalarParameterValue(FName("Percent"),HPPercent);
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION
