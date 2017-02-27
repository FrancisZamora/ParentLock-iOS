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

@protocol AGSPopupsContainer;

@class AGSPopup;

/** @file AGSPopupsContainerDelegate.h */ //Required for Globals API doc

/**  A delegate of  AGSPopupsContainerViewController
 
  A protocol that must be adopted by any class wishing to be notified when  AGSPopupsContainerViewController detects user interaction with popups or if a user tries to edit a popup. An instance of the class must then be set as  [AGSPopupsContainerViewController delegate] .
 
 All methods of this protocol are optional.
 @since 2.0
 */
@protocol AGSPopupsContainerDelegate <NSObject>
@optional

/** Tells the delegate that a new mutable geometry is required for a graphic that currently has no geometry.
 Must return a mutable geometry.
 @param popupsContainer The popup view controller
 @param popup Popup for who's graphic we need a geometry for.
 @since 2.0
 */
-(AGSGeometry*)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsNewMutableGeometryForPopup:(AGSPopup*)popup;

/** Tells the delegate that a user is ready to edit the geometry for
 the current popup. This will happen when the user clicks the toolbar item for 
 editing the geometry. Or if the editing mode is "Geometry Inline", it will happen when
 editing begins.
 @param popupsContainer The popup view controller
 @param geometry If you are using an  AGSSketchGraphicsLayer, this will be the same geometry that
 you give the AGSSketchGraphicsLayer.
 @param popup whose graphic's geometry needs to be edited
 @deprecated Deprecated at 10.2. Please use  [AGSPopupsContainerDelegate popupsContainer:readyToEditGeometry:forPopup:] instead.
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer readyToEditGraphicGeometry:(AGSGeometry*)geometry forPopup:(AGSPopup*)popup __attribute__((deprecated));

/** Tells the delegate that a user is ready to edit the geometry for
 the current popup. This will happen when the user clicks the toolbar item for
 editing the geometry. Or if the editing mode is "Geometry Inline", it will happen when
 editing begins. 
 
 The geometry will be mutable. You need to update it based on the changes the user wants to make. For example,
 if you are using an  AGSSketchGraphicsLayer to allow the user to interactively reshape the feature, this will be the same geometry that
 you give the AGSSketchGraphicsLayer. Another option is that you could update the geometry based on the GPS coordinates reported by  AGSLocationDisplay.
 @param popupsContainer The popup view controller
 @param geometry The mutable geometry that should be updated with the desired changes.
 @param popup whose feature's geometry needs to be edited
 @since 10.2
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer readyToEditGeometry:(AGSGeometry*)geometry forPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when the user begins editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose graphic needs to be edited
 @deprecated Deprecated at 10.2. Please use  [AGSPopupsContainerDelegate popupsContainer:didStartEditingForPopup:] instead.
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didStartEditingGraphicForPopup:(AGSPopup*)popup __attribute((deprecated));

/** The method called by the AGSPopupsContainer when the user begins editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose feature needs to be edited
 @since 10.2
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didStartEditingForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when the user is done editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose graphic was edited
 @deprecated Deprecated at 10.2. Please use  [AGSPopupsContainerDelegate popupsContainer:didFinishEditingForPopup:] instead.
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didFinishEditingGraphicForPopup:(AGSPopup*)popup __attribute__((deprecated));

/** The method called by the AGSPopupsContainer when the user is done editing the current popup.
 @note If the popup is for an online feature (represented by  AGSGraphic objects belonging to  AGSFeatureLayer), the popupsContainer only applies edits to the feature in memory. You are responsible for applying the edit on the server or persisting it some other way to ensure it does not get lost when the application terminates.
 If the popup is for an offline feature (represented by  AGSGDBFeature in a local geodatabase), the popupsContainer automatically persists edits to the geodatabase on the device. You only need to sync changes in the geodatabase with the server.
 @param popupsContainer The popup view controller
 @param popup whose feature was edited
 @since 10.2
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didFinishEditingForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when the user tries to finish editing but errors were encountered.
 If you implement this method then you are responsible for showing any UI that should be shown when an editing error
 occurs. If you do not implement this method the AGSPopupsContainer will show an alert depicting the localized description of the error.
 @param popupsContainer The popup view controller
 @param popup whose feature was edited
 @param error that occurred when trying to finish editing
 @since 10.2
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didFailToFinishEditingForPopup:(AGSPopup*)popup withError:(NSError*)error;

/** The method called by the AGSPopupsContainer when the user cancels editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose graphic was started to be edited but later cancelled
 @deprecated Deprecated at 10.2. Please use  [AGSPopupsContainerDelegate popupsContainer:didCancelEditingForPopup:] instead.
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didCancelEditingGraphicForPopup:(AGSPopup*)popup __attribute__((deprecated));

/** The method called by the AGSPopupsContainer when the user cancels editing the current popup.
 @param popupsContainer The popup view controller
 @param popup whose feature was started to be edited but later cancelled
 @since 10.2
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didCancelEditingForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when the user presses the delete button.
 The implementer of this method must actually delete the graphic.
 @param popupsContainer The popup view controller
 @param popup whose graphic needs to be deleted
 @deprecated Deprecated at 10.2. Please use  [AGSPopupsContainerDelegate popupsContainer:wantsToDeleteForPopup:] instead.
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToDeleteGraphicForPopup:(AGSPopup*)popup __attribute__((deprecated));

/** The method called by the AGSPopupsContainer when the user confirms they want to delete the feature.
 The implementer of this method must actually delete the feature.
 @note This method will only be called for online features (represented by  AGSGraphic objects belonging to  AGSFeatureLayer) which the developer must delete themselves. It will NOT be called for features in a local geodatabase (represented by  AGSGDBFeature objects). Local features will be automatically deleted by the SDK and then  popupsContainer:didDeleteForPopup: will be called.
 @param popupsContainer The popup view controller
 @param popup whose feature needs to be deleted
 @since 10.2
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToDeleteForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when it successfully deletes an  AGSGDBFeature in a local geodatabase.
 @param popupsContainer The popup view controller
 @param popup whose feature was deleted
 @since 10.2.2
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didDeleteForPopup:(AGSPopup*)popup;

/** The method called by the AGSPopupsContainer when it fails to delete an  AGSGDBFeature in a local geodatabase.
 If you do not implement this method then AGSPopupsContainer will show an alert to the user with the error.
 If you do implement this method then you are responsible for bubbling up the error to the user.
 @param popupsContainer The popup view controller
 @param popup whose feature was meant to be deleted
 @param error that occurred
 @since 10.2.2
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didFailToDeleteForPopup:(AGSPopup*)popup withError:(NSError*)error;

/** The method that is called when the user is done viewing the popups.
 @param popupsContainer The popup view controller
 @since 2.0
 */
-(void)popupsContainerDidFinishViewingPopups:(id<AGSPopupsContainer>)popupsContainer;

/** The method called by the AGSPopupsContainer when a popup's validity is changed. This happens
 when the geometry or attributes of the popup's feature are changed. isValid will be YES if it is 
 determined that a feature meets it's requirements to be saved to it's datasource.
 This method is useful if you have your own "finish editing" button and you want to enable/disable it
 when the feature is valid.
 @param popupsContainer The popup view controller
 @param isValid Whether or not the feature meets it's known requirements to be saved to it's datasource.
 @since 10.2.3
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer validityForPopupChanged:(BOOL)isValid;

#if TARGET_OS_IPHONE

/** The AGSPopupsContainer will call this method on the delegate when a view controller needs to be presented.
 This method is optional, but if you want to show view controllers in different ways than the standard modal way,
 then you need to implement this method.
 @param popupsContainer The popup view controller
 @param svc The view controller that needs to be displayed
 @param viewType The predefined type of the view controller
 @param fvc The view controller that is currently being displayed
 @param rect The rect is in the coordinate space of the fromViewController. Only applicable if viewType is  AGSPopupViewTypeUIImagePicker
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToShowViewController:(AGSViewController *)svc ofType:(AGSPopupViewType)viewType fromViewController:(AGSViewController*)fvc atRect:(CGRect)rect;

/** The AGSPopupsContainer will call this method on the delegate when a view controller needs to be hidden.
 You need to implement this if you implement popupsContainer:wantsToShowViewController:fromViewController:atRect,
 so that you can hide a view controller in the proper way if you've shown it in a custom manner.
 @param popupsContainer The popup view controller
 @param vc The view controller that needs to be hidden
 @param viewType the predefined type of the view controller
 
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToHideViewController:(AGSViewController*)vc ofType:(AGSPopupViewType)viewType;

/** The AGSPopupsContainer will call this delegate method when it one of it's view controllers
 needs to know if it can auto-rotate to an certain interface orientation. If you don't implement this
 method then we just always return YES.
 @param popupsContainer The popup view controller
 @param interfaceOrientation The orientation to change to
 @param vc The view controller that needs to respond to orientation change
 @param viewType the predefined type of the view controller  
 @since 2.0
 */
-(BOOL)popupsContainer:(id<AGSPopupsContainer>)popupsContainer shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation forViewController:(UIViewController*)vc ofType:(AGSPopupViewType)viewType;

#endif

/** The AGSPopupsContainer will call this method when the currently showing popup changes.
 @param popupsContainer The popup view controller
 @param popup which is currently being displayed
 @since 2.0
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didChangeToCurrentPopup:(AGSPopup*)popup;

/** The AGSPopupsContainer will call this method when there is a document that it wants to preview. 
 By default, if this method is not implemented, it will preview the document with a UIDocumentInteractionController. 
 If you have need to hide or show popovers before previewing you should implement this method and 
 create the UIDocumentInteractionController manually.
 @since 2.3
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer wantsToPreviewDocumentAtURL:(NSURL*)documentURL fromViewController:(AGSViewController*)fvc atRect:(CGRect)rect;

/** The AGSPopupsContainer will call this when the user switches a feature type for the current popup.
 Potentially at this point symbology will change for the feature.
 @since 10.1.1
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didChangeFeatureTypeForPopup:(AGSPopup *)popup;

#if TARGET_OS_MAC && (!TARGET_OS_IPHONE)

/** The AGSPopupsContainer will call this when the user opens a window containing an attachment or media object.
 If this method is not implemented, the window will close when the popup is removed from the container.
 @since 10.2
 */
-(void)popupsContainer:(id<AGSPopupsContainer>)popupsContainer didShowWindow:(NSWindow *)window forPopup:(AGSPopup *)popup;

#endif

@end

