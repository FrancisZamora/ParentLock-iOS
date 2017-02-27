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

@protocol AGSPortalDelegate;
@protocol AGSPortalModelObject;
@class AGSPortalFolder;
@class AGSPortalItem;
@class AGSPortalItemContentParameters;
@class AGSPortalQueryParams;
@class AGSPortalUser;
@class AGSPortalGroup;
@class AGSPortalInfo;
@class AGSPortalQueryResultSet;
@class AGSCredential;
@protocol AGSSecuredResource;


/** Notification that indicates that an  AGSPortal successfully loaded.
 @since 10.2
 */
AGS_EXTERN NSString *const AGSPortalDidLoadNotification;

/** Notification that indicates that an  AGSPortal failed to load.
 @since 10.2
 */
AGS_EXTERN NSString *const AGSPortalDidFailToLoadNotification;

/** Notification that indicates that an  AGSPortal successfully found items.
 @since 10.2
 */
AGS_EXTERN NSString *const AGSPortalDidFindItemsNotification;

/** Notification that indicates that an  AGSPortal failed to find items.
 @since 10.2
 */
AGS_EXTERN NSString *const AGSPortalDidFailToFindItemsNotification;

/** Notification that indicates that an  AGSPortal successfully found groups.
 @since 10.2
 */
AGS_EXTERN NSString *const AGSPortalDidFindGroupsNotification;

/** Notification that indicates that an  AGSPortal failed to find groups.
 @since 10.2
 */
AGS_EXTERN NSString *const AGSPortalDidFailToFindGroupsNotification;


/** @file AGSPortal.h */ //Required for Globals API doc

/**  An Object representing a Portal for ArcGIS
 
 AGSPortal is an object that represents a view for a user (anonymous or not) into a 
 portal. www.ArcGIS.com is an example of a portal. A portal may support subscriptions which provides organizations a  sandboxed area on the portal. 
 
 AGSPortal is the main class and the entry point into the API to work with portals and organization subscriptions. It implements all the operations to 
 interface with the backend ArcGIS Portal REST API. It has a delegate  AGSPortalDelegate that is informed when each 
 operation completes successfully or encounters an error. 
 
 
 
 @b Concepts:
 
 - Portals  allow users and  organizations to publish and share content over the web. 
 
 - A Portal has  Users ( AGSPortalUser), Groups ( AGSPortalGroup) and Content ( AGSPortalItem).
 
 - A Portal may have users who are unaffiliated with an organization or users who are part of an 
 organization.
 
 - Users sign in to the portal and  create and share content which is organized into Items. The system 
 supports different types of items including web maps, map services (that can be used as layers in web 
 maps), applications (that are built around web maps) and data files (that can be uploaded and 
 downloaded).
 
 - Users can choose to keep content Private or to share it with other users via Groups or make content 
 Public and accessible to everyone.
 
 - Users can create and join Groups. Users can share items with Groups. This makes the items visible to 
 and accessible by the other members of the Group.
 
 - A Portal may contain multiple Organizations.
 
 - A user of the Portal (and of the REST API) sees the view off the Portal that applies to their 
 organization subscription.  This view includes users, groups and items that belong to the organization and have been 
 shared with them. This view may also include users, groups and items that are external to the 
 organization and have been shared with the user.
 
 - An organization has users in different roles including administrators, publishers and  information 
 workers.
 
 - Administrators can add  users to  their organization subscriptions and have access to all content within the 
 organization.
 
 - All users can create web maps based  on mashing up services that they have access to and can register 
 services running on external servers.
 
 - Publishers within an organization can in addition create hosted services based on data files that they 
 upload.
 
 @see AGSPortalDelegate
 @see oncept{connecting-to-a-portal.htm, Working with Portals}
 @see 
 */
@interface AGSPortal : NSObject <AGSSecuredResource>

/** The URL of the portal.
 @since 2.2
 */
@property (nonatomic, strong, readonly) NSURL *URL;

/** The credential of the user for authenticated access. Can be nil, in which case it requests for anonymous access to the portal.
 @since 2.2
 */
@property (nonatomic, copy, readwrite) AGSCredential *credential;

/** The credential cache to be used for this resource. By default, each portal will create it's own cache.
 @since 10.1.1
 */
@property (nonatomic, strong, readwrite) AGSCredentialCache *credentialCache;

/** The delegate for the portal operations. 
 @since 2.2
 */
@property (nonatomic, weak, readwrite) id<AGSPortalDelegate> delegate;

/** Returned upon successful initialization of the portal. Contains details of the portal/organization as seen by the current user, anonymous or logged in. 
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSPortalInfo *portalInfo;

/** Represents the registered user of the portal/organization and is returned upon successful initialization of the portal with a credential. 
 @since 2.2
 */
@property (nonatomic, strong, readonly) AGSPortalUser *user;

/** Whether the portal has loaded or not.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL loaded;

/** Block that is called when the portal loads or fails to load.
 @since 10.2
 */
@property (nonatomic, copy) void (^loadCompletion)(NSError *error);


/** Instantiates the AGSPortal and initiates a connection to the portal. It will fetch the portal properties and 
 user properties asynchronously and invoke the loaded/failed methods on  AGSPortalDelegate. It is recommended you assign a delegate to ensure that the portal loaded properly.
 
 @param url The url for the portal. Eg, www.arcgis.com
 @param cred The credential of the user. Can be Nil if anonymous access is desired. 
 @since 2.2
 */
-(id)initWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** If the portal failed to load with a specific url and credential, you can
 resubmit it to try and load again using the same url and credential. If you want to modify the
 credential, you can update the credential on the portal before calling this method.
 If you also want to update the url, you should use  # resubmitWithURL:credential: instead.
 
 This function does nothing if the
 portal is already loaded. This function also does nothing if the portal is currently
 trying to load.
 @since 10.1.1

 */
- (void)resubmit;

/** If the portal fails to load, you can resubmit it with a different URL and/or credential.
 This method will do nothing if the portal is already loaded.
 @param url The url for the portal. 
 @param cred The credential of the user. Can be Nil if anonymous access is desired. 
 @since 2.2
 */
-(void)resubmitWithURL:(NSURL*)url credential:(AGSCredential*)cred;

/** Kicks off an operation that finds items with query. Corresponding methods on the  AGSPortalDelegate are invoked when the operation completes successfully or if an error is encountered.
 @param queryParams The query parameters to find items.  
 @since 2.2
 */
-(NSOperation*)findItemsWithQueryParams:(AGSPortalQueryParams*)queryParams;

/** Kicks off an operation that finds groups with query. Corresponding methods on the  AGSPortalDelegate are invoked when the operation completes successfully or if an error is encountered.
 @param queryParams The query parameters to find groups.  
 @since 2.2
 */
-(NSOperation*)findGroupsWithQueryParams:(AGSPortalQueryParams*)queryParams;

/** Adds the specified portal item to the portal at the given folder.
 @param portalItem The new item to be added to the portal.
 @param contentParams The portal item content parameters for the item to be added.
 @param folder The folder in which to create the item. If nil is passed it will
 be added to the user's root folder.
 @return The operation that is currently adding this item to the portal.
 @since 10.2
 */
-(NSOperation*)addPortalItem:(AGSPortalItem*)portalItem withContentParams:(AGSPortalItemContentParameters*)contentParams toFolder:(AGSPortalFolder*)folder;

/** Deletes an item from the current portal.
 @param portalItem The item to be deleted from the portal.
 @return The operation that is currently deleting this item.
 @since 10.2
 */
-(NSOperation*)deletePortalItem:(AGSPortalItem*)portalItem;

@end




/**  A delegate of  AGSPortal
 
 A protocol which must be adopted by a class wishing to serve as a delegate for AGSPortal. An instance of the
 class must then be set as  [AGSPortal delegate] .

 AGSPortal
 informs the delegate when operations complete successfully or encounter an error.
 
 All of the methods of this protocol are optional.
 
 @since 2.2
 */
@protocol AGSPortalDelegate <NSObject>
@optional

/** Tells the delegate that the portal was loaded successfully.
 @param portal The portal that was loaded. 
 @since 2.2
 */
-(void)portalDidLoad:(AGSPortal*)portal;

/** Tells the delegate that an error was encountered while tyring to load the portal.
 @param portal 	The portal that failed to load.
 @param error Information about the cause of the failure. 
 @since 2.2
 */
-(void)portal:(AGSPortal*)portal didFailToLoadWithError:(NSError*)error;

/** Tells the delegate that the query to find items completed successfully. 
 @param portal The portal on which the query was made.
 @param op The operation that performed the query.
 @param resultSet The  AGSPortalQueryResultSet containing the results as an array of  AGSPortalItem
 @since 2.2
 */
-(void)portal:(AGSPortal*)portal operation:(NSOperation*)operation didFindItems:(AGSPortalQueryResultSet*)resultSet;

/** Tells the delegate that an error was encountered while tyring to query items. 
 @param portal The portal on which the query was made.
 @param op The operation that performed the query. 
 @param queryParams The query parameters
 @param error Information about the cause of the failure.
 @since 2.2
 */
-(void)portal:(AGSPortal*)portal operation:(NSOperation*)operation didFailToFindItemsForQueryParams:(AGSPortalQueryParams*)queryParams withError:(NSError*)error;

/** Tells the delegate that the query to find groups completed successfully. 
 @param portal The portal on which the query was made.
 @param op The operation that performed the query.
 @param resultSet The  AGSPortalQueryResultSet containing the results as an array of  AGSPortalGroup
 @since 2.2
 */
-(void)portal:(AGSPortal*)portal operation:(NSOperation*)operation didFindGroups:(AGSPortalQueryResultSet*)resultSet;

/** Tells the delegate that an error was encountered while tyring to query groups. 
 @param portal The portal on which the query was made.
 @param op The operation that performed the query. 
 @param queryParams The query parameters
 @param error Information about the cause of the failure.
 @since 2.2
 */
-(void)portal:(AGSPortal*)portal operation:(NSOperation*)operation didFailToFindGroupsForQueryParams:(AGSPortalQueryParams*)queryParams withError:(NSError*)error;

/** Tells the delegate that the portal item was successfully added.
 @param portal The portal on which the item was added.
 @param op The operation that performed the add.
 @param portalItem The portal item which was added.
 @since 10.2
 */
-(void)portal:(AGSPortal*)portal operation:(NSOperation*)op didAddPortalItem:(AGSPortalItem*)portalItem;

/** Tells the delegate that the portal item was not added to the portal.
 @param portal The portal on which the item was to be added.
 @param op The operation that performed the add.
 @param portalItem The portal item that failed to be added.
 @param error The resulting error from the add item operation.
 @since 10.2
 */
-(void)portal:(AGSPortal*)portal operation:(NSOperation*)op didFailToAddPortalItem:(AGSPortalItem*)portalItem withError:(NSError*)error;

/** Tells the delegate that the portal item was deleted.
 @param portal The portal on which the item was deleted.
 @param op The operation that performed the delete.
 @param portalItem The portal item which was deleted.
 @since 10.2
 */
-(void)portal:(AGSPortal*)portal operation:(NSOperation*)op didDeletePortalItem:(AGSPortalItem*)portalItem;

/** Tells the delegate that the portal item was not deleted from the portal.
 @param portal The portal on which the item was to be deleted.
 @param op The operation that performed the delete.
 @param portalItem The portal item that failed to be deleted.
 @param error The resulting error from the delete item operation.
 @since 10.2
 */
-(void)portal:(AGSPortal*)portal operation:(NSOperation*)op didFailToDeletePortalItem:(AGSPortalItem*)portalItem withError:(NSError*)error;

@end











