// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "Fragments/OSMPlaylistFragment.h"

#include "OSMPlaylistDefinition.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class OSMCORE_API UOSMPlaylistDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Playlist)
	FText GamemodeName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Playlist, meta=(ShowInnerProperties))
	TArray<UOSMPlaylistFragment*> Fragments;
	
	virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
	
	template<typename T>
	T* GetFragment();

	template<typename T>
	T* GetFragmentByInterface();
	
};

template<typename T>
T* UOSMPlaylistDefinition::GetFragment()
{
	for (const UOSMPlaylistFragment* Fragment : Fragments)
	{
		if(Fragment->IsA<T>())
		{
			return CastChecked<T>(Fragment);
		}
	}
		
	return nullptr;
}

template<typename T>
T* UOSMPlaylistDefinition::GetFragmentByInterface()
{
	for (UOSMPlaylistFragment* Fragment : Fragments)
	{
		if(Fragment->Implements<typename T::UClassType>())
		{
			return CastChecked<T>(Fragment);
		}
	}
		
	return nullptr;
}