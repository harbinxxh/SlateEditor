// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "SlateEditor.h"
#include "UMG.h"
#include "SVRSTopmostWindow.h"
#include "VRSWidgetTopmostPanel.h"


void SVRSTopmostWindow::Construct(const FArguments& InArgs)
{
	UVRSWidgetTopmostPanel* UserWidget = nullptr;
	TSubclassOf<UVRSWidgetTopmostPanel> WidgetClass = LoadClass<UVRSWidgetTopmostPanel>(nullptr, TEXT("/Game/BP/BP_WidgetTopmostPanel.BP_WidgetTopmostPanel_C"));
	if (WidgetClass)
	{
		UserWidget = CreateWidget<UVRSWidgetTopmostPanel>(GWorld, WidgetClass);
	}

	//TopmostWindow = SNew(SWindow);
	//TopmostWindow->SetContent(UserWidget->TakeWidget());
	//TopmostWindow->ShowWindow();


	ChildSlot
	[
		UserWidget->TakeWidget()
		//TopmostWindow
		//SNew(SWindow)
		//SNew(SButton)
	];
}
