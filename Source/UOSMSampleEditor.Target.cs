// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UOSMSampleEditorTarget : TargetRules
{
	public UOSMSampleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		CustomConfig = "EOS";

		ExtraModuleNames.AddRange( new string[] { "UOSMSample" } );
	}
}
