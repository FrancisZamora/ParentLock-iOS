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

/** @file AGSDynamicLayer.h */ //Required for Globals API doc

/**  A base class for dynamic layers.
 
 A base class for dynamic layers. You would typically work with concrete dynamic 
 layers represented by the sub-classes of this class, for instance, 
  AGSDynamicMapServiceLayer.
 
 
 
 */
@interface AGSDynamicLayer : AGSLayer

/** The time interval in seconds that will cause the layer to auto-refresh.
 If 0 or less is specified, the layer will not auto-refresh itself.
 @since 10.1.1
 */
@property (nonatomic, assign) double autoRefreshInterval;

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
