/*
 COPYRIGHT 2010 ESRI
 
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

/** @file AGSRasterFunction.h */

/**  The rendering rule to be used for an image service's export image
 operation.
 
 Specifies the processing to be done to the image service.
 
 */
@interface AGSRasterFunction : NSObject <AGSCoding>

/** The raster function type.  These are documented well-known raster functions.  Refer to
 the link in arguments for more information.
 @since 1.8
 */
@property (nonatomic, assign) AGSRasterFunctionType type;

/** A server or client defined raster function template.
 If a  rasterFunctionName exists, it will supercede the  type property.
 @since 10.2.4
 */
@property (nonatomic, copy) NSString *rasterFunctionName;

/** The input arguments to the raster function, in the form of an NSDictionary.
 The dictionary must be based on the JSON syntax of the arguments. Refer to the
 [REST API [documentation](http://resources.arcgis.com/en/help/arcgis-rest-api/index.html //02r3000000rv000000)]
 for the JSON syntax.
 @since 1.8
 */
@property (nonatomic, strong) NSMutableDictionary *arguments;
	
@end
