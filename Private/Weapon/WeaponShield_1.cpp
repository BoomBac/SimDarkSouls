// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponShield_1.h"

AWeaponShield_1::AWeaponShield_1()
{
	ObjectIndex = 2;
	//给模型组件添加模型
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticBaseMesh(TEXT("StaticMesh'/Game/Characters/SnSAnimsetPro/Models/Shield/Shield.Shield'"));
	BaseMesh->SetStaticMesh(StaticBaseMesh.Object);
}
