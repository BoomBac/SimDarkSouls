// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuController.h"

AMenuController::AMenuController()
{
	bShowMouseCursor = true;
}

void AMenuController::BeginPlay()
{
	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	SetInputMode(InputMode);
}
