// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavLinkGeneratorStyle.h"
#include "NavLinkGenerator.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FNavLinkGeneratorStyle::SpawnInstance = nullptr;


void FNavLinkGeneratorStyle::Initialize()
{
	if (!SpawnInstance.IsValid())
	{
		SpawnInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*SpawnInstance);
	}
}

void FNavLinkGeneratorStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*SpawnInstance);
	ensure(SpawnInstance.IsUnique());
	SpawnInstance.Reset();
}

FName FNavLinkGeneratorStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("NavLinkGeneratorStyle"));
	return StyleSetName;
}


const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);

TSharedRef< FSlateStyleSet > FNavLinkGeneratorStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("NavLinkGeneratorStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("NavLinkGenerator")->GetBaseDir() / TEXT("Resources"));

	Style->Set("NavLinkGenerator.SpawnLinksAction", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon20x20));
	return Style;
}

void FNavLinkGeneratorStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FNavLinkGeneratorStyle::Get()
{
	return *SpawnInstance;
}
