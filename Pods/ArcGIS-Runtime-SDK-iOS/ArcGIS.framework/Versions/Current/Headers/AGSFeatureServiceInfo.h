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
@class AGSSpatialReference;
@class AGSEnvelope;
@class AGSMapServiceDocumentInfo;
@class AGSFeatureServiceSyncCapabilities;

/** @file AGSFeatureServiceInfo.h */ //Required for Globals API doc

/**  Information about an ArcGIS Feature service
 
 This class holds metadata about an ArcGIS Feature service. The service may be hosted in the cloud on ArcGIS Online or on-premise with ArcGIS server.
 
 An instance of the class is available from  [AGSGDBSyncTask featureServiceInfo] once the task has finished loading. It may be used to instantiate an  AGSGDBGenerateParameters which will set up some convenient defaults.
 
  
 */
@interface AGSFeatureServiceInfo : NSObject <AGSCoding>

/** User-friendly description about the service.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *serviceDescription;

/** Indicates whether the service is backed by versioned data.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL hasVersionedData;

/** The maximum number of features that will be returned by the service for
 any query operation. Applications should handle re-querying the omitted results when
 this limit is reached.
 @since 10.2
 */
@property (nonatomic, assign, readonly) NSUInteger maxRecordCount;

/** Indicates whether the service allows new data to be created.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL canCreate;

/** Indicates whether the service allows existing data to be deleted.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL canDelete;

/** Indicates whether the service allows existing data to be updated.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL canUpdate;

/** Indicates whether the service allows existing data to be queried.
 @see  maxRecordCount
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL queryable;

/** Indicates whether the layer allows geometries of features to be updated.
 You should check this property before allowing the ability to update a feature's geometry in your app.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL canUpdateGeometry;

/**
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *dataFrameDescription;

/** Copyright information of the service.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *copyrightText;

/** Spatial reference of geographic data available in the service.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

/** The default extent of geographic data available in the service
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSEnvelope *initialExtent;

/** The default extent of geographic data available in the service
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSEnvelope *fullExtent;

/** The units of measurement for geographic data available in the service
 @since 10.2
 */
@property (nonatomic, assign, readonly) AGSUnits units;

/** Information about the backing map document used to create the service.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSMapServiceDocumentInfo *documentInfo;

/** Available layers in the service and their default visibility as an array of
  AGSMapServiceLayerInfo objects.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *layerInfos;

/** Available stand-alone tables in the service as an array of
  AGSMapServiceTableInfo objects. Stand-alone tables are just like layers
 except they don't have a geometry column.
 @since 10.2
 */
@property (nonatomic, strong, readonly) NSArray *tableInfos;


/** Indicates whether service supports default values for 3D geometries.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL enableZDefaults;


/** Information about sync related capabilities of the service.
 This will be nil if the service does not support sync.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSFeatureServiceSyncCapabilities *syncCapabilities;

/** Specifies the version of this particular service.
 @since 10.2.5
 */
@property (nonatomic, assign, readonly) CGFloat version;


@end
