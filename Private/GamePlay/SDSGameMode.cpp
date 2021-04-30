// Fill out your copyright notice in the Description page of Project Settings.


#include "SDSGameMode.h"

#include "GameHUD.h"
#include "PlayController.h"
#include "PlayerCharacter.h"
#include "PlayeState.h"

ASDSGameMode::ASDSGameMode()
{
	HUDClass = AGameHUD::StaticClass();
	PlayerControllerClass = APlayController::StaticClass();
	PlayerStateClass = APlayeState::StaticClass();
	DefaultPawnClass = APlayerCharacter::StaticClass();
}
