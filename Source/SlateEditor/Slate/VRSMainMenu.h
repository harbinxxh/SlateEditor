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

	// �༭�˵�
	static void FillEditMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// �ӿڲ˵�
	static void FillViewMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// ��˵�
	static void FillGroupMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// �����˵�
	static void FillPlanMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// ��Ⱦ
	static void FillRenderMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// ����
	static void FillQualityMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// ����
	static void FillHelpMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

	// ϵͳ����
	static void FillManagementMenu(FMenuBuilder& MenuBuilder, const TSharedRef<FExtender> Extender);

};
