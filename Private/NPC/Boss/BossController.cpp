// Fill out your copyright notice in the Description page of Project Settings.


#include "BossController.h"

#include "BossCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

ABossController::ABossController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABossController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	BossCharacter = Cast<ABossCharacter>(InPawn);
	//从蓝图加载行为树
	UBehaviorTree* BehaviorTree = LoadObject<UBehaviorTree>(nullptr,TEXT("BehaviorTree'/Game/BluePrint/AI/Boss/BT_Boss.BT_Boss'"));
	bool bSuccess = true;

	// 创建黑板组件，并将给定的黑板数据和黑板组件链接，就是创建对应黑板组件，并将类内指针指向该组件
	UBlackboardComponent* BlackboardComp = Blackboard;
	if (BehaviorTree->BlackboardAsset && (Blackboard == nullptr || Blackboard->IsCompatibleWith(BehaviorTree->BlackboardAsset) == false))
	{
		bSuccess = UseBlackboard(BehaviorTree->BlackboardAsset, BlackboardComp);
	}
	//创建行为树组件，来控制行为树的运行
	if (bSuccess)
	{
		
		UBehaviorTreeComponent* BTComp = Cast<UBehaviorTreeComponent>(BrainComponent);
		if (BTComp == NULL)
		{
			BTComp = NewObject<UBehaviorTreeComponent>(this, TEXT("BTComponent"));
			//真正赋值阶段，将以上创建的一些值赋值给 BTComp
			BTComp->RegisterComponent();
		}
		
		// make sure BrainComponent points at the newly created BT component
		BrainComponent = BTComp;

		check(BTComp != NULL);
		BTComp->StartTree(*BehaviorTree, EBTExecutionMode::Looped);
	}
}

void ABossController::OnUnPossess()
{
	Cast<UBehaviorTreeComponent>(BrainComponent)->StopTree();
}
