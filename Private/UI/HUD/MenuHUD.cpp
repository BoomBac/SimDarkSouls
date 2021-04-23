// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"

#include "Kismet/GameplayStatics.h"
#include "UI/Widget/SMenuHUDWidget.h"
#include "Widgets/SWeakWidget.h"

AMenuHUD::AMenuHUD()
{
	if(GEngine&&GEngine->GameViewport)
	{
		SAssignNew(MenuHUDWidget,SMenuHUDWidget);
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MenuHUDWidget.ToSharedRef()));
		// if (FString("GameMap") == UGameplayStatics::GetCurrentLevelName(GWorld))
		// {
		// 	GEngine->GameViewport->RemoveAllViewportWidgets();
		// }
	}
}
