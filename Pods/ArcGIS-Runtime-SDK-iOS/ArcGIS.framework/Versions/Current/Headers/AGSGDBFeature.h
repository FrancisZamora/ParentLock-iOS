/*
 COPYRIGHT 2013 ESRI
 
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

@class AGSGDBFeatureTable;
@class AGSGeometry;
@protocol AGSFeature;
@protocol AGSInfoTemplateDelegate;
@class AGSGDBAttachment;
@class AGSEditResult;

/** @file AGSFeature.h */ //Required for Globals API doc

/**  A feature in a local geodatabase
 
 Instances of this class represent a geographic feature in a local geodatabase.
 
 
 */
@interface AGSGDBFeature : NSObject <AGSFeature>

/** The dataset that this feature belongs to.
 @since 10.2
 */
@property (nonatomic, weak, readonly) AGSGDBFeatureTable *table;

/** An identifier uniquely identifying this feature in the dataset.
 @since 10.2
 */
@property (nonatomic, assign, readonly) long long objectID;

/** Whether or not the feature exists inside of it's table yet.
 If not then you must call  [AGSGDBFeatureTable saveFeature:error:] to get it in the table.
 @since 10.2.2
 */
@property (nonatomic, assign, readonly) BOOL isAddedToTable;

/** An array of  AGSGDBAttachemnt objects representing attachments belonging to this feature.
 This will only contain attachments that you've added until  fetchAttachmentsWithCompletion: is called.
 @since 10.2
 */
-(NSArray*)attachments;

/** Initialize an empty feature that belongs to the given dataset
 @param table The dataset the feature belongs to
 @since 10.2
 */
-(id)initWithTable:(AGSGDBFeatureTable*)table;

/**
 Asynchronously fetches attachments that belong to this feature.
 @param completionBlock Handler that is called when the operation is complete. The attachments are passed in as an array of  AGSGDBAttachment objects.
 @since 10.2
 */
-(void)fetchAttachmentsWithCompletion:(void(^)(NSArray* attachments, NSError* error))completionBlock;

/** Add a new attachment for this feature. The attachment exists only in memory until it is 
 commited to the geodatabase using  [AGSFeatureTable saveFeature:error:]
 @param attachment to be added
 @since 10.2
 */
-(void)addAttachment:(AGSGDBAttachment*)attachment;

/** Delete an existing attachment for this feature. The attachment is not deleted from the
 the geodatabase until  [AGSFeatureTable saveFeature:error:] is called.
 @param attachment to be deleted
 @since 10.2
 */
-(void)deleteAttachment:(AGSGDBAttachment*)attachment;

/** Reverts the feature to the state it is in inside the table.
 This will delete any edits you have made to this in-memory copy of the feature.
 This method is only valid to be called on features that have been added to the table.
 @since 10.2.2
 */
-(void)revert;

@end
