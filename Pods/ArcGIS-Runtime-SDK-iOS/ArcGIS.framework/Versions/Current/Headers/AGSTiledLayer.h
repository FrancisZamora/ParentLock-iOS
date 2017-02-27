/*
 COPYRIGHT 2012 ESRI
 
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

@class AGSLayer;
@class AGSTileInfo;
@class AGSLOD;

/** @file AGSTiledLayer.h */ //Required for Globals API doc

/**   A base class for tiled layers.
 
 A base class for layers which displays cached maps. You would typically work 
 with one or more sub-classes of this class, for instance,  AGSTiledMapServiceLayer.
 
 
 
 */
@interface AGSTiledLayer : AGSLayer

/** Tiling scheme for the layer. This property must be implemented by subclasses.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSTileInfo *tileInfo;

/**
 Takes the scale passed in and converts it to a scale you can zoom to on the map
 to see the tiles for that particular LOD. This takes into account how the layer
 is being rendered on the map and the PPI of the device the map is on.
 @param lodScale The scale reported by an  AGSLOD object
 @return equivalent map scale that you can zoom to
 @since 10.1.1
 */
-(double)convertedScaleForLodScale:(double)lodScale;

/**
 Takes the resolution passed in and converts it to a resolution you can zoom to on the map
 to see the tiles for that particular LOD. This takes into account how the layer
 is being rendered on the map and the PPI of the device the map is on.
 @param lodResolution The resolution reported by an  AGSLOD object
 @return equivalent map resolution that you can zoom to
 @since 10.1.1
 */
-(double)convertedResolutionForLodResolution:(double)lodResolution;

/** The current LOD that is being displayed on the map for this layer.
 If the layer is not in a map it will return nil. 
 @since 10.2.2
 */
-(AGSLOD*)currentLOD;

/** Percentage of map's extent by which a buffer of tiles will be fetched.
 A value of 1.0 corresponds to the actual visible extent. A value of 1.2 for example
 will increase the visible extent by 20 percents.
 The expansion factor will determine eventually how many additional rows an columns of tiles the layer will fetch/render
 in addition to those covering the visible extent.
 Setting this value too high will have a negative impact on performance because
 the more tiles that are fetched, the more memory is used.
 
 Default value is 1. Values in the range 1 - 2 are valid.
 Values below 1 and above 2 are ignored.
 @since 10.2.2
 */
@property (nonatomic, assign) CGFloat bufferFactor;

/** The brightness of the layer.
 Default value is 0.  Values in the range -100.0 to 100.0 are valid.
 Values outside that range are ignored.
 @since 10.2.3
 */
@property (nonatomic, assign) CGFloat brightness;

/** The contrast of the layer.
 Default value is 0.  Values in the range -100.0 to 100.0 are valid.
 Values outside that range are ignored.
 @since 10.2.3
 */
@property (nonatomic, assign) CGFloat contrast;

/** The gamma of the layer.
 Default value is 0.  Values in the range -100.0 to 100.0 are valid.
 Values outside that range are ignored.
 @since 10.2.3
 */
@property (nonatomic, assign) CGFloat gamma;


@end
