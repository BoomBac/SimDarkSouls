// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Types.h"


/**
 * 
 */
class SIMDARKSOULS_API International
{
public:
	International();
	void SetCulture(ECultureType::Type NewCulture);
	ECultureType::Type GetCulture();
	FName GetCultureAsFname();
	void ShutDown();
private:
	ECultureType::Type CurrenCulture;
};
