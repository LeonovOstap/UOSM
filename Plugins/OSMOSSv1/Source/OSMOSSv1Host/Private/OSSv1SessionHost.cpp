// Fill out your copyright notice in the Description page of Project Settings.


#include "OSSv1SessionHost.h"

#include "Online.h"
#include "OnlineSubsystemUtils.h"
#include "Definition/Fragments/PlaylistFragment_LobbySetup.h"
#include "Handlers/OSSv1FragmentHandler_SessionParameter.h"

void FOSSv1SessionHost::Initialize()
{
	RegisterHandler<IOSMSessionParameterProvider, FOSSv1FragmentHandler_SessionParameter>();
	RegisterHandler<UPlaylistFragment_LobbySetup, FOSSv1FragmentHandler_SessionParameter>();
}

void FOSSv1SessionHost::HostSession(UOSMPlaylistDefinition* Definition)
{
	const TUniquePtr<FOnlineSessionSettings> SessionSettings = MakeUnique<FOnlineSessionSettings>();
	Handle(Definition, SessionSettings.Get());

	SessionSettings->NumPublicConnections = 2;
	
	IOnlineSessionPtr SessionInterface = Online::GetSubsystem(GWorld)->GetSessionInterface();
	if(FUniqueNetIdPtr UniqueNetId = Online::GetSubsystem(GWorld)->GetIdentityInterface()->GetUniquePlayerId(0))
	{
		SessionInterface->CreateSession(*UniqueNetId, NAME_GameSession, *SessionSettings);
	}

}
