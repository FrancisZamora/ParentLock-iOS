/*
 COPYRIGHT 2011 ESRI
 
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

@protocol AGSCoding;

@class AGSGeometry;
@class AGSMosaicRule;
@class AGSImageServiceIdentifyParameters;
@class AGSRasterFunction;
@class AGSTimeExtent;

/**  Input parameters for the Image Service Identify Task.
 
 Input parameters for an  AGSImageServiceIdentifyTask.
 
 */
@interface AGSImageServiceIdentifyParameters : NSObject <AGSCoding>

/** The geometry according to which features should be identified.  AGSPoint 
 is most commonly used for identifying features at a location, but  AGSPolygon 
 may also be used for searching within an area.
 @since 1.8
 */
@property (nonatomic, strong) AGSGeometry *geometry;

/** Specifies the mosaic rule defining the image sorting order. When mosaic rule 
 is not specified, mosaic rule will default to AGSMosaicMethodCenter. 
 @since 1.8
 */
@property (nonatomic, strong) AGSMosaicRule *mosaicRule;

/** Specifies the rendering rule for how the requested map image should be rendered.
 Valid for image service versions 10.1 and later.
@since 10.2.4
 */
@property (nonatomic, strong) AGSRasterFunction *renderingRule;

/*
 Indicates whether or not to return the raster catalog item's footprint. Set it to NO when
 the catalog item's footprint is not needed to improve the identify operation's response time.
 Defaults to NO.
 Valid for image service versions 10.1 and later.
 @since 10.2.4
 */
@property (nonatomic, assign) BOOL returnGeometry;

/*
 Description: Indicates whether or not to return raster catalog items. Set it to NO when
 catalog items are not needed to improve the identify operation's performance significantly.
 When set to NO, neither the geometry nor attributes of catalog items will be returned.
 Defaults to NO
 Valid for image service versions 10.1 and later.
 @since 10.2.4
 */
@property (nonatomic, assign) BOOL returnCatalogItems;

/** The pixel level being identified (or the resolution being looked at). If pixel
 size is not specified, then it will default to the base resolution of the dataset.
 The raster at the specified pixel size in the mosaic dataset will be used for identify.
 Use @p pixelSize when you want to specify a spatial reference along with the resolution.
 Most commonly, the @p pixelSize x and y values will simply be the resolution of the map view containing
 the image service layer and the spatial reference will be that of the map view.
 Note that @p pixelSize will take precedence over @p pixelSizeX and @p pixelSizeY if they all
 have been specified.
 @since 1.8
 */
@property (nonatomic, strong) AGSPoint *pixelSize;

/** The pixel level being identified (or the resolution being looked at) on the x-axis. If pixel
 size is not specified, then it will default to the base resolution of the dataset.
 The raster at the specified pixel size in the mosaic dataset will be used for identify.
 Note that @p pixelSize will take precedence over @p pixelSizeX and @p pixelSizeY if they all
 have been specified.
 @since 1.8
 */
@property (nonatomic, assign) double pixelSizeX;

/** The pixel level being identified (or the resolution being looked at) on the y-axis. If pixel
 size is not specified, then it will default to the base resolution of the dataset.
 The raster at the specified pixel size in the mosaic dataset will be used for identify.
 Note that @p pixelSize will take precedence over @p pixelSizeX and @p pixelSizeY if they all
 have been specified.
 @since 1.8
 */
@property (nonatomic, assign) double pixelSizeY;

/* The time instant or time extent of the raster to be identified.  If @p timeExtent's start
 and end properties are equal, then @p timeExtent is treated as a time instant.
 This parameter is only valid if the image service supports time.
 Valid for image service versions 10.1 and later.
@since 10.2.4
 */
@property (nonatomic, strong) AGSTimeExtent *timeExtent;

/** Initialize an autoreleased <code>AGSImageServiceIdentifyParameters</code> object.
 @since 1.8
 */
+(id)imageServiceIdentifyParameters;

@end

