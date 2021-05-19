// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttackDetect.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"



DECLARE_DELEGATE_OneParam(FOnHitted,FAttackInfo);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SIMDARKSOULS_API UAttackComponent : public UActorComponent,public IAttackDetect
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttackComponent();
	void SetDetectenable(bool value);
	void AttackDetect(USkeletalMeshComponent* Mesh, FName TraceStart, FName TraceEnd, ETraceTypeQuery TarceChannel, FAttackInfo
	                  CurrentAttack);
public:
	FOnHitted OnHitted;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void OnAttackDetected(AActor* CauseBy, FAttackInfo AttackInfo) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

//data
public:
	bool bDetectenable;	
};
