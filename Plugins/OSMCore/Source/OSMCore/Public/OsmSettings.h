// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "OsmSettings.generated.h"

/**
 * 
 */
UCLASS(config=Engine, defaultconfig)
class OSMCORE_API UOsmSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	static const ThisClass* Get()
	{
		return GetDefault<ThisClass>();
	}
	
	UPROPERTY(Config, EditAnywhere, meta=(GetOptions=GetHostInterfacesNames))
	FName SessionHost ;

private:
	UFUNCTION()
	TArray<FName> GetHostInterfacesNames();

private:
	TArray<FName> GetCapabilityNames(FName CapabilityType);
};
