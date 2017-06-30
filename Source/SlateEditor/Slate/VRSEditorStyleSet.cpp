// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

//#include "EditorStylePrivatePCH.h"
#include "SlateEditor.h"
#include "VRSEditorStyleSet.h"

TSharedPtr< ISlateStyle > FVRSEditorStyle::Instance = NULL;

void FVRSEditorStyle::ResetToDefault()
{
	SetStyle( FCoreStyle::Create("EditorStyle") );
	//SetStyle(FCoreStyle::Create("UMGStyle")); // UMGStyle CoreStyle
}

void FVRSEditorStyle::SetStyle( const TSharedRef< ISlateStyle >& NewStyle )
{
	if( Instance != NewStyle )
	{
		if ( Instance.IsValid() )
		{
			FSlateStyleRegistry::UnRegisterSlateStyle( *Instance.Get() );
		}

		Instance = NewStyle;

		if ( Instance.IsValid() )
		{
			FSlateStyleRegistry::RegisterSlateStyle( *Instance.Get() );
		}
		else
		{
			ResetToDefault();
		}
	}
}
