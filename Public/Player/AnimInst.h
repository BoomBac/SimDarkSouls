// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInst.generated.h"

/**
 * 
 */
UCLASS()
class SIMDARKSOULS_API UAnimInst : public UAnimInstance
{
	GENERATED_BODY()
public:
	UAnimInst();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	FTimerHandle CombatHandle;
	void Attack();
	void Roll(int Direction);
	void Dodge();
	void FORCEINLINE DisableCombat();
	bool bCanAttack;
	bool bCanRoll;
	UPROPERTY(BlueprintReadOnly)
	float WalkRight_Anim;
	UPROPERTY(BlueprintReadOnly)
	float WalkForward_Anim;
	UPROPERTY(BlueprintReadOnly)
	float FootAlpha_Anim;
	UPROPERTY(BlueprintReadOnly)
	bool bisLock_Anim;
	UPROPERTY(BlueprintReadOnly)
	bool bisRun_Anim;
	UPROPERTY(BlueprintReadOnly)
	bool bisFall_Anim;
	class APlayerCharacter* Character;

protected:	
	//初始化角色指针
	void InitCharacter();
	//更新蓝图数据
	void UpdateParameter();
	//
	bool bCanCombat;

protected:
	UAnimMontage* MontageAL1;
	UAnimMontage* MontageAL2;
	UAnimMontage* MontageAH1;
	UAnimMontage* MontageRF;
	UAnimMontage* MontageRB;
	UAnimMontage* MontageRL;
	UAnimMontage* MontageRR;
	UAnimMontage* MontageDodge;
	
};
