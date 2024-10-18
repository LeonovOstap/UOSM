// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSMOSSv1Types.h"
#include "Interfaces/OSMSessionParameterProvider.h"
#include "Handlers/HandlerBase.h"

/**
 * 
 */

class OSMOSSV1HOST_API FOSSv1FragmentHandler_SessionParameter : public TOnlineFragmentHandlerOSSv1<IOSMSessionParameterProvider>
{
public:
	virtual void Process();

};


