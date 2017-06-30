// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SlateEditor : ModuleRules
{
	public SlateEditor(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(
            new string[] {
                "Core",
                "CoreUObject",
                "Engine",
                "InputCore",
                "HeadMountedDisplay",
                "UMG",
                "Slate",
                "SlateCore",
                "RHI"
            });

        PublicIncludePaths.AddRange(
            new string[]
            {
                "SlateEditor/Slate"
            });
    }
}
