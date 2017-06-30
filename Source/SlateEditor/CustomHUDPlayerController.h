// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UMG.h"
#include "GameFramework/PlayerController.h"
#include "VRSTopmostWindow.h"
#include "Runtime/SlateCore/Public/Input/Reply.h"
#include "CustomHUDPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SLATEEDITOR_API ACustomHUDPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
	TSharedPtr<FUICommandList> CommandList;

	FReply OnOk(ETopmostWindow::Type _Type, FString _String);
	FReply OnCancel(ETopmostWindow::Type _Type, FString _String);
	FReply OnOkCancel(ETopmostWindow::Type _Type, FString _String);
	FReply OnOKRolling(ETopmostWindow::Type _Type, FString _String);
	FReply OnCancelRolling(ETopmostWindow::Type _Type, FString _String);
	FReply OnOKCancelRolling(ETopmostWindow::Type _Type, FString _String);

};
