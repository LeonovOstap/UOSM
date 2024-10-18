#pragma once
#include "OSMOSSv1Types.h"
#include "Definition/Fragments/PlaylistFragment_LobbySetup.h"

class OSMOSSV1HOST_API FOSSv1FragmentHandler_Lobby : public TOnlineFragmentHandlerOSSv1<UPlaylistFragment_LobbySetup>
{
public:
	virtual void Process() override;
	
};
