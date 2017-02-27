/*
 COPYRIGHT 2010 ESRI
 
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

@class AGSCredential;
@protocol AGSSecuredResource;

/** @file AGSTask.h */ //Required for Globals API doc

/**  Base class for all ArcGIS task objects
 
 Base class to hold common objects among ArcGIS tasks. You should never
 instantiate an <code>%AGSTask</code> object directly.
 
 @see oncept{tasks-overview.htm, Overview of Tasks}
 @since 1.0
 */
@interface AGSTask : NSObject <AGSSecuredResource>

/** URL to a task resource in the ArcGIS Server REST Services Directory.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSURL *URL;

/** The credential to be used to access secured resources.
 @since 1.0
 */
@property (nonatomic, copy, readwrite) AGSCredential *credential;

/** The credential cache to be used for this resource.
 @since 10.1.1
 */
@property (nonatomic, strong, readwrite) AGSCredentialCache *credentialCache;

/** The cache policy that should be used for making the web request.
 Default value is NSURLRequestUseProtocolCachePolicy
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) NSURLRequestCachePolicy requestCachePolicy;

/** The timeout interval (in seconds) for this request. Default value is 60.
 @since 10.1.1
 */
@property (nonatomic, assign, readwrite) NSTimeInterval timeoutInterval;

/** Initialize the task.
 @param url URL to a task resource in the ArcGIS Server REST Services Directory.
 @return A new task object.
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url;

/** Initialize the task with a URL and credential to a secured resource.
 @param url URL to a task resource in the ArcGIS Server REST Services Directory.
 @param cred <code>AGSCredential</code> used to access secure resource.
 @return A new task object.
 @since 1.0
 */
- (id)initWithURL:(NSURL *)url credential:(AGSCredential*)cred;

@end



/**  A category on  AGSTask to manage asynchronous server jobs
 
 A category on  AGSTask to manage asynchronous server jobs represented by  AGSResumableTaskJob, for example,
 those performed by  AGSExportTileCacheTask or  AGSGDBSyncTask
 
 @see 
 @since 10.2.2
 */
@interface AGSTask (AsyncServerJobs)

#if TARGET_OS_IPHONE
/** Provides a way to check the status of all pending async server jobs while the app is in the background. If any job is complete, it  will also
 initiate the download in the background.
 
 This method should be called in the <code>-[UIApplicationDelegate application:performFetchWithCompletionHandler:]</code> delegate method.
 @note Only applicable to iOS 7 or later. You will need to enable the "background fetch" capability at your application level in order to take advantage of this method while your app has been suspended.
 @see  [AGSURLSessionManager setBackgroundURLSessionCompletionHandler:forIdentifier:] to handle downloads in background
 @since 10.2.2
 @see 
 */
+(void)checkStatusForAllResumableTaskJobsWithCompletion:(void (^)(UIBackgroundFetchResult result))completion;
#endif

/** Returns a dictionary of all active resumable jobs. The key will be the jobType and the value will be an array of resumeIDs.
 @since 10.2.2
 */
+(NSDictionary*)activeResumeIDs;

/** Returns <code>YES</code> if the job with the specified @p resumeID is still valid.
 @since 10.2.2
 */
+(BOOL)isActiveResumeID:(NSString*)resumeID;

/** Cancels the job with the associated resumeID.
 @param resumeID The resume ID of the job to be canceled.
 @since 10.2.2
 */
-(void)cancelResumableTaskJobWithResumeID:(NSString*)resumeID;

@end


