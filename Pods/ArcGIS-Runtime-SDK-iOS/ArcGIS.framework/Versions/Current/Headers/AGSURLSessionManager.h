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

@class AGSURLSessionContainer;

/**  Handles  NSURLSession related events for background downloads
 
 This class handles  NSURLSession related events for downloads performed while the
 app is in the background.
 
 @since 10.2.2
 @see 
 */
@interface AGSURLSessionManager : NSObject

/** The singleton instance of this class.
 @since 10.2.2
 */
+(instancetype)sharedManager;

/** Provides a way to process  NSURLSession related events for data downloaded in the background. 
 The download could have been initiated in the background by  [AGSTask checkStatusForAllResumableTaskJobsWithCompletion:,]
 or it might have been initiated in the foreground and the app later terminated or moved into the background.
 This method should be called in the <code>-[UIApplicationDelegate application:handleEventsForBackgroundURLSession:completionHandler:]</code> delegate method.
 Once the download finishes, the completion handler on your  AGSGDBSyncTask or  AGSExportTileCacheTask will be invoked to let you know that the job has completed. If your app is still in the background, you can post a local notification to alert the user.
 
 @param completionHandler The completion handler that will be called by the API when downloading is finished to let the system know that your app’s user interface is updated and a new snapshot can be taken. This handler is provided to UIApplicationDelegate by the system. Before invoking this handler, the API will first call the completion handler on your  AGSGDBSyncTask or  AGSExportTileCacheTask to let you know that the job has completed so that you can update your app's UI, and if desired, post a local notification to alert the user.
 @param identifier The identifier of the URL session requiring attention. This is provided to UIApplicationDelegate by the system
 @note Only applicable to iOS 7 or later.
 @since 10.2.2
 */
-(void)setBackgroundURLSessionCompletionHandler:(void(^)())completionHandler forIdentifier:(NSString*)identifier;

@end
