// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSMOSSv1Types.h"
#include "OSMSessionHost.h"

/**
 * 
 */


class IOnlineFramentHandlerBase;

class OSMOSSV1HOST_API FOSSv1SessionHost : public FSessionHostBase
{
public:
	virtual void Initialize() override;
	virtual void DeInitialize() override {}
	virtual FName GetFeatureSetName() override
	{
		return TEXT("OSSv1");
	}
	virtual void HostSession(UOSMPlaylistDefinition* Definition) override;
	
	

private:

};

