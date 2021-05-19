// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SimDarkSouls : ModuleRules
{
	public SimDarkSouls(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","GameplayTasks" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		

		// Uncomment if you are using Slate UI
		 PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		
		//PrivateIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/GamePlay"});
		PublicIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/GamePlay"});
		PublicIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/UI/HUD"});
		PublicIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/UI/Widget"});
		PublicIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/UI/Style"});
		PublicIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/Common"});
		PublicIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/Data"});
		PublicIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/Player"});
		PublicIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/Player/AnimNotify"});
		PublicIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/Weapon"});
		PublicIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/NPC/Boss"});
		PublicIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/NPC/Boss/Task"});
		PublicIncludePaths.AddRange(new string[]{"SimDarkSouls/Public/NPC/Boss/Service"});

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
