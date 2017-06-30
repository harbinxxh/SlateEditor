// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "VRSTopmostWindow.h"
#include "VRSWidgetTopmostPanel.generated.h"


/**
 * 
 */
UCLASS()
class SLATEEDITOR_API UVRSWidgetTopmostPanel : public UUserWidget
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

	UTextBlock* TextBlock_Content;
	UButton*	BTN_OK;
	UButton*	BTN_Cancel;
	UCircularThrobber* CircularThrobber;
};
