// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavLinkGeneratorCommands.h"

#define LOCTEXT_NAMESPACE "FNavLinkGeneratorModule"

void FNavLinkGeneratorCommands::RegisterCommands()
{
	UI_COMMAND(SpawnLinksAction, "NavLinkGenerator", "Spawn Nav Links", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(DestroyLinksAction, "NavLinkGenerator", "Destroy Nav Links", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
