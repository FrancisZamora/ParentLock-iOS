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

@class AGSFeatureTable;
@class AGSGDBFeatureTable;
@class AGSCredentialCache;
@class AGSFeatureSet;
@class AGSFeatureTableLayer;
@class AGSGDBEditErrors;
@protocol AGSSecuredResource;
@protocol AGSQueryTaskDelegate;

/** @file AGSGDBFeatureServiceTable.h */

/**  A dataset from an ArcGIS Map or Feature service
 
 Instances of this class represent datasets in a layer of an ArcGIS Map or Feature service. The service may be hosted in the cloud on ArcGIS Online, or on-premises on an ArcGIS Server. The data is retrieved
 from the service as needed and stored in a temporary geodatabase on disk.
 
When using a Feature service, you can potentially create, delete, and update the data depending upon whether the service allows those operations, who owns the data, and what ownership-based access control policies are in place. Refer to the   canCreate,  canUpdate,  canDelete,  canUpdateFeature:,  canDeleteFeature:,  canUpdateGeometry for information on what's permitted.

If the data supports attachments ( hasAttachments), you can also view and potentially edit the attachments.
 
You can also query the data based on SQL expressions and/or spatial relationships.
 
 This class, when used in conjunction with  AGSFeatureTableLayer to display data on a map, is meant to eventually replace
  AGSFeatureLayer because it can handle temporary network outages while still allowing you to work with the data that
 has already been retrieved from the service. Your edits are immediately peristed to the local geodatabase and can be applied to the service later when network connectivity is restored.
 

@see  AGSFeatureTableLayer to visualize features from this dataset on a map.
@since 10.2.3
 */

@interface AGSGDBFeatureServiceTable : AGSGDBFeatureTable <AGSSecuredResource>

// what should be done with the goedatabaseVersion?
//@property (nonatomic, copy, readonly) NSString *geodatabaseVersion;

/** SQL Where clause for filtering when querying the service for features.
 @since 10.2.3
 */
@property (nonatomic, copy) NSString *definitionExpression;

/** The URL of a layer in the feature service
 @since 10.2.3
 */
@property (nonatomic, copy, readonly) NSURL *serviceURL;

/** The spatial reference that the features will be in (this must match the
 map spatial reference)
 @since 10.2.3
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** The credential to be used to access the secured feature source.
 @since 10.2.3
 */
@property (nonatomic, copy, readwrite) AGSCredential *credential;

/** The credential cache to be used for this resource. By default this will be set to the global cache.
 @since 10.2.3
 */
@property (nonatomic, strong, readwrite) AGSCredentialCache *credentialCache;


/** The block that is executed when the feature service table connects to the service.
 @since 10.2.3
 */
@property (nonatomic, copy) void (^loadCompletion)(NSError *error);

/** Error, if any, if the table could not be loaded.
 @since 10.2.3
 */
@property (nonatomic, strong, readonly) NSError *loadError;

/** Whether or not the table is loaded.
 You should not call methods on the table until it is loaded.
 @since 10.2.3
 */
@property (nonatomic, assign, readonly) BOOL loaded;

/** Initialize this layer with a URL of an ArcGIS Server Feature Service layer.
 @param url URL to a feature service layer.
 @param mode The mode in which to retrieve features.
 @param spatialReference The spatial reference that the retrieved feature will be in (this must match the map spatial reference).
 @return A new feature service layer object.
 @since 10.2.3
 */
-(instancetype)initWithServiceURL:(NSURL*)Url
                       credential:(AGSCredential*)credential
                 spatialReference:(AGSSpatialReference*)spatialReference;

/** Apply the feature edits in the local geodatabase to the service.
 The featureEditErrors is an array with objects of type AGSGDBFeatureEditError.
 @param completionBlock the block that is executed when the operation finishes
 @return <code>NSOperation</code> that performs the apply
 @since 10.2.3
 */
-(NSOperation *)applyFeatureEditsWithCompletion:(void(^)(NSArray *featureEditErrors, NSError* error))completionBlock;

/** Apply the attachment edits in the local geodatabase to the service
 The attachmentEditErrors is an array with objects of type AGSGDBFeatureEditError.
 @param completionBlock the block that is executed when the operation finishes
 @return NSSet of NSOperations the perform the apply
 @since 10.2.3
 */
-(id<AGSCancellable>)applyAttachmentEditsWithCompletion:(void (^)(NSArray *attachmentEditErrors, NSError *error))completionBlock;

/** Clears the local geodatabase and begins requerying for features
 @param discardEdits if YES then edited features are cleared from the local database too
 @since 10.2.3
 */
-(void)refreshFeaturesAndDiscardEdits:(BOOL)discardEdits;

@end
