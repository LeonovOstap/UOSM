// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Capability/OnlineCapabilitySet.h"
#include "Definition/OSMPlaylistDefinition.h"
#include "Handlers/HandlerBase.h"

/**
 * 
 */


class OSMCOREHOST_API FSessionHostBase : public IOnlineCapability
{
public:
	virtual void Initialize() = 0;
	virtual void DeInitialize() = 0;
	
	virtual void HostSession(UOSMPlaylistDefinition* Definition) = 0;
	
	void Handle(UOSMPlaylistDefinition* Definition, void* Data);

protected:

	template <class FragmentType, class HandlerType>
	typename TEnableIf<TIsIInterface<FragmentType>::Value, void>::Type
	RegisterHandler()
	{
		static_assert(TIsDerivedFrom<FragmentType, IOnlineFragmentInterface>::Value);
		
		TSharedPtr<HandlerType> Handler = MakeShared<HandlerType>(); 
		HandlerArray.Emplace(FragmentType::UClassType::StaticClass(), Handler);
	}

	template <class FragmentType, class HandlerType>
	typename TEnableIf<TIsDerivedFrom<FragmentType, UOSMPlaylistFragment>::Value, void>::Type
	RegisterHandler()
	{
		TSharedPtr<HandlerType> Handler = MakeShared<HandlerType>(); 
		HandlerArray.Emplace(FragmentType::StaticClass(), Handler);
	}

private:
	TMap<UClass*, TSharedPtr<IOnlineFramentHandlerBase>> HandlerArray;
};
