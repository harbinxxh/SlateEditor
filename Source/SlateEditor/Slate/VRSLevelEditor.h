// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "VRSAssetEditorToolkit.h"
#include "VRSLevelEditor.generated.h"


/**
 * 
 */
UCLASS()
class UVRSLevelEditor : public UObject
{
	GENERATED_BODY()
	
public:
	UVRSLevelEditor();

	TSharedRef< SWidget > MakeLevelEditorMenu();

	/**
	* Binds all global level editor commands to delegates
	*/
	void BindGlobalLevelEditorCommands();





	//TSharedPtr<FUICommandList> CommandList;
	
	TSharedPtr<FVRSExtensibilityManager> MenuExtensibilityManager;


	/**
	* A command list that can be passed around and isn't bound to an instance of a level editor.
	* Only commands that arent bound to an instance of SLevelEditor should be used here (like level context menu commands)
	*/
	TSharedPtr<FUICommandList> GlobalLevelEditorActions;




	// The list of commands with bound delegates for the level editor.
	TSharedPtr<FUICommandList> LevelEditorCommands;


	
};

extern UVRSLevelEditor * GLevelEditor;