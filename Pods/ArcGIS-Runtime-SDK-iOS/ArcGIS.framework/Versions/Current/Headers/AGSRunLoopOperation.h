/*
 COPYRIGHT 2011 ESRI
 
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

/** Represents the block signature for a request operation's completion handler.
   obj will be of type  NSDictionary if the result you're expecting is json,  AGSImage if the result is an image, and  NSData for anything else.
 @since 2.3
 */
typedef void (^AGSIdBlock)(id obj);

/** Represents the block signature for a request operation's error handler.
 @since 2.3
 */
typedef void (^AGSErrorBlock)(NSError *error);

@protocol AGSCancellable;

/** @file AGSRunLoopOperation.h */ //Required for Globals API doc

/**  Base class for concurrent operations that should run on a run loop thread.
 @since 2.1
 */
@interface AGSRunLoopOperation : NSOperation<AGSCancellable>

/** Target class to perform the operation from.
 @since 2.1
 */
@property (nonatomic, weak) id target;

/** Selector to be called if the operation succeeds. The method must accept
 two parameters. The first parameter will be an instance of this class, the second will be the result. The result will of type  NSDictionary for json,  AGSImage for image, and  NSData for anything else.
 
 An example of a selector is  @selector(operation:didSucceedWithResponse:)
 The corresponding method signature would be <code>-(void) operation:(NSOperation*)op didSucceedWithResponse:(id)result</code>
 
 @since 2.1
 @see  completionHandler for block-based alternative
 */
@property (nonatomic, assign) SEL action;

/** Selector to be called if the operation fails.The method must accept
 two parameters. The first parameter will be an instance of this class, the second will be the error.
 
 An example of a selector is  @selector(operation:didFailWithError:)
 The corresponding method signature would be <code>-(void) operation:(NSOperation*)op didFailWithError:(NSError*)error</code>
 @since 2.1
 @see  errorHandler for block-based alternative
 */
@property (nonatomic, assign) SEL errorAction;

/** The thread that this concurrent operation should start it's work on.
 This can only be set before the operation starts executing.
 After that, setting it will be ignored.
 @since 2.1
 */
@property (nonatomic, strong, readwrite) NSThread *runLoopThread;

/** Defaults to <code>NO</code>, but it is helpful if this operation is a 
 dependency for another operation and the action selector processes some results 
 that the dependent operation needs before it can start.
 @since 2.1
 */
@property (nonatomic, assign) BOOL waitUntilActionSelectorIsDone;

/** The results of an operation.
 It will be of type  NSDictionary when the result is json,  AGSImage when the result is an image, and  NSData when anything else.
 @since 2.1
 */
@property (nonatomic, strong, readonly ) id result;

/** Completion handler that will be called when the operation is 
 completed successfully. This handler will only be called when a target is not
 specified. The AGSIdBlock is called with an object of type id passed as
 the parameter.
 @since 2.3
 */
@property (nonatomic, copy) AGSIdBlock completionHandler;

/** Error handler that will be called when an error is returned
 by the operation. This handler will only be called when a target is not
 specified. The AGSErrorBlock is called with an object of type NSError passed as
 the parameter.
 @since 2.3
 */
@property (nonatomic, copy) AGSErrorBlock errorHandler;

/**
 A subclass should call finishWithError: when the operation is complete, 
 passing the desired result. If an error ocurred, pass an NSError object and
 the errorAction selector will be called. Any other type of result will
 cause the action selector to be fired.
 
 Note that this will call -operationWillFinish before returning.
 @since 2.1
*/
- (void)finishWithResult:(id)result;

/** A function that can be overridden by subclasses to start actual operation work.
 @since 2.1
 */
- (void)operationDidStart;

/** A function that can be overridden by subclasses to know when the operation was finished.
 This may get called even if operationDidStart was never called.
 @since 2.1
 */
- (void)operationWillFinish;

@end
