// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

using FOnlineSessionValue = TVariant<bool, double, int32, FString>;

struct FOnlineSessionParameter
{
	FOnlineSessionParameter() = default;
	
	template<class T>
	FOnlineSessionParameter(FName InName, T InValue)
	{
		Name = InName;
		Value.Emplace<T>(InValue);
	}
	
	FName Name;
	FOnlineSessionValue Value;

	bool operator==(const FOnlineSessionParameter& Other) const
	{
		return Other.Name == Name;
	}

	friend uint32 GetTypeHash(const FOnlineSessionParameter& Param)
	{
		return GetTypeHash(Param.Name);
	}
};
