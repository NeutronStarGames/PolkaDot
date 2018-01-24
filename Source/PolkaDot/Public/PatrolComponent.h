// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolComponent.generated.h"

/**
*A route Map to help choose AI the next waypoint
*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class POLKADOT_API UPatrolComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrolComponent();

	TArray<AActor*> GetPatrollingPoints() const;

protected:
	UPROPERTY(EditInstanceOnly, Category = "NSPatrolPoints")
		TArray<AActor*> PatrollingPoints;





	
};
