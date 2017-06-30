#include "SlateEditor/SlateEditor.h"
#include "VRSLevelEditorActions.h"
#include "Runtime/RHI/Public/RHIDefinitions.h"

#define LOCTEXT_NAMESPACE "VRSLevelEditorActions"


void FVRSLevelEditorActionCallbacks::BrowseDocumentation()
{
	//IDocumentation::Get()->OpenHome(FDocumentationSourceInfo(TEXT("help_menu")));
	UE_LOG(LogTemp, Warning, TEXT("BrowseDocumentation"));
}


bool FVRSLevelEditorActionCallbacks::CanSaveWorld()
{
	//return FSlateApplication::Get().IsNormalExecution() && (!GUnrealEd || !GUnrealEd->GetPackageAutoSaver().IsAutoSaving());
	UE_LOG(LogTemp, Warning, TEXT("CanSaveWorld()"));
	return true;
}

void FVRSLevelEditorActionCallbacks::Save()
{
	//FEditorFileUtils::SaveCurrentLevel();
	UE_LOG(LogTemp, Warning, TEXT("SaveCurrentLevel()"));
}

void FVRSLevelEditorActionCallbacks::SaveAllLevels()
{
	UE_LOG(LogTemp, Warning, TEXT("SaveAllLevels()"));
	//const bool bPromptUserToSave = false;
	//const bool bSaveMapPackages = true;
	//const bool bSaveContentPackages = false;
	//const bool bFastSave = false;
	//FEditorFileUtils::SaveDirtyPackages(bPromptUserToSave, bSaveMapPackages, bSaveContentPackages, bFastSave);
}


/** UI_COMMAND takes long for the compile to optimize */
PRAGMA_DISABLE_OPTIMIZATION
void FVRSLevelEditorCommands::RegisterCommands()
{
	UI_COMMAND(Save, "Save Current", "Saves the current level to disk", EUserInterfaceActionType::Button, FInputChord(EModifierKey::Control, EKeys::S));
	UI_COMMAND(SaveAllLevels, "Save All Levels", "Saves all unsaved levels to disk", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(BrowseDocumentation, "Documentation...", "Opens the main documentation page, and allows you to search across all UE4 support sites.", EUserInterfaceActionType::Button, FInputChord(EKeys::F1));

	static const FText FeatureLevelToolTips[ERHIFeatureLevel::Num] =
	{
		NSLOCTEXT("LevelEditorCommands", "FeatureLevelPreviewTooltip_ES2", "OpenGLES 2"),
		NSLOCTEXT("LevelEditorCommands", "FeatureLevelPreviewTooltip_ES3", "OpenGLES 3.1, Metal"),
		NSLOCTEXT("LevelEditorCommands", "FeatureLevelPreviewTooltip_SM4", "DirectX 10, OpenGL 3.3+"),
		NSLOCTEXT("LevelEditorCommands", "FeatureLevelPreviewTooltip_SM5", "DirectX 11, OpenGL 4.3+, PS4, XB1"),
	};

	static const FText FeatureLevelLabels[ERHIFeatureLevel::Num] =
	{
		NSLOCTEXT("LevelEditorCommands", "FeatureLevelPreviewType_ES2", "Mobile / HTML5"),
		NSLOCTEXT("LevelEditorCommands", "FeatureLevelPreviewType_ES31", "High-End Mobile / Metal"),
		NSLOCTEXT("LevelEditorCommands", "FeatureLevelPreviewType_SM4", "Shader Model 4"),
		NSLOCTEXT("LevelEditorCommands", "FeatureLevelPreviewType_SM5", "Shader Model 5"),
	};

	for (int32 i = 0; i < ERHIFeatureLevel::Num; ++i)
	{
		FName Name;
		GetFeatureLevelName((ERHIFeatureLevel::Type)i, Name);

		FeatureLevelPreview[i] =
			FUICommandInfoDecl(
				this->AsShared(),
				Name,
				FeatureLevelLabels[i],
				FeatureLevelToolTips[i])
			.UserInterfaceType(EUserInterfaceActionType::RadioButton)
			.DefaultChord(FInputChord());
	}

}

PRAGMA_ENABLE_OPTIMIZATION

#undef LOCTEXT_NAMESPACE
