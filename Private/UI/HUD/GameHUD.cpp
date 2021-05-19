// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"

#include "PlayeState.h"
#include "SDSGameMode.h"
#include "SGameDefaultWidget.h"
#include "SGameHUDWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/SWeakWidget.h"

AGameHUD::AGameHUD()
{
	if(GEngine&&GEngine->GameViewport)
    {
    	SAssignNew(GameHUDWidget,SGameHUDWidget);
    	GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(GameHUDWidget.ToSharedRef()));
    }

}

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();
	GM = Cast<ASDSGameMode>(UGameplayStatics::GetGameMode(GWorld));
	if(GM)
	{
		GM->SPState->OnLimitChanged.BindRaw(GameHUDWidget->DefaultHud.Get(),&SGameDefaultWidget::SetBarLength);
		GM->SPState->UpdateHPMaterial.BindRaw(GameHUDWidget->DefaultHud.Get(),&SGameDefaultWidget::UpdateHPMaterial);
		GM->SPState->UpdateMPMaterial.BindRaw(GameHUDWidget->DefaultHud.Get(),&SGameDefaultWidget::UpdateMPMaterial);
		GM->SPState->UpdatePPMaterial.BindRaw(GameHUDWidget->DefaultHud.Get(),&SGameDefaultWidget::UpdatePPMaterial);
	}
}
