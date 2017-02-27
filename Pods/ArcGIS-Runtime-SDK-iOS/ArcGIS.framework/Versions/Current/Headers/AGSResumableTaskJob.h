/*
 COPYRIGHT 2014 ESRI
 
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

@protocol AGSPausable;

/** @file AGSResumableTaskJob */ //Required for Globals API doc

/**  A protocol exposed by operations that allow resumption
 
 A protocol exposed by operations that allow resumption in the event
 an application was backgrounded or killed by the OS before the operation completed.
 
 
 @since 10.2.2
 */
@protocol AGSResumableTaskJob <AGSPausable>

/** The ID with which the operation can be resumed.
 @since 10.2.2
 */
@property (nonatomic, copy, readonly) NSString *resumeID;

/** The type of resumable task. Possible values include the following string constants

 @li  AGSResumableTaskJobTypeGenerateGeodatabase
 @li  AGSResumableTaskJobTypeSyncGeodatabase
 @li  AGSResumableTaskJobTypeExportTileCacheSizeEstimate
 @li  AGSResumableTaskJobTypeExportTileCache
 
 @since 10.2.2
 */
@property (nonatomic, copy, readonly) NSString *jobType;

@end
