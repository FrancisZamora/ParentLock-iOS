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

@class AGSGDBFeatureTable;

/** @file AGSGDBGeodatabase.h */ //Required for Globals API doc

/**  A geodatabase on disk
 
 Instances of this class represent a local geodatabase containing
 geographic datasets.
 
 @see  AGSGDBSyncTask to download the geodatabase from a sync enabled ArcGIS Feature service.
  
 */
@interface AGSGDBGeodatabase : NSObject

/** The credentials that were used to download this geodatabase
 from a remote ArcGIS Feature service. Might be nil if the service 
 wasn't secured or if the geodatabase wasn't down loaded from a service.
 @since 10.2
 */
@property (nonatomic, copy, readwrite) AGSCredential *credential;

/** The full path to the geodatabase on disk, including the ".geodatabse" file extension.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *path;

/** The URL of the service from the geodatabase is created.
 @since 10.2.2
 */
@property (nonatomic, copy, readonly) NSURL *serviceURL;

/** The sync model defines how datasets within this geodatabase can be synced with the originating source.
 Only applicable if this geodatabase was originally downloaded from a sync-enabled
 ArGIS feature service.
 @see  syncEnabled
 @since 10.2
 */
@property (nonatomic, assign, readonly) AGSGDBSyncModel syncModel;

/** Indicates whether this geodatabase was originally downloaded from a sync-enabled
 ArGIS feature service.
 @since 10.2
 */
@property (nonatomic, assign, readonly, getter = isSyncEnabled) BOOL syncEnabled;

/** The ID of the replica from which the geodatabase is created.
 @since 10.2.4
 */
@property (nonatomic, copy, readonly) NSString *syncEnabledGeodatabaseID;

/** Initalize autoreleased object with a reference to a geodatabase on disk.
 @param path to geodatabase on disk
 @param error if error occurs then this is populated with the error
 @return A new, autoreleased, geodatabase object.
 @since 10.2.3
 */
+ (id)geodatabaseWithPath:(NSString *)path error:(NSError **)error;

/** Initalize autoreleased object with a reference to a geodatabase on disk.
 @param name Name of the geodatabase (excluding the .geodatabase extension) within the application bundle or shared documents directory.
 @param error if error occurs then this is populated with the error
 @return A new, autoreleased, geodatabase object.
 @since 10.2.3
 */
+ (id)geodatabaseWithName:(NSString *)name error:(NSError **)error;

/** Initalize this object with a reference to a geodatabase on disk.
 @param path to geodatabase on disk
 @param error if error occurs then this is populated with the error
 @since 10.2
 */
-(id)initWithPath:(NSString*)path error:(NSError**)error;

/** An array of  AGSGDBFeatureTable objects representing the geographic datasets
 in this geodatabase.
 @since 10.2
 */
-(NSArray*)featureTables;

/** Retrieve the dataset that corresponds to a particular layerID in the
 ArcGIS Feature Service from which this geodatabase was generated.
 @param layerID ID of the layer for which the dataset is needed.
 @return  AGSGDBFeatureTable representing the dataset
 @since 10.2
 */
-(AGSGDBFeatureTable*)featureTableForLayerID:(NSUInteger)layerID;

/** Retrieve the dataset that corresponds to a particular layer name in the
 ArcGIS Feature Service from which this geodatabase was generated.
 @param layerName Name of the layer for which the dataset is needed.
 @return  AGSGDBFeatureTable representing the dataset
 @since 10.2
 */
-(AGSGDBFeatureTable*)featureTableForLayerName:(NSString*)layerName;

/** Indicates whether the geodatabase has been edited.
 @return  YES if edited, else  NO
 @since 10.2
 */
-(BOOL)hasLocalEdits;

/** Indicates whether the geodatabase has been edited since the specified date.
 @param date
 @return  YES if edited, else  NO
 @since 10.2
 */
-(BOOL)hasLocalEditsSince:(NSDate*)date;

@end
