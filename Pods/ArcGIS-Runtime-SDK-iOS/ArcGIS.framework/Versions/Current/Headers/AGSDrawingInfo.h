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


/** @file AGSDrawingInfo.h */ //Required for Globals API doc

/**  Instances of this class represent drawing information about a sub-layer of a dynamic ArcGIS Map Service.
 
 
 @since 10.2.4
*/

@interface AGSDrawingInfo : NSObject <AGSCoding>

/**  The renderer assigned to the layer.
 @since 10.2.4
 */
@property (nonatomic, strong) AGSRenderer *renderer;

/** The opacity of this layer as a value between 0(fully transparent) and 1(fully opaque)
 @since 10.2.4
 */
@property (nonatomic, assign) CGFloat opacity;

/** An array of  AGSLabelClass objects representing the labeling information associated with this sub-layer.
 @since 10.2.4
 */
@property (nonatomic, assign) NSArray *labelingInfo;

/** Determine whether the symbols are scaled or not.
 @since 10.2.4
 */
@property (nonatomic) BOOL scaleSymbols;

/** Determine whether the labels are shown or not.
 @since 10.2.4
 */
@property (nonatomic) BOOL showLabels;

/** Initialize a   AGSDrawingInfo with the given renderer and opacity.
 @param renderer renderer to be assigned to the layer.
 @param opacity opacity for the layer as a value between 0(fully transparent) and 1(fully opaque).
 @since 10.2.4
 */
-(id)initWithRenderer:(AGSRenderer *)renderer opacity:(CGFloat)opacity;

/** Create a new  AGSDrawingInfo with the given renderer and opacity.
 @param renderer renderer to be assigned to the layer.
 @param opacity opacity for the layer as a value between 0(fully transparent) and 1(fully opaque).
 @return A new drawing info object.
 @since 10.2.4
 */
+(id)drawingInfoWithRenderer:(AGSRenderer *)renderer opacity:(CGFloat)opacity;

@end
