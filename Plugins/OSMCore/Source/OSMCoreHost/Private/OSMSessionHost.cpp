// Fill out your copyright notice in the Description page of Project Settings.


#include "OSMSessionHost.h"


void FSessionHostBase::Handle(UOSMPlaylistDefinition* Definition, void* Data)
{
	for (UOSMPlaylistFragment* Fragment : Definition->Fragments)
	{
		for (const FImplementedInterface& Interface : Fragment->GetClass()->Interfaces)
		{
			if(TSharedPtr<IOnlineFramentHandlerBase>* Handler = HandlerArray.Find(Interface.Class))
			{
				Handler->Get()->Init(Fragment->GetInterfaceAddress(Interface.Class), Data);
				Handler->Get()->Process();
			}
		}
		if(TSharedPtr<IOnlineFramentHandlerBase>* Handler = HandlerArray.Find(Fragment->GetClass()))
		{
			Handler->Get()->Init(Fragment, Data);
			Handler->Get()->Process();
		}
	}
}
