// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSMPlaylistFragment.h"
#include "Interfaces/OSMSessionParameterProvider.h"
#include "PlaylistFragment_PlayerLimits.generated.h"

/**
 * 
 */
UCLASS()
class OSMCORE_API UPlaylistFragment_PlayerLimits : public UOSMPlaylistFragment
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=PlayerLimits)
	int32 MaxPlayers = 2;
};
