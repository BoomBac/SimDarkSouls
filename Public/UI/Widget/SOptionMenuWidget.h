// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Types.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SIMDARKSOULS_API SOptionMenuWidget : public SCompoundWidget,public  FGCObject
{
public:
	SLATE_BEGIN_ARGS(SOptionMenuWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	TSharedPtr<class SCanvas> RootPannel;
	FVector2D MouPos;
	//顶部选项卡组
	TSharedPtr<SWidget> CurrentOption;
	TSharedPtr<SButton> Left;
	TSharedPtr<STextBlock> TopTitle;
	FText GetTitleText() const;
	FReply OnLeftClicked();
	TSharedPtr<SButton> Controller;
	void OnControlHovered();
	TSharedPtr<SButton> Sound;
	void OnSoundHovered();
	TSharedPtr<SButton> Graphic;
	void OnGraphicHovered();
	TSharedPtr<SButton> MultiPlayer;
	void OnMultiPlayerHovered();
	TSharedPtr<SButton> Right;
	FReply OnRightClicked();
	//顶部选项材质.贴图.样式
	UMaterialInterface* OptionIconMatInst;
	UMaterialInstanceDynamic* ControlDynamic;
	UMaterialInstanceDynamic* SoundDynamic;
	UMaterialInstanceDynamic* GraphicDynamic;
	UMaterialInstanceDynamic* MultiplayerDynamic;
	UTexture2D* TexControl;
	UTexture2D* TexSound;
	UTexture2D* TexMultiPlayer;
	UTexture2D* TexGraphic;
	TSharedPtr<FButtonStyle> ControlStyle;
	TSharedPtr<FButtonStyle> SoundStyle;
	TSharedPtr<FButtonStyle> GrahpicStyle;
	TSharedPtr<FButtonStyle> MultiPlayerStyle;
	//当前选中选项
	EOptionIconType::Type CurrentIcon;
	//mapgroup
	TMap<EOptionIconType::Type,UMaterialInstanceDynamic*> IconMaterialMap;
	TMap<EOptionIconType::Type,TSharedPtr<SButton>> IconButtonMap;
	TMap<EOptionIconType::Type,FText> TopTitleMap;
	//Tarray 用于防止材质实例被gc
	UPROPERTY()
	TArray<UMaterialInstanceDynamic*> IconMaterialArr;
	void SetIconChoosed(EOptionIconType::Type Button);
	void InitializeIconStyle();
	void InitializeIconMap();
	//覆写
	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
};
