// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponSword_1.h"

#include "Components/BoxComponent.h"

AWeaponSword_1::AWeaponSword_1()
{
	ObjectIndex = 1;
	//给模型组件添加模型
    static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticBaseMesh(TEXT("StaticMesh'/Game/Characters/SnSAnimsetPro/Models/Sword/Sword.Sword'"));
    BaseMesh->SetStaticMesh(StaticBaseMesh.Object);

    //设置碰撞体属性
    AffectCollision->SetRelativeLocation(FVector(0.f, 40.f, 0.f));
    AffectCollision->SetRelativeScale3D(FVector(0.125f, 2.f, 0.125f));
}
