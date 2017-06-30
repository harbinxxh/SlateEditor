// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

//#include "STutorialLoading.h"

class SVRSTutorialButton : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SVRSTutorialButton) {}


	SLATE_END_ARGS()

	/** Widget constructor */
	void Construct(const FArguments& Args);

	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyClippingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

public:
	void OnStartBegin();

};