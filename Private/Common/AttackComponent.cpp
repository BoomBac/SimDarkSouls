// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackComponent.h"

#include "AttackDetect.h"
#include "DevelopTool.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UAttackComponent::UAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bDetectenable =false;
	// ...
}

void UAttackComponent::SetDetectenable(bool value)
{
	bDetectenable = value;
}

void UAttackComponent::AttackDetect(USkeletalMeshComponent* Mesh, FName TraceStart, FName TraceEnd,
                                    ETraceTypeQuery TarceChannel, FAttackInfo CurrentAttack)
{
	if(!bDetectenable) return;
	FHitResult Result;
	TArray<AActor*>ActorsToIgnore;
	ActorsToIgnore.Add(GetOwner());
	if (UKismetSystemLibrary::LineTraceSingle(GetWorld(),Mesh->GetSocketLocation(TraceStart),Mesh->GetSocketLocation(TraceEnd),TarceChannel,
false,ActorsToIgnore,EDrawDebugTrace::Persistent,Result,true))
	{
		if(Result.Actor.IsValid())
		{
			if(Result.Actor->GetComponentsByInterface(UAttackDetect::StaticClass()).Num()!=0)
			{
				UActorComponent* Target = Result.Actor->GetComponentsByInterface(UAttackDetect::StaticClass())[0];
				if(Target->GetClass()->ImplementsInterface(UAttackDetect::StaticClass()))
				{
					IAttackDetect* Interface = Cast<IAttackDetect>(Target);
					Interface->OnAttackDetected(GetOwner(),CurrentAttack);
					bDetectenable = false;
				}	
			}
		}
	}
}


// Called when the game starts
void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAttackComponent::OnAttackDetected(AActor* CauseBy, FAttackInfo AttackInfo)
{
	DHelper::Debug(CauseBy->GetName());
	OnHitted.ExecuteIfBound(AttackInfo);
}


// Called every frame
void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


