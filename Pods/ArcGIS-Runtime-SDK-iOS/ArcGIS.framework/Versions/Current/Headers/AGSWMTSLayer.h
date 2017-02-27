/*
 COPYRIGHT 2012 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and 
 Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */

@class AGSTiledServiceLayer;
@class AGSCredential;
@class AGSWMTSInfo;
@class AGSWMTSLayerInfo;
@class AGSWMTSStyle;
@class AGSSpatialReference;
@protocol AGSSecuredResource;

/** @file AGSWMTSLayer.h */ //Required for Globals API doc

/**  A layer based on an OGC-WMTS map service
 
 An instance of this class allows you to display maps from a cached WMTS map service.
 For example, http://v2.suite.opengeo.org/geoserver/gwc/service/wmts
 A cached map service uses a cache of pre-generated tiles to create a map instead of 
 dynamically generating map images. If the service permits requests in the RESTful
 style, the layer will make tile requests in this manner, otherwise requests will be made
 using KVP.
 
 
*/

@interface AGSWMTSLayer : AGSTiledServiceLayer<AGSSecuredResource>

/** The URL of the layer.
 @since 10.1.1
*/
@property (nonatomic, copy, readonly) NSURL *URL;

/** The version of the layer.
 @since 10.1.1
 */
@property (nonatomic, copy, readonly) NSString *version;

/** The copyright info for the layer.
 @since 10.1.1
 */
@property (nonatomic, copy, readonly) NSString *copyright;

/** The spatial reference of the layer,
 must be a valid EPSG code.
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** The credential to be used to access this layer's secured map service.
    Populated by the  AGSWMTSInfo object. 
 @since 10.1.1
 */
@property (nonatomic, copy, readwrite) AGSCredential *credential;

/** The credential cache to be used for this resource. By default this will be populated by the  AGSWMTSInfo object.
 @since 10.1.1
 */
@property (nonatomic, strong, readwrite) AGSCredentialCache *credentialCache;


/** The image format of the map. Possible values include
 
 @li  AGSImageFormatPNG32
 @li  AGSImageFormatPNG24
 @li  AGSImageFormatPNG8
 @li  AGSImageFormatPNG
 @li  AGSImageFormatJPG
 @li  AGSImageFormatGIF
 @li  AGSImageFormatPNGJPG
 
 Please ensure the map service supports 
 the requested image format.
 @since 10.1.1
 */

@property (nonatomic, assign) AGSImageFormat imageFormat;


/** A description of the layer's contents.
 @since 10.1.1
*/
@property (nonatomic, copy, readonly) NSString *layerDescription;

/** The title of the layer.
 @since 10.1.1
 */
@property (nonatomic, copy, readonly) NSString *title;

/** The style of the layer.
 @since 10.1.1
 */
@property (nonatomic, assign) AGSWMTSStyle *style;

/** Make a WMTS layer.
 @since 10.1.1
 */
+ (id)wmtsLayerWithUrl:(NSURL *)url
                 title:(NSString *)title
           imageFormat:(AGSImageFormat)imageFormat
         tileMatrixSet:(NSString *)tms;

/** Make a WMTS layer.
 @since 10.1.1
 */
+ (id)wmtsLayerWithUrl:(NSURL *)url
                 title:(NSString *)title
           imageFormat:(AGSImageFormat)imageFormat
         tileMatrixSet:(NSString *)tms
            credential:(AGSCredential*)credential;


/** Return a WMTS Layer from the layer info and spatial reference.
 @since 10.1.1
 */
+ (id)wmtsLayerWithWMTSInfo:(AGSWMTSInfo*)wmtsInfo wmtsLayerInfo:(AGSWMTSLayerInfo*)layerInfo spatialReference:(AGSSpatialReference*)sr;

@end
