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

@protocol AGSCancellable;

/** @file AGSPausable.h */ //Required for Globals API doc

/**  A protocol exposed by jobs or operations that allow pausing and resuming.
 
 A protocol exposed by jobs or operations that allow pausing and resuming while in progress.
 
 
 @since 10.2.3
 */
@protocol AGSPausable <NSObject, AGSCancellable>

/** Some jobs/operations may conform to this protocol, but depending on how they were set up or what
 they are doing they may not support pausing. For example AGSRequestOperations supports pause if they
 are downloading a file, but only on certain operating systems that support it (ie, at least iOS 7.0).
 One use case for this method is if you only wanted to show a pause button when you are using an operation
 that supports pause.
 @since 10.2.3
 */
-(BOOL)supportsPause;

/** Pause the job or operation. Returns YES if it isPaused is YES after calling this.
 If the job/operation is in a state where it cannot be paused, it will return NO. For example
 if the job/operation is cancelled it may return YES for supportsPause, but for example you can't pause it if it's cancelled or done.
 If supportsPause is NO, this method also returns NO.
 @since 10.2.3
 */
-(BOOL)pause;

/** Indicates whether the job or operation is paused.
 @since 10.2.3
 */
-(BOOL)isPaused;

/** Resumes a job or operation after it's been paused. Only valid to be called when isPaused is YES.
 @since 10.2.3
 */
-(void)resume;
@end
