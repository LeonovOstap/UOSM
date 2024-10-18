// Copyright Epic Games, Inc. All Rights Reserved.

#include "OSMCore.h"

#include "Capability/OnlineCapabilitySet.h"

#define LOCTEXT_NAMESPACE "FOSMCoreModule"

void FOSMCoreModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FOSMCoreModule::ShutdownModule()
{
	/*for (IOnlineCapability* Capability : RegisteredOnlineCapabilities)
	{
		IModularFeatures::UnregisterModularFeature()
	}*/
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FOSMCoreModule, OSMCore)