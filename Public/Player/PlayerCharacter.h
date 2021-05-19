// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AttackDetect.h"
#include "PlayeState.h"
#include "Types.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class UAnimInst;
UCLASS()
class SIMDARKSOULS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	//接受轴输入变量
	void GetMoveForward(float value);
	void GetMoveRight(float value);
	void Turn(float Value);
	void LookUp(float Value);
	void Run();
	void unRun();
	void ViewLock();
	void Attack();
	void Roll();
	void CalculateAnimData();
private:
	//gamelay value
	class APlayController* DSPlayerController;
	APlayeState* DSPlayerState;
	UPROPERTY()
	UAnimInst* Animation;
	FAttackInfo CurrentInfo;
public:
	UPROPERTY(VisibleDefaultsOnly)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleDefaultsOnly)
	class UCameraComponent* Camera;
	UPROPERTY(VisibleDefaultsOnly)
	UChildActorComponent* RighetHandIbject;
	UPROPERTY(VisibleDefaultsOnly)
	UChildActorComponent* LeftHandObject;
	UPROPERTY(VisibleDefaultsOnly)
	class UAttackComponent* AttackComponent;
	UFUNCTION()
	void OnHitted(FAttackInfo AttackInfo);
	
	EPlayerState::Type PlayerCombatState;

	//用于动画的变量
	float MoveForward;
	float MoveRight;
	bool bIsViewLocked;
	bool bIsRun;
	bool bIsFalling;
	FRotator MoveRotation;
	FVector MoveDirection;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	void ReducePP(float ReduceRate);
	UFUNCTION()
	void RecoverPP();
private:
	FTimerHandle Runhandle;
	//耐力恢复定时器
	FTimerHandle PPRecoverHandle;
	bool bRecoverHandleSet;
};

