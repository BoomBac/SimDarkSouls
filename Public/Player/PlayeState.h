// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlayeState.generated.h"

/**
 * 
 */
DECLARE_DELEGATE_FourParams(FOnLimitChanged,float,float,float,float)
DECLARE_DELEGATE_OneParam(FUpdateHPMaterial,float)
DECLARE_DELEGATE_OneParam(FUpdateMPMaterial,float)
DECLARE_DELEGATE_OneParam(FUpdatePPMaterial,float)

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
	void SetStateInfo();
	//委托用于设置defalutinfo
	FOnLimitChanged OnLimitChanged;
	//一下三个只有数值剧烈变化时才需要执行
	FUpdateHPMaterial UpdateHPMaterial;
	FUpdateMPMaterial UpdateMPMaterial;
	FUpdatePPMaterial UpdatePPMaterial;
private:
	FStateInfo StateInfo;

};
