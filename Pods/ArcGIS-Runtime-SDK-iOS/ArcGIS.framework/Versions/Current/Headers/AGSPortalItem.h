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

@class AGSEnvelope;
@class AGSSpatialReference;
@class AGSPortal;
@class AGSPortalItemComment;
@protocol AGSPortalItemDelegate;

/** @file AGSPortalItem.h */ //Required for Globals API doc

/** Constant used to retrieve the groups this user is admin of from the fetchGroups operation.
 @since 10.2
 */
AGS_EXTERN NSString *const kAGSPortalItemGroupAdmin;

/** Constant used to retrieve the groups this user is a member of from the fetchGroups operation.
 @since 10.2
 */
AGS_EXTERN NSString *const kAGSPortalItemGroupMember;

/** Constant used to retrieve the groups that are public or shared, but that this user is not a part of from the fetchGroups operation.
 @since 10.2
 */
AGS_EXTERN NSString *const kAGSPortalItemGroupOther;

/** Notification that indicates the comments for the portal item have been fetched successfully.
 @since 10.2
 */
AGS_EXTERN NSString *const AGSPortalItemDidFetchCommentsNotification;

/** Notification that indicates there was an error fetching the comments for the portal item.
 @since 10.2
 */
AGS_EXTERN NSString *const AGSPortalItemDidFailToFetchCommentsNotification;

/** Notification that indicates the portal item was successfully rated.
 @since 10.2
 */
AGS_EXTERN NSString *const AGSPortalItemDidAddRatingNotification;

/** Notification that indicates there was an error rating the portal item.
 @since 10.2
 */
AGS_EXTERN NSString *const AGSPortalItemDidFailToAddRatingNotification;

/** Notification that indicates the current user's rating for the portal item was retrieved.
 @since 10.2
 */
AGS_EXTERN NSString *const AGSPortalItemDidFetchUserRatingNotification;

/** Notification that indicates there was an error fetching the current user's rating for the portal item.
 @since 10.2
 */
AGS_EXTERN NSString *const AGSPortalItemDidFailToFetchUserRatingNotification;

/**  Object representing a unit of content in the portal. 
 
 An AGSPortalItem is a unit of content in the AGSPortal.  Each item has a unique identifier and a well-
 known URL that is independent of the user owning the item. An item may have associated binary or 
 textual data which has to be fetched explicitly using  fetchData.  For example, an item of type  AGSPortalItemTypeMapPackage will
 fetch the actual bits corresponding to the map package.
 
 The AGSPortalItem's delegate is informed whenever operations performed by the AGSPortalItem  
 complete successfully or encounter an error. 
 
 @see AGSPortalItemDelegate
 @since 2.2
 */
@interface AGSPortalItem : NSObject <AGSCoding>

/** The delegate for the portal item operations. 
 @since 2.2
 */
@property (nonatomic, weak, readwrite) id<AGSPortalItemDelegate> delegate;

/** The portal that the item belogs to. 
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSPortal *portal;

/** The Id of the item. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *itemId;

/** The URL of the service inside the portal item.
 @since 10.2
 */
@property (nonatomic, strong, readonly) NSURL *serviceURL;

/** The Id of the folder this item belongs to.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *folderId;

/** The user who created the item. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *owner;

/** Title of the item. 
 @since 2.2
 */
@property (nonatomic, copy) NSString *title;

/** The type of the item. 
 @since 2.2
 */
@property (nonatomic, assign) AGSPortalItemType type; 

/** The description of the item, if any. 
 @since 2.2
 */
@property (nonatomic, copy) NSString *itemDescription;

/** Snippet or summary of the item with a character limit of 250 characters.
 @since 2.2
 */
@property (nonatomic, copy) NSString *snippet;

/** The access information about the item. 
 @since 2.2
 */
@property (nonatomic, copy) NSString *credits;

/** Information about licenses or restrictions to view or edit the item. 
 @since 2.2
 */
@property (nonatomic, copy) NSString *license;

/** The name of the thumbnail image of the item. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *thumbnailFileName;

/** The item's language and country information.
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSLocale *locale;

/** Words or short phrases that describe the item.
 @since 2.2
 */
@property (nonatomic, copy) NSArray *tags;

/** A set of keywords that further describes the type of item. Each item is tagged with a set of type keywords that are derived based on its primary type.
 @since 2.2
 */
@property (nonatomic, copy) NSArray *typeKeywords;

/** Date on which the item was first uploaded. 
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSDate *created;

/** Date on which the item was modified.
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSDate *modified;

/** The default extent of the item. Only applicable to certain item types.
 @since 2.2
 */
@property (nonatomic, strong) AGSEnvelope *extent;

/** The spatial reference of the item. Only applicable to certain item types.
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** The size of the item in kilobytes.
 @since 2.2
 */
@property (nonatomic, assign, readonly) NSInteger size;

/** The number of comments on the item.
 @since 2.2
 */
@property (nonatomic, assign, readonly) NSInteger numComments;

/** The number of ratings made by the users on the item.
 @since 2.2
 */
@property (nonatomic, assign, readonly) NSInteger numRatings;

/** Average rating of the item.
 @since 2.2
 */
@property (nonatomic, assign, readonly) CGFloat avgRating;

/** Number of times a file item type is downloaded for the first time or a text item type is opened. For 
 a URL item type, the numViews property increases the first time a service is opened. 
 @since 2.2
 */
@property (nonatomic, assign, readonly) NSInteger numViews;

/** Indicates who can access this item. Can be  AGSPortalAccessPrivate,  AGSPortalAccessShared,  AGSPortalAccessOrganization, or  AGSPortalAccessPublic.
 
 If  AGSPortalAccessPrivate, only the item owner
 can access.  AGSPortalAccessShared allows access to members of a group that the item is shared with .  AGSPortalAccessOrganization restricts item access to members of an organization. If  AGSPortalAccessPublic, all users can access the item.
 @since 2.2
 */
@property (nonatomic, assign, readonly) AGSPortalAccess access;

/** The thumbnail image of the item.  This needs to be fetched explicitly using fetchThumbnail. 
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSImage *thumbnail;

/** Array of comments ( AGSPortalItemComment) of the item. These need to be fetched explicitly using fetchComments. 
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSArray *comments;

/** Indicates whether or not comments are enabled for the item.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL commentsEnabled;

/** The rating of this item by the current user. This needs to be fetched explicitly using fetchUserRating. If
 the rating has not been fetched it will be -1.
 @since 10.2
 */
@property (nonatomic, assign, readonly) CGFloat userRating;

/** Initializes a portal item with a portal and item id.
 @param portal The portal to which the item may belong to. 
 @param itemId The Id of the item. 
 @since 2.2
 */
-(id)initWithPortal:(AGSPortal*)portal itemId:(NSString*)itemId;

/** Kicks off an operation that fetches raw bytes for the item. The corresponding methods on  AGSPortalItemDelegate 
 are invoked when the operation completes successfully or encounters an error.
 @return The operation fetching the data for this item.
 @since 2.2
 */
-(NSOperation*)fetchData;

/** Kicks off an operation that fetches the thumbnail for the item. The corresponding methods on  AGSPortalItemDelegate 
 are invoked when the operation completes successfully or encounters an error.
 @return The operation fetching the thumbnail.
 @since 2.2
 */
-(NSOperation*)fetchThumbnail;

/** Kicks off an operation that fetches the comments for the item. The corresponding methods on  AGSPortalItemDelegate 
 are invoked when the operation completes successfully or encounters an error. The resulting AGSPortalItemComment objects will
 be sorted by date descending.
 @return The operation fetching the comments.
 @since 2.2
 */
-(NSOperation*)fetchComments;

/** Kicks off an operation that fetches the groups that this item belongs to. The corresponding methods on  AGSPortalItemDelegate 
 are invoked when the operation completes successfully or encounters an error. This groups returned will only be groups that
 are visible to the current logged in user.
 @since 10.2
 */
-(NSOperation*)fetchGroups;

/** Update the portal item's properties on the portal. The corresponding methods on  AGSPortalItemDelegate 
 are invoked when the operation completes successfully or encounters an error.
 @return The operation performing the update.
 @since 10.2
 */
-(NSOperation*)updateItemProperties;

/** Update the JSON data for the item on the portal. This method should be used when the context
 for this item is a web map. The corresponding methods on  AGSPortalItemDelegate are invoked when 
 the operation completes successfully or encounters an error.
 @param json The JSON with which to update the portal item.
 @return The operation performing the update.
 @since 10.2
 */
-(NSOperation*)updateDataWithJSON:(NSDictionary*)json;

/** Update the file for the item on the portal. This method should be used when the content for
 this item is a static file, such as a shapefile, CSV, etc. The corresponding methods on  AGSPortalItemDelegate 
 are invoked when the operation completes successfully or encounters an error.
 @param fileData The data representing the file to be updated.
 @return The operation performing the update.
 @since 10.2
 */
-(NSOperation*)updateDataWithFile:(NSData*)fileData;

/** Add a comment to an item. Available only to authenticated users who have access to the item. The corresponding 
 methods on  AGSPortalItemDelegate are invoked when the operation completes successfully or encounters an error.
 @param comment The comment to add to the portal item.
 @return The operation that is adding the comment to the portal item.
 @since 10.2
 */
-(NSOperation*)addComment:(NSString*)comment;

/** Add a rating to an item that you have access to. Only 1 rating can be given to an item per user. 
 If this call is made on an already rated item, the new rating will overwrite the current one. A user 
 cannot rate their own item. Available only to authenticated users. The corresponding methods on 
  AGSPortalItemDelegate are invoked when the operation completes successfully or encounters an error.
 NOTE: If the current user's rating has not been fetched, this method will fetch it before adding the rating.
 After a successfull call to addRating: the avgRating and numRatings will be updated on the portal item.
 @param rating The rating to add to the portal item. The value must be between 1.0 and 5.0.
 @return The operation that is adding the rating to the portal item.
 @since 10.2
 */
-(NSOperation*)addRating:(CGFloat)rating;

/** Retrieves the rating of the portal item by the current portal user.
 @return The operation that is fetching the current user's rating of this portal item.
 @since 10.2
 */
-(NSOperation*)fetchUserRating;

/** Sets the thumbnail for this portal item. To update the server, updateItemProperties: or addPortalItem:withContentParams:toFolder: must
 be called after calling this method.
 @param image The NSImage/UIImage representing the thumbnail.
 @since 10.2
 */
-(void)setThumbnailWithImage:(AGSImage*)image;

@end


/**  The delegate of  AGSPortalItem
 
 A protocol which must be adopted by a class wishing to serve as a delegate for AGSPortalItem. 
 An instance of the
 class must then be set as  [AGSPortalItem delegate] .

 AGSPortalItem informs the delegate when operations complete successfully or encounter an error.
 
 All of the methods of this protocol are optional. 
 
 @since 2.2
 */
@protocol AGSPortalItemDelegate <NSObject>
@optional

/** Tells the delegate that the portal item was loaded successfully.
 @param portalItem The portalItem that was loaded. 
 @since 2.2
 */
-(void)portalItemDidLoad:(AGSPortalItem*)portalItem;

/** Tells the delegate that an error was encountered while tyring to load the portal item.
 @param portalItem 	The portal item that failed to load.
 @param error Information about the cause of the failure. 
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem didFailToLoadWithError:(NSError*)error;

/** Tells the delegate that item's data was fetched successfully. 
 @param portalItem The portal item of which the data was fetched. 
 @param op The operation that performed the fetch. 
 @param data The NSData that was retrieved. 
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFetchData:(NSData*)data;

/** Tells the delegate that an error was encountered while tyring to fetch the item's data. 
 @param portalItem The portal item of which the data was fetched.  
 @param op The operation that performed the fetch. 
 @param error Information about the cause of the failure.
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFailToFetchDataWithError:(NSError*)error;

/** Tells the delegate that the item's thumbnail was fetched successfully. 
 @param portalItem 	The portal item for which the thumbnail was fetched. 
 @param op The operation that performed the fetch. 
 @param thumbnail The thumbnail image file.
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFetchThumbnail:(AGSImage*)thumbnail;

/** Tells the delegate that an error was encountered while fetching the item's thumbnail. 
 @param portalItem The portal item for which the thumbnail was fetched. 
 @param op The operation that performed the fetch. 
 @param error Information about the cause of the failure.
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFailToFetchThumbnailWithError:(NSError*)error;

/** Tells the delegate that the item's comments were fetched successfully.
 @param portalItem 	The portal item for which the comments were fetched. 
 @param operation The operation that performed the fetch. 
 @param comments The comments.
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)operation didFetchComments:(NSArray*)comments;

/** Tells the delegate that an error was encountered while trying to fetch the item's comments. 
 @param portalItem The portal item for which the comments fetched. 
 @param operation The operation that performed the fetch. 
 @param error Information about the cause of the failure.
 @since 2.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)operation didFailToFetchCommentsWithError:(NSError*)error;

/** Tells the delegate that the item's groups were fetched successfully.
 @param portalItem 	The portal item for which the groups were fetched.
 @param op The operation that performed the fetch.
 @param groups A dictionary containing the groups that this portal item belongs to, that are visible to the calling user. 
 The dictionary keys will be kAGSPortalItemGroupAdmin, kAGSPortalItemGroupMember, and kAGSPortalItemGroupOther and the associated value will be an array of AGSPortalGroup
 objects. The groups under the kAGSPortalItemGroupAdmin key are groups for which this user is an administrator. The groups under the kAGSPortalItemGroupMember
 key are groups for which this user is a member. The groups under the kAGSPortalItemGroupOther key are groups that are public or shared
 to the user's organization, but that the user is not a member of.
 @since 10.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFetchGroups:(NSDictionary*)groups;

/** Tells the delegate that an error was encountered while trying to fetch the item's groups.
 @param portalItem The portal item for which the groups fetched.
 @param op The operation that performed the fetch.
 @param error Information about the cause of the failure.
 @since 10.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFailToFetchGroupsWithError:(NSError*)error;

/** Tells the delegate that the portal item was successfully updated.
 @param portalItem The portal item that was successfully updated.
 @param op The operation that performed the update.
 @since 10.2
 */
- (void)portalItem:(AGSPortalItem*)portalItem operationDidUpdateItemProperties:(NSOperation*)op;

/** Tells the delegate that the portal item failed to update.
 @param portalItem The portal item that failed to update.
 @param op The operation that performed the update.
 @param error The resulting error from the update operation
 @since 10.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFailToUpdateItemPropertiesWithError:(NSError*)error;

/** Tells the delegate that the portal item data was successfully updated.
 @param portalItem The portal item whose data was successfully updated.
 @param op The operation that performed the update.
 @since 10.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operationDidUpdateData:(NSOperation*)op;

/** Tells the delegate that the portal item data failed to update.
 @param portalItem The portal item that failed to update.
 @param op The operation that performed the update.
 @param error The resulting error from the update operation
 @since 10.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)op didFailToUpdateDataWithError:(NSError*)error;

/** Tells the delegate that the comment was added to the portal item successfully.
 @param portalItem The portal item that the comment was added to successfully.
 @param operation The operation that attempted to add the comment.
 @param comment The comment that was successfully added to the portal item.
 @since 10.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)operation didAddComment:(AGSPortalItemComment*)comment;

/** Tells the delegate that the comment was not added to the portal item.
 @param portalItem The portal item that failed to add the comment.
 @param operation The operation that attempted to add the comment.
 @param comment The comment that failed to be added to the portal item.
 @param error The resulting error from the addComment method.
 @since 10.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)operation didFailToAddComment:(NSString*)comment withError:(NSError*)error;

/** Tells the delegate that the rating was added to the portal item successfully.
 @param portalItem The portal item that the rating was added to successfully.
 @param operation The operation that attempted to add the rating.
 @param rating The rating that was successfully added to the portal item.
 @since 10.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)operation didAddRating:(CGFloat)rating;

/** Tells the delegate that the rating was not added to the portal item.
 @param portalItem The portal item that failed to add the rating.
 @param operation The operation that attempted to add the rating.
 @param rating The rating that failed to be added to the portal item.
 @param error The resulting error from the addRating method.
 @since 10.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)operation didFailToAddRating:(CGFloat)rating withError:(NSError*)error;

/** Tells the delegate that the user's rating of this portal item was retrieved successfully.
 @param portalItem The portal item to retrieve the rating for.
 @param operation The operation that attempted to fetch the rating.
 @param rating The rating of this portal item by the current user.
 @since 10.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)operation didFetchUserRating:(CGFloat)rating;

/** Tells the delegate that the rating for the current user was not retrieved.
 @param portalItem The portal item that failed to fetch the rating.
 @param operation The operation that attempted to fetch the rating.
 @param error The resulting error from the fetchUserRating method.
 @since 10.2
 */
-(void)portalItem:(AGSPortalItem*)portalItem operation:(NSOperation*)operation didFailToFetchUserRatingWithError:(NSError*)error;

@end
