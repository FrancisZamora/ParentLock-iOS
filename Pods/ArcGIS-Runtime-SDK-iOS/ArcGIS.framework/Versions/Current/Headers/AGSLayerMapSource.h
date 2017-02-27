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

#import "AGSLayerSource.h"

/** @file AGSLayerMapSource.h */ //Required for Globals API doc

/**  An on-the-fly created layer source.
 
 Instances of this class represent a layer created from an existing map service layer.
 
 @since 10.2.4
 */
@interface AGSLayerMapSource : AGSLayerSource

/** The source map layer id.
 @since 10.2.4
 */
@property (nonatomic, assign) NSInteger mapLayerID;

/** If supported, use geodatabaseVersion to specify an alternate geodatabase version.
 @since 10.2.4
 */
@property (nonatomic, copy) NSString *geodatabaseVersion;

/** Initialize a   AGSLayerMapSource with the map layer id and optionally an alternate geodatabase version.
 @param mapLayerID map layer ID.
 @param geodatabaseVersion specifies an alternate geodatabase version.  If not requried, use @p nil.
 @since 10.2.4
 */
-(id)initWithMapLayerID:(NSInteger) mapLayerID geodatabaseVersion:(NSString *)geodatabaseVersion;

/** Create a new  AGSLayerMapSource with the map layer id and optionally an alternate geodatabase version.
 @param mapLayerID map layer ID.
 @param geodatabaseVersion specifies an alternate geodatabase version.  If not requried, use @p nil.
 @return A new unique value layer map source.
 @since 10.2.4
 */
+(id)layerMapSourceWithMapLayerID:(NSInteger) mapLayerID geodatabaseVersion:(NSString *)geodatabaseVersion;

@end
