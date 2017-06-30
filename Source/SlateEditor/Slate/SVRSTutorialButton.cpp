// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "SlateEditor.h"
#include "SVRSTutorialButton.h"
#include "VRSMainFrameActions.h"

#define LOCTEXT_NAMESPACE "SVRSTutorialButton"

namespace TutorialButtonConstants
{
	const float MaxPulseOffset = 32.0f;
	const float PulseAnimationLength = 2.0f;
}

void SVRSTutorialButton::Construct(const FArguments& InArgs)
{

	ChildSlot
	[
		SNew(SButton)
		.ContentPadding(0.0f)
		[
			SNew(SBox)
			.WidthOverride(100)
			.HeightOverride(100)
		]
	];
}


static void GetAnimationValues(float InAnimationProgress, float& OutAlphaFactor0, float& OutPulseFactor0, float& OutAlphaFactor1, float& OutPulseFactor1)
{
	InAnimationProgress = FMath::Fmod(InAnimationProgress * 2.0f, 1.0f);

	OutAlphaFactor0 = FMath::Square(1.0f - InAnimationProgress);
	OutPulseFactor0 = 1.0f - FMath::Square(1.0f - InAnimationProgress);

	float OffsetProgress = FMath::Fmod(InAnimationProgress + 0.25f, 1.0f);
	OutAlphaFactor1 = FMath::Square(1.0f - OffsetProgress);
	OutPulseFactor1 = 1.0f - FMath::Square(1.0f - OffsetProgress);
}

int32 SVRSTutorialButton::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyClippingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	LayerId = SCompoundWidget::OnPaint(Args, AllottedGeometry, MyClippingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled) + 1000;

	return LayerId;
}


FReply SVRSTutorialButton::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.GetEffectingButton() == EKeys::RightMouseButton)
	{
		UE_LOG(LogTemp, Warning, TEXT("OnMouseButtonDown::RightMouseButton"));

		const bool bInShouldCloseWindowAfterMenuSelection = true;
		FMenuBuilder MenuBuilder(bInShouldCloseWindowAfterMenuSelection, FVRSMainFrameCommands::ActionList);

		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_Clone);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Group_Group);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Group_Ungroup);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_Copy);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_Paste);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_Delete);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_MirrorX);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_MirrorY);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_SnapFloor);
		MenuBuilder.AddMenuEntry(FVRSMainFrameCommands::Get().Edit_Detail);

		FWidgetPath WidgetPath = MouseEvent.GetEventPath() != nullptr ? *MouseEvent.GetEventPath() : FWidgetPath();

		FSlateApplication::Get().PushMenu(SharedThis(this), WidgetPath, MenuBuilder.MakeWidget(), FSlateApplication::Get().GetCursorPos(), FPopupTransitionEffect::ContextMenu);

	}
	return FReply::Handled();
}


void SVRSTutorialButton::OnStartBegin()
{
	UE_LOG(LogTemp, Warning, TEXT("OnStartBegin()"));
}

#undef LOCTEXT_NAMESPACE