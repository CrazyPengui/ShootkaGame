// Shootka Game. All rights reserved!

using UnrealBuildTool;
using System.Collections.Generic;

public class ShootkaEditorTarget : TargetRules
{
	public ShootkaEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "Shootka" } );
	}
}
