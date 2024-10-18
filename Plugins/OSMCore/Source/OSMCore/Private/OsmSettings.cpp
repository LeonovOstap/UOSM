// Fill out your copyright notice in the Description page of Project Settings.


#include "OsmSettings.h"

#include "OsmNames.h"
#include "Capability/OnlineCapabilitySet.h"

TArray<FName> UOsmSettings::GetHostInterfacesNames()
{
	return GetCapabilityNames(OSM_HOST_INTERFACE);
}

TArray<FName> UOsmSettings::GetCapabilityNames(FName CapabilityType)
{
	TArray<IOnlineCapability*> SessionHostInterfaces = IModularFeatures::Get().GetModularFeatureImplementations<IOnlineCapability>(CapabilityType);
	TArray<FName> OutOptions;

	for (IOnlineCapability* SessionHostInterface : SessionHostInterfaces)
	{
		OutOptions.Add(SessionHostInterface->GetFeatureSetName());
	}

	return OutOptions;
}
