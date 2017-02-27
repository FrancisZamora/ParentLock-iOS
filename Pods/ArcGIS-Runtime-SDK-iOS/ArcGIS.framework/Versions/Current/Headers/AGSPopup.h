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

@class AGSGraphic;
@class AGSPopupInfo;
@class AGSPopupFieldInfo;
@class AGSPopupUtility;
@class AGSFeatureLayer;
@class AGSGeometry;
@class AGSGDBFeature;
@class AGSGDBFeatureTable;
@class AGSImageServiceLayer;
@protocol AGSGDBFeatureSourceInfo;
@protocol AGSFeature;

/** @file AGSPopup.h */ //Required for Globals API doc

/**  A popup which displays a graphic's information.
 
 Instances of this class represent a popup which associates a graphic with popup definition for the purpose of displaying in an AGSPopupsContainer.
 @since 2.0
 */
@interface AGSPopup : NSObject

/** A popup definition that dictates which information belonging to the graphic should be displayed in the popup  and how it should be formatted. 
 @since 2.0
 */
@property (nonatomic, strong, readonly) AGSPopupInfo *popupInfo;

/** The feature for which the popup is associated with.
 @since 10.2
 */
@property (nonatomic, strong, readonly) id<AGSFeature> feature;

/** A convenience method for retrieving the AGSGraphic associated with this popup. The popup deals with AGSFeatures. However,
 if an AGSGraphic was used, then this property will not be nil.
 @since 2.0
 */
@property (nonatomic, strong, readonly) AGSGraphic *graphic;

/** A convenience method for retrieving the AGSGDBFeature associated with this popup. The popup deals with AGSFeatures. However,
 if an AGSGDBFeature was used, then this property will not be nil.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSGDBFeature *gdbFeature;

/** The feature source for which the popup is associated with.
 @since 10.2
 */
@property (nonatomic, strong, readonly) id<AGSGDBFeatureSourceInfo> gdbFeatureSourceInfo;

/** A convenient way to retrieve the feature layer for the popup graphic. Will be nil if
 the graphic was not part of a feature layer when the popup was initialized. This is
 helpful if you have popups open for graphics in an OnDemand feature layer that is refreshing
 and the graphics are getting removed from the feature layer. This will cache the feature layer,
 at the time of initialization so that you can post edits, etc, on this reference.
 @since 2.1
 */
@property (nonatomic, strong, readonly) AGSFeatureLayer *featureLayer;

/** A convenient way to retrieve the image service layer for the popup graphic. Will be nil if
 the popup was not initialized using initWithGraphic:popupInfo:imageServiceLayer:.
 @since 10.2.4
 */
@property (nonatomic, strong, readonly) AGSImageServiceLayer *imageServiceLayer;

/** A convenience method for retrieving the AGSGDBFeatureTable associated with this popup. The popup deals with objects that implement AGSGDBFeatureSourceInfo protocol. However,
 if an AGSGDBFeatureTable was used, then this property will not be nil.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSGDBFeatureTable *gdbFeatureTable;

/** Whether or not the popup should allow the graphic to be edited.
 @since 2.3
 */
@property (nonatomic, assign) BOOL allowEdit;

/** Whether or not the popup should allow the graphic's geometry should be edited. Only applicable when allowEdit is YES.
 @since 2.3
 */
@property (nonatomic, assign) BOOL allowEditGeometry;

/** Whether or not the popup should allow the graphic to be deleted.
 @since 2.3
 */
@property (nonatomic, assign) BOOL allowDelete;

/** The title of the popup. This looks at the graphic and the popupInfo to determine what
 the title the actual popup will show.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *title;

/** Returns a string attribute value for a field info based on the graphic
 that this AGSPopup represents.
 @since 10.1.1
 */
-(NSString*)attributeForPopupFieldInfo:(AGSPopupFieldInfo*)popupFieldInfo;

/** A convenience method that returns a string that has the templated portions replaced with attributes from the graphic. For example, a template string <i>Population of ${CITY_NAME} is ${POP1990}</i> will return a string
 with templates replaced by  values of attribute CITY_NAME and POP1990 in the graphic.
 @param aString The template string with templates enclosed in ${}
 @since 10.1.1
 */
-(NSString *)stringForTemplatedString:(NSString *)aString;


/** Initializes an  AGSPopup instance.
 @param graphic for which the popup needs to be displayed
 @param popupInfo defining how information about the graphic should be displayed
 @return An AGSPopup
 @since 2.0
 */
-(id)initWithGraphic:(AGSGraphic*)graphic popupInfo:(AGSPopupInfo*)popupInfo;

/** Initializes an  AGSPopup instance.
 @param graphic for which the popup needs to be displayed
 @param popupInfo defining how information about the graphic should be displayed
 @param featureLayer if one is associated with the graphic
 @return An AGSPopup
 @since 10.1.1
 */
-(id)initWithGraphic:(AGSGraphic*)graphic popupInfo:(AGSPopupInfo*)popupInfo featureLayer:(AGSFeatureLayer*)featureLayer;

/** Initializes an  AGSPopup instance.
 @since 10.2
 */
-(id)initWithGDBFeature:(AGSGDBFeature*)feature
           popupInfo:(AGSPopupInfo*)popupInfo;

/** Initializes an  AGSPopup instance.
 @param feature for which the popup needs to be displayed
 @param popupInfo defining how information about the graphic should be displayed
 @param imageServiceLayer if one is associated with the graphic
 @return An AGSPopup
 @since 10.2.4
 */
-(id)initWithFeature:(id<AGSFeature>)feature popupInfo:(AGSPopupInfo*)popupInfo imageServiceLayer:(AGSImageServiceLayer*)imageServiceLayer;

/** Returns an autoreleased  AGSPopup.
 @since 10.2
 */
+(instancetype)popupWithGDBFeature:(AGSGDBFeature*)feature popupInfo:(AGSPopupInfo*)popupInfo;

/** Returns an autoreleased  AGSPopup.
 @param graphic for which the popup needs to be displayed
 @param popupInfo defining how information about the graphic should be displayed
 @return An autoreleased AGSPopup
 @since 2.0
 */
+(AGSPopup*)popupWithGraphic:(AGSGraphic*)graphic popupInfo:(AGSPopupInfo*)popupInfo;

/** Returns an autoreleased  AGSPopup.
 @param graphic for which the popup needs to be displayed
 @param popupInfo defining how information about the graphic should be displayed
 @param featureLayer if one is associated with the graphic
 @return An autoreleased AGSPopup
 @since 10.1.1
 */
+(AGSPopup*)popupWithGraphic:(AGSGraphic*)graphic popupInfo:(AGSPopupInfo*)popupInfo featureLayer:(AGSFeatureLayer*)featureLayer;

/** Returns an autoreleased  AGSPopup.
 @param feature for which the popup needs to be displayed
 @param popupInfo defining how information about the graphic should be displayed
 @param imageServiceLayer if one is associated with the graphic
 @return An autoreleased AGSPopup
 @since 10.2.4
 */
+(AGSPopup*)popupWithFeature:(id<AGSFeature>)feature popupInfo:(AGSPopupInfo*)popupInfo imageServiceLayer:(AGSImageServiceLayer*)imageServiceLayer;


@end
