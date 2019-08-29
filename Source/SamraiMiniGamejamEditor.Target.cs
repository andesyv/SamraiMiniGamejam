// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class SamraiMiniGamejamEditorTarget : TargetRules
{
	public SamraiMiniGamejamEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("SamraiMiniGamejam");
	}
}
