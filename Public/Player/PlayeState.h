// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlayeState.generated.h"

/**
 * 
 */
DECLARE_DELEGATE_FourParams(FOnLimitChanged,float,float,float,float)
DECLARE_DELEGATE(FUpdateHPMaterial)

USTRUCT(BlueprintType)
struct FRawAttribute
{
	GENERATED_BODY()
	float limit;
	float max;
	float min;
	float currnt;
	float RecoverSpeed;
};

USTRUCT(BlueprintType)
struct FStateInfo
{
	GENERATED_BODY()
	FStateInfo();
	//生命，魔法，体力
	FRawAttribute hp;
	FRawAttribute mp;
	FRawAttribute pp;
	//韧性
	int Tough;
	//经验
	int Exp;
};



UCLASS()
class SIMDARKSOULS_API APlayeState : public APlayerState
{
	GENERATED_BODY()
public:
	APlayeState();
	FStateInfo& GetStateInfo();
	void SetStateInfo(FStateInfo NewValue);
	//委托用于设置defalutinfo
	FOnLimitChanged OnLimitChanged;
	FUpdateHPMaterial UpdateHPMaterial;
private:
	FStateInfo StateInfo;
};
