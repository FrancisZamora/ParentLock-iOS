/*
 COPYRIGHT 2013 ESRI
 
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

#import "AGSTiledServiceLayer.h"

@class AGSTileInfo;
@class AGSSpatialReference;
@class AGSEnvelope;
/**  A layer based on non-ArcGIS map tiles.
 
 An instance of this class provides a simple way to add non-ArcGIS map tiles as a layer to a map.
 
 The tiles are fetched through a template URL such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc.
 
 
 
 @since 10.2.3
 */

@interface AGSWebTiledLayer : AGSTiledServiceLayer <AGSSecuredResource>

/** A template URL for the tile service such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc. For eg. http://{subDomain}.tile.opencyclemap.org/cycle/{level}/{col}/{row}.png
 
 @since 10.2.3
 */
@property (nonatomic, copy, readonly) NSString* templateURL;

/** The credential to be used to access this layer's secured service.
 @since 10.2.3
 */
@property (nonatomic, copy, readwrite) AGSCredential *credential;

/** The credential cache to be used for this resource. By default this will be set to the global cache.
 @since 10.2.3
 */
@property (nonatomic, strong, readwrite) AGSCredentialCache *credentialCache;

/** Initializes a  AGSWebTileLayer object.
 @param templateURL of the tile service such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc. For eg. http://{subDomain}.tile.opencyclemap.org/cycle/{level}/{col}/{row}.png
 @param tileInfo defining the tiling scheme; if nil the Open Street Map tiling scheme is used.
 @param spatialReference of the tile service; if nil the spatial reference of the full extent is used.
 @param fullExtent of the tile service; if nil the extent of the world in web mercator is used.
 @param subdomains used for load balancing tile requests if supported by the service, for eg. a,b,c for Open Cycle Map. If nil the templateURL should not contain {subDomain}
 @since 10.2.3
 */
-(id)initWithTemplateURL:(NSString*)templateURL
                tileInfo:(AGSTileInfo*)tileInfo
        spatialReference:(AGSSpatialReference*)sr
              fullExtent:(AGSEnvelope*)fullExtent
              subdomains:(NSArray*)subdomains;

/** Initializes a  AGSWebTileLayer object.
 @param templateURL of the tile service such as http://{subDomain}.host.com/{level}/{col}/{row}.png where {level} corresponds to a zoom level, and {col} and {row} represent tile column and row, respectively. The file extension may change depending upon the image format used by the service, and {subDomain} may not be present. This pattern is not required, but is the most common one on the web currently and used by Map Quest, Open Cycle Map, Stamen, Bing, etc. For eg. http://{subDomain}.tile.opencyclemap.org/cycle/{level}/{col}/{row}.png
 @param tileInfo defining the tiling scheme; if nil the Open Street Map tiling scheme is used.
 @param spatialReference of the tile service; if nil the spatial reference of the full extent is used.
 @param fullExtent of the tile service; if nil the extent of the world in web mercator is used.
 @param subdomains used for load balancing tile requests if supported by the service, for eg. a,b,c for Open Cycle Map. If nil the templateURL should not contain {subdomain}
 @param credential to be used to access this layer's secured service
 @since 10.2.3
 */
-(id)initWithTemplateURL:(NSString*)templateURL
                tileInfo:(AGSTileInfo*)tileInfo
        spatialReference:(AGSSpatialReference*)sr
              fullExtent:(AGSEnvelope*)fullExtent
              subdomains:(NSArray*)subdomains
              credential:(AGSCredential*)credential;

@end
