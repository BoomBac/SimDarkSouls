// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayController.h"

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
}
