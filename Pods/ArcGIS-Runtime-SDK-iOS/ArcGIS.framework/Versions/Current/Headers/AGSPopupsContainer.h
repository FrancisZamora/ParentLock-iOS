/*
 COPYRIGHT 2011 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */


@protocol AGSPopupsContainerDelegate;

@class AGSGeometry;
@class AGSPopup;

/** @file AGSPopupsContainer.h */ //Required for Globals API doc

/**  An abstraction for a container of popups
 
 A protocol that needs to be adopted by an object wishes to serve as an AGSPopupsContainer.
 
 @see  AGSPopupsContainerViewController
 @since 2.0
 */
@protocol AGSPopupsContainer <NSObject>
@required

/** The delegate.
 @since 2.0
 */
@property (nonatomic, assign) id<AGSPopupsContainerDelegate> delegate;

/**
 Main data structure for supplying individual popupviewcontroller's
 their data
 @since 2.0
 */
@property (nonatomic, copy) NSArray *popups;

/** Whether the AGSPopupsContainer is in a process of editing.
 @since 2.0
 */
@property (nonatomic, assign, readonly) BOOL inEditingMode;

/** When in edit mode and geometry editing is allowed, this property 
 returns a mutable geometry that you can edit and when editing is finished, it will 
 be set on the feature.
 @since 2.0
 */
@property (nonatomic, strong, readonly) AGSGeometry *currentEditingGeometry;

/** The current AGSPopup that is being viewed.
 @since 2.0
 */
@property (nonatomic, strong, readonly) AGSPopup *currentPopup;

#if TARGET_OS_IPHONE

/** The style for the AGSPopupsContainer.
 @since 2.0
 */
@property (nonatomic, assign) AGSPopupsContainerStyle style;

/** The color that is used for the toolbars and navigation bars in the popup views when  style
 is set to  AGSPopupsContainerStyleCustomColor.
 @since 2.0
 */
@property (nonatomic, strong) AGSColor *styleColor;

/** Sets the tint color of items in toolbars and navigation bars that appear in the popup.
 Only valid when the style is set to AGSPopupsContainerStyleCustomColor.
 This property only works on iOS 7 and above.
 @since 10.2
 */
@property (nonatomic, strong) AGSColor *barItemTintColor;

/** Sets whether toolbars and navigation bars that appear in the popup are translucent.
 Only valid when the style is set to AGSPopupsContainerStyleCustomColor.
 @since 10.2
 */
@property (nonatomic, assign) BOOL barTranslucent;

/** Sets the tint color of titles in toolbars and navigation bars that appear in the popup.
 Only valid when the style is set to AGSPopupsContainerStyleCustomColor.
 @since 10.2
 */
@property (nonatomic, strong) AGSColor *barTitleTintColor;

/** The view representing this container.
 @since 10.2
 */
@property (nonatomic, strong, readonly) UIView *view;

/** The style that is used in the AGSPopupsContainer for editing.
 @since 2.0
 */
@property (nonatomic, assign) AGSPopupsContainerEditingStyle editingStyle;

//TODO:  Need to figure out what to do with UIBarButtonItems & modalPresenter for OSX...

/** You can replace the button that appears on the left side of the top bar of the 
 container view with a custom button through this property. This button is only used
 when not in editing mode.
 @since 2.1
 */
@property (nonatomic, strong, readwrite) UIBarButtonItem *doneButton;

/** You can replace the button that appears on the right side of the top bar of the 
 container view with a custom button through this property. This button is only used
 when not in editing mode.
 @since 2.1
 */
@property (nonatomic, strong, readwrite) UIBarButtonItem *actionButton;

/** The default action button that is shown.
 @since 2.1
 */
@property (nonatomic, strong, readonly) UIBarButtonItem *defaultActionButton;

/** The default done button that is shown.
 @since 2.1
 */
@property (nonatomic, strong, readonly) UIBarButtonItem *defaultDoneButton;

/** The UIViewController that should be used for presenting modal view controllers
 from within this AGSPopupsContainer. This is useful when using this view controller
 as a standalone object and when it's not part of a view controller hierarchy.
 @since 2.0
 */
@property (nonatomic, strong) UIViewController *modalPresenter;

/** Font used for heading text in the popups container. 
 You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong, readwrite) AGSFont *headlineFont;
    
/** Color used for heading text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong) AGSColor *headlineColor;

/** Font used for attribute title text in the popups container.
 You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong, readwrite) AGSFont *attributeTitleFont;

    /** Font used for attribute detail text in the popups container.
     You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong, readwrite) AGSFont *attributeDetailFont;

    /** Font used for attachment title text in the popups container.
     You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong, readwrite) AGSFont *attachmentTitleFont;

    /** Color of text used for attribute title text in the popups container.
     You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong) AGSColor *attributeTitleColor;

    /** Color of text used for attribute detail text in the popups container.
     You must set this before you access the view or present the popups view controller.
 @since 10.2.3
 */
@property (nonatomic, strong) AGSColor *attributeDetailColor;

#elif TARGET_OS_MAC && (!TARGET_OS_IPHONE)

/** Lets the popup container know that the geometry for the current popup was updated.
 @since 2.0
 */
-(void)geometryUpdated;

#endif

/**
 Popups view controller should show additional popups as defined by input.
 @since 2.0
 */
-(void)showAdditionalPopups:(NSArray *)popupInfos;

/** Method to start editing the currently displayed popup.
 @since 2.0
 */
-(void)startEditingCurrentPopup;

/** Method that must be called if you implement your own done editing button.
 @since 10.2.2
 */
-(void)finishEditingCurrentPopup;

/** Method that must be called if you implement your own cancel editing button.
 @since 10.2.2
 */
-(void)cancelEditingCurrentPopup;

/** Clears all the popups currently being shown. This is useful if you want to cache
 a reference to the popups container so it doesn't have to reload from a NIB
 everytime it is shown.
 @since 2.0
 */
-(void)clearAllPopups;

@end
