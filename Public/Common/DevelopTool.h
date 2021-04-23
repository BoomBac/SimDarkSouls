// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
namespace DHelper
{
	//template<class ValueType>
	FORCEINLINE FVector2D PositionConvert(FVector2D pos)
	{
	  return FVector2D{pos.X+960.f,pos.Y+540.f};
	}
	FORCEINLINE void Debug(FString Message ,float Duration = 2.f,FColor color = FColor::Cyan)
	{
		if(GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1,Duration,color,Message);
		}
	}
}
