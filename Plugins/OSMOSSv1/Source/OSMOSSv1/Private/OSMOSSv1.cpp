// Copyright Epic Games, Inc. All Rights Reserved.

#include "OSMOSSv1.h"

#include "OSMCore.h"
#include "OsmNames.h"
#include "OSSv1SessionHost.h"

#define LOCTEXT_NAMESPACE "FOSMOSSv1Module"


void FOSMOSSv1Module::StartupModule()
{
	FOSMCoreModule& OSMModule = FModuleManager::GetModuleChecked<FOSMCoreModule>(TEXT("OSMCore"));
	
	OSMModule.RegisterOnlineCapability<FOSSv1SessionHost>(OSM_HOST_INTERFACE);
}

void FOSMOSSv1Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FOSMOSSv1Module, OSMOSSv1)