// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PlayeState.h"
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
protected:
	//gamelay value
	class APlayController* DSPlayerController;
	APlayeState* DSPlayerState;
	UPROPERTY()
	UAnimInst* Animation;
	
public:
	UPROPERTY(VisibleDefaultsOnly)
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleDefaultsOnly)
	class UCameraComponent* Camera;
	UPROPERTY(VisibleDefaultsOnly)
	UChildActorComponent* RighetHandIbject;
	UPROPERTY(VisibleDefaultsOnly)
	UChildActorComponent* LeftHandObject;

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

};
