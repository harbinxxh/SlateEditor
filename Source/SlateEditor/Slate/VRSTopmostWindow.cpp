// Fill out your copyright notice in the Description page of Project Settings.

#include "SlateEditor.h"
#include "VRSTopmostWindow.h"
#include "UMGConfirm.h"

UVRSTopmostWindow * GTopmostWindow = nullptr;

UVRSTopmostWindow::UVRSTopmostWindow()
{
	GTopmostWindow = this;
	UserWidget = nullptr;
	TopmostWindow = nullptr;
}

void UVRSTopmostWindow::Init()
{
	TSubclassOf<UUMGConfirm> WidgetClass = LoadClass<UUMGConfirm>(nullptr, TEXT("/Game/BP/BP_UMGConfirm.BP_UMGConfirm_C"));
	if (WidgetClass)
	{
		UserWidget = CreateWidget<UUMGConfirm>(GWorld, WidgetClass);
	}

	SAssignNew(TopmostWindow, SWindow)
		.Title(FText::FromString(TEXT("Confirm")))
		.SizingRule(ESizingRule::Autosized)
		.AutoCenter(EAutoCenter::PreferredWorkArea)
		.SupportsMinimize(false)
		.SupportsMaximize(false);

	TopmostWindow->SetContent(UserWidget->TakeWidget());
	FSlateApplication::Get().AddWindow(TopmostWindow.ToSharedRef());
	TopmostWindow->HideWindow();

}

void UVRSTopmostWindow::ShowWindow(ETopmostWindow::Type & _Type)
{
	TopmostWindow->ShowWindow();
	UserWidget->Show(_Type);
}

void UVRSTopmostWindow::HideWindow()
{
	TopmostWindow->HideWindow();
}

void UVRSTopmostWindow::SetConfirmText(FString& _Text)
{
	UserWidget->SetConfirmText(_Text);
}

void UVRSTopmostWindow::Callback_ConfirmOKClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Callback_ConfirmOKClicked()"));
	ConfirmOKClickedDelegate.ExecuteIfBound();
}

void UVRSTopmostWindow::Callback_ConfirmCancelClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Callback_ConfirmCancelClicked()"))
	ConfirmCancelClickedDelegate.ExecuteIfBound();
}
