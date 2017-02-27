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

/**  Performance optimization settings for  AGSLocator.
 
 This class holds settings to optimize the  AGSLocator for use with local address locator datasets (*.loc files)
 
 
 */
@interface AGSLocatorSettings : NSObject

/** If <code>YES</code>, locator will preload dictionaries used to lookup strings in indexes into memory.
 This increases performance and memory consumption. Enabling this option is not recommended for mobile
 applications, but suggested for desktop use cases which require massive amounts of addresses to be geocoded.
 @since 10.2
 */
@property (nonatomic, assign) BOOL preloadDictionaries;

/** If <code>YES</code>, locator will cache relations used to map values matched in indexes into actual records.
 This increases performance and memory consumption. Enabling this option is not recommended for mobile
 applications, but suggested for desktop use cases which require massive amounts of addresses to be geocoded.
 @since 10.2
 */
@property (nonatomic, assign) BOOL cacheRelations;

/** If <code>YES</code>, locator will not load and use relations which are optional. Optional relations
 improve geocoding performance, but require more memory. Enabling this option is recommended for mobile
 applications. Desktop applications should set this to <code>NO</code> in most of the cases.
 @since 10.2
 */
@property (nonatomic, assign) BOOL excludeRedundantRelations;

/** Sets memory limit in megabytes for the locator. The higher the limit, the better is the performance.
 The optimal limit depends on particular locator and use case. Please, note, that limit should be treated as
 recommendation and may be violated if set to too small value.
 @since 10.2
 */
@property (nonatomic, assign) NSUInteger memoryLimit;

@end