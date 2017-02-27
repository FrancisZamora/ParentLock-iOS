/*
 COPYRIGHT 2014 ESRI
 
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

/** @file AGSGDBFeatureEditError.h */ //Required for Globals API doc

/**  An error generated from synchronizing an edited feature in a sync enable geodatabase.
 
 Instances of this class represent an error that occured when synchronizing an edited feature (add, update,
 or delete) in a sync enabled geodatabase.
 
 
 @since 10.2.2
 */
@interface AGSGDBFeatureEditError : NSError

/** The name of the table to which the feature belongs.
 @since 10.2.2
 @see  [AGSGDBGeodatabase featureTableForLayerName:] to retrieve the particular  AGSGDBFeatureTable this name refers to.
 */
@property (nonatomic, copy, readonly) NSString *tableName;

/** The @em OBJECTID of the feature that was edited.
 @since 10.2.2
 */
@property (nonatomic, assign, readonly) long long objectID;

/** The @em GLOBALID of the feature that was edited.
 @since 10.2.2
 */
@property (nonatomic, copy, readonly) NSString *globalID;

/** The type of edit made to the feature: unknown, add, update or delete.
 @since 10.2.2
 */
@property (nonatomic, assign, readonly) AGSGDBSyncEditType editType;

/** The ID of the attchment that was edited.  A value of -1 means the error
 is not for an attachment edit.
 @since 10.2.2
 */
@property (nonatomic, assign, readonly) long long attachmentID;

/** The @em GLOBALID of the attchment that was edited.
 @since 10.2.2
 */
@property (nonatomic, copy, readonly) NSString* attachmentGlobalID;

@end
