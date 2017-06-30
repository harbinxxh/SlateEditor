// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "UMG.h"
#include "VRSTopmostWindow.generated.h"

class UUMGConfirm;

UENUM()
namespace ETopmostWindow
{
	enum Type
	{
		TW_OK,
		TW_CANCEL,
		TW_OKCANCEL,
		TW_OKROLLING,
		TW_CANCELROLLING,
		TW_OKCANCELROLLING
	};
}


/**
 * 
 */
UCLASS()
class SLATEEDITOR_API UVRSTopmostWindow : public UObject
{
	GENERATED_BODY()
	
public:
	UVRSTopmostWindow();

	void Init();
	void ShowWindow(ETopmostWindow::Type & _Type);
	void HideWindow();
	void SetConfirmText(FString& _Text);
	
	TSharedPtr<SWindow> TopmostWindow;
	UUMGConfirm* UserWidget;
	
	FSimpleDelegate ConfirmOKClickedDelegate;
	FSimpleDelegate ConfirmCancelClickedDelegate;

	// UMGConfirm
	UFUNCTION()
	void Callback_ConfirmOKClicked();
	UFUNCTION()
	void Callback_ConfirmCancelClicked();

};

extern UVRSTopmostWindow * GTopmostWindow;