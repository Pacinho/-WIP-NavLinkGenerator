// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;
class ARecastNavMesh;
class ACustomNavLinkProxy;
class UGenSettings;

class FNavLinkGeneratorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** This function will be bound to Command. */
	void SpawnLinksButtonClicked();

	void DestroyLinksButtonClicked();

private:

	const UGenSettings* GenSettings;

	bool bIsGenerated;
	TArray<ACustomNavLinkProxy*> NavLinks;

	void PlaceNavLinks();

	void RegisterMenus();

	bool IsTileValid(const ARecastNavMesh* NavMesh, int32 TileIndex) const;

	void GetMiddlePoints(const ARecastNavMesh* NavMesh, NavNodeRef Poly, TArray<FVector>& OutMiddlePoints, FVector& PolyCenter, double& MaxDistance);

private:
	TSharedPtr<class FUICommandList> SpawnLinks;

	TSharedPtr<class FUICommandList> DestroyLinks;
};
