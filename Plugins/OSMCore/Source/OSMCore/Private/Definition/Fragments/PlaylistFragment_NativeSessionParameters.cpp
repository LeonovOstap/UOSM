// Fill out your copyright notice in the Description page of Project Settings.


#include "Definition/Fragments/PlaylistFragment_NativeSessionParameters.h"

#include "Misc/DataValidation.h"

#define LOCTEXT_NAMESPACE "PlaylistFragment_NativeSessionParameters"

class FPropertyBagHelper
{
public:
	FPropertyBagHelper(const UPropertyBag* InPropertyBag, const uint8* InStructData)
		: PropertyBag(InPropertyBag), StructData(InStructData)
	{
	}

	FOnlineSessionParameter GetPropertyAsSessionParam(const FPropertyBagPropertyDesc& InDesc) const
	{
		FOnlineSessionParameter OutParam;
		OutParam.Name = InDesc.Name;
		
		FProperty* ValueProperty = const_cast<FProperty*>(InDesc.CachedProperty);
		if(auto ValuePtr = ValueProperty->ContainerPtrToValuePtr<void>(StructData))
		{
			switch (InDesc.ValueType)
			{
			case EPropertyBagPropertyType::Bool:
				{
					bool BoolValue = *(ValueProperty->ContainerPtrToValuePtr<bool>(StructData));
					OutParam.Value.Emplace<bool>(BoolValue);
				}
				break;
			case EPropertyBagPropertyType::Double:
			case EPropertyBagPropertyType::Float:
				{
					double DoubleValue = *(ValueProperty->ContainerPtrToValuePtr<double>(StructData));
					OutParam.Value.Emplace<double>(DoubleValue);
				}
				break;
			case EPropertyBagPropertyType::Int32:
				{
					int32 IntValue = *(ValueProperty->ContainerPtrToValuePtr<int32>(StructData));
					OutParam.Value.Emplace<int32>(IntValue);
				}
				break;
			case EPropertyBagPropertyType::String:
				{
					FString StringValue = *(ValueProperty->ContainerPtrToValuePtr<FString>(StructData));
					OutParam.Value.Emplace<FString>(StringValue);
				}
				break;
			default:
				ensureMsgf(false,
					TEXT("NativeSessionParameters -> invalid property type %s:%s"),
					*InDesc.Name.ToString(),
					 *StaticEnum<EPropertyBagPropertyType>()->GetNameStringByValue((int64) InDesc.ValueType));
			}
		}
		return OutParam;
	}
	
private:
	const UPropertyBag* PropertyBag;
	const uint8* StructData;
};



EDataValidationResult UPlaylistFragment_NativeSessionParameters::IsDataValid(FDataValidationContext& Context) const
{
	for (const FPropertyBagPropertyDesc& PropertyDesc
		 : NativeOSSParams.GetPropertyBagStruct()->GetPropertyDescs())
	{
		if(!(PropertyDesc.ValueType == EPropertyBagPropertyType::Bool ||
				PropertyDesc.ValueType == EPropertyBagPropertyType::Int32 ||
				PropertyDesc.ValueType == EPropertyBagPropertyType::Double ||
				PropertyDesc.ValueType == EPropertyBagPropertyType::Float ||
				PropertyDesc.ValueType == EPropertyBagPropertyType::String))
		{
			const FText ValueName = FText::FromName(PropertyDesc.Name);
			const FText ValueType = StaticEnum<EPropertyBagPropertyType>()->GetDisplayNameTextByValue((int64) PropertyDesc.ValueType);
			
			Context.AddError(FText::Format(
				LOCTEXT("NativeSessionParamsPropertyValidationError",
					"Unsupported property type declared - {0}::{1}"),
					ValueName,
					ValueType));
			
			return EDataValidationResult::Invalid;
		}
	}
	return Super::IsDataValid(Context);
}

void UPlaylistFragment_NativeSessionParameters::AddParameters(TSet<FOnlineSessionParameter>& OutParameters)
{
	const UPropertyBag* PropertyBag = NativeOSSParams.GetPropertyBagStruct();
	const uint8* StructData = NativeOSSParams.GetValue().GetMemory();
	FPropertyBagHelper PropertyBagHelper = FPropertyBagHelper(PropertyBag, StructData);

	for (const FPropertyBagPropertyDesc& PropertyDesc
		 : NativeOSSParams.GetPropertyBagStruct()->GetPropertyDescs())
	{
		OutParameters.Add(PropertyBagHelper.GetPropertyAsSessionParam(PropertyDesc));
	}
}
#undef LOCTEXT_NAMESPACE