// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.


#include "SlateEditor/SlateEditor.h"
#include "VRSAssetEditorToolkit.h"


#define LOCTEXT_NAMESPACE "VRSAssetEditorToolkit"


TSharedPtr<FExtender> FVRSExtensibilityManager::GetAllExtenders()
{
	return FExtender::Combine(Extenders);
}
	
TSharedPtr<FExtender> FVRSExtensibilityManager::GetAllExtenders(const TSharedRef<FUICommandList>& CommandList, const TArray<UObject*>& ContextSensitiveObjects)
{
	auto OutExtenders = Extenders;
	for (int32 i = 0; i < ExtenderDelegates.Num(); ++i)
	{
		if (ExtenderDelegates[i].IsBound())
		{
			OutExtenders.Add(ExtenderDelegates[i].Execute(CommandList, ContextSensitiveObjects));
		}
	}
	return FExtender::Combine(OutExtenders);
}
	
#undef LOCTEXT_NAMESPACE
