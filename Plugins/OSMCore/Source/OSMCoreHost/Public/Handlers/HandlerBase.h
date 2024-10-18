// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/OnlineFragmentInterface.h"

/**
 * 
 */

class IOnlineFramentHandlerBase
{
public:
	virtual void Init(void* InFragment, void* InDataType ) = 0;
	virtual void Process() = 0;
};

template<class FragmentType, class DataType> 
class TOnlineFragmentHandler : public IOnlineFramentHandlerBase
{
	static_assert(TIsDerivedFrom<FragmentType, IOnlineFragmentInterface>::IsDerived);
	
public:
	virtual void Init(void* InFragment, void* InDataType) override
	{
		Fragment = static_cast<FragmentType*>(InFragment);
		DataTypeRef = static_cast<DataType*>(InDataType);
	}

protected:
	FragmentType* Fragment;
	DataType* DataTypeRef;
};
