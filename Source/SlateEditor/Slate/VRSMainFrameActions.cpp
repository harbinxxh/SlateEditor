// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "SlateEditor/SlateEditor.h"
#include "VRSMainFrameActions.h"


#define LOCTEXT_NAMESPACE "VRSMainFrameActions"

TSharedRef< FUICommandList > FVRSMainFrameCommands::ActionList( new FUICommandList() );

FVRSMainFrameCommands::FVRSMainFrameCommands()
	: TCommands<FVRSMainFrameCommands>(
		TEXT("MainFrame"), // Context name for fast lookup
		LOCTEXT( "MainFrame", "Main Frame" ), // Localized context name for displaying
		NAME_None,	 // No parent context
		FName("EditorStyle")/*FVRSEditorStyle::GetStyleSetName()*/ /*FEditorStyle::GetStyleSetName()*/ 
		), // Icon Style Set
	  ToggleFullscreenConsoleCommand(
		TEXT( "MainFrame.ToggleFullscreen" ),
		TEXT( "Toggles the editor between \"full screen\" mode and \"normal\" mode.  In full screen mode, the task bar and window title area are hidden." ),
		FConsoleCommandDelegate::CreateStatic( &FVRSMainFrameActionCallbacks::ToggleFullscreen_Execute ))
{ }

void FVRSMainFrameCommands::RegisterCommands()
{
	// FileLoadAndSave
	UI_COMMAND( File_SaveHome, "保存户型", "", EUserInterfaceActionType::Button, FInputChord( EModifierKey::Control, EKeys::S ) );
	ActionList->MapAction( File_SaveHome, FExecuteAction::CreateStatic( &FVRSMainFrameActionCallbacks::OnFileSaveHome ));

	UI_COMMAND( File_LoadImage, "导入底图", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction( File_LoadImage, FExecuteAction::CreateStatic( &FVRSMainFrameActionCallbacks::OnFileLoadImage ));

	UI_COMMAND( File_Clean, "清空", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction( File_Clean, FExecuteAction::CreateStatic( &FVRSMainFrameActionCallbacks::OnFileClean ) );

	UI_COMMAND( File_Close, "关闭", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction( File_Close, FExecuteAction::CreateStatic( &FVRSMainFrameActionCallbacks::OnFileClose) );


	// EditMenu
	UI_COMMAND( Edit_Translate, "移动", "", EUserInterfaceActionType::Button, FInputChord( EKeys::One) );
	ActionList->MapAction(Edit_Translate, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnEditTranslate));

	UI_COMMAND(Edit_Rotate, "旋转", "", EUserInterfaceActionType::Button, FInputChord( EKeys::Two ) );
	ActionList->MapAction(Edit_Rotate, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnEditRotate));

	UI_COMMAND(Edit_Scale, "缩放", "", EUserInterfaceActionType::Button, FInputChord( EKeys::Three ) );
	ActionList->MapAction(Edit_Scale, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnEditScale));

	UI_COMMAND(Edit_Clone, "复制品", "", EUserInterfaceActionType::Button, FInputChord( EModifierKey::Control, EKeys::W ) );
	ActionList->MapAction(Edit_Clone, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnEditClone));

	UI_COMMAND(Edit_Delete, "删除", "", EUserInterfaceActionType::Button, FInputChord( EKeys::Delete ) );
	ActionList->MapAction(Edit_Delete, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnEditDelete));

	UI_COMMAND(Edit_SnapFloor, "落地", "", EUserInterfaceActionType::Button, FInputChord( EKeys::End ) );
	ActionList->MapAction(Edit_SnapFloor, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnEditSnapFloor));

	UI_COMMAND(Edit_MirrorX, "镜像X", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Edit_MirrorX, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnEditMirrorX));

	UI_COMMAND(Edit_MirrorY, "镜像Y", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Edit_MirrorY, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnEditMirrorY));

	UI_COMMAND(Edit_Detail, "详情", "", EUserInterfaceActionType::Button, FInputChord( EKeys::Home ) );
	ActionList->MapAction(Edit_Detail, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnEditDetail));

	UI_COMMAND(Edit_Undo, "撤销一步", "", EUserInterfaceActionType::Button, FInputChord( EModifierKey::Control, EKeys::Z ) );
	ActionList->MapAction(Edit_Undo, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnEditUndo));

	UI_COMMAND(Edit_Copy, "拷贝", "", EUserInterfaceActionType::Button, FInputChord(EModifierKey::Control, EKeys::C));
	ActionList->MapAction(Edit_Copy, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnEditCopy));

	UI_COMMAND(Edit_Paste, "粘贴", "", EUserInterfaceActionType::Button, FInputChord(EModifierKey::Control, EKeys::V));
	ActionList->MapAction(Edit_Paste, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnEditPaste));


	// ViewMenu
	UI_COMMAND(View_Perspective, "透视", "", EUserInterfaceActionType::Button, FInputChord( EKeys::N ));
	ActionList->MapAction(View_Perspective, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnViewPerspective));

	UI_COMMAND(View_Top, "顶视", "", EUserInterfaceActionType::Button, FInputChord( EKeys::T ) );
	ActionList->MapAction(View_Top, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnViewTop));

	UI_COMMAND(View_Round, "环绕", "", EUserInterfaceActionType::Button, FInputChord( EKeys::P ) );
	ActionList->MapAction(View_Round, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnViewRound));


	// GroupMenu
	UI_COMMAND(Group_Group, "成组", "", EUserInterfaceActionType::Button, FInputChord( EModifierKey::Control, EKeys::G ));
	ActionList->MapAction(Group_Group, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnGroup));

	UI_COMMAND(Group_Ungroup, "解组", "", EUserInterfaceActionType::Button, FInputChord( EModifierKey::Control | EModifierKey::Shift, EKeys::G ) );
	ActionList->MapAction(Group_Ungroup, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnUngroup));

	UI_COMMAND(Group_SaveGroup, "存组", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Group_SaveGroup, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnSaveGroup));

	UI_COMMAND(Group_SaveToSoftPackage, "存套餐", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Group_SaveToSoftPackage, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnSaveToSoftPackage));


	// PlanMenu
	UI_COMMAND(Plan_Receive, "接收方案", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Plan_Receive, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnPlanReceive));

	UI_COMMAND(Plan_Private, "我的设计", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Plan_Private, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnPlanPrivate));

	UI_COMMAND(Plan_Public, "整屋方案", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Plan_Public, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnPlanPublic));


	// RenderMenu
	UI_COMMAND(Render_Screenshot2K, "效果图", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Render_Screenshot2K, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnRenderScreenshot2K));

	UI_COMMAND(Render_SinglePanorama, "生成单张全景图", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Render_SinglePanorama, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnRenderSinglePanorama));

	UI_COMMAND(Render_MutiPanoramas, "生成全屋全景图", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Render_MutiPanoramas, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnRenderMutiPanoramas));

	
	// QualityMenu
	UI_COMMAND(Quality_High, "高画质", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Quality_High, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnQualityHigh));

	UI_COMMAND(Quality_Medium, "中画质", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Quality_Medium, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnQualityMedium));

	UI_COMMAND(Quality_Low, "低画质", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Quality_Low, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnQualityLow));

	// HelpMenu
	UI_COMMAND(Help_Online, "在线客服", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Help_Online, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnHelpOnline));

	UI_COMMAND(Help_Website, "公司官网", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Help_Website, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnHelpWebsite));

	UI_COMMAND(Help_HelpPanel, "按键控制", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Help_HelpPanel, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnHelpHelpPanel));

	UI_COMMAND(Help_Tutorials, "视频教学", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Help_Tutorials, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnHelpTutorials));

	UI_COMMAND(Help_MessageList, "公告板", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Help_MessageList, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnHelpMessageList));

	UI_COMMAND(Help_VirtualJoystick, "虚拟摇杆", "", EUserInterfaceActionType::Button, FInputChord());
	ActionList->MapAction(Help_VirtualJoystick, FExecuteAction::CreateStatic(&FVRSMainFrameActionCallbacks::OnHelpVirtualJoystick));


	// ManagementMenu
	UI_COMMAND( Management_Backstage, "管理后台", "", EUserInterfaceActionType::Button, FInputChord() );
	ActionList->MapAction( Management_Backstage, FExecuteAction::CreateStatic( &FVRSMainFrameActionCallbacks::OnManagementBackstage ));
}


// FileMenu

void FVRSMainFrameActionCallbacks::OnFileSaveHome()
{
	UE_LOG(LogTemp, Warning, TEXT("OnSaveHome()"));
}


void FVRSMainFrameActionCallbacks::OnFileLoadImage()
{
	UE_LOG(LogTemp, Warning, TEXT("OnLoadImage()"));
}


void FVRSMainFrameActionCallbacks::OnFileClean()
{
	UE_LOG(LogTemp, Warning, TEXT("OnClean()"));
}


void FVRSMainFrameActionCallbacks::OnFileClose()
{
	UE_LOG(LogTemp, Warning, TEXT("OnClose()"));
}



// EditMenu

void FVRSMainFrameActionCallbacks::OnEditTranslate()
{

}


void FVRSMainFrameActionCallbacks::OnEditRotate()
{

}


void FVRSMainFrameActionCallbacks::OnEditScale()
{

}


void FVRSMainFrameActionCallbacks::OnEditClone()
{

}


void FVRSMainFrameActionCallbacks::OnEditDelete()
{

}


void FVRSMainFrameActionCallbacks::OnEditSnapFloor()
{

}


void FVRSMainFrameActionCallbacks::OnEditMirrorX()
{

}


void FVRSMainFrameActionCallbacks::OnEditMirrorY()
{

}


void FVRSMainFrameActionCallbacks::OnEditDetail()
{

}


void FVRSMainFrameActionCallbacks::OnEditUndo()
{

}


void FVRSMainFrameActionCallbacks::OnEditCopy()
{

}


void FVRSMainFrameActionCallbacks::OnEditPaste()
{

}

void FVRSMainFrameActionCallbacks::OnViewPerspective()
{

}


void FVRSMainFrameActionCallbacks::OnViewTop()
{

}


void FVRSMainFrameActionCallbacks::OnViewRound()
{

}


void FVRSMainFrameActionCallbacks::OnGroup()
{

}


void FVRSMainFrameActionCallbacks::OnUngroup()
{

}


void FVRSMainFrameActionCallbacks::OnSaveGroup()
{

}


void FVRSMainFrameActionCallbacks::OnSaveToSoftPackage()
{

}


void FVRSMainFrameActionCallbacks::OnPlanReceive()
{

}


void FVRSMainFrameActionCallbacks::OnPlanPrivate()
{

}


void FVRSMainFrameActionCallbacks::OnPlanPublic()
{

}


void FVRSMainFrameActionCallbacks::OnRenderScreenshot2K()
{

}


void FVRSMainFrameActionCallbacks::OnRenderSinglePanorama()
{

}


void FVRSMainFrameActionCallbacks::OnRenderMutiPanoramas()
{

}


void FVRSMainFrameActionCallbacks::OnQualityHigh()
{

}


void FVRSMainFrameActionCallbacks::OnQualityMedium()
{

}


void FVRSMainFrameActionCallbacks::OnQualityLow()
{

}


void FVRSMainFrameActionCallbacks::OnHelpOnline()
{

}


void FVRSMainFrameActionCallbacks::OnHelpWebsite()
{

}


void FVRSMainFrameActionCallbacks::OnHelpHelpPanel()
{

}


void FVRSMainFrameActionCallbacks::OnHelpTutorials()
{

}


void FVRSMainFrameActionCallbacks::OnHelpMessageList()
{

}


void FVRSMainFrameActionCallbacks::OnHelpVirtualJoystick()
{

}


void FVRSMainFrameActionCallbacks::OnManagementBackstage()
{

}


void FVRSMainFrameActionCallbacks::ToggleFullscreen_Execute()
{
}


#undef LOCTEXT_NAMESPACE
