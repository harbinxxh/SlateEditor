// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.



#pragma once

//#include "IToolkit.h"
//#include "LightmapResRatioAdjust.h"
#include "VRSEditorStyleSet.h"
#include "Developer/AssetTools/Public/IAssetTypeActions.h"

/**
* Unreal level editor actions
*/
class FVRSLevelEditorCommands : public TCommands<FVRSLevelEditorCommands>
{

public:
	FVRSLevelEditorCommands() : TCommands<FVRSLevelEditorCommands>
		(
			"LevelEditor", // Context name for fast lookup
			NSLOCTEXT("Contexts", "LevelEditor", "Level Editor"), // Localized context name for displaying
			"", // Parent
			//FVRSEditorStyle::GetStyleSetName()
			FName("EditorStyle")//FEditorStyle::GetStyleSetName() // Icon Style Set EditorStyle CoreStyle
			)
	{
	}

	/**
	* Initialize commands
	*/
	virtual void RegisterCommands() override;

public:

	TSharedPtr< FUICommandInfo > BrowseDocumentation;


	/** Level file commands */
	TSharedPtr< FUICommandInfo > Save;

	TSharedPtr< FUICommandInfo > SaveAllLevels;

	TSharedPtr< FUICommandInfo > FeatureLevelPreview[ERHIFeatureLevel::Num];
};




/**
* Implementation of various level editor action callback functions
*/
class FVRSLevelEditorActionCallbacks
{
public:

	/**
	* The default can execute action for all commands unless they override it
	* By default commands cannot be executed if the application is in K2 debug mode.
	*/
	static bool DefaultCanExecuteAction();

	/** Opens the global documentation homepage */
	static void BrowseDocumentation();

	/** Determine whether the level can be saved at this moment */
	static bool CanSaveWorld();

	/** Saves the current map */
	static void Save();

	/** Saves all unsaved maps (but not packages) */
	static void SaveAllLevels();


};

