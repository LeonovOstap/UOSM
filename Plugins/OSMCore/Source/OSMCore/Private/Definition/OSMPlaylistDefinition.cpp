#include "Definition/OSMPlaylistDefinition.h"

#include "OnlineSessionSettings.h"
#include "Definition/Fragments/PlaylistFragment_NativeSessionParameters.h"
#include "Misc/DataValidation.h"

EDataValidationResult UOSMPlaylistDefinition::IsDataValid(FDataValidationContext& Context) const
{
	bool bIsObjectValid = Super::IsDataValid(Context) != EDataValidationResult::Invalid;
	for (const UOSMPlaylistFragment* Fragment : Fragments)
	{
		if(Fragment->IsDataValid(Context) == EDataValidationResult::Invalid)
		{
			bIsObjectValid = false;
		}
	}
	return bIsObjectValid? EDataValidationResult::Valid : EDataValidationResult::Invalid;
}