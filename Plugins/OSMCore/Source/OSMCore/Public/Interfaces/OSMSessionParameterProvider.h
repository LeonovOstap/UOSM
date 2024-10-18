// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineFragmentInterface.h"
#include "UObject/Interface.h"
#include "OSMSessionParameterProvider.generated.h"

// This class does not need to be modified.
UINTERFACE()
class OSMCORE_API UOSMSessionParameterProvider : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */



class OSMCORE_API IOSMSessionParameterProvider : public IOnlineFragmentInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void AddParameters(TSet<struct FOnlineSessionParameter>& OutParameters) = 0;
};
