// Fill out your copyright notice in the Description page of Project Settings.


#include "Style.h"



#include "GameWidgetStyle.h"
#include "MenuWidgetStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"

TSharedPtr<FSlateStyleSet> Style::StyleInstance = nullptr;
TSharedPtr<FMenuStyle> Style::MenuStyle = nullptr;
TSharedPtr<FGameStyle> Style::GameStyle = nullptr;

void Style::Initialize()
{
	if(!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
	MenuStyle = MakeShared<FMenuStyle>(Style::Get().GetWidgetStyle<FMenuStyle>("BP_MenuStyle"));
	GameStyle = MakeShared<FGameStyle>(Style::Get().GetWidgetStyle<FGameStyle>("BP_GameStyle"));
}

FName Style::GetStyleSetName()
{
	static FName slateSetName(TEXT("Style"));
	return slateSetName;
}

void Style::ShutDown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

const ISlateStyle& Style::Get()
{
	return *StyleInstance;
}

const FMenuStyle* Style::GetMenuStyle()
{
	return MenuStyle.Get();
}

const FGameStyle* Style::GetGameStyle()
{
	return GameStyle.Get();
}

TSharedRef<FSlateStyleSet> Style::Create()
{
	TSharedRef<FSlateStyleSet> styleRef = FSlateGameResources::New(Style::GetStyleSetName(),"/Game/UI/Style","/Game/UI/Style");
	return styleRef;
}

