/*
 COPYRIGHT 2009 ESRI
 
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

@class AGSSymbol;
@class AGSGraphic;
@class AGSGraphicsLayer;
@class AGSRenderer;
@class AGSTimeExtent;

/** @file AGSRenderer.h */ //Required for Globals API doc

/** Create an <code>%AGSRenderer</code> object from JSON representation
 @param json The JSON representation of the renderer to create.
 @since 1.0
 */
AGS_EXTERN AGSRenderer *AGSRendererWithJSON(NSDictionary *json);

#pragma mark -

/**  A base class for renderers.
 
 Instances of this class represent renderers. Renderers symbolize all graphics in 
 a graphics layer according to a given scheme. This is easier than symbolizing 
 each graphic individually.
 
 
 */
@interface AGSRenderer : NSObject <AGSCoding, NSCopying>

/** The graphics layer that this renderer belongs to, if any.
 @since 2.2
 */
@property (nonatomic, weak, readonly) AGSGraphicsLayer *layer;

/** Controls the origin and direction of rotation. If the rotationType is defined as arithmetic, the symbol is rotated from East in a counter-clockwise direction where East is the 0° axis. If the rotationType is defined as geographic, the symbol is rotated from North in a clockwise direction where North is the 0° axis.
 @since 10.2.2
 */
@property (nonatomic, assign, readwrite) AGSRotationType rotationType;

/** Constant value or an expression that derives the angle of rotation based on the feature attribute value. When an attribute name is specified in rotationExpression, it's enclosed in square brackets, for example, [Rotation].
 @since 10.2.2
 */
@property (nonatomic, strong, readwrite) NSString *rotationExpression;

/** Return a symbol for the graphic based on the scheme used by this renderer.
 @param feature The feature to determine the symbol for.
 @param timeExtent The time extent to determine the symbol at.
 @return Symbol for graphic.
 @since 10.2
 */
-(AGSSymbol*)symbolForFeature:(id<AGSFeature>)feature timeExtent:(AGSTimeExtent*)timeExtent;

/** Returns an image that represents a swatch for a feature.
 @param attributes Attributes of the feature for which the swatch should be drawn. This is used to determine what symbol in the renderer is used.
 @param geometryType The type of the geometry determines what kind of swatch is drawn.
 @param size Size of the output swatch.
 @return AGSImage of the drawn swatch.
 @since 10.2
 */
-(AGSImage *)swatchForFeatureWithAttributes:(NSDictionary*)attributes geometryType:(AGSGeometryType)geometryType size:(CGSize)size;
    
/** Returns an image that represents a swatch for a particular feature. The feature must have a valid geometry.
 @param feature Feature for which the swatch should be drawn. This is used to determine what symbol in the renderer is used.
 @param size Size of the output swatch.
 @return AGSImage of the drawn swatch.
 @since 10.2
 */
- (AGSImage *)swatchForFeature:(id<AGSFeature>)feature size:(CGSize)size;

/** Returns an image that represents a swatch for a particular feature. This method can be used when your feature does not have a geometry
 but you know the geometry type.
 @param feature Feature for which the swatch should be drawn. This is used to determine what symbol in the renderer is used.
 @param geometryType The type of the geometry determines what kind of swatch is drawn.
 @param size Size of the output swatch.
 @return AGSImage of the drawn swatch.
 @since 10.2
 */
- (AGSImage *)swatchForFeature:(id<AGSFeature>)feature geometryType:(AGSGeometryType)geometryType size:(CGSize)size;

//
// deprecated
//

/** Return a symbol for the graphic based on the scheme used by this renderer.
 @param graphic The graphic to determine symbol.
 @param timeExtent The time extent to determine the symbol at.
 @return Symbol for graphic.
 @deprecated Deprecated at 10.2. Please use  [AGSRenderer symbolForFeature:timeExtent:] instead.
 @since 1.8
 */
-(AGSSymbol*)symbolForGraphic:(AGSGraphic*)graphic timeExtent:(AGSTimeExtent*)timeExtent __attribute__((deprecated));

/** Returns an image that represents a swatch for a particular graphic. The graphic must have a valid geometry.
 @param graphic Graphic for which the swatch should be drawn. This is used to determine what symbol in the renderer is used.
 @param size Size of the output swatch.
 @return AGSImage of the drawn swatch.
 @deprecated Deprecated at 10.2. Please use  [AGSRenderer swatchForFeature:size:] instead.
 */
- (AGSImage *)swatchForGraphic:(AGSGraphic *)graphic size:(CGSize)size __attribute__((deprecated));

/** Returns an image that represents a swatch for a particular graphic. This method can be used when your graphic does not have a geometry
 but you know the geometry type.
 @param graphic Graphic for which the swatch should be drawn. This is used to determine what symbol in the renderer is used.
 @param geometryType The type of the geometry determines what kind of swatch is drawn.
 @param size Size of the output swatch.
 @return AGSImage of the drawn swatch.
 @deprecated Deprecated at 10.2. Please use  [AGSRenderer swatchForFeature:geometryType:size:] instead.
 */
- (AGSImage *)swatchForGraphic:(AGSGraphic *)graphic geometryType:(AGSGeometryType)geometryType size:(CGSize)size __attribute__((deprecated));

@end


