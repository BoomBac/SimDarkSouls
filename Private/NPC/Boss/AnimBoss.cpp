// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimBoss.h"

#include "BossCharacter.h"

void UAnimBoss::NativeUpdateAnimation(float DeltaSeconds)
{
	InitCharacter();
	UpdateParm();
}
void UAnimBoss::InitCharacter()
{
	if(!Character)
		Character = Cast<ABossCharacter>(TryGetPawnOwner());
}

void UAnimBoss::UpdateParm()
{
	if(!Character) return;
	Forward = Character->Forward;
	Right = Character->Right;
}
