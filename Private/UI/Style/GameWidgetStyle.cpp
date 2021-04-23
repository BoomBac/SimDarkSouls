// Fill out your copyright notice in the Description page of Project Settings.


#include "GameWidgetStyle.h"

FGameStyle::FGameStyle()
{
}

FGameStyle::~FGameStyle()
{
}

const FName FGameStyle::TypeName(TEXT("FGameStyle"));

const FGameStyle& FGameStyle::GetDefault()
{
	static FGameStyle Default;
	return Default;
}

void FGameStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

