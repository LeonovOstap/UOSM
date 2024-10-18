// Copyright Epic Games, Inc. All Rights Reserved.

#include "OSMOSSv1Host.h"

#define LOCTEXT_NAMESPACE "FOSMOSSv1HostModule"


void FOSMOSSv1HostModule::StartupModule()
{
}

void FOSMOSSv1HostModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FOSMOSSv1HostModule, OSMOSSv1Host)