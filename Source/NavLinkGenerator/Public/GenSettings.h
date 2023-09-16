// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GenSettings.generated.h"

class ACustomNavLinkProxy;

/**
 *
 */
UCLASS(config = Engine, defaultconfig, meta = (DisplayName = "Nav Link Generator"))
class NAVLINKGENERATOR_API UGenSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UGenSettings();

	// Enables experimental *incomplete and unsupported* texture atlas groups that sprites can be assigned to
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "NavLink", AdvancedDisplay)
		TSubclassOf<ACustomNavLinkProxy> LinkClass;
};
