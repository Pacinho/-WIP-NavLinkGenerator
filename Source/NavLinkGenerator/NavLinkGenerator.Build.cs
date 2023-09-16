// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NavLinkGenerator : ModuleRules
{
    public NavLinkGenerator(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
			}
            );


        PrivateIncludePaths.AddRange(
            new string[] {
				// ... add other private include paths required here ...
			}
            );


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "Engine",
                "NavigationSystem",
                "AIModule",
                "DeveloperSettings"
				// ... add other public dependencies that you statically link with here ...
			}
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Projects",
                "InputCore",
                "EditorFramework",
                "UnrealEd",
                "ToolMenus",
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );

        if (Target.bCompileRecast)
        {
            PublicDependencyModuleNames.Add("Navmesh");
            PublicDefinitions.Add("WITH_RECAST=1");
        }
        else
        {
            // Because we test WITH_RECAST in public Engine header files, we need to make sure that modules
            // that import us also have this definition set appropriately.  Recast is a private dependency
            // module, so it's definitions won't propagate to modules that import Engine.
            PublicDefinitions.Add("WITH_RECAST=0");
        }
    }
}
