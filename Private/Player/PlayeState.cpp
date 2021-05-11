// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayeState.h"

FStateInfo::FStateInfo()
{
	hp={2000.f,500.f,50.f,250.f};
	mp={2000.f,500.f,50.f,100.f};
	pp={2000.f,500.f,50.f,150.f};
	Tough = 100;
	Exp = 100;
}

APlayeState::APlayeState()
{
	
}

FStateInfo& APlayeState::GetStateInfo()
{
	//test
	return StateInfo;
}

void APlayeState::SetStateInfo(FStateInfo NewValue)
{
}
