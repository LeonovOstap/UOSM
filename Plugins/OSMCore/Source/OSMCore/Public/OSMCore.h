// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class IOnlineCapability;

class FOSMCoreModule : public IModuleInterface
{
public:
	template<class T>
	typename TEnableIf<TIsDerivedFrom<T, IOnlineCapability>::IsDerived, void>::Type
	RegisterOnlineCapability(FName Name)
	{
		T* Instance = new T;
		IModularFeatures::Get().RegisterModularFeature(Name, Instance);
		
		RegisteredOnlineCapabilities.Add(Instance);
	}

protected:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TArray<IOnlineCapability*> RegisteredOnlineCapabilities;


};
