// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once


class FExtender;
class FUICommandList;
//class IToolkit;
//class IToolkitHost;
//class SBorder;
//class SStandaloneAssetEditorToolkitHost;
//class SWidget;
//class UObject;
//struct FSlateBrush;
//struct FTabId;



DECLARE_DELEGATE_RetVal_TwoParams( TSharedRef<FExtender>, FAssetEditorExtender, const TSharedRef<FUICommandList>, const TArray<UObject*>);

/**
 * Extensibility managers simply keep a series of FExtenders for a single menu/toolbar/anything
 * It is here to keep a standardized approach to editor extensibility among modules
 */
class FVRSExtensibilityManager
{
public:
	virtual ~FVRSExtensibilityManager() {}

	/** Functions for outsiders to add or remove their extenders */
	virtual void AddExtender(TSharedPtr<FExtender> Extender) {Extenders.AddUnique(Extender);}
	virtual void RemoveExtender(TSharedPtr<FExtender> Extender) {Extenders.Remove(Extender);}
	
	/** Gets all extender delegates for this manager */
	virtual TArray<FAssetEditorExtender>& GetExtenderDelegates() {return ExtenderDelegates;}

	/** Gets all extenders, consolidated, for use by the editor to be extended */
	virtual TSharedPtr<FExtender> GetAllExtenders();
	/** Gets all extenders and asset editor extenders from delegates consolidated */
	virtual TSharedPtr<FExtender> GetAllExtenders(const TSharedRef<FUICommandList>& CommandList, const TArray<UObject*>& ContextSensitiveObjects);
	
private:
	/** A list of extenders the editor will use */
	TArray<TSharedPtr<FExtender>> Extenders;
	/** A list of extender delegates the editor will use */
	TArray<FAssetEditorExtender> ExtenderDelegates;
};


/** Indicates that a class has a default menu that is extensible */
class IVRSHasMenuExtensibility
{
public:
	virtual TSharedPtr<FVRSExtensibilityManager> GetMenuExtensibilityManager() = 0;
};


/** Indicates that a class has a default toolbar that is extensible */
class IVRSHasToolBarExtensibility
{
public:
	virtual TSharedPtr<FVRSExtensibilityManager> GetToolBarExtensibilityManager() = 0;
};
