// Fill out your copyright notice in the Description page of Project Settings.


#include "NavLinkDestroyButton.h"
#include "NavLinkGenerator.h"
#include "Framework/Application/SlateApplication.h"
#include "Styling/SlateStyleRegistry.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FNavLinkDestroyButton::DestroyInstance = nullptr;

void FNavLinkDestroyButton::Initialize()
{
	if (!DestroyInstance.IsValid())
	{
		DestroyInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*DestroyInstance);
	}
}

void FNavLinkDestroyButton::Shutdown()
{

	FSlateStyleRegistry::UnRegisterSlateStyle(*DestroyInstance);
	ensure(DestroyInstance.IsUnique());
	DestroyInstance.Reset();
}

FName FNavLinkDestroyButton::GetStyleSetName()
{
	static FName StyleSetName(TEXT("NavLinkDestroyButton"));
	return StyleSetName;
}

const FVector2D Icon(40.0f, 40.0f);

TSharedRef< FSlateStyleSet > FNavLinkDestroyButton::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("NavLinkDestroyButton"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("NavLinkGenerator")->GetBaseDir() / TEXT("Resources"));

	Style->Set("NavLinkGenerator.DestroyLinksAction", new IMAGE_BRUSH_SVG(TEXT("PlaceholderButtonIcon"), Icon));
	return Style;
}

void FNavLinkDestroyButton::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FNavLinkDestroyButton::Get()
{
	return *DestroyInstance;
}