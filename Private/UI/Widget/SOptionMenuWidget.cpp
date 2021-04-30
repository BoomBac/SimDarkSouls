// Fill out your copyright notice in the Description page of Project Settings.


#include "SOptionMenuWidget.h"

#include "DevelopTool.h"
#include "GeneratedCodeHelpers.h"
#include "International.h"
#include "MenuWidgetStyle.h"
#include "SControlWidget.h"
#include "SDisplaySoundWidget.h"
#include "SGrahpicWidget.h"
#include "Singleton.h"
#include "SlateOptMacros.h"
#include "SMultiPlayerWidget.h"
#include "Style.h"
#include "Widgets/SCanvas.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Layout/SBackgroundBlur.h"
#include "Widgets/Layout/SWrapBox.h"
#include "Engine/Texture2D.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SOptionMenuWidget::Construct(const FArguments& InArgs)
{
	// TexControl = LoadObject<UTexture2D>(nullptr,TEXT("Texture2D'/Game/UI/Texture/Control.Control'"));
	// TexGraphic = LoadObject<UTexture2D>(nullptr,TEXT("Texture2D'/Game/UI/Texture/graphic.graphic'"));
	// TexSound = LoadObject<UTexture2D>(nullptr,TEXT("Texture2D'/Game/UI/Texture/DisplaySound.DisplaySound'"));
	//  TexMultiPlayer = LoadObject<UTexture2D>(nullptr,TEXT("Texture2D'/Game/UI/Texture/MultiPlayer.MultiPlayer'"));
	// static ConstructorHelpers::FObjectFinder<UTexture2D> ControlTexLoader(TEXT("Texture2D'/Game/UI/Texture/Control.Control'"));
	// TexControl = ControlTexLoader.Object;

	//创建选项图标动态材质
	// OptionIconMatInst = LoadObject<UMaterialInterface>(NULL, TEXT("MaterialInstanceConstant'/Game/UI/Material/OptionIConMask_Inst.OptionIConMask_Inst'"));
	// OptionIconDynamic = UMaterialInstanceDynamic::Create(OptionIconMatInst, nullptr);
	// ButtonStyle = MakeShareable(new FButtonStyle(Style::GetMenuStyle()->OptionIcon));
	// ButtonStyle.Get()->Hovered.SetResourceObject(OptionIconDynamic);
	// ButtonStyle.Get()->Normal.SetResourceObject(OptionIconDynamic);
	// ButtonStyle.Get()->Pressed.SetResourceObject(OptionIconDynamic);
	//加载贴图


	ChildSlot
	[
		SAssignNew(RootPannel,SCanvas)
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
		.Size(FVector2D{1294.f,680.f})
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
				.OnClicked_Raw(this,&SOptionMenuWidget::OnLeftClicked)
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
				//.ButtonStyle(&Style::GetMenuStyle()->OptionIcon)
				.OnHovered_Raw(this,&SOptionMenuWidget::OnSoundHovered)
			]
			//control
			+SHorizontalBox::Slot()
			.Padding(FMargin{10.f,0.f,20.f,0.f})
			.FillWidth(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(Controller,SButton)
				//.ButtonStyle(&Style::GetMenuStyle()->OptionIcon)
				.OnHovered_Raw(this,&SOptionMenuWidget::OnControlHovered)
			]
			//graphic
			+SHorizontalBox::Slot()
			.Padding(FMargin{0.f,0.f,20.f,0.f})
			.FillWidth(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(Graphic,SButton)
				//.ButtonStyle(&Style::GetMenuStyle()->OptionIcon)
				.OnHovered_Raw(this,&SOptionMenuWidget::OnGraphicHovered)
			]
			//multiplayer
			+SHorizontalBox::Slot()
			.Padding(FMargin{0.f,0.f,10.f,0.f})
			.FillWidth(1.f)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SAssignNew(MultiPlayer,SButton)	
				//.ButtonStyle(&Style::GetMenuStyle()->OptionIcon)
				.OnHovered_Raw(this,&SOptionMenuWidget::OnMultiPlayerHovered)
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
				.OnClicked_Raw(this,&SOptionMenuWidget::OnRightClicked)
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
		+SCanvas::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		.Position(FVector2D{364.f,132.f})
		.Size(FVector2D{200.f,40.f})
		[
			SAssignNew(TopTitle,STextBlock)
			.Font(Style::GetMenuStyle()->ChineseFont_20)
			.Text_Raw(this,&SOptionMenuWidget::GetTitleText)
		]
	];
	InitializeIconStyle();
	InitializeIconMap();
}

void SOptionMenuWidget::SetIconChoosed(EOptionIconType::Type Button)
{
	(*IconMaterialMap.Find(CurrentIcon))->SetScalarParameterValue(FName("Location"),0.5f);
	(*IconMaterialMap.Find(CurrentIcon))->SetScalarParameterValue(FName("Darker"),0.4f);
	IconButtonMap.Find(CurrentIcon)->Get()->SetRenderTransform(FVector2D{0.f,0.f});
	 (*IconMaterialMap.Find(Button))->SetScalarParameterValue(FName("Location"),0.f);
	 (*IconMaterialMap.Find(Button))->SetScalarParameterValue(FName("Darker"),1.f);
	 IconButtonMap.Find(Button)->Get()->SetRenderTransform(FVector2D{0.f,-20.f});
	 CurrentIcon = Button;
}

void SOptionMenuWidget::InitializeIconStyle()
{
	TexControl =  Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL,TEXT("Texture2D'/Game/UI/Texture/Control.Control'")));  
	TexGraphic =  Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL,TEXT("Texture2D'/Game/UI/Texture/graphic.graphic'")));  
	TexSound =  Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL,TEXT("Texture2D'/Game/UI/Texture/DisplaySound.DisplaySound'")));  
	TexMultiPlayer =  Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL,TEXT("Texture2D'/Game/UI/Texture/MultiPlayer.MultiPlayer'")));  
	//创建选项图标动态材质
	OptionIconMatInst = LoadObject<UMaterialInterface>(nullptr, TEXT("MaterialInstanceConstant'/Game/UI/Material/OptionIConMask_Inst.OptionIConMask_Inst'"));
	ControlDynamic = UMaterialInstanceDynamic::Create(OptionIconMatInst, nullptr);
	GraphicDynamic = UMaterialInstanceDynamic::Create(OptionIconMatInst, nullptr);
	MultiplayerDynamic = UMaterialInstanceDynamic::Create(OptionIconMatInst, nullptr);
	SoundDynamic = UMaterialInstanceDynamic::Create(OptionIconMatInst, nullptr);
	IconMaterialArr.Add(ControlDynamic);
	IconMaterialArr.Add(GraphicDynamic);
	IconMaterialArr.Add(MultiplayerDynamic);
	IconMaterialArr.Add(SoundDynamic);
	
	ControlStyle = MakeShareable(new FButtonStyle(Style::GetMenuStyle()->OptionIcon));
	ControlDynamic->SetTextureParameterValue(FName("Texture"),TexControl);
	ControlStyle.Get()->Hovered.SetResourceObject(ControlDynamic);
	ControlStyle.Get()->Normal.SetResourceObject(ControlDynamic);
	ControlStyle.Get()->Pressed.SetResourceObject(ControlDynamic);
	Controller.Get()->SetButtonStyle(ControlStyle.Get());
	
	SoundStyle = MakeShareable(new FButtonStyle(Style::GetMenuStyle()->OptionIcon));
	SoundDynamic->SetTextureParameterValue(FName("Texture"),TexSound);
	SoundStyle.Get()->Hovered.SetResourceObject(SoundDynamic);
	SoundStyle.Get()->Normal.SetResourceObject(SoundDynamic);
	SoundStyle.Get()->Pressed.SetResourceObject(SoundDynamic);
	Sound.Get()->SetButtonStyle(SoundStyle.Get());

	GrahpicStyle = MakeShareable(new FButtonStyle(Style::GetMenuStyle()->OptionIcon));
	GraphicDynamic->SetTextureParameterValue(FName("Texture"),TexGraphic);
	GrahpicStyle.Get()->Hovered.SetResourceObject(GraphicDynamic);
	GrahpicStyle.Get()->Normal.SetResourceObject(GraphicDynamic);
	GrahpicStyle.Get()->Pressed.SetResourceObject(GraphicDynamic);
	Graphic.Get()->SetButtonStyle(GrahpicStyle.Get());

	MultiPlayerStyle = MakeShareable(new FButtonStyle(Style::GetMenuStyle()->OptionIcon));
	MultiplayerDynamic->SetTextureParameterValue(FName("Texture"),TexMultiPlayer);
	MultiPlayerStyle.Get()->Hovered.SetResourceObject(MultiplayerDynamic);
	MultiPlayerStyle.Get()->Normal.SetResourceObject(MultiplayerDynamic);
	MultiPlayerStyle.Get()->Pressed.SetResourceObject(MultiplayerDynamic);
	MultiPlayer.Get()->SetButtonStyle(MultiPlayerStyle.Get());
}

void SOptionMenuWidget::InitializeIconMap()
{
	//初始化buttonmap
	IconMaterialMap.Add(EOptionIconType::Control,ControlDynamic);
	IconMaterialMap.Add(EOptionIconType::Grahpic,GraphicDynamic);
	IconMaterialMap.Add(EOptionIconType::Multiplayer,MultiplayerDynamic);
	IconMaterialMap.Add(EOptionIconType::DisplaySound,SoundDynamic);
	IconButtonMap.Add(EOptionIconType::Control,Controller.ToSharedRef());
	IconButtonMap.Add(EOptionIconType::Grahpic,Graphic.ToSharedRef());
	IconButtonMap.Add(EOptionIconType::Multiplayer,MultiPlayer.ToSharedRef());
	IconButtonMap.Add(EOptionIconType::DisplaySound,Sound.ToSharedRef());
	TopTitleMap.Add(EOptionIconType::Control,FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),TEXT("Control")));
	TopTitleMap.Add(EOptionIconType::Grahpic,FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),TEXT("Grahpic")));
	TopTitleMap.Add(EOptionIconType::Multiplayer,FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),TEXT("MP")));
	TopTitleMap.Add(EOptionIconType::DisplaySound,FText::FromStringTable(Singleton<International>::Get()->GetCultureAsFname(),TEXT("Display")));
	CurrentIcon = EOptionIconType::DisplaySound;
	RootPannel->AddSlot().HAlign(HAlign_Center).VAlign(VAlign_Center).Position(DHelper::PositionConvert(FVector2D{0.f,55.f})).Size(FVector2D{1170.f,500.f})
	[
		SAssignNew(CurrentOption,SDisplaySoundWidget)
	];
	SetIconChoosed(EOptionIconType::DisplaySound);
}


FReply SOptionMenuWidget::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	//MouPos = MyGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
	return FReply::Handled();
}

void SOptionMenuWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{

	
}

void SOptionMenuWidget::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObjects(IconMaterialArr);
}

FText SOptionMenuWidget::GetTitleText() const
{
	return *TopTitleMap.Find(CurrentIcon);
}

FReply SOptionMenuWidget::OnLeftClicked()
{
	switch (CurrentIcon)
	{
		case EOptionIconType::Control:
			{
				OnSoundHovered();
				CurrentIcon = EOptionIconType::DisplaySound;
			}break;
		case EOptionIconType::DisplaySound:
			{
				OnSoundHovered();
				CurrentIcon = EOptionIconType::DisplaySound;
			}break;
		case EOptionIconType::Grahpic:
			{
				OnControlHovered();
				CurrentIcon = EOptionIconType::Control;
			}break;
		case EOptionIconType::Multiplayer:
			{
				OnGraphicHovered();
				CurrentIcon = EOptionIconType::Grahpic;
			}break;
	}
	return FReply::Handled();
}
FReply SOptionMenuWidget::OnRightClicked()
{
	switch (CurrentIcon)
	{
	case EOptionIconType::Control:
		{
			OnGraphicHovered();
			CurrentIcon = EOptionIconType::Grahpic;
		}
		break;
	case EOptionIconType::DisplaySound:
		{
			OnControlHovered();
			CurrentIcon = EOptionIconType::Control;
		}break;	
	case EOptionIconType::Grahpic:
		{
			OnMultiPlayerHovered();
			CurrentIcon = EOptionIconType::Multiplayer;
		}break;
	case EOptionIconType::Multiplayer:
		{
			OnMultiPlayerHovered();
			CurrentIcon = EOptionIconType::Multiplayer;
		}break;
	}
	return FReply::Handled();
}

void SOptionMenuWidget::OnControlHovered()
{
	SetIconChoosed(EOptionIconType::Control);
	if(CurrentOption.IsValid())
	{
		RootPannel->RemoveSlot(CurrentOption.ToSharedRef());
		CurrentOption.Reset();
	}
	RootPannel->AddSlot().HAlign(HAlign_Center).VAlign(VAlign_Center).Position(DHelper::PositionConvert(FVector2D{0.f,55.f})).Size(FVector2D{1170.f,500.f})
	[
		SAssignNew(CurrentOption,SControlWidget)
	];
}

void SOptionMenuWidget::OnSoundHovered()
{
	SetIconChoosed(EOptionIconType::DisplaySound);
	if(CurrentOption.IsValid())
	{
		RootPannel->RemoveSlot(CurrentOption.ToSharedRef());
		CurrentOption.Reset();
	}
	RootPannel->AddSlot().HAlign(HAlign_Center).VAlign(VAlign_Center).Position(DHelper::PositionConvert(FVector2D{0.f,55.f})).Size(FVector2D{1170.f,500.f})
	[
		SAssignNew(CurrentOption,SDisplaySoundWidget)
	];
}

void SOptionMenuWidget::OnGraphicHovered()
{
	SetIconChoosed(EOptionIconType::Grahpic);
	if(CurrentOption.IsValid())
	{
		RootPannel->RemoveSlot(CurrentOption.ToSharedRef());
		CurrentOption.Reset();
	}
	RootPannel->AddSlot().HAlign(HAlign_Center).VAlign(VAlign_Center).Position(DHelper::PositionConvert(FVector2D{0.f,55.f})).Size(FVector2D{1170.f,500.f})
	[
		SAssignNew(CurrentOption,SGrahpicWidget)
	];
}

void SOptionMenuWidget::OnMultiPlayerHovered()
{
	SetIconChoosed(EOptionIconType::Multiplayer);
	if(CurrentOption.IsValid())
	{
		RootPannel->RemoveSlot(CurrentOption.ToSharedRef());
		CurrentOption.Reset();
	}
	RootPannel->AddSlot().HAlign(HAlign_Center).VAlign(VAlign_Center).Position(DHelper::PositionConvert(FVector2D{0.f,55.f})).Size(FVector2D{1170.f,500.f})
	[
		SAssignNew(CurrentOption,SMultiPlayerWidget)
	];
}




END_SLATE_FUNCTION_BUILD_OPTIMIZATION
