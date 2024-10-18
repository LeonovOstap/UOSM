#pragma once
#include "OnlineSessionSettings.h"
#include "Handlers/HandlerBase.h"

template<class FragmentType>
using TOnlineFragmentHandlerOSSv1 = TOnlineFragmentHandler<FragmentType, FOnlineSessionSettings>;
