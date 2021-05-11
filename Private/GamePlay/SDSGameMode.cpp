// Fill out your copyright notice in the Description page of Project Settings.


#include "SDSGameMode.h"

#include "GameHUD.h"
#include "PlayController.h"
#include "PlayerCharacter.h"
#include "PlayeState.h"
#include "Kismet/GameplayStatics.h"

ASDSGameMode::ASDSGameMode()
{
	HUDClass = AGameHUD::StaticClass();
	PlayerControllerClass = APlayController::StaticClass();
	PlayerStateClass = APlayeState::StaticClass();
	DefaultPawnClass = APlayerCharacter::StaticClass();
}

void ASDSGameMode::BeginPlay()
{
	Super::BeginPlay();
	if(!SPController) InitialPlayer();
}

void ASDSGameMode::InitialPlayer()
{
	SPController = Cast<APlayController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	SPCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	SPState = Cast<APlayeState>(SPController->PlayerState);
}
