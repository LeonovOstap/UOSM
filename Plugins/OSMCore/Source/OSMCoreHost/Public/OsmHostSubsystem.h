// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Definition/OSMPlaylistDefinition.h"
#include "OSMSessionHost.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OsmHostSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class OSMCOREHOST_API UOsmHostSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()


public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable)
	void HostSession(UOSMPlaylistDefinition* PlaylistDefinition);


	FSessionHostBase* GetSessionHostInterface();
};
