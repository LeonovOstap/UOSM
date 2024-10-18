// Fill out your copyright notice in the Description page of Project Settings.


#include "OsmHostSubsystem.h"

#include "OsmNames.h"
#include "OsmSettings.h"
#include "Features/IModularFeatures.h"

void UOsmHostSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	if(FSessionHostBase* HostInterface = GetSessionHostInterface())
	{
		HostInterface->Initialize();
	}
}

void UOsmHostSubsystem::HostSession(UOSMPlaylistDefinition* PlaylistDefinition)
{
	if(FSessionHostBase* HostInterface = GetSessionHostInterface())
	{
		HostInterface->HostSession(PlaylistDefinition);
	}
}

FSessionHostBase* UOsmHostSubsystem::GetSessionHostInterface()
{
	FName SessionHostName = UOsmSettings::Get()->SessionHost;

	for (auto Element : IModularFeatures::Get().GetModularFeatureImplementations<FSessionHostBase>(OSM_HOST_INTERFACE))
	{
		if(Element->GetFeatureSetName() == SessionHostName)
			return Element;
	}

	return nullptr;
}
