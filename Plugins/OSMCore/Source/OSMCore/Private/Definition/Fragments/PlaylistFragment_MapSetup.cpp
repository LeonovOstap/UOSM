// Fill out your copyright notice in the Description page of Project Settings.


#include "Definition/Fragments/PlaylistFragment_MapSetup.h"

#include "Misc/DataValidation.h"
#include "Online/OnlineSessionNames.h"
#include "SessionHost/SessionHostRequest.h"

#define LOCTEXT_NAMESPACE "PlaylistFragment_MapSetup"
EDataValidationResult UPlaylistFragment_MapSetup::IsDataValid(FDataValidationContext& Context) const
{
	if(MapToLoad.IsNull())
	{
		Context.AddError(LOCTEXT("PlaylistFragment_MapSetup_MapNull", "MapToLoad can't be null"));
		return EDataValidationResult::Invalid;
	}
	
	return Super::IsDataValid(Context);
}

void UPlaylistFragment_MapSetup::AddParameters(TSet<FOnlineSessionParameter>& OutParameters)
{
	OutParameters.Add(FOnlineSessionParameter(SETTING_MAPNAME, MapToLoad->GetMapName()));
	OutParameters.Add(FOnlineSessionParameter(SETTING_GAMEMODE, GetOuter()->GetName()));
}
#undef LOCTEXT_NAMESPACE
