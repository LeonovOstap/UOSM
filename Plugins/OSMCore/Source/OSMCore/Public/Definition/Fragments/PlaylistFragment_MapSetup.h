// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSMPlaylistFragment.h"
#include "Interfaces/OSMSessionParameterProvider.h"
#include "PlaylistFragment_MapSetup.generated.h"

/**
 * 
 */
UCLASS()
class OSMCORE_API UPlaylistFragment_MapSetup : public UOSMPlaylistFragment, public IOSMSessionParameterProvider
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> MapToLoad;

	UPROPERTY(EditAnywhere)
	FString ServerDefaultPortal;

	UPROPERTY(EditAnywhere)
	bool bIgnorePlayersPortalArgument = false;

	virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
protected:
	virtual void AddParameters(TSet<FOnlineSessionParameter>& OutParameters) override;
};
