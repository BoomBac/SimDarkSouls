// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponObject.generated.h"

UCLASS()
class SIMDARKSOULS_API AWeaponObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponObject();
	void SetCollisionEnable(bool enable);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//根据物品ID返回物品的工厂方法
	static TSubclassOf<AActor> SpawnHandWeapon(int ObjectID);

public:

//物品ID
int ObjectIndex;
	
UFUNCTION()
	virtual void OnOverlayBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

UFUNCTION()
	virtual void OnOverlayEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


protected:
	//根组件
	class USceneComponent* RootScene;

	//静态模型
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* BaseMesh;

	//盒子碰撞体
	UPROPERTY(EditAnywhere)
	class UBoxComponent* AffectCollision;

};
