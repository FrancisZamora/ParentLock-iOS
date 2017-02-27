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

@class AGSLayerInfo;
@class AGSDrawingInfo;
@class AGSLayerSource;
@class AGSLayerTimeOptions;

/** @file AGSDynamicLayerInfo.h */ //Required for Globals API doc

/**  Information about a layer.
 
 Instances of this class represent information about a single dynamic layer of a map service.
 
 
 @since 10.2.4
 */
@interface AGSDynamicLayerInfo : AGSLayerInfo <AGSCoding>

/** The layer source.
 @since 10.2.4
 */
@property (nonatomic, strong) AGSLayerSource *layerSource;

/** The drawing information associated with this sub-layer.
 @since 10.2.4
 */
@property (nonatomic, strong) AGSDrawingInfo * drawingInfo;

/** The definition by which to filter features.
 @since 10.2.4
 */
@property (nonatomic, copy) NSString *definitionExpression;

/** The time options per layer. Users can indicate whether or not the layer should
 use the time extent specified by the time parameter or not, whether to draw the layer
 features cumulatively or not and the time offsets for the layer.
 @since 10.2.4
 */
@property (nonatomic, strong) AGSLayerTimeOptions *layerTimeOptions;

/** Initialize a  AGSDynamicLayerInfo with the given layer ID in a dynamic map service.
 The given  AGSDrawingInfo will set the renderer used by the service to renderer the sublayer.
 The given  AGSLayerSource will be used to set a new data source for the sublayer.
 @param layerID layer id.
 @param drawingInfo drawing info specifying the renderer.
 @param layerSource layer source specifying the data source.
 @since 10.2.4
 */
-(id)initWithLayerID:(NSUInteger)layerID drawingInfo:(AGSDrawingInfo *)drawingInfo layerSource:(AGSLayerSource *)layerSource;

/** Initialize a  AGSDynamicLayerInfo with the given layer ID in a dynamic map service.
 This creates a default dynamic layer info that will use the service's renderer for
 the given layer and the layer's original data source. This constructor can be used
 with the @p dynamicLayerInfos property of  AGSDynamicMapServiceLayer to reorder layers
 in a dynamic map service without changing their renderer or data source.
 @param layerID layer id.
 @since 10.2.4
 */
-(id)initWithLayerID:(NSUInteger)layerID;

/** Initialize a  AGSDrawingInfo with the given layer ID in a dynamic map service.
 The given  AGSDrawingInfo will set the renderer used by the service to renderer the sublayer.
 The dynamic layer info will use the layer's original data source.
 @param layerID layer id.
 @param drawingInfo drawing info specifying the renderer.
 @since 10.2.4
 */
-(id)initWithLayerID:(NSUInteger)layerID drawingInfo:(AGSDrawingInfo *)drawingInfo;

/** Create a new  AGSDynamicLayerInfo with the given layer ID in a dynamic map service.
 The given  AGSDrawingInfo will set the renderer used by the service to renderer the sublayer.
 The given  AGSLayerSource will be used to set a new data source for the sublayer.
 @param layerID layer id.
 @param drawingInfo drawing info specifying the renderer.
 @param layerSource layer source specifying the data source.
 @return A new dynamic layer info object.
 @since 10.2.4
 */
+(id)dynamicLayerInfoWithLayerID:(NSUInteger)layerID drawingInfo:(AGSDrawingInfo *)drawingInfo layerSource:(AGSLayerSource *)layerSource;

/** Create a new  AGSDynamicLayerInfo with the given layer ID in a dynamic map service.
 This creates a default dynamic layer info that will use the service's renderer for
 the given layer and the layer's original data source. This constructor can be used
 with the @p dynamicLayerInfos property of  AGSDynamicMapServiceLayer to reorder layers
 in a dynamic map service without changing their renderer or data source.
 @param layerID layer id.
 @return A new dynamic layer info object.
 @since 10.2.4
 */
+(id)dynamicLayerInfoWithLayerID:(NSUInteger)layerID;

/** Create a new  AGSDynamicLayerInfo with the given layer ID in a dynamic map service.
 The given  AGSDrawingInfo will set the renderer used by the service to renderer the sublayer.
 The dynamic layer info will use the layer's original data source.
 @param layerID layer id.
 @param drawingInfo drawing info specifying the renderer.
 @return A new dynamic layer info object.
 @since 10.2.4
 */
+(id)dynamicLayerInfoWithLayerID:(NSUInteger)layerID drawingInfo:(AGSDrawingInfo *)drawingInfo;

@end
