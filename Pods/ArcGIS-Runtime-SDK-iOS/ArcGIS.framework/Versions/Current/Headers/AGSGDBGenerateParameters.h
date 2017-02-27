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

#import <Foundation/Foundation.h>
@class AGSGeometry;
@class AGSSpatialReference;
@class AGSFeatureServiceInfo;

/** @file AGSGDBGenerateParameters.h */ //Required for Globals API doc

/**  Parameters to download a sync-enabled geodatabase
 
 Instances of this class represent parameters that will be sent to the  [AGSGDBSyncTask generateGeodatabaseWithParameters:downloadFolderPath:useExisting:status:completion:] method.
 
 
 */
@interface AGSGDBGenerateParameters : NSObject <NSCoding>

/** The geographic extent within which features will be included in the sync-enabled geodatabase. Cannot be nil. To include non-spatial records, you must also specify queries.
 @since 10.2
 */
@property (nonatomic, strong) AGSGeometry *extent;

/** Array of layer ids as NSNumber objects. Cannot be nil.
 The datasets of these layers on the server will be included in the geodatabase.
 @since 10.2
 */
@property (nonatomic, copy) NSArray *layerIDs;

/** Array of AGSGDBLayerQuery objects specifiying how to filter
 features for inclusion into the sync-enabled geodatabase on a layer-by-layer basis. If not specified, all features within the extent are included. For non-spatial records, you must set
  [AGSGDBLayerQuery useGeometry] to  NO.
 @since 10.2
 */
@property (nonatomic, copy) NSArray *queries;

/** Specifies whether the geodatabase to be generated should be configured to sync with the originating service as a whole or on per
 individual layer basis.
 
 Defaults to AGSGDBSyncModelPerGeodatabase unless  initWithFeatureServiceInfo: is used to initialize the object defaults best suited for the given geodatabase.
 @since 10.2
 @see  [AGSGDBSyncTask syncGeodatabase:params:status:completion:]
 */
@property (nonatomic, assign) AGSGDBSyncModel syncModel;

/** Indicates whether or not the sync-enabled geodatabase should contain attachments for the features that are included. Defaults to NO unless initWithFeatureServiceInfo: is used to initialize the object with intelligent defaults.
 @since 10.2
 */
@property (nonatomic, assign) BOOL returnAttachments;

/**
 The spatial reference in which you would like the generated geodatabase.
 If the data on the server is not in this spatial reference, it will be reprojected on the fly.
 @since 10.2
 */
@property (nonatomic, strong) AGSSpatialReference *outSpatialReference;

/** Initialize the object
 @param extent The extent to create sync-enabled geodatabase. Cannot be nil.
 @param layerIDs An array of layer ids as NSNumber objects. Cannot be nil.
 @since 10.2
 */
-(id)initWithExtent:(AGSGeometry*)extent layerIDs:(NSArray*)layerIDs;

/** Initialize the object with defaults based on the feature service. The extent is set as the full extent of the service. All layers in the service are included. Sync model is set based on which model is supported by the service. If both models are supported, AGSGDBSyncModelPerLayer is chosen. Attachments are included.
 @since 10.2
 */
-(id)initWithFeatureServiceInfo:(AGSFeatureServiceInfo*)featureServiceInfo;

@end
