// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSMPlaylistFragment.h"
#include "Interfaces/OSMSessionParameterProvider.h"
#include "PlaylistFragment_LobbySetup.generated.h"

/**
 * 
 */
UCLASS()
class OSMCORE_API UPlaylistFragment_LobbySetup : public UOSMPlaylistFragment, public IOSMSessionParameterProvider
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bAllowHostMigration = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bShouldCreateVoiceChatRoom = false;
	
protected:
	void AddParameters(TSet<FOnlineSessionParameter>& OutParameters) override;
};
