// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "AttackDetect.h"
#include "GameFramework/Character.h"
#include"Engine/Datatable.h"
#include "BossCharacter.generated.h"


class UAttackComponent;
UCLASS()
class SIMDARKSOULS_API ABossCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABossCharacter();
	//设置角色旋转朝向玩家
	void UpdateRotation(float deltasecond);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
//Data
public:
	//动画蓝图
	float Forward;
	float Right;
	float Phycics;

	//当前攻击信息
	FAttackInfo CurrentAttack;
	bool bCanSetRotation;
	bool bCanAttack;
	UPROPERTY()
	UAttackComponent* AttackComponent;
	UFUNCTION()
	void OnHitted(FAttackInfo AttackInfo);
	
private:
	//存储攻击信息数据表
	UPROPERTY()
	UDataTable* DTAttackInfo;
	//


	//目标玩家
	UPROPERTY()
	class APlayerCharacter* TargetPlayer;

//func
public:
	//供行为树调用
	void Attack(float Distance);
};
