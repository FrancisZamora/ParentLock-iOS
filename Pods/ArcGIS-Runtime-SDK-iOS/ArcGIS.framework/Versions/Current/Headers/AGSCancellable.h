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


/** @file AGSCancellable */ //Required for Globals API doc

/**  A protocol exposed by operations that allow cancellation
 
 A protocol exposed by operations that allow cancellation while in progress.
 
 
 */
@protocol AGSCancellable <NSObject>

/** Cancel the operation
 @since 10.2
 */
- (void)cancel;

/** Indicates whether the operation has been cancelled
 @since 10.2
 */
- (BOOL)isCancelled;
@end
