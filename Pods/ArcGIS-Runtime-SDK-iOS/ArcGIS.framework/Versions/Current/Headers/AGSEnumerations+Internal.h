/*
 COPYRIGHT 2012 ESRI
 
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

// spatial relation
AGS_EXTERN NSArray *AGSSpatialRelationshipStrings();

// geometry relation
AGS_EXTERN NSArray *AGSGeometryRelationStrings();

// geometry offset
AGS_EXTERN NSArray *AGSGeometryOffsetStrings();

// network analyst
AGS_EXTERN NSArray *AGSNAUnitStrings();
AGS_EXTERN NSArray *AGSNAOutputLineStrings();
AGS_EXTERN NSArray *AGSNAUTurnStrings();
AGS_EXTERN NSArray *AGSNALayerStrings();
AGS_EXTERN NSArray *AGSNATravelDirectionStrings();
AGS_EXTERN NSArray *AGSNADirectionsManeuverStrings();
AGS_EXTERN NSArray *AGSNAOutputPolygonStrings();
AGS_EXTERN NSArray *AGSNATimeOfDayStrings();
AGS_EXTERN NSArray *AGSNADirectionsOutputTypeStrings();
AGS_EXTERN NSArray *AGSNADirectionsStringTypeStrings();
    
    
AGS_EXTERN NSArray *AGSPortalItemTypeStrings();
AGS_EXTERN NSArray *AGSPortalAccessStrings();
AGS_EXTERN NSArray *AGSPortalUserRoleStrings();
AGS_EXTERN NSArray *AGSPortalGroupSortFieldStrings();
AGS_EXTERN AGSPortalAccess AGSPortalAccessForString(NSString *accessString);
AGS_EXTERN AGSPortalUserRole AGSPortalUserRoleForString(NSString *roleString);
AGS_EXTERN AGSPortalGroupSortField AGSPortalGroupSortFieldForString(NSString *sortFieldString);
AGS_EXTERN NSArray *AGSFileFormatStrings();
AGS_EXTERN NSString *AGSFileFormatForImageFormat(AGSImageFormat imageFormat);
AGS_EXTERN NSArray *AGSQueryStatisticsTypeStrings();
    
AGS_EXTERN NSArray *AGSTextSymbolHAlignmentStrings();
AGS_EXTERN NSArray *AGSTextSymbolVAlignmentStrings();

@class AGSAsyncServerJobContext;
/*
 blocks for Async jobs (AGSGDBSyncTask, AGSExportTileCacheTask, AGSGeoprocessor)
 */
typedef void (^AGSAsyncServerJobStartedBlock)(AGSAsyncServerJobContext *jobContext, NSError* error);

typedef NS_ENUM(NSInteger, AGSExportTileCacheRequestType) {
    AGSExportTileCacheRequestTypeExport = 0,
    AGSExportTileCacheRequestTypeEstimate
};

typedef void (^AGSExportTileCacheTaskStatusBlock)(NSString *jobId, AGSExportTileCacheJobStatus status, NSArray *messages, id result, NSError *statusRequestError, NSError *jobError);

