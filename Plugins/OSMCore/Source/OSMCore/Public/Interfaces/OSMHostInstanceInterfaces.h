// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Definition/OSMPlaylistDefinition.h"
#include "UObject/Interface.h"
#include "OSMHostInstanceInterfaces.generated.h"

UINTERFACE()
class UOSMHostInstanceImpl : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OSMCORE_API IOSMHostInstanceImpl
{
	GENERATED_BODY()

public:
	virtual bool InitializeHost() = 0;
	virtual void DeinitializeHost() = 0;

	virtual void StartHosting(UOSMPlaylistDefinition* ) = 0;
};
