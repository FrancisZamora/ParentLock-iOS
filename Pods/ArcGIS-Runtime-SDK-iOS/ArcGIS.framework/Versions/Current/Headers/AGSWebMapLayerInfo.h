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

@class AGSWebMapFeatureCollection;
@class AGSPopupInfo;
@class AGSLayer;
@class AGSFeatureLayer;
@class AGSTileInfo;
@class AGSEnvelope;
@class AGSMosaicRule;
@class AGSRasterFunction;

/** @file AGSWebMapLayerInfo.h */ //Required for Globals API doc

/**  Information about top-level layers in a webmap
 
 Instances of this class represent information about top-level layers (such as map service layer, bing maps layer, openstreetmap layer, feature layer, feature collection, wms layer, etc) in the web map. 
 
 @since 2.2
 */
@interface AGSWebMapLayerInfo : NSObject <AGSCoding>

/**Initialize the layer info with provided details.
 @param title
 @param URL
 @param opacity
 @param lyrtype
 @param visibility
 @since 10.2
 */
- (id)initWithTitle: (NSString *) title
                url: (NSURL *) URL
            opacity: (float) opacity
          layerType: (NSString *) lyrtype
         visibility:(BOOL)visibility;

/** Initialize the layer info with a layer.
 @param mapLayer
 @since 10.2
 */
-(id)initWithMapLayer:(AGSLayer*)mapLayer;

/** The id of the layer in the webmap.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *layerId;

/** The id of an item containing default information for the layer. The item resides on the same portal as the webmap.
 @since 2.2
 */
@property (nonatomic, copy, readonly) NSString *itemId;

/** The title of the layer in the webmap.
 @since 2.2
 */
@property (nonatomic, copy, readwrite) NSString *title;

/** URL of the layer's backing service.
 @since 2.2
 */
@property (nonatomic, strong, readwrite) NSURL *URL; 

/** If the value is 1, the layer is fully opaque. If 0, the layer is fully transparent.
 @since 2.2
 */
@property (nonatomic, readwrite) float opacity;

/** The type of the layer. For example, OpenStreetMap, BingMapsAerial, BingMapsRoad, BingMapsHybrid, WMS, CSV, etc
 @since 2.2
 */
@property (nonatomic, copy, readwrite) NSString *layerType;

/** Whether the layer is visible or not.
 @since 2.2
 */
@property (nonatomic, readwrite) BOOL visibility;

/** If YES, then the layer should be drawn on top of all other layers in the web map. Else, it should be drawn
 based on the order it was stored in the web map. This property only applies to basemap layers, not to operational layers.
 @since 2.2
 */
@property (nonatomic, assign, readwrite) BOOL isReference;

/** Only applicable if the layer is a feature collection. A feature collection is a representation of one or more feature layers, where each layer contains the definition of that layer and the features that belong to that layer.
 @since 2.2
 */
@property (nonatomic, strong, readwrite) AGSWebMapFeatureCollection *featureCollection;

/** Only applies if the layer is a feature layer. A value of 0 implies  AGSFeatureLayerModeSnapshot, 1 implies  AGSFeatureLayerModeOnDemand, and 2 implies  AGSFeatureLayerModeSelection. 
 @since 2.2
 */
@property (nonatomic, assign, readwrite) NSInteger mode;

/** A popup definition for the layer.
 @since 2.2
 */
@property (nonatomic, strong, readwrite) AGSPopupInfo *popupInfo;

/** An array of  AGSWebMapSubLayerInfo objects representing the sublayers of the layer. 
 For example, if the layer is based on an ArcGIS map service. Each sublayer will have an id and optionally a popup definition.
 @since 2.2
 */
@property (nonatomic, copy, readwrite) NSArray *layers;

/** An array of sub-layer ids that should be visible
 @since 2.2
 */
@property (nonatomic, copy, readwrite) NSArray *visibleLayers;

/** Only applicable if the layer is a feature layer or image service layer. This is the JSON returned by a Map or Feature Service for one of its layers, for example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/SanFrancisco/311Incidents/FeatureServer/0?f=pjson. 
 @since 2.2
 */
@property (nonatomic, copy, readwrite) NSDictionary *layerDefinition;

/** A property indicating whether the web map should show the features from this service in the legend.
 @since 2.3
 */
@property (nonatomic, assign, readwrite) BOOL showLegend;

/** Array of bandIds to override the image service layer's defaults.
 @since 2.3
 */
@property (nonatomic, copy, readwrite) NSArray *bandIds;

/** The minimum scale at which this layer is visible. If the map is zoomed out
 beyond this scale, the layer will not be visible.
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) double minScale;

/** The maximum scale at which this layer is visible. If the map is zoomed in
 beyond this scale, the layer will not be visible.
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) double maxScale;

/** The time interval in minutes that will cause the layer to auto-refresh.
 If 0 or less is specified, the layer will not auto-refresh itself.
 @since 10.2.4
 */
@property (nonatomic, assign, readwrite) double refreshInterval;

/** A property indicating whether the web map has disabled editing for the features in this layer
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) BOOL isEditingDisabled;

/** The layer on the map that this is associated with.
 This property will be nil if this AGSWebMapLayerInfo has an AGSWebMapFeatureCollection.
 (In which cases, look at the mapLayer property of the AGSWebMapSubLayerInfos on the AGSWebMapFeatureCollection.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSLayer *mapLayer;

/** The AGSFeatureLayer that is associated with this AGSWebMapLayerInfo.
 If this is populated then it's the same as the mapLayer as the mapLayer represents an AGSFeatureLayer in those cases.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSFeatureLayer *backingFeatureLayer;

/** The url of the portal that potentially contains information to access this layer such as the bing maps key.
 @since 10.2
 */
@property (nonatomic, strong, readwrite) NSURL *portalURL;

/** The AGSTileInfo associated with this AGSWebMapLayerInfo.
 If this is populated the layer is a web tiled layer
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSTileInfo *tileInfo;

/** The AGSEnvelope of the full extent of the service associated with this AGSWebMapLayerInfo.
 If this is populated the layer is a web tiled layer
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSEnvelope *fullExtent;

/** The web tiled layer template URL associated with this AGSWebMapLayerInfo.
 If this is populated the layer is a web tiled layer
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *templateURL;

/** The subdomains of the web tiled layer associated with this AGSWebMapLayerInfo.
 @since 10.2.3
 */
@property (nonatomic, copy, readonly) NSArray *subDomains;

/** Determines whether popups are disabled for this layer.
 @since 10.2
 */
@property (nonatomic, assign, readwrite) BOOL disablePopup;

/** The format of the layer.  For  AGSImageFormatJPGPNG, the image format is a JPG if
 there are no transparent pixels; otherwise, it is a PNG (png32).
 This only applies to  AGSImageServiceLayer layers.
 @since 10.2.4
 */
@property (nonatomic, assign, readwrite) AGSImageFormat format;

/** Controls how much loss the image will be subjected to by the compression algorithm.
 Valid value ranges of compression quality are from 0 to 100.  The compression quality
 works for the JPEG format, JPGPNG (if the result is a JPG), and TIFF with JPEG compression.
 This only applies to  AGSImageServiceLayer layers.
 @since 10.2.4
 */
@property (nonatomic, assign, readwrite) NSInteger compressionQuality;

/** The resampling process of extrapolating the pixel values while transforming
 the raster dataset when it undergoes warping or when it changes coordinate space.
 This only applies to  AGSImageServiceLayer layers.
 @since 10.2.4
 */
@property (nonatomic, assign, readwrite) AGSInterpolation interpolation;

/** Description: The pixel value representing no information.  The value can be either an NSNumber
 or an NSString
 
 Example 1: noData=0—A pixel is transparent when the pixel value of any band is 0.  Value is an NSNumber
 
 Example 2: noData=58,128,187—Added at 10.0 SP2. When a pixel matches a nodata value, the pixel will be rendered transparent.
 value is an NSString with three comma-separated values
 This only applies to  AGSImageServiceLayer layers.
 @since 10.2.4
 */
@property (nonatomic, strong, readwrite) id noData;

/** Interpretation of the noData setting.  The default is esriNoDataMatchAny when noData is a
 single number and esriNoDataMatchAll when noData is a comma-delimited string.
 Example 1: noData=0&noDataInterpretation=esriNoDataMatchAll—A pixel is transparent only if the pixel value is 0 for all bands.
 Example 2: noData=58,128,187&noDataInterpretation=esriNoDataMatchAll—A pixel is transparent when the pixel value is 58,128,187. Equivalent of noData=58,128,187.
 Example 3: noData=0&noDataInterpretation=esriNoDataMatchAny—A pixel is transparent if any band is 0.
 This only applies to  AGSImageServiceLayer layers.
 @since 10.2.4
 */
@property (nonatomic, assign, readwrite) AGSNoDataInterpretation noDataInterpretation;

/** Specifies the mosaic rule when defining how individual images should be mosaicked.
 This only applies to  AGSImageServiceLayer layers.
 @since 10.2.4
 */
@property (nonatomic, strong, readwrite) AGSMosaicRule *mosaicRule;

/** Specifies the rendering rule for how the requested image should be rendered.
 This only applies to  AGSImageServiceLayer layers.
 @since 10.2.4
 */
@property (nonatomic, strong, readwrite) AGSRasterFunction *renderingRule;

@end




