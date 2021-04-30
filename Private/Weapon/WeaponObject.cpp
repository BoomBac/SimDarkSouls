// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponObject.h"

#include "WeaponShield_1.h"
#include "WeaponSword_1.h"
#include "Components/BoxComponent.h"

// Sets default values
AWeaponObject::AWeaponObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("RootScene"));
	RootComponent = RootScene;

	//创建静态模型组件
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(RootComponent);
	BaseMesh->SetCollisionProfileName(FName("NoCollision"));

	//实现碰撞组件
	AffectCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("AffectCollision"));
	AffectCollision->SetupAttachment(RootComponent);
	AffectCollision->SetCollisionProfileName(FName("EquipmentProfile"));

	//初始时关闭Overlay检测
	AffectCollision->SetGenerateOverlapEvents(false);

	//绑定检测方法到碰撞体
	FScriptDelegate OverlayBegin;
	OverlayBegin.BindUFunction(this, "OnOverlayBegin");
	AffectCollision->OnComponentBeginOverlap.Add(OverlayBegin);

	FScriptDelegate OverlayEnd;
	OverlayEnd.BindUFunction(this, "OnOverlayEnd");
	AffectCollision->OnComponentEndOverlap.Add(OverlayEnd);

}

void AWeaponObject::SetCollisionEnable(bool enable)
{
	AffectCollision->SetGenerateOverlapEvents(enable);
}

// Called when the game starts or when spawned
void AWeaponObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TSubclassOf<AActor> AWeaponObject::SpawnHandWeapon(int ObjectID)
{
	switch (ObjectID)
	{
		case 1:
			return AWeaponSword_1::StaticClass();
		case 2:
			return AWeaponShield_1::StaticClass();
	}
	return AWeaponSword_1::StaticClass();
}

void AWeaponObject::OnOverlayBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void AWeaponObject::OnOverlayEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

