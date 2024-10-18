// Fill out your copyright notice in the Description page of Project Settings.


#include "Handlers/OSSv1FragmentHandler_SessionParameter.h"

#include "SessionHost/SessionHostRequest.h"

void FOSSv1FragmentHandler_SessionParameter::Process()
{
	TSet<FOnlineSessionParameter> CurrentParams;
	Fragment->AddParameters(CurrentParams);

	for (const FOnlineSessionParameter& Param : CurrentParams)
	{
		Visit([&](auto&& Value)
		{
			DataTypeRef->Set(Param.Name, Value, EOnlineDataAdvertisementType::ViaOnlineService);
		}, Param.Value);
	}
}
	