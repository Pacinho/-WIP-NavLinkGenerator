// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "NavLinkGeneratorStyle.h"

class FNavLinkGeneratorCommands : public TCommands<FNavLinkGeneratorCommands>
{
public:

	FNavLinkGeneratorCommands()
		: TCommands<FNavLinkGeneratorCommands>(TEXT("NavLinkGenerator"), NSLOCTEXT("Contexts", "NavLinkGenerator", "NavLinkGenerator Plugin"), NAME_None, FNavLinkGeneratorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > SpawnLinksAction;
	TSharedPtr< FUICommandInfo > DestroyLinksAction;
};
