// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "VRSTopmostWindow.h"
#include "UMGConfirm.generated.h"


/**
 * 
 */
UCLASS()
class SLATEEDITOR_API UUMGConfirm : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "WidgetTopmostPanel")
	void WidgetConstruct(
		UTextBlock* _TextBlock_Content,
		UButton*	_BTN_OK,
		UButton*	_BTN_Cancel,
		UCircularThrobber* _CircularThrobber_Loading
	);
	
	void Show(ETopmostWindow::Type & _Type);
	void HideAll();
	void SetConfirmText(FString & _Text);

	UTextBlock* TextBlock_Content;
	UButton*	BTN_OK;
	UButton*	BTN_Cancel;
	UCircularThrobber* CircularThrobber;
};
