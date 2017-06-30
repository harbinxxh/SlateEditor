// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "SlateEditor/SlateEditor.h"
#include "VRSMainMenu.h"
#include "VRSMainFrameActions.h"


#define LOCTEXT_NAMESPACE "VRSMainFileMenu"

void FVRSMainMenu::FillFileMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender)
{
	MenuBuilder.BeginSection("FileLoadAndSave", LOCTEXT("LoadSandSaveHeading", "���ز�����"));
	{
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().File_SaveHome, "SaveHome");
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().File_LoadImage, "LoadImage");
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().File_Clean, "Clean");
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().File_Close, "Close");
	}
	MenuBuilder.EndSection();
}

#undef LOCTEXT_NAMESPACE



#define LOCTEXT_NAMESPACE "VRSMainEditMenu"
void FVRSMainMenu::FillEditMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender)
{
	MenuBuilder.BeginSection("EditOperation", LOCTEXT("OperationHeading", "�༭������"));
	{
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_Translate);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_Rotate);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_Scale);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_Clone);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_Delete);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_SnapFloor);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_MirrorX);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_MirrorY);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_Detail);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_Undo);
	}
	MenuBuilder.EndSection();
}
#undef LOCTEXT_NAMESPACE



#define LOCTEXT_NAMESPACE "VRSMainViewMenu"
void FVRSMainMenu::FillViewMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender)
{
	MenuBuilder.BeginSection("Viewport", LOCTEXT("ViewportHeading", "�ӿ�"));
	{
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().View_Perspective);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().View_Top);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().View_Round);
	}
	MenuBuilder.EndSection();
}
#undef LOCTEXT_NAMESPACE



#define LOCTEXT_NAMESPACE "VRSMainGroupMenu"
void FVRSMainMenu::FillGroupMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender)
{
	MenuBuilder.BeginSection("Group", LOCTEXT("Group", "��"));
	{
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Group_Group);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Group_Ungroup);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Group_SaveGroup);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Group_SaveToSoftPackage);
	}
	MenuBuilder.EndSection();
}
#undef LOCTEXT_NAMESPACE



#define LOCTEXT_NAMESPACE "VRSMainPlanMenu"
void FVRSMainMenu::FillPlanMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender)
{
	MenuBuilder.BeginSection("Plan", LOCTEXT("Group", "����"));
	{
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Plan_Receive);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Plan_Private);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Plan_Public);
	}
	MenuBuilder.EndSection();
}
#undef LOCTEXT_NAMESPACE



#define LOCTEXT_NAMESPACE "VRSMainRenderMenu"
void FVRSMainMenu::FillRenderMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender)
{
	MenuBuilder.BeginSection("Render", LOCTEXT("Render", "��Ⱦ"));
	{
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Render_Screenshot2K);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Render_SinglePanorama);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Render_MutiPanoramas);
	}
	MenuBuilder.EndSection();
}
#undef LOCTEXT_NAMESPACE



#define LOCTEXT_NAMESPACE "VRSMainQualityMenu"
void FVRSMainMenu::FillQualityMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender)
{
	MenuBuilder.BeginSection("Quality", LOCTEXT("Render", "���ʼ���"));
	{
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Quality_High);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Quality_Medium);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Quality_Low);
	}
	MenuBuilder.EndSection();
}
#undef LOCTEXT_NAMESPACE



#define LOCTEXT_NAMESPACE "VRSMainHelpMenu"
void FVRSMainMenu::FillHelpMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender)
{
	MenuBuilder.BeginSection("Help", LOCTEXT("Help", "����"));
	{
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Help_Online);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Help_Website);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Help_HelpPanel);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Help_Tutorials);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Help_MessageList);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Help_VirtualJoystick);

	}
	MenuBuilder.EndSection();
}
#undef LOCTEXT_NAMESPACE


#define LOCTEXT_NAMESPACE "VRSMainManagementMenu"
void FVRSMainMenu::FillManagementMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender)
{
	MenuBuilder.BeginSection("Management", LOCTEXT("Management", "�����̨"));
	{
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Management_Backstage);
	}
	MenuBuilder.EndSection();
}
#undef LOCTEXT_NAMESPACE


#define LOCTEXT_NAMESPACE "VRSMainFileMenu"

TSharedRef<SWidget> FVRSMainMenu::MakeMainMenu(const TSharedRef<FExtender> Extender)
{
#define LOCTEXT_NAMESPACE "VRSMainMenu"

	FMenuBarBuilder MenuBuilder(FVRSMainFrameCommands::ActionList, Extender);
	{
		// File
		MenuBuilder.AddPullDownMenu(
			LOCTEXT("FileMenu", "�ļ�"),
			LOCTEXT("FileMenu_ToolTip", "Open the file menu"),
			FNewMenuDelegate::CreateStatic(&FVRSMainMenu::FillFileMenu, Extender),
			"File",
			FName(TEXT("FileMenu"))
		);

		// Edit
		MenuBuilder.AddPullDownMenu(
			LOCTEXT("EditMenu", "�༭"),
			LOCTEXT("EditMenu_ToolTip", "Open the edit menu"),
			FNewMenuDelegate::CreateStatic(&FVRSMainMenu::FillEditMenu, Extender),
			"Edit"
			,
			FName(TEXT("EditMenu"))
		);

		// View
		MenuBuilder.AddPullDownMenu(
			LOCTEXT("ViewMenu", "��ͼ"),
			LOCTEXT("ViewMenu_ToolTip", "Open the View menu"),
			FNewMenuDelegate::CreateStatic(&FVRSMainMenu::FillViewMenu, Extender),
			"View",
			FName(TEXT("ViewMenu"))
		);

		// Group
		MenuBuilder.AddPullDownMenu(
			LOCTEXT("GroupMenu", "��"),
			LOCTEXT("GroupMenu_ToolTip", "Open the Group menu"),
			FNewMenuDelegate::CreateStatic(&FVRSMainMenu::FillGroupMenu, Extender),
			"Group",
			FName(TEXT("GroupMenu"))
		);

		// Plan
		MenuBuilder.AddPullDownMenu(
			LOCTEXT("PlanMenu", "����"),
			LOCTEXT("PlanMenu_ToolTip", "Open the Plan menu"),
			FNewMenuDelegate::CreateStatic(&FVRSMainMenu::FillPlanMenu, Extender),
			"Plan",
			FName(TEXT("PlanMenu"))
		);

		// Render
		MenuBuilder.AddPullDownMenu(
			LOCTEXT("RenderMenu", "��Ⱦ"),
			LOCTEXT("RenderMenu_ToolTip", "Open the Render menu"),
			FNewMenuDelegate::CreateStatic(&FVRSMainMenu::FillRenderMenu, Extender),
			"Render",
			FName(TEXT("RenderMenu"))
		);

		// Quality
		MenuBuilder.AddPullDownMenu(
			LOCTEXT("QualityMenu", "����"),
			LOCTEXT("QualityMenu_ToolTip", "Open the Quality menu"),
			FNewMenuDelegate::CreateStatic(&FVRSMainMenu::FillQualityMenu, Extender),
			"Quality",
			FName(TEXT("QualityMenu"))
		);

		// Help
		MenuBuilder.AddPullDownMenu(
			LOCTEXT("HelpMenu", "����"),
			LOCTEXT("HelpMenu_ToolTip", "Open the help menu"),
			FNewMenuDelegate::CreateStatic(&FVRSMainMenu::FillHelpMenu, Extender),
			"Help",
			FName(TEXT("HelpMenu"))
		);

		// Management
		MenuBuilder.AddPullDownMenu(
			LOCTEXT("ManagementMenu", "ϵͳ����"),
			LOCTEXT("ManagementMenu_ToolTip", "Open the Management menu"),
			FNewMenuDelegate::CreateStatic(&FVRSMainMenu::FillManagementMenu, Extender),
			"Management"
			,
			FName(TEXT("ManagementMenu"))
		);
	}

	// Create the menu bar!
	TSharedRef<SWidget> MenuBarWidget = MenuBuilder.MakeWidget();

	return MenuBarWidget;
}

#undef LOCTEXT_NAMESPACE