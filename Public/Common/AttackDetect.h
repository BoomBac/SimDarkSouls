// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/Datatable.h"
#include "UObject/Interface.h"
#include "AttackDetect.generated.h"

// This class does not need to be modified.
UENUM()
enum EHittype
{
	Low,
	Mid,
	High
};


USTRUCT()
struct FAttackInfo : public  FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Table")
	UAnimMontage* AttackMontage;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Table")
	float Phycics;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Table")
	float PhycicsDecrease;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Table")
	float Damage;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Table")
	bool bCanBlock;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Table")
	TEnumAsByte<EHittype> HitType;	
};


UINTERFACE(MinimalAPI)
class UAttackDetect : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SIMDARKSOULS_API IAttackDetect
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void OnAttackDetected(AActor* CauseBy, FAttackInfo AttackInfo);
};
