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

@class AGSTask;
@class AGSLocalTiledLayer;
@class AGSMapServiceInfo;
@class AGSExportTileCacheParams;
@class AGSExportTileCacheSizeEstimate;
@protocol AGSResumableTaskJob;

/** Notification to indicate the task loaded  [AGSExportTileCacheTask tiledServiceInfo]
 @since 10.2
 */
AGS_EXTERN NSString *const AGSExportTileCacheTaskDidLoadNotification;

/** Notification to indicate the task failed to load  [AGSExportTileCacheTask tiledServiceInfo]
 @since 10.2
 */
AGS_EXTERN NSString *const AGSExportTileCacheTaskDidFailToLoadNotification;

/** @file AGSExportTileCacheTask.h */ //Required for Globals API doc

/**  A task to download a basemap tiles
 
 This class represents a task that can be used to download tiles (as a tile package) from
 supporting ArcGIS Map services. The service could be hosted in the cloud on ArcGIS Online or
 on-premise with ArcGIS servers.
 
 @see 
 */

@interface AGSExportTileCacheTask : AGSTask

/** The interval at which status for jobs are checked.
 @since 10.2
 */
@property (nonatomic, assign) NSTimeInterval interval;

/** Information about the tile service such as scale visibility, tiling scheme, etc.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSMapServiceInfo *tiledServiceInfo;

/** Whether or not the  tiledServiceInfo has been retrieved. You do not have to wait for this property to be
 YES before calling methods on the task. But it's helpful if you need to generate parameters based on the service information.
 @see  loadCompletion
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL loaded;

/** The error, if any, while retrieving tiledServiceInfo.
 @since 10.2
 */
@property (nonatomic, strong, readonly) NSError *loadError;

/** The block that is executed when the task loads or fails to load the  tiledServiceInfo.
 @since 10.2
 */
@property (nonatomic, copy) void (^loadCompletion)(NSError *error);

#if TARGET_OS_IPHONE

/**Whether or not the status and completion blocks are allowed to be called when the app is in the background.
 If this is NO then the completion block will not be fired until the app comes back into the foreground. This is
 useful when you want to show a local notification if your task completes when the app is in the background. The
 default for this property is <code>YES</code>.
 
 There are a few different ways for callbacks to happen in the background. The most common way is for your application
 to support the "background fetch" capability. This is only available on iOS7 and above. When your application is
 in woken up with the following app delegate method -[UIApplication application:performFetchWithCompletionHandler:]
 your application should call +[AGSTask checkStatusForAllResumableTaskJobsWithCompletion:] so that any jobs that are
 currently active will fetch their status. In the event a job has completed, a download will be kicked off using
 NSURLSession and that download will continue even if your app is killed by the OS. The only time a download will
 be stopped is when the user explicitly kills the application.
 
 In some rare cases you can get callbacks in the background in other ways. One of those cases would be if the app
 is sent to the background while the result of the job was being downloaded and the download then completed within
 the allotted time for a background process (10 minutes on iOS 6 and 3 minutes on iOS 7).
 @since 10.2
 */
@property (nonatomic, assign) BOOL allowCallbackWhenAppInBackground;
#endif

/** Initialize the task with a URL and credential to a secured resource.
 @param url URL to a task resource in the ArcGIS Server REST Services Directory.
 @param cred <code>AGSCredential</code> used to access secure resource.
 @return A new task object.
 @since 1.0
 */
-(id)initWithURL:(NSURL *)url credential:(AGSCredential *)cred;

/**
 Retrieves the estimated size of the TPK file for the given parameters
 @param parameters The parameters used to create the estimate
 @param status A block that will be invoked when  [AGSExportTileCacheTask estimateSizeWithParameters:status:completion:] has a new status to report.
 @param completion A block that will be invoked when the size estimate is ready
 */
-(id<AGSResumableTaskJob>)estimateTileCacheSizeWithParameters:(AGSExportTileCacheParams*)parameters
                                                       status:(void(^)(AGSResumableTaskJobStatus status, NSDictionary *userInfo))statusBlock
                                                   completion:(void(^)(AGSExportTileCacheSizeEstimate *exportTileCacheSizeEstimate, NSError* error))completionBlock;

/**
 Resumes the estimate job with the specified resumeID.
 @param resumeID The ID with which to resume the estimate job.
 @param status A block that will be invoked when  [AGSExportTileCacheTask estimateSizeWithParameters:status:completion:] has a new status to report.
 @param completion A block that will be invoked when the size estimate is ready
 @since 10.2.2
 */
-(id<AGSResumableTaskJob>)estimateTileCacheSizeWithResumeID:(NSString*)resumeID
                                                     status:(void(^)(AGSResumableTaskJobStatus status, NSDictionary *userInfo))statusBlock
                                                 completion:(void(^)(AGSExportTileCacheSizeEstimate *exportTileCacheSizeEstimate, NSError* error))completionBlock;


/**
 All-in-one method to call to ask the server to create a tile cache with specified parameters
 and download it after it's created.
 If you have an existing tile cache on the device that matches those parameters then it will use that one unless
 the useExisting parameter is NO.
 This method handles when the device goes in the background and fore-ground. It will also find jobs that
 match the parameters that are still executing even if the app gets evicted and you call this method after
 the app is launched again. The only issues that arise when the user backgrounds the app are job expirations
 on the server, if the user doesn't come back into the app before the job expires, the job will need to be kicked
 off again.
 @param parameters The parameters with which the tile cache will be exported. This can be nil in which
 case it will download all the LODs in the service and at the full extent.
 @param downloadFolderPath The path to the folder that you want the tile cache downloaded to. This can be nil in
 which case a default folder (ie. documents directory) is chosen.
 @param useExisting Whether or not to use an existing tile cache on the devices whose parameters match the one you are asking for.
 @since 10.2
 @see  [AGSTask checkStatusForAllResumableTaskJobsWithCompletion:] to monitor job status even when the app is in the background
 @see  [AGSRequest allowsCellularAccessForDownloads] to prevent downloading tile packages over cellular network
 */
-(id<AGSResumableTaskJob>)exportTileCacheWithParameters:(AGSExportTileCacheParams*)parameters
                                     downloadFolderPath:(NSString*)downloadFolderPath
                                            useExisting:(BOOL)useExisting
                                                 status:(void(^)(AGSResumableTaskJobStatus status, NSDictionary *userInfo))statusBlock
                                             completion:(void(^)(AGSLocalTiledLayer *localTiledLayer, NSError* error))completionBlock;

/**
 All-in-one method to resume a previous job to create and download a TPK.
 This method handles when the device goes in the background and fore-ground. If the resumed job is no longer valid, a 
 new job will be kicked off with the same @p parameters and @p downloadFolderPath as the original.
 @param resumeID The ID with which to resume the export and download of the tile cache.
 case it will download all the LODs in the service and at the full extent.
 @since 10.2.2
 @see  [AGSTask checkStatusForAllResumableTaskJobsWithCompletion:] to monitor job status even when the app is in the background
 @see  [AGSRequest allowsCellularAccessForDownloads] to prevent downloading tile packages over cellular network
 */
-(id<AGSResumableTaskJob>)exportTileCacheWithResumeID:(NSString*)resumeID
                                               status:(void(^)(AGSResumableTaskJobStatus status, NSDictionary *userInfo))statusBlock
                                           completion:(void(^)(AGSLocalTiledLayer *localTiledLayer, NSError* error))completionBlock;

@end
