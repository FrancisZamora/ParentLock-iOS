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
@class AGSGeometry;
@class AGSGDBGenerateParameters;
@class AGSFeatureServiceInfo;
@class AGSGDBGeodatabase;
@class AGSGDBSyncParameters;
@class AGSGDBSyncTaskStatusInfo;
@class AGSGDBEditErrors;
@protocol AGSCancellable;
@protocol AGSResumableTaskJob;

/** Notification to indicate the task loaded  [AGSGDBSyncTask featureServiceInfo]
 @since 10.2
 */
AGS_EXTERN NSString *const AGSGDBSyncTaskDidLoadNotification;

/** Notification to indicate the task failed to load  [AGSGDBSyncTask featureServiceInfo]
 @since 10.2
 */
AGS_EXTERN NSString *const AGSGDBSyncTaskDidFailToLoadNotification;

/** @file AGSGDBSyncTask.h */ //Required for Globals API doc

/**  A task to download a sync-enabled geodatabase
 
 This class represents a task that can be used to create and download a sync-enabled geodatabase from
 a sync-enabled ArcGIS Feature service. The service could be hosted in the cloud on ArcGIS Online or
 on-premise with ArcGIS servers.
 
 @see oncept{create-an-offline-map.htm, Create an offline map}
 @see oncept{sync-offline-edits.htm, Sync offline edits}
 @see 
 */
@interface AGSGDBSyncTask : AGSTask

/** The interval at which status for jobs are checked.
 @since 10.2
 */
@property (nonatomic, assign) NSTimeInterval interval;

/** Whether or not the featureServiceInfo has been retrieved. You do not have to wait for this property to be 
 YES before calling methods on the task.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL loaded;

/** The service information for the URL that this task was instantiated with.
 This is nil until that task has completed loading.
 @see  loaded
 @see  loadCompletion
 @since 10.2
 */
@property (nonatomic, strong) AGSFeatureServiceInfo *featureServiceInfo;

/** The block that is executed when the task loads or fails to load the  featureServiceInfo.
 @since 10.2
 */
@property (nonatomic, copy) void (^loadCompletion)(NSError *error);

/** The error, if any, that occurred when trying to load the task.
 @since 10.2
 */
@property (nonatomic, strong, readonly) NSError *loadError;

#if TARGET_OS_IPHONE

/**  Whether or not the status and completion blocks are allowed to be called when the app is in the background.
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

/** Register an existing sync-enabled geodatabase as a new sync-enabled geodatabase with the service. The geodatabase can then sync changes with the service indepedently of any other copies of the geodatabase that may exist.
 @param geoadatabase The sync-enabled geodatabase to register
 @param completion The block that will be invoked when the operation completes.
 @return A handle to the operation incase you want to cancel it
 @since 10.2
 */
-(id<AGSCancellable>)registerSyncEnabledGeodatabase:(AGSGDBGeodatabase*)geodatabase completion:(void (^)(NSError *error))completion;

/** Unregister an existing sync-enabled geodatabase from the service. The geodatabase will not be able to sync with the service hereafter.
 The local geodatabase will be left behind, but all information about the geodatabase on the service will be removed.
 @param geodatabase The sync-enabled geodatabase to unregister
 @param completion The block that will be invoked when the operation completes.
 @return A handle to the operation incase you want to cancel it
 @since 10.2
 */
-(id<AGSCancellable>)unregisterSyncEnabledGeodatabase:(AGSGDBGeodatabase*)geodatabase completion:(void (^)(NSError *error))completion;

/** Unregister an existing sync-enabled geodatabase from the service. The geodatabase will not be able to sync with the service hereafter.
 The local geodatabase will be left behind, but all information about the geodatabase on the service will be removed.
 @param syncEnabledGeodatabaseID from the sync-enabled geodatabase to unregister
 @param completion The block that will be invoked when the operation completes.
 @return A handle to the operation incase you want to cancel it
 @since 10.2.4
 */
-(id<AGSCancellable>)unregisterSyncEnabledGeodatabaseWithID:(NSString*)syncEnabledGeodatabaseID completion:(void (^)(NSError *error))completion;

#pragma mark -
#pragma mark All-in-one methods

/**
 All-in-one method to call to ask the server to create a geodatabase with specified parameters
 and download it after it's created.
 If you have an existing geodatabase on the device that matches those parameters then it will use that one unless
 the useExisting parameter is NO.
 This method handles when the device goes in the background and fore-ground. It will also find jobs that
 match the parameters that are still executing even if the app gets evicted and you call this method after
 the app is launched again. The only issues that arise when the user backgrounds the app are job expirations
 on the server, if the user doesn't come back into the app before the job expires, the job will need to be kicked
 off again.
 @param parameters The parameters with which the geodatabase will be generated. This can be nil in which 
 case it will download all the layers and tables and at the full extent. However if it is initialized, its extent and layerIDs must be set.
 @param downloadFolderPath The path to the folder that you want the geodatabase downloaded to. This can be nil in
 which case a default folder (ie. documents directory) is chosen.
 @param useExisting Whether or not to use an existing geodatabase on the device whose parameters match the one you are asking for.
 @param statusBlock
 @param completionBlock
 @since 10.2
 @see  [AGSTask checkStatusForAllResumableTaskJobsWithCompletion:] to monitor job status even when the app is in the background
 @see  [AGSRequest allowsCellularAccessForDownloads] to prevent downloading geodatabase over cellular network
 */
-(id<AGSResumableTaskJob>)generateGeodatabaseWithParameters:(AGSGDBGenerateParameters*)parameters
                                         downloadFolderPath:(NSString*)downloadFolderPath
                                                useExisting:(BOOL)useExisting
                                                     status:(void(^)(AGSResumableTaskJobStatus status, NSDictionary *userInfo))statusBlock
                                                 completion:(void(^)(AGSGDBGeodatabase *geodatabase, NSError* error))completionBlock;

/**
 All-in-one method to resume a previous call to create and download a geodatabase
 This method handles when the device goes in the background and fore-ground. This method will place the
 resulting geodatabase in the @p downloadFolderPath specified when the job was originally created.
 @param resumeID The ID with which this job should be resumed.
 @since 10.2.2
 @see  [AGSTask checkStatusForAllResumableTaskJobsWithCompletion:] to monitor job status even when the app is in the background
 @see  [AGSRequest allowsCellularAccessForDownloads] to prevent downloading geodatabase over cellular network
 */
-(id<AGSResumableTaskJob>)generateGeodatabaseWithResumeID:(NSString*)resumeID
                                                   status:(void(^)(AGSResumableTaskJobStatus status, NSDictionary *userInfo))statusBlock
                                               completion:(void(^)(AGSGDBGeodatabase *geodatabase, NSError* error))completionBlock;

/**
 All-in-one method to upload changes, apply them to the server, and download server changes.
 This method handles when the device goes in the background and fore-ground. It will also find jobs that
 match the parameters that are still executing even if the app gets evicted and you call this method after
 the app is launched again. The only issues that arise when the user backgrounds the app are job expirations
 on the server, if the user doesn't come back into the app before the job expires, the job will need to be kicked
 off again.
 @param geodatabase to synchronize with the service
 @param params describing which changes should be sync'ed in which direction
 @param statusBlock is called at every  interval with the status of the operation and any related info
 @param completionBlock is called when the operation completes, returning any errors that occurred when synchronizing edits in the featureEditErrors.
 @since 10.2
 @note Uploading local edits requires a standard license for deployment. See  [AGSGDBSyncParameters syncDirection.]
 */
-(id<AGSResumableTaskJob>)syncGeodatabase:(AGSGDBGeodatabase*)geodatabase
                                   params:(AGSGDBSyncParameters*)params
                                   status:(void(^)(AGSResumableTaskJobStatus status, NSDictionary *userInfo))statusBlock
                               completion:(void(^)(AGSGDBEditErrors *editErrors, NSError* syncError))completionBlock;

/**
 All-in-one method to resume a previous -[AGSGDBSyncTask syncGeodatabase:params:status:completion:] call.
 This method handles when the device goes in the background and fore-ground. 
 @param geodatabase to synchronize with the service 
 @param resumeID The ID with which this job should be resumed.
 @param statusBlock is called at every  interval with the status of the operation and any related info
 @param completionBlock is called when the operation completes, returning any errors that occurred when synchronizing edits in the featureEditErrors.
 @since 10.2.2
 @note Uploading local edits requires a standard license for deployment. See  [AGSGDBSyncParameters syncDirection.]
 */
-(id<AGSResumableTaskJob>)syncGeodatabase:(AGSGDBGeodatabase*)geodatabase
                                 resumeID:(NSString*)resumeID
                                   status:(void(^)(AGSResumableTaskJobStatus status, NSDictionary *userInfo))statusBlock
                               completion:(void(^)(AGSGDBEditErrors *editErrors, NSError* syncError))completionBlock;

@end

/**  A category with debugging options for  AGSGDBSyncTask
 
 Debugging options when sync operations on  AGSGDBSyncTask fail mysteriously.
 
 
*/

@interface AGSGDBSyncTask (DebugSync)

//
// TODO: synchronize in/out deltas names with server terminology
/** Delta files will be created here named with &lt;epoch time&gt;.geodatabase
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *deltaDirectory;

/** Defaults to  YES.
 Set this to  NO to leave the deltas on the device for debugging.
 @since 10.2
 */
@property (nonatomic, assign) BOOL deleteDeltas;

@end

