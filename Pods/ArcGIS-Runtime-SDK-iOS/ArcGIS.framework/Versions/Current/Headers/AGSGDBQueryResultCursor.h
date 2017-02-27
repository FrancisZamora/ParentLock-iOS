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

@class AGSGDBFeature;

/** @file AGSGDBQueryResultCursor.h */ //Required for Globals API doc

/**  A cursor for query results
 
 This class represent a results cursor for queries on a local geodatabase.
 You need to call  reset and then  next to advance the cursor to the first result.
 
 
 @since 10.2
 */
@interface AGSGDBQueryResultCursor : NSObject <NSFastEnumeration>

/** The current results as a feature.
 Only available if geodatabase was queried for features.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSGDBFeature *currentFeature;

/** The current result as a group of statistics.
 Only available if geodatabase was queried for statistics.
 @since 10.2
 */
@property (nonatomic, strong, readonly) NSDictionary *currentStatistics;

/** Advance the cursor to the next result.
 You need to call  reset and then  next to advance the cursor to the first result.
 @return  YES, if cursor was advanced, @NO if no more results
 @since 10.2
 */
-(BOOL)next;

/** Reset the cursor to the begining of the results.
 You need to call  reset and then  next to advance the cursor to the first result.
 @since 10.2
 */
-(void)reset;

@end
