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

@class AGSLayer;
@class AGSMapContentsTree;
@class AGSWebMapBaseMap;
@class AGSWebMapFeatureCollection;

/**  Represents a layer in a map.
 
 Represents a layer in a map. Includes both visibility information as well as cartographic
 information. This could be useful for a number of UI components, including a table of contents,
 legend, etc.
 
 @since 10.2
 */

@interface AGSMapContentsLayerInfo : NSObject {}

/**
 Indicates whether layer is visibile in the map or not. Visibility 
 set to YES does not guarantee that a scale dependency is rendering
 a particular layer visible. 
 @since 10.2
 */
@property (nonatomic, assign) BOOL visible;


/**
 Title of layer
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString* title;

/**
 Name of layer (as it exists in map view)
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString* layerName;

/**
 Indicates whether the visibility of this layer can be changed
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL canChangeVisibility;

/**
 Layer as it's represented in map view
 @since 10.2
 */
@property (nonatomic, weak, readonly) AGSLayer* layer;

/**
 An array of sub layers (if sublayers exist). Nil otherwise
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray* subLayers;

/**
 An array of legend items.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray* legendItems;

/**
 Indicates whether to show legend information
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL showLegend;

/**
 Parent of this this node
 @since 10.2
 */
@property (nonatomic, weak, readonly) AGSMapContentsLayerInfo* parent;

/**
 Returns YES if layer is visible with scale dependency at given map scale
 @since 10.2
 */
- (BOOL)visibleAtMapScale:(double)mapScale;

/**
 Refreshes the content based on the current layer property.  Only
 applies to  AGSDynamicMapServiceLayers.  This should be called
 when any changes are made to how the dynamic layer is rendered, such
 as changes to the  AGSDynamicMapServiceLayer @p dynamicLayerInfos property.
 @since 10.2.4
 */
-(void)refresh;

@end


