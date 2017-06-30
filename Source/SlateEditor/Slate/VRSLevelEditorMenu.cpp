//// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
//
#include "SlateEditor/SlateEditor.h"
#include "VRSLevelEditorMenu.h"
#include "VRSMainFrameActions.h"
#include "VRSMainMenu.h"



#define LOCTEXT_NAMESPACE "VRSMainMenu"

TSharedRef< SWidget > FVRSLevelEditorMenu::MakeLevelEditorMenu()
{
	// UI…œ≤Àµ•œÓ
	TSharedRef< FExtender > Extenders(new FExtender());
	
	TSharedRef< SWidget > MenuBarWidget = FVRSMainMenu::MakeMainMenu(Extenders);
	return MenuBarWidget;

}

#undef LOCTEXT_NAMESPACE
