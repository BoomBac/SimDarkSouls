// Copyright Epic Games, Inc. All Rights Reserved.

#include "SimDarkSouls.h"

#include "International.h"
#include "Singleton.h"
#include "Style.h"
#include "Internationalization/StringTableRegistry.h"
#include "Modules/ModuleManager.h"
#include "Styling/SlateStyleRegistry.h"

DEFINE_LOG_CATEGORY(LogAI);

void FSimDarkSoulsModule::StartupModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(Style::GetStyleSetName());
	Style::Initialize();
	Singleton<International>::Initialize();
}

void FSimDarkSoulsModule::ShutdownModule()
{
	Style::ShutDown();
	Singleton<International>::Get()->ShutDown();
}
//此处参一为.h中的模块类
IMPLEMENT_PRIMARY_GAME_MODULE(FSimDarkSoulsModule, SimDarkSouls, "SimDarkSouls");