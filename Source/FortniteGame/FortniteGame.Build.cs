// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class FortniteGame : ModuleRules
{
	public FortniteGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
			"GameplayAbilities", 
			"AnimationBudgetAllocator", 
			"Niagara", 
			"FortniteUI",
			"McpProfileSys",
			"Account",
			"AIModule",
			"CinematicCamera",
			"EpicGameplayStatsRuntime",
			"GameplayTags",
			"GameplayTasks",
			"Gauntlet",
			"NiagaraCore",
			"NiagaraShader",
			"Party",
			"OnlineSubsystem",
			"OnlineSubsystemUtils",
			"UMG",
			"Slate",
			"SlateCore",
			"ReplicationGraph",
			"GameSubCatalog",
			"Lobby",
			"MediaAssets",
			"WebBrowser",
			"Hotfix",
			"CommonUI",
			"LoginFlow",
			"FortniteEditor",
			"MeshNetwork",
			"ClientPilot",
			"BlueprintContext",
			"AnimGraphRuntime",
			"PhysXVehicles",
			"Rejoin",
			"SidecarSys",
			"SignificanceManager",
			"Foliage",
			"Paper2D",
			"ClothingSystemRuntime",
			"JsonUtilities",
			"HeadMountedDisplay",
			"CommonInput"
		});

        PrivateDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks", "AnimationBudgetAllocator", "McpProfileSys" });

        // Uncomment if you are using Slate UI
         PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore", "UMG" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
