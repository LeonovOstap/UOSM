// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OSMPlaylistFragment.h"
#include "PropertyBag.h"
#include "Interfaces/OSMSessionParameterProvider.h"
#include "SessionHost/SessionHostRequest.h"
#include "UObject/Object.h"
#include "PlaylistFragment_NativeSessionParameters.generated.h"

/**
 * 
 */

UCLASS()
class OSMCORE_API UPlaylistFragment_NativeSessionParameters : public UOSMPlaylistFragment, public IOSMSessionParameterProvider
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, DisplayName="Parameters")
	FInstancedPropertyBag NativeOSSParams;

protected:

	virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
	virtual void AddParameters(TSet<FOnlineSessionParameter>& OutParameters) override;
};
