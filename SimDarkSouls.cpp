// Copyright Epic Games, Inc. All Rights Reserved.

#include "SimDarkSouls.h"

#include "Style.h"
#include "Modules/ModuleManager.h"
#include "Styling/SlateStyleRegistry.h"



void FSimDarkSoulsModule::StartupModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(Style::GetStyleSetName());
	Style::Initialize();
}

void FSimDarkSoulsModule::ShutdownModule()
{
	Style::ShutDown();
}
//此处参一为.h中的模块类
IMPLEMENT_PRIMARY_GAME_MODULE(FSimDarkSoulsModule, SimDarkSouls, "SimDarkSouls");