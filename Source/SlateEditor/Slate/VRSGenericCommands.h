// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

class FVRSGenericCommands : public TCommands<FVRSGenericCommands>
{
public:
	
	FVRSGenericCommands()
		: TCommands<FVRSGenericCommands>( TEXT("GenericCommands"), NSLOCTEXT("GenericCommands", "Generic Commands", "Common Commands"), NAME_None, FCoreStyle::Get().GetStyleSetName() )
	{
	}

	virtual ~FVRSGenericCommands()
	{
	}

	virtual void RegisterCommands() override;	

	//TSharedPtr<FUICommandInfo> Cut;
	//TSharedPtr<FUICommandInfo> Copy;
	//TSharedPtr<FUICommandInfo> Paste;
	//TSharedPtr<FUICommandInfo> Duplicate;
	//TSharedPtr<FUICommandInfo> Undo;
	//TSharedPtr<FUICommandInfo> Redo;
	TSharedPtr<FUICommandInfo> Delete;
	//TSharedPtr<FUICommandInfo> Rename;
	//TSharedPtr<FUICommandInfo> SelectAll;	
};
