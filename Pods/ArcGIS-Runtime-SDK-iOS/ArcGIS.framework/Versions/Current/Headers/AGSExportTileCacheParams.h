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

#import <Foundation/Foundation.h>
@class AGSGeometry;

/** @file AGSExportTileCacheParams.h */ //Required for Globals API doc

/**  Parameters for  AGSExportTileCacheTask to create and download a tile cache
 
 This class holds parameters describing the tile cache that should be returned by
  [AGSExportTileCacheTask exportTileCacheWithParameters:downloadFolderPath:useExisting:status:completion:]
 
 
 */

@interface AGSExportTileCacheParams : NSObject<NSCoding>

/**
 This is an NSArray of NSNumbers.  The numbers in the array are the
 levels of detail to be exported by the service eg. (0, 1, 2, 3, 4).
 You can inspect  [AGSExportTileCacheTask tiledServiceInfo] to find out 
 the levels available 
 @see  [AGSTileInfo lods]
 @since 10.2
 */
@property (nonatomic, copy) NSArray *levelsOfDetail;

/**
 An AGSPolygon or AGSEnvelope that defines the area to be exported.
 @since 10.2
 */
@property (nonatomic, strong) AGSGeometry *areaOfInterest;

/** Value greater than 0 and less than or equal to 1 which specifies a quality factor by which to recompress the tiles.
 This currently only works for caches which are already in the jpg format. It also must
 be a value smaller than the current compression of the cache. Default is 1.
 @since 10.2
 */
@property (nonatomic, assign) CGFloat recompressionQuality;

/**
 initialize a new AGSExportTileCacheParams
 @param lods the levels of detail to be exported
 @param aoi the area of interest to be exported
 @return a new AGSExportTileCacheParams
 @since 10.2
 */
-(id)initWithLevelsOfDetail:(NSArray*)lods areaOfInterest:(AGSGeometry*)aoi;

@end
