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

@class AGSGDBGeodatabase;

/** @file AGSGDBSyncParameters.h */ // Required for Globals API doc

/**  Parameters to synchronize a sync-enabled geodatabase with its originating service
 
 Instances of this class represent the parameters that will be sent to the  [AGSGDBSyncTask syncGeodatabase:params:status:completion:] method.
 
 
 */
@interface AGSGDBSyncParameters : NSObject<NSCoding>

/**
 Array of  AGSGDBLayerSyncInfo objects specifying the direction in which individual layers in the geodatabase must sync changes with the service. Not all layers need to be included in the sync operation. Some of them can be excluded by leaving them out of the array.

 Only applies if the geodatabase uses a sync model of  AGSGDBSyncModelPerLayer, else use syncDirection
 @see  [AGSGDBGeodatabase syncModel]
 @since 10.2
 */
@property (nonatomic, copy) NSArray *layerSyncInfos;

/**
 Specifies the direction in which all the layers in the sync-enabled geodatabase must sync changes with the service.
 
 Defaults to AGSGDBSyncDirectionBidirectional unless  initWithGeodatabase: is used, in which case, 
 defaults best suited to the given geodatabase are chosen.
 @see  layerSyncInfos to specify sync direction on a layer-by-layer basis.
 @since 10.2
 @note AGSGDBSyncDirectionBidirectional and AGSGDBSyncDirectionUpload options require a standard license for deployment.
 */
@property (nonatomic, assign) AGSGDBSyncDirection syncDirection;


+(instancetype)syncParameters;

/** Initializes the object and sets defaults based on the geodatabase.
 All layers in the geodatabase are included in the sync operation. The direction of the sync is set to AGSGDBSyncDirectionBidirectional if permitted by the service, else AGSGDBSyncDirectionDownload. If you want to only upload changes but not download, you can override the parameters after initialization.
 @since 10.2
 */
-(id)initWithGeodatabase:(AGSGDBGeodatabase*)geodatabase;

@end
