// Fill out your copyright notice in the Description page of Project Settings.


#include "Definition/Fragments/PlaylistFragment_LobbySetup.h"

#include "Online/OnlineSessionNames.h"
#include "SessionHost/SessionHostRequest.h"

void UPlaylistFragment_LobbySetup::AddParameters(TSet<FOnlineSessionParameter>& OutParameters)
{
	OutParameters.Add(FOnlineSessionParameter(SETTING_HOST_MIGRATION, bAllowHostMigration));
	
}
