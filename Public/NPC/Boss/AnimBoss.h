// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimBoss.generated.h"

/**
 * 
 */
UCLASS()
class SIMDARKSOULS_API UAnimBoss : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
//data
public:	
	UPROPERTY(BlueprintReadOnly)
	float Forward;
	UPROPERTY(BlueprintReadOnly)
	float Right;
	class ABossCharacter* Character;
private:
	void InitCharacter();
	void UpdateParm();
};
