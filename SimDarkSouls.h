// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

//Logging for your AI system
DECLARE_LOG_CATEGORY_EXTERN(LogAI, Log, All);

class FSimDarkSoulsModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};