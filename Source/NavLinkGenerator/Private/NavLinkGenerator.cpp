// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavLinkGenerator.h"
#include "NavLinkGeneratorStyle.h"
#include "NavLinkDestroyButton.h"
#include "NavLinkGeneratorCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

#include "NavLinkCustomComponent.h"
#include "CustomNavLinkProxy.h"
#include "Kismet/GameplayStatics.h"

#include "NavigationSystem.h"
#include "NavMesh/RecastNavMesh.h"

#include "GenSettings.h"
#include "ISettingsModule.h"

#if WITH_RECAST
#include "Detour/DetourNavMesh.h"
#include "NavMesh/RecastHelpers.h"
#endif

static const FName NavLinkGeneratorTabName("NavLinkGenerator");

#define LOCTEXT_NAMESPACE "FNavLinkGeneratorModule"

void FNavLinkGeneratorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	GenSettings = GetDefault<UGenSettings>();

	FNavLinkGeneratorStyle::Initialize();
	FNavLinkGeneratorStyle::ReloadTextures();

	FNavLinkDestroyButton::Initialize();
	FNavLinkDestroyButton::ReloadTextures();

	FNavLinkGeneratorCommands::Register();

	SpawnLinks = MakeShareable(new FUICommandList);

	SpawnLinks->MapAction(
		FNavLinkGeneratorCommands::Get().SpawnLinksAction,
		FExecuteAction::CreateRaw(this, &FNavLinkGeneratorModule::SpawnLinksButtonClicked),
		FCanExecuteAction());

	DestroyLinks = MakeShareable(new FUICommandList);

	DestroyLinks->MapAction(
		FNavLinkGeneratorCommands::Get().DestroyLinksAction,
		FExecuteAction::CreateRaw(this, &FNavLinkGeneratorModule::DestroyLinksButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FNavLinkGeneratorModule::RegisterMenus));
}

void FNavLinkGeneratorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FNavLinkGeneratorStyle::Shutdown();

	FNavLinkDestroyButton::Shutdown();

	FNavLinkGeneratorCommands::Unregister();
}

void FNavLinkGeneratorModule::SpawnLinksButtonClicked()
{
	// Put your "OnButtonClicked" stuff here

	PlaceNavLinks();
}

void FNavLinkGeneratorModule::DestroyLinksButtonClicked()
{
	/*TArray<AActor*> Links;
	UGameplayStatics::GetAllActorsOfClass(GEditor->GetEditorWorldContext().World(), ACustomNavLinkProxy::StaticClass(), Links);
	for (auto Link : Links)
	{
		Link->Destroy();
	}
	Links.Empty();*/

	for (auto Link : NavLinks)
	{
		Link->Destroy();
	}
	NavLinks.Empty();
	bIsGenerated = false;
}

void FNavLinkGeneratorModule::PlaceNavLinks()
{
	if (!bIsGenerated)
	{
		UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GEditor->GetEditorWorldContext().World());

		ARecastNavMesh* RecastNavMesh = Cast<ARecastNavMesh>(NavSys->GetMainNavData());

		int32 TileCount = RecastNavMesh->GetNavMeshTilesCount();
		TArray<int32> TileIndexes;
		for (int32 i = 0; i < TileCount; ++i)
		{
			if (IsTileValid(RecastNavMesh, i))
			{
				int32 X, Y, OutLayer;
				RecastNavMesh->GetNavMeshTileXY(i, X, Y, OutLayer);
				if (OutLayer > 0)
				{
					FBox Box1 = RecastNavMesh->GetNavMeshTileBounds(i);
					const dtNavMesh* NavMesh = RecastNavMesh->GetRecastMesh();
					//FBox Box2 = RecastNavMesh->GetNavMeshTileXY();
					dtMeshTile const* const Tile = NavMesh->getTileAt(X, Y, 0);

					if (Tile)
					{
						FBox Bbox(ForceInit);
						dtMeshHeader const* const Header = Tile->header;
						if (Header)
						{
							Bbox = Recast2UnrealBox(Header->bmin, Header->bmax);

							if (FMath::Abs(Bbox.Min.Z - Box1.Min.Z) > RecastNavMesh->AgentMaxStepHeight)
							{
								TileIndexes.Add(i);
							}
						}
					}
					//if(Box.Min -  )
					//TileIndexes.Add(i);
				}
			}
		}

		if (TileIndexes.Num() > 0)
		{
			DestroyLinksButtonClicked();
			for (auto Index : TileIndexes)
			{
				TArray<FNavPoly> Polys;
				RecastNavMesh->GetPolysInTile(Index, Polys);
				for (auto Poly : Polys)
				{
					TArray<FVector> MiddlePoints;
					double MaxDistance = 0.0;
					FVector PolyCenter;
					GetMiddlePoints(RecastNavMesh, Poly.Ref, MiddlePoints, PolyCenter, MaxDistance);

					TArray<FNavigationWallEdge> OutWallEdges;
					RecastNavMesh->FindEdges(Poly.Ref, PolyCenter, MaxDistance, nullptr, OutWallEdges);

					TArray<FNavigationWallEdge> Edges;

					for (auto WallEdge : OutWallEdges)
					{
						FVector WallMiddle = WallEdge.Start + (WallEdge.End - WallEdge.Start) / 2;

						for (auto Point : MiddlePoints)
						{
							if (Point.Equals(WallMiddle, 0.1f))
							{
								Edges.Add(WallEdge);
							}
						}
					}

					FVector CenterToMiddleNormal;

					for (auto Edge : Edges)
					{
						FVector WallMiddle = Edge.Start + (Edge.End - Edge.Start) / 2;
						//CenterToMiddleNormal = (WallMiddle - PolyCenter).GetSafeNormal();

						FVector EdgeNormal = (Edge.End - Edge.Start).GetSafeNormal();
						CenterToMiddleNormal.X = EdgeNormal.Y;
						CenterToMiddleNormal.Y = -EdgeNormal.X;
						CenterToMiddleNormal.Z = 0.0;

						FVector ExtentOrigin = WallMiddle + (-CenterToMiddleNormal * RecastNavMesh->AgentRadius * 2) + (-CenterToMiddleNormal * 400.f);
						FHitResult Hit;


						DrawDebugLine(GEditor->GetEditorWorldContext().World(), WallMiddle, ExtentOrigin, FColor::Red, false, 60.f, 0, 5.f);
						if (!GEditor->GetEditorWorldContext().World()->LineTraceSingleByChannel(Hit, WallMiddle, ExtentOrigin, ECC_Visibility))
						{
							FNavLocation OutLocation;
							RecastNavMesh->ProjectPoint(ExtentOrigin, OutLocation, FVector(50.0, 50.0, 1000.0));

							if (GenSettings->LinkClass)
							{
								FTransform Transform(FRotator::ZeroRotator, OutLocation.Location);
								ACustomNavLinkProxy* Link = GEditor->GetEditorWorldContext().World()->SpawnActorDeferred<ACustomNavLinkProxy>(GenSettings->LinkClass, Transform);
								if (Link)
								{
									Link->bSmartLinkIsRelevant = true;
									Link->PointLinks[0].Left = Link->GetActorTransform().GetRelativeTransform(Transform).GetTranslation();

									FTransform RightTransform(FRotator::ZeroRotator, WallMiddle - (-CenterToMiddleNormal * RecastNavMesh->AgentRadius));
									Link->PointLinks[0].Right = -Link->GetActorTransform().GetRelativeTransform(RightTransform).GetTranslation();
									Link->CopyEndPointsFromSimpleLinkToSmartLink();
									NavLinks.Add(Link);
									UGameplayStatics::FinishSpawningActor(Link, Transform);
								}
							}
						}

					}

				}
			}
			bIsGenerated = true;
		}
	}
}

bool FNavLinkGeneratorModule::IsTileValid(const ARecastNavMesh* NavMesh, int32 TileIndex) const
{
	if (!NavMesh)
	{
		return false;
	}
	const FBox TileBounds = NavMesh->GetNavMeshTileBounds(TileIndex);

	return TileBounds.IsValid != 0;
}

void FNavLinkGeneratorModule::GetMiddlePoints(const ARecastNavMesh* NavMesh, NavNodeRef Poly, TArray<FVector>& OutMiddlePoints, FVector& PolyCenter, double& MaxDistance)
{
	TArray<FVector> OutVerts;
	NavMesh->GetPolyVerts(Poly, OutVerts);
	NavMesh->GetPolyCenter(Poly, PolyCenter);
	for (int32 i = 0; i < OutVerts.Num(); ++i)
	{
		if (FVector::Distance(OutVerts[i], PolyCenter) > MaxDistance)
		{
			MaxDistance = FVector::Distance(OutVerts[i], PolyCenter);
		}
		FVector Point;
		if (i < OutVerts.Num() - 1)
		{
			Point = OutVerts[i] + (OutVerts[i + 1] - OutVerts[i]) / 2;
			OutMiddlePoints.Add(Point);
		}
		else
		{
			Point = OutVerts[i] + (OutVerts[0] - OutVerts[i]) / 2;
			OutMiddlePoints.Add(Point);
		}
	}
}

void FNavLinkGeneratorModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FNavLinkGeneratorCommands::Get().SpawnLinksAction, SpawnLinks);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FNavLinkGeneratorCommands::Get().SpawnLinksAction));
				Entry.SetCommandList(SpawnLinks);
			}
		}
	}

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FNavLinkGeneratorCommands::Get().DestroyLinksAction, DestroyLinks);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FNavLinkGeneratorCommands::Get().DestroyLinksAction));
				Entry.SetCommandList(DestroyLinks);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FNavLinkGeneratorModule, NavLinkGenerator)