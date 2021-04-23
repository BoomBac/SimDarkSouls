// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidgetStyle.h"

FMenuStyle::FMenuStyle()
{
}

FMenuStyle::~FMenuStyle()
{
}

const FName FMenuStyle::TypeName(TEXT("FMenuStyle"));

const FMenuStyle& FMenuStyle::GetDefault()
{
	static FMenuStyle Default;
	return Default;
}

void FMenuStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	// Add any brush resources here so that Slate can correctly atlas and reference them
}

