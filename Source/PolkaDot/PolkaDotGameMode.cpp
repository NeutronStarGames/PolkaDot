// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "PolkaDotGameMode.h"
#include "PolkaDotHUD.h"
#include "PolkaDotCharacter.h"
#include "UObject/ConstructorHelpers.h"

APolkaDotGameMode::APolkaDotGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APolkaDotHUD::StaticClass();
}
