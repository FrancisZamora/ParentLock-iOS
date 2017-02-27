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

@class AGSTask;
@class AGSGenerateRendererParameters;

/** @file AGSGenerateRendererTask.h */ //Required for Globals API doc

/**  This task is used to generate a renderer from a map service’s generateDataClasses REST end-point.
 The task requires the URL of a single sub-layer in a dynamic map service, a classification definition and
 an optional where clause to restrict the data to be classified.  The classification definition and
 where clause are set using the  AGSGenerateRendererParameters object.
 @since 10.2.4
 */
@interface AGSGenerateRendererTask : AGSTask

/** Initialize an autoreleased generate renderer task.
 @param url URL to a single sub-layer in the dynamic map service.
 @return A new identify task object.
 @since 10.2.4
 */
+ (id)generateRendererTaskWithURL:(NSURL *)url;

/** Initialize autoreleased identify task with credential.
 @param url URL to a single sub-layer in the dynamic map service.
 @param cred <code>AGSCredential</code> for accessing a secure generate renderer task.
 @return A new generate renderer task object.
 @since 10.2.4
 */
+ (id)generateRendererTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/** Generates the renderer using the supplied @p parameters and @p completionBlock
 @param parameters The parameters with which the generate renderer task will be called.
 @param completionBlock - the code block to be called upon completion of the operation
 @return the  NSOperation for the task.
 @since 10.2.4
 */
-(id<AGSCancellable>)generateRendererWithParameters:(AGSGenerateRendererParameters*)parameters
                                         completion:(void(^)(AGSRenderer *renderer, NSError* error))completionBlock;

@end
