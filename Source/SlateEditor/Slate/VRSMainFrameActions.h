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
	TSharedPtr< FUICommandInfo > File_SaveHome;		// 保存户型
	TSharedPtr< FUICommandInfo > File_LoadImage;	// 加载地图
	TSharedPtr< FUICommandInfo > File_Clean;		// 清空
	TSharedPtr< FUICommandInfo > File_Close;		// 关闭

	// EditMenu
	TSharedPtr< FUICommandInfo > Edit_Translate;	// 移动
	TSharedPtr< FUICommandInfo > Edit_Rotate;		// 旋转
	TSharedPtr< FUICommandInfo > Edit_Scale;		// 缩放
	TSharedPtr< FUICommandInfo > Edit_Clone;		// 克隆
	TSharedPtr< FUICommandInfo > Edit_Delete;		// 删除
	TSharedPtr< FUICommandInfo > Edit_SnapFloor;	// 落地
	TSharedPtr< FUICommandInfo > Edit_MirrorX;		// 镜像X
	TSharedPtr< FUICommandInfo > Edit_MirrorY;		// 镜像Y
	TSharedPtr< FUICommandInfo > Edit_Detail;		// 详情
	TSharedPtr< FUICommandInfo > Edit_Undo;			// 撤销一步
	TSharedPtr< FUICommandInfo > Edit_Copy;			// 拷贝
	TSharedPtr< FUICommandInfo > Edit_Paste;		// 粘贴
  
	// ViewMenu
	TSharedPtr< FUICommandInfo > View_Perspective;	// 透视
	TSharedPtr< FUICommandInfo > View_Top;			// 顶视
	TSharedPtr< FUICommandInfo > View_Round;		// 环绕

	// GroupMenu
	TSharedPtr< FUICommandInfo > Group_Group;		// 成组
	TSharedPtr< FUICommandInfo > Group_Ungroup;		// 解组
	TSharedPtr< FUICommandInfo > Group_SaveGroup;	// 存组
	TSharedPtr< FUICommandInfo > Group_SaveToSoftPackage;// 存套餐

	// PlanMenu;
	TSharedPtr< FUICommandInfo > Plan_Receive;		// 接收方案
	TSharedPtr< FUICommandInfo > Plan_Private;		// 我的设计
	TSharedPtr< FUICommandInfo > Plan_Public;		// 整屋方案

	// RenderMenu
	TSharedPtr< FUICommandInfo > Render_Screenshot2K; // 效果图
	TSharedPtr< FUICommandInfo > Render_SinglePanorama;// 生成单张全景图
	TSharedPtr< FUICommandInfo > Render_MutiPanoramas;// 生成全屋全景图"


	// QualityMenu
	TSharedPtr< FUICommandInfo > Quality_High;		// 高画质
	TSharedPtr< FUICommandInfo > Quality_Medium;	// 中画质
	TSharedPtr< FUICommandInfo > Quality_Low;		// 低画质


	// HelpMenu
	TSharedPtr< FUICommandInfo > Help_Online;		// 在线客服
	TSharedPtr< FUICommandInfo > Help_Website;		// 公司官网
	TSharedPtr< FUICommandInfo > Help_HelpPanel;	// 按键控制
	TSharedPtr< FUICommandInfo > Help_Tutorials;	// 视频教学
	TSharedPtr< FUICommandInfo > Help_MessageList;	// 公告板
	TSharedPtr< FUICommandInfo > Help_VirtualJoystick;// 虚拟摇杆

	// ManagementMenu
	TSharedPtr< FUICommandInfo > Management_Backstage;// 管理后台

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
	static void OnFileSaveHome();	// 保存户型
	static void OnFileLoadImage();	// 加载地图
	static void OnFileClean();		// 清空
	static void OnFileClose();		// 关闭

	// EditMenu
	static void OnEditTranslate();	// 移动
	static void OnEditRotate();		// 旋转
	static void OnEditScale();		// 缩放
	static void OnEditClone();		// 克隆
	static void OnEditDelete();		// 删除
	static void OnEditSnapFloor();	// 落地
	static void OnEditMirrorX();	// 镜像X
	static void OnEditMirrorY();	// 镜像Y
	static void OnEditDetail();		// 详情
	static void OnEditUndo();		// 撤销一步
	static void OnEditCopy();		// 拷贝
	static void OnEditPaste();		// 粘贴

	// ViewMenu
	static void OnViewPerspective();// 透视
	static void OnViewTop();		// 顶视
	static void OnViewRound();		// 环绕

	// GroupMenu
	static void OnGroup();			// 成组
	static void OnUngroup();		// 解组
	static void OnSaveGroup();		// 存组
	static void OnSaveToSoftPackage();// 存套餐

	// PlanMenu
	static void OnPlanReceive();	// 接收方案
	static void OnPlanPrivate();	// 我的设计
	static void OnPlanPublic();		// 整屋方案

	// RenderMenu
	static void OnRenderScreenshot2K(); // 效果图
	static void OnRenderSinglePanorama();// 生成单张全景图
	static void OnRenderMutiPanoramas();// 生成全屋全景图"

	// QualityMenu
	static void OnQualityHigh();		// 高画质
	static void OnQualityMedium();		// 中画质
	static void OnQualityLow();			// 低画质

	// HelpMenu
	static void OnHelpOnline();			// 在线客服
	static void OnHelpWebsite();		// 公司官网
	static void OnHelpHelpPanel();		// 按键控制
	static void OnHelpTutorials();		// 视频教学
	static void OnHelpMessageList();	// 公告板
	static void OnHelpVirtualJoystick();// 虚拟摇杆


	// ManagementMenu
	static void OnManagementBackstage();// 管理后台

	/** Toggle the level editor's fullscreen mode */
	static void ToggleFullscreen_Execute();

};


#endif		// __VRSMainFrameActions_h__
