// Fill out your copyright notice in the Description page of Project Settings.

#include "SlateEditor.h"
#include "VRSWidgetTopmostPanel.h"




void UVRSWidgetTopmostPanel::WidgetConstruct(
	UTextBlock* _TextBlock_Content,
	UButton* _BTN_OK,
	UButton* _BTN_Cancel,
	UCircularThrobber* _CircularThrobber_Loading
)
{
	TextBlock_Content = _TextBlock_Content;
	BTN_OK = _BTN_OK;
	BTN_Cancel = _BTN_Cancel;
	CircularThrobber = _CircularThrobber_Loading;
}

void UVRSWidgetTopmostPanel::Show(ETopmostWindow::Type & _Type)
{
	HideAll();

	if (_Type == ETopmostWindow::Type::TW_OK)
	{
		BTN_OK->SetVisibility(ESlateVisibility::Visible);
	}
	else if (_Type == ETopmostWindow::Type::TW_CANCEL)
	{
		BTN_Cancel->SetVisibility(ESlateVisibility::Visible);
	}
	else if (_Type == ETopmostWindow::Type::TW_OKCANCEL)
	{
		BTN_OK->SetVisibility(ESlateVisibility::Visible);
		BTN_Cancel->SetVisibility(ESlateVisibility::Visible);
	}
	else if (_Type == ETopmostWindow::Type::TW_OKROLLING)
	{
		BTN_OK->SetVisibility(ESlateVisibility::Visible);
		CircularThrobber->SetVisibility(ESlateVisibility::Visible);
	}
	else if (_Type == ETopmostWindow::Type::TW_CANCELROLLING)
	{
		BTN_Cancel->SetVisibility(ESlateVisibility::Visible);
		CircularThrobber->SetVisibility(ESlateVisibility::Visible);
	}
	else if (_Type == ETopmostWindow::Type::TW_OKCANCELROLLING)
	{
		BTN_OK->SetVisibility(ESlateVisibility::Visible);
		BTN_Cancel->SetVisibility(ESlateVisibility::Visible);
		CircularThrobber->SetVisibility(ESlateVisibility::Visible);
	}
}

void UVRSWidgetTopmostPanel::HideAll()
{
	//TextBlock_Content->SetVisibility(ESlateVisibility::Hidden);
	BTN_OK->SetVisibility(ESlateVisibility::Collapsed);
	BTN_Cancel->SetVisibility(ESlateVisibility::Collapsed);
	CircularThrobber->SetVisibility(ESlateVisibility::Collapsed);
}
