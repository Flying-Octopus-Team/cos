// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class cos : ModuleRules
{
	public cos(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "DeveloperSettings" });
	}
}
