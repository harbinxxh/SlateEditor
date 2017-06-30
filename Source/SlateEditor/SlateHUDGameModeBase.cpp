// Fill out your copyright notice in the Description page of Project Settings.

#include "SlateEditor.h"
#include "SlateHUDGameModeBase.h"

#include "CustomHUDPlayerController.h"


ASlateHUDGameModeBase::ASlateHUDGameModeBase():Super()
{
	PlayerControllerClass = ACustomHUDPlayerController::StaticClass();
}
