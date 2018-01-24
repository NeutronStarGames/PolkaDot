// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "GameFramework/Actor.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "PatrolComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
		
	UBlackboardComponent* MyBlackboard = OwnerComp.GetBlackboardComponent();		//Get Attached Blackboard
	if (!ensure(MyBlackboard)) { return EBTNodeResult::Failed; }
	
	FName KeyName = IndexKey.SelectedKeyName;	//See what is chosen on the BlackBoard, assume that it's an Index Variable
	int32 BlackBoardIndex = MyBlackboard->GetValueAsInt(KeyName);
	
	//Get the Patrol points from a Character
	auto MyGuard = OwnerComp.GetAIOwner()->GetPawn();
	if (!ensure(MyGuard)) { return EBTNodeResult::Failed; }

	UPatrolComponent* MyPatrolComponent = MyGuard->FindComponentByClass<UPatrolComponent>();
	if (!ensure(MyPatrolComponent)) { return EBTNodeResult::Failed; }

	TArray<AActor*> GuardPoints = MyPatrolComponent->GetPatrollingPoints();
	if (!ensure(GuardPoints.Num()>0)) { return EBTNodeResult::Failed; }
		
	// Set to the Blackboard NextPoint for current index
	auto NextPoint = GuardPoints[BlackBoardIndex];
	MyBlackboard->SetValueAsObject(WaypointKey.SelectedKeyName, (UObject* )NextPoint);
	
	//Move to next index
	auto ArrayNumber = GuardPoints.Num();
	int32 NextIndex = (BlackBoardIndex + 1) % ArrayNumber;
	MyBlackboard->SetValueAsInt(FName("Index"), NextIndex);

	
	return EBTNodeResult::Succeeded;
}
