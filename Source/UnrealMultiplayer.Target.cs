// Copyright (c) 2023 Sebastien Rombauts (sebastien.rombauts@gmail.com)

using UnrealBuildTool;
using System.Collections.Generic;

public class UnrealMultiplayerTarget : TargetRules
{
	public UnrealMultiplayerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("UnrealMultiplayer");
	}
}
