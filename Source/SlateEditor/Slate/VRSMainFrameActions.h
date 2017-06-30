// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.


#ifndef __VRSMainFrameActions_h__
#define __VRSMainFrameActions_h__

#pragma once

/**
 * Unreal editor main frame actions
 */
class FVRSMainFrameCommands : public TCommands<FVRSMainFrameCommands>
{
public:
	/** FMainFrameCommands constructor */
	FVRSMainFrameCommands();

	/** List of all of the main frame commands */
	static TSharedRef< FUICommandList > ActionList;


	// FileMenu
	TSharedPtr< FUICommandInfo > File_SaveHome;		// ���滧��
	TSharedPtr< FUICommandInfo > File_LoadImage;	// ���ص�ͼ
	TSharedPtr< FUICommandInfo > File_Clean;		// ���
	TSharedPtr< FUICommandInfo > File_Close;		// �ر�

	// EditMenu
	TSharedPtr< FUICommandInfo > Edit_Translate;	// �ƶ�
	TSharedPtr< FUICommandInfo > Edit_Rotate;		// ��ת
	TSharedPtr< FUICommandInfo > Edit_Scale;		// ����
	TSharedPtr< FUICommandInfo > Edit_Clone;		// ��¡
	TSharedPtr< FUICommandInfo > Edit_Delete;		// ɾ��
	TSharedPtr< FUICommandInfo > Edit_SnapFloor;	// ���
	TSharedPtr< FUICommandInfo > Edit_MirrorX;		// ����X
	TSharedPtr< FUICommandInfo > Edit_MirrorY;		// ����Y
	TSharedPtr< FUICommandInfo > Edit_Detail;		// ����
	TSharedPtr< FUICommandInfo > Edit_Undo;			// ����һ��
	TSharedPtr< FUICommandInfo > Edit_Copy;			// ����
	TSharedPtr< FUICommandInfo > Edit_Paste;		// ճ��
  
	// ViewMenu
	TSharedPtr< FUICommandInfo > View_Perspective;	// ͸��
	TSharedPtr< FUICommandInfo > View_Top;			// ����
	TSharedPtr< FUICommandInfo > View_Round;		// ����

	// GroupMenu
	TSharedPtr< FUICommandInfo > Group_Group;		// ����
	TSharedPtr< FUICommandInfo > Group_Ungroup;		// ����
	TSharedPtr< FUICommandInfo > Group_SaveGroup;	// ����
	TSharedPtr< FUICommandInfo > Group_SaveToSoftPackage;// ���ײ�

	// PlanMenu;
	TSharedPtr< FUICommandInfo > Plan_Receive;		// ���շ���
	TSharedPtr< FUICommandInfo > Plan_Private;		// �ҵ����
	TSharedPtr< FUICommandInfo > Plan_Public;		// ���ݷ���

	// RenderMenu
	TSharedPtr< FUICommandInfo > Render_Screenshot2K; // Ч��ͼ
	TSharedPtr< FUICommandInfo > Render_SinglePanorama;// ���ɵ���ȫ��ͼ
	TSharedPtr< FUICommandInfo > Render_MutiPanoramas;// ����ȫ��ȫ��ͼ"


	// QualityMenu
	TSharedPtr< FUICommandInfo > Quality_High;		// �߻���
	TSharedPtr< FUICommandInfo > Quality_Medium;	// �л���
	TSharedPtr< FUICommandInfo > Quality_Low;		// �ͻ���


	// HelpMenu
	TSharedPtr< FUICommandInfo > Help_Online;		// ���߿ͷ�
	TSharedPtr< FUICommandInfo > Help_Website;		// ��˾����
	TSharedPtr< FUICommandInfo > Help_HelpPanel;	// ��������
	TSharedPtr< FUICommandInfo > Help_Tutorials;	// ��Ƶ��ѧ
	TSharedPtr< FUICommandInfo > Help_MessageList;	// �����
	TSharedPtr< FUICommandInfo > Help_VirtualJoystick;// ����ҡ��

	// ManagementMenu
	TSharedPtr< FUICommandInfo > Management_Backstage;// �����̨

	virtual void RegisterCommands() override;

private:

	/** Console command for toggling full screen.  We need this to expose the full screen toggle action to
	    the game UI system for play-in-editor view ports */
	FAutoConsoleCommand ToggleFullscreenConsoleCommand;
};


/**
 * Implementation of various main frame action callback functions
 */
class FVRSMainFrameActionCallbacks
{

public:
	// FileMenu
	static void OnFileSaveHome();	// ���滧��
	static void OnFileLoadImage();	// ���ص�ͼ
	static void OnFileClean();		// ���
	static void OnFileClose();		// �ر�

	// EditMenu
	static void OnEditTranslate();	// �ƶ�
	static void OnEditRotate();		// ��ת
	static void OnEditScale();		// ����
	static void OnEditClone();		// ��¡
	static void OnEditDelete();		// ɾ��
	static void OnEditSnapFloor();	// ���
	static void OnEditMirrorX();	// ����X
	static void OnEditMirrorY();	// ����Y
	static void OnEditDetail();		// ����
	static void OnEditUndo();		// ����һ��
	static void OnEditCopy();		// ����
	static void OnEditPaste();		// ճ��

	// ViewMenu
	static void OnViewPerspective();// ͸��
	static void OnViewTop();		// ����
	static void OnViewRound();		// ����

	// GroupMenu
	static void OnGroup();			// ����
	static void OnUngroup();		// ����
	static void OnSaveGroup();		// ����
	static void OnSaveToSoftPackage();// ���ײ�

	// PlanMenu
	static void OnPlanReceive();	// ���շ���
	static void OnPlanPrivate();	// �ҵ����
	static void OnPlanPublic();		// ���ݷ���

	// RenderMenu
	static void OnRenderScreenshot2K(); // Ч��ͼ
	static void OnRenderSinglePanorama();// ���ɵ���ȫ��ͼ
	static void OnRenderMutiPanoramas();// ����ȫ��ȫ��ͼ"

	// QualityMenu
	static void OnQualityHigh();		// �߻���
	static void OnQualityMedium();		// �л���
	static void OnQualityLow();			// �ͻ���

	// HelpMenu
	static void OnHelpOnline();			// ���߿ͷ�
	static void OnHelpWebsite();		// ��˾����
	static void OnHelpHelpPanel();		// ��������
	static void OnHelpTutorials();		// ��Ƶ��ѧ
	static void OnHelpMessageList();	// �����
	static void OnHelpVirtualJoystick();// ����ҡ��


	// ManagementMenu
	static void OnManagementBackstage();// �����̨

	/** Toggle the level editor's fullscreen mode */
	static void ToggleFullscreen_Execute();

};


#endif		// __VRSMainFrameActions_h__
