// Copyright (c) 2023 Sebastien Rombauts (sebastien.rombauts@gmail.com)

using UnrealBuildTool;

public class UnrealMultiplayer : ModuleRules
{
	public UnrealMultiplayer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
