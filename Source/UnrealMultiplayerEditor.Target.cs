// Copyright (c) 2023 Sebastien Rombauts (sebastien.rombauts@gmail.com)

using UnrealBuildTool;
using System.Collections.Generic;

public class UnrealMultiplayerEditorTarget : TargetRules
{
	public UnrealMultiplayerEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_3;
		ExtraModuleNames.Add("UnrealMultiplayer");
	}
}
