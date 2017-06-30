// Fill out your copyright notice in the Description page of Project Settings.

#include "SlateEditor.h"
#include "VRSLevelEditor.h"
#include "VRSGenericCommands.h"
#include "VRSMainFrameActions.h"
#include "VRSLevelEditorActions.h"
#include "VRSLevelEditorMenu.h"
#include "VRSEditorStyleSet.h"

UVRSLevelEditor * GLevelEditor = nullptr;

UVRSLevelEditor::UVRSLevelEditor()
{
	GLevelEditor = this;
}

TSharedRef< SWidget > UVRSLevelEditor::MakeLevelEditorMenu()
{
	//FVRSEditorStyle::ResetToDefault();

	// Our command context bindings depend on having the mainframe loaded
	MenuExtensibilityManager = MakeShareable(new FVRSExtensibilityManager);

	// Note this must come before any tab spawning because that can create the SLevelEditor and attempt to map commands
	//FVRSLevelEditorCommands::Register();
	FVRSMainFrameCommands::Register();
	FVRSGenericCommands::Register();

	// Bind level editor commands shared across an instance
	//BindGlobalLevelEditorCommands();


	//CommandList = MakeShareable(new FUICommandList);

	LevelEditorCommands = MakeShareable(new FUICommandList);
	TSharedRef<SWidget> Widget1 = FVRSLevelEditorMenu::MakeLevelEditorMenu();

	return Widget1;
}

void UVRSLevelEditor::BindGlobalLevelEditorCommands()
{
	check( !GlobalLevelEditorActions.IsValid() );

	GlobalLevelEditorActions = MakeShareable( new FUICommandList );

	const FVRSLevelEditorCommands& Commands = FVRSLevelEditorCommands::Get();
	FUICommandList& ActionList = *GlobalLevelEditorActions;

	ActionList.MapAction(Commands.BrowseDocumentation, FExecuteAction::CreateStatic(&FVRSLevelEditorActionCallbacks::BrowseDocumentation));
	ActionList.MapAction(Commands.Save, FExecuteAction::CreateStatic(&FVRSLevelEditorActionCallbacks::Save), FCanExecuteAction::CreateStatic(&FVRSLevelEditorActionCallbacks::CanSaveWorld));
	ActionList.MapAction(Commands.SaveAllLevels, FExecuteAction::CreateStatic(&FVRSLevelEditorActionCallbacks::SaveAllLevels), FCanExecuteAction::CreateStatic(&FVRSLevelEditorActionCallbacks::CanSaveWorld));
}
