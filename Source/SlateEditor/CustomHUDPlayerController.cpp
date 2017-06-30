// Fill out your copyright notice in the Description page of Project Settings.

#include "SlateEditor.h"
#include "SlateBasics.h"
#include "SButton.h"
#include "STextBlock.h"
#include "CustomHUDPlayerController.h"
#include "VRSLevelEditor.h"

#include "VRSLevelEditorMenu.h"
#include "VRSMainFrameActions.h"


#include "VRSMainMenu.h"
#include "SVRSTutorialButton.h"
#include "SVRSTopmostWindow.h"
#include "VRSTopmostWindow.h"

void ACustomHUDPlayerController::BeginPlay()
{
	Super::BeginPlay();

	/////// �����˵��� Begin
	//FVRSMainFrameCommands::Register();
	//TSharedRef< FExtender > Extenders(new FExtender());
	//TSharedRef< SWidget > MenuBarWidget = FVRSMainMenu::MakeMainMenu(Extenders);
	////// �����˵��� End

	GTopmostWindow->Init();

	FString StringOK = TEXT("OK �������Ǿ��ܵĴ����ʣ���һ����˵���仹�иĽ�����ء�");
	FString StringCancel = TEXT("Cancel �������Ǿ��ܵĴ����ʣ���һ����˵���仹�иĽ�����ء���Ӽ����������.");
	FString StringOKCancel = TEXT("OKCancel �������Ǿ��ܵĴ����ʣ���һ����˵���仹�иĽ�����ء���Ӽ����������.");
	FString StringOKROLLING = TEXT("StringOKROLLING �������Ǿ��ܵĴ����ʣ���һ����˵���仹�иĽ�����ء���Ӽ����������.");
	FString StringCANCELROLLING = TEXT("StringCANCELROLLING �������Ǿ��ܵĴ����ʣ���һ����˵���仹�иĽ�����ء���Ӽ����������.");
	FString StringOKCANCELROLLING = TEXT("StringOKCANCELROLLING �������Ǿ��ܵĴ����ʣ���һ����˵���仹�иĽ�����ء���Ӽ����������.");


	TSharedRef<SVerticalBox> widget = SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			//MenuBarWidget					// ���˵�������
			//SNew(SVRSTutorialButton)		// �Ҽ��˵�������
			//SNew(SVRSTopmostWindow)			// ���Զ��㴰��
			//SNew(SButton).OnClicked(this, &ACustomHUDPlayerController::OnOk)
			SNew(SButton)
			.OnClicked(FOnClicked::CreateUObject(this, &ACustomHUDPlayerController::OnOk, ETopmostWindow::TW_OK, StringOK))
			.Content()
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("OK")))
			]
		]
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.OnClicked(FOnClicked::CreateUObject(this, &ACustomHUDPlayerController::OnCancel, ETopmostWindow::TW_CANCEL, StringCancel))
			.Content()
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("CANCEL")))
			]
		]
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.OnClicked(FOnClicked::CreateUObject(this, &ACustomHUDPlayerController::OnOkCancel, ETopmostWindow::TW_OKCANCEL, StringOKCancel))
			.Content()
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("OKCANCEL")))
			]
		]
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.OnClicked(FOnClicked::CreateUObject(this, &ACustomHUDPlayerController::OnOKRolling, ETopmostWindow::TW_OKROLLING, StringOKROLLING))
			.Content()
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("OKROLLING")))
			]
		]
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.OnClicked(FOnClicked::CreateUObject(this, &ACustomHUDPlayerController::OnCancelRolling, ETopmostWindow::TW_CANCELROLLING, StringCANCELROLLING))
			.Content()
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("CANCELROLLING")))
			]
		]
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SButton)
			.OnClicked(FOnClicked::CreateUObject(this, &ACustomHUDPlayerController::OnOKCancelRolling, ETopmostWindow::TW_OKCANCELROLLING, StringOKCANCELROLLING))
			.Content()
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("OKCANCELROLLING")))
			]
		]
	;


	GEngine->GameViewport->AddViewportWidgetForPlayer(GetLocalPlayer(), widget, 1);


	// ���Ե�������
	
	//TSharedRef<SWindow> TopmostWindow = SNew(SWindow)
	//	.Title(FText::FromString(TEXT("12345")))
	//	.SizingRule(ESizingRule::UserSized)
	//	.ClientSize(FVector2D(600, 400))
	//	.AutoCenter(EAutoCenter::PreferredWorkArea)
	//	.SupportsMinimize(false)
	//	.SupportsMaximize(false);

	//TopmostWindow->SetContent(SNew(SVRSTopmostWindow));

	//FSlateApplication::Get().AddWindow(TopmostWindow);
}

FReply ACustomHUDPlayerController::OnOk(ETopmostWindow::Type _Type, FString _String)
{
	GTopmostWindow->SetConfirmText(_String);
	GTopmostWindow->ShowWindow(_Type);
	return FReply::Handled();
}

FReply ACustomHUDPlayerController::OnCancel(ETopmostWindow::Type _Type, FString _String)
{
	GTopmostWindow->SetConfirmText(_String);
	GTopmostWindow->ShowWindow(_Type);
	return FReply::Handled();
}

FReply ACustomHUDPlayerController::OnOkCancel(ETopmostWindow::Type _Type, FString _String)
{
	GTopmostWindow->SetConfirmText(_String);
	GTopmostWindow->ShowWindow(_Type);
	return FReply::Handled();
}

FReply ACustomHUDPlayerController::OnOKRolling(ETopmostWindow::Type _Type, FString _String)
{
	GTopmostWindow->SetConfirmText(_String);
	GTopmostWindow->ShowWindow(_Type);
	return FReply::Handled();
}

FReply ACustomHUDPlayerController::OnCancelRolling(ETopmostWindow::Type _Type, FString _String)
{
	GTopmostWindow->SetConfirmText(_String);
	GTopmostWindow->ShowWindow(_Type);
	return FReply::Handled();
}

FReply ACustomHUDPlayerController::OnOKCancelRolling(ETopmostWindow::Type _Type, FString _String)
{
	GTopmostWindow->SetConfirmText(_String);
	GTopmostWindow->ShowWindow(_Type);
	return FReply::Handled();
}
