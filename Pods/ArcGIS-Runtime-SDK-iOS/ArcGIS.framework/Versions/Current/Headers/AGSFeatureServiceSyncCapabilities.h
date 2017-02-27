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

/** @file AGSFeatureServiceSyncCapabilities.h */ //Required for Globals API doc

/**  Capabilities supported by a sync-enabled service
 
 Instances of this class represent capabilities supported by a sync-enabled service.
 
 
 */
@interface AGSFeatureServiceSyncCapabilities : NSObject <AGSCoding>

/** Indicates whether the service supports registering existing datasets (*.geodatabase file)
 as new a sync-enabled geodatabase. This is useful when you already have a geodatabase that you want to sync
 on multiple devices independently without affecting each other.
 @since 10.2
 */
@property (nonatomic, assign) BOOL supportsRegisteringExistingData;

/** Indicates whether the service allows the client application to control direction of
 sync - upload only, download only, or bi-directional. 
 @see AGSGDBSyncDirection
 @since 10.2
 */
@property (nonatomic, assign) BOOL supportsSyncDirectionControl;

/** Indicates whether the service supports sync capabilities independently on a layer-by-layer basis in
 the sync-enabled geodatabase. For example, one layer can upload changes while another downloads during sync. A perLayer sync model also allows clients to limit the sync to a subset of layers in the geodatabase.
 @see AGSGDBSyncModel
 @since 10.2
 */
@property (nonatomic, assign) BOOL supportsPerLayerSync;

/** Indicates whether the service supports sync capabilities for the entire sync-enabled geodatabase.
 All layers in the geodatabase will be synchronized together in the same direction.
 @see AGSGDBSyncModel
 @since 10.2
 */
@property (nonatomic, assign) BOOL supportsPerGeodatabaseSync;

/** Indicates whether the service supports rolling back edits in case of a failure during sync operations.
 @since 10.2
 */
@property (nonatomic, assign) BOOL supportsRollbackOnFailure;

/** Indicates whether the service supports asynchronous operations. This avoids server timeouts.
 @since 10.2
 */
@property (nonatomic, assign) BOOL supportsAsync;

@end
