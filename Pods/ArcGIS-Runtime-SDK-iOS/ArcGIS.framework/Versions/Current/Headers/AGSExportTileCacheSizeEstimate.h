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

/**  Size estimate of a tile cache requested by
  AGSExportTileCacheTask
 
 This class holds estimates about a tile cache requested by the
  [AGSExportTileCacheTask estimateTileCacheSizeWithParameters:status:completion:] operation
 
 
 @since 10.2
 */
@interface AGSExportTileCacheSizeEstimate : NSObject <AGSCoding>

/**
 The size of the .tpk file in bytes
 @since 10.2
 */
@property (nonatomic, assign, readonly) long long fileSize;

/**
 The number of tile in the .tpk file
 @since 10.2
 */
@property (nonatomic, assign, readonly) NSInteger tileCount;

@end
