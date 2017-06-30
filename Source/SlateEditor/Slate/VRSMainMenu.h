// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

/**
 * Unreal editor main frame Slate widget
 */
class FVRSMainMenu
{
public:

	/**
	 * Static: Creates a widget for the main menu bar.
	 *
	 * @param Extender Extensibility support for the menu.
	 * @return New widget
	 */
	static TSharedRef<SWidget> MakeMainMenu( const TSharedRef<FExtender> Extender );

protected:

	/**
	 * Called to fill the file menu's content.
	 *
	 * @param MenuBuilder The multi-box builder that should be filled with content for this pull-down menu.
	 * @param Extender Extensibility support for this menu.
	 */
	static void FillFileMenu( FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender );

	// 编辑菜单
	static void FillEditMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// 视口菜单
	static void FillViewMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// 组菜单
	static void FillGroupMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// 方案菜单
	static void FillPlanMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// 渲染
	static void FillRenderMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// 画质
	static void FillQualityMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// 帮助
	static void FillHelpMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// 系统管理
	static void FillManagementMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

};
