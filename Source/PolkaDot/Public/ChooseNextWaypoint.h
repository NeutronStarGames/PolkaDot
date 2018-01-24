// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class POLKADOT_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:
	
	UPROPERTY(EditAnywhere, Category = "NS Blackboard")
	struct FBlackboardKeySelector IndexKey;		//Draw KeySelector in the Editor

	UPROPERTY(EditAnywhere, Category = "NS Blackboard")
	struct FBlackboardKeySelector WaypointKey;		//Draw KeySelector in the Editor

};
