// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SamraiMiniGamejamGameMode.h"
#include "SamraiMiniGamejamHUD.h"
#include "SamraiMiniGamejamCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASamraiMiniGamejamGameMode::ASamraiMiniGamejamGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASamraiMiniGamejamHUD::StaticClass();
}
