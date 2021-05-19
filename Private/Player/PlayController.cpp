// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayController.h"

#include "DevelopTool.h"
#include "PlayeState.h"
#include "GameFramework/PlayerInput.h"


APlayController::APlayController()
{
	
}

void APlayController::BeginPlay()
{
	Super::BeginPlay();
	//设置鼠标不显示
	bShowMouseCursor = false;
	//设置输入模式
	FInputModeGameOnly InputMode;
	InputMode.SetConsumeCaptureMouseDown(true);
	SetInputMode(InputMode);
	if(!SPState)
		SPState = Cast<APlayeState>(PlayerState);
}

void APlayController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//FInputActionKeyMapping HPUP("HPUP", EKeys::Up, 0, 0, 0, 0);
	InputComponent->BindAction("HPUP",IE_Pressed,this,&APlayController::AddHP);
	//FInputActionKeyMapping HPdown("HPdown", EKeys::Down, 0, 0, 0, 0);
	InputComponent->BindAction("HPdown",IE_Pressed,this,&APlayController::SubHP);
}

void APlayController::AddHP()
{
	SPState->UpdateHPMaterial.ExecuteIfBound(2.f);
	SPState->GetStateInfo().hp.currnt+=250.f;
}

void APlayController::SubHP()
{
	SPState->UpdateHPMaterial.ExecuteIfBound(2.f);
	SPState->GetStateInfo().hp.currnt-=250.f;
}
