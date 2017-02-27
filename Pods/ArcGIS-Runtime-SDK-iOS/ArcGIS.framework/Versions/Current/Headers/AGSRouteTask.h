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




/** @file AGSRouteTask.h */

@class AGSTask;
@class AGSCredential;
@class AGSRouteTaskParameters;
@class AGSRouteTaskResult;
@class AGSNetworkDescription;
@protocol AGSRouteTaskDelegate;

/**  A task to compute routes.
 
 Instances of this class represent tasks than can find the best route 
 to get from one location to another or to visit several locations. 
 
 The route task requires either a local network dataset on the device to compute routes, or access to a remote ArcGIS Network Analyst Service. When using a local network dataset, routes can be computed wholly on the device even when the device has no network connectivity.
 
 The task allows you to find a variety of routes between any given locations - the quickest, shortest, most scenic, and so on. The route returned depends on the impedance chosen by you. For example, if the impedance is time, then the best route is the quickest route. Hence, the best route can be defined as the route that has the lowest impedance.

 @see oncept{routing-task.htm, Using a Route Task}
 @see 
 */
@interface AGSRouteTask : AGSTask

/** Delegate to be notified when the solve operation has completed or returned 
 an error.
 @since 1.8
 */
@property (nonatomic, weak) id<AGSRouteTaskDelegate> delegate;

/** Return an initialized, auto released, route task
 @param url URL to a REST webservice endpoint that represents a Route analysis layer in a Network Analyst service. For example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/Network/USA/NAServer/Route
 @since 1.8
 */
+ (id)routeTaskWithURL:(NSURL *)url;

/** Return an initialized, auto released, route task
 @param url URL to a REST webservice endpoint that represents a Route analysis layer in a Network Analyst service. For example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/Network/USA/NAServer/Route
 @param cred Credentials need to access the secured service
 @since 1.8
 */
+ (id)routeTaskWithURL:(NSURL *)url credential:(AGSCredential*)cred;

/**
 Return an initialized, auto released, route task.
 @param path NSString path to database
 @param network NSString network name
 @param error NSError if error occurs during task creation then this is populated with error
 @since 10.2
 @note Requires a standard license for deployment.
 */
+ (id)routeTaskWithDatabasePath:(NSString *)path network:(NSString *)network error:(NSError **)error;

#if TARGET_OS_IPHONE

/**
 Return an initialized, auto released, route task that works with a local network dataset within the application bundle or shared documents directory.
 @param name of the database (the *.geodatabase file)
 @param network common prefix in the name of network files under the *.tn folder
 @param error NSError if error occurs during task creation then this is populated with error
 @since 10.2
 @note Requires a standard license for deployment.
 */
+ (id)routeTaskWithDatabaseName:(NSString *)name network:(NSString *)network error:(NSError **)error;

/**
 Initializes route task that works with a local network dataset within the application bundle or shared documents directory.
 @param name of the database (the *.geodatabase file)
 @param network common prefix in the name of network files under the *.tn folder
 @param error NSError if error occurs during task creation then this is populated with error
 @since 10.2
 @note Requires a standard license for deployment.
 */
- (id)initWithDatabaseName:(NSString *)name network:(NSString *)network error:(NSError **)error;

#endif

/**
 Initializes route task that works with a local network dataset anywhere on disk.
 @param path to the database file, including the name & extension of the file
 @param network common prefix in the name of network files under the *.tn folder
 @param error NSError if error occurs during task creation then this is populated with error
 @since 10.2
 @note Requires a standard license for deployment.
 */
- (id)initWithDatabasePath:(NSString *)path network:(NSString *)network error:(NSError **)error;

/** Solves a route with the given input parameters. It relies on the <i>Solve Route</i> operation
 of the REST resource.
 @param routeParams The input parameters for the solve operation.
 @return <code>NSOperation</code> for the current solve task.
 @since 1.8
 @see  [AGSRouteTaskDelegate routeTask:operation:didSolveWithResult:] , method on delegate for success
 @see  [AGSRouteTaskDelegate routeTask:operation:didFailSolveWithError:] , method on delegate for failure
 */
- (NSOperation*)solveWithParameters:(AGSRouteTaskParameters*)routeParams;

/** Retrieves the default route parameters. 
 @return <code>NSOperation</code> for the request.
 @since 1.8
 @see  [AGSRouteTaskDelegate routeTask:operation:didRetrieveDefaultRouteTaskParameters:] , method on delegate for success
 @see  [AGSRouteTaskDelegate routeTask:operation:didFailToRetrieveDefaultRouteTaskParametersWithError:] , method on delegate for failure
 */
- (NSOperation*)retrieveDefaultRouteTaskParameters;

/** Retrieves the transportation network description. This description includes, among other things, cost and restriction attributes that can be used to customize the route and optimize it on various dimensions (such as total time, distance, etc)
 @return <code>NSOperation</code> for the request.
 @since 10.2
 @see  [AGSRouteTaskDelegate routeTask:operation:didRetrieveNetworkDescription:] , method on delegate for success
 @see  [AGSRouteTaskDelegate routeTask:operation:didFailToRetrieveNetworkDescriptionWithError:] , method on delegate for failure
 */
- (NSOperation*)retrieveNetworkDescription;

@end

/**  A delegate of  AGSRouteTask.
 
 A protocol which must be adopted by any class wishing to be notified when 
  AGSRouteTask completes successfully or encounters an error. An 
 instance of the class must then be set  [AGSRouteTask delegate] .
 
 
 */
@protocol AGSRouteTaskDelegate <NSObject>

@required

/** Tells the delegate that the solve operation completed successfully.
 @param routeTask The route task that performed the solve operation.
 @param op <code>NSOperation</code> that performed the solve task.
 @param routeTaskResult The result of the solve operation.
 @since 1.8
 */
- (void)routeTask:(AGSRouteTask*)routeTask operation:(NSOperation*)op didSolveWithResult:(AGSRouteTaskResult*)routeTaskResult;

@optional

/** Tells the delegate that an error was encountered while performing the 
 solve operation.
 @param routeTask The route task that performed the solve operation.
 @param op <code>NSOperation</code> that performed the solve task.
 @param error The error encountered by the solve operation.
 @since 1.8
 */
- (void)routeTask:(AGSRouteTask*)routeTask operation:(NSOperation*)op didFailSolveWithError:(NSError*)error;

/** Tells the delegate that the default route parameters were retrieved successfully.
 @param routeTask The route task that performed the request for default parameters.
 @param op <code>NSOperation</code> that performed the request.
 @param routeParams The default route parameters for the task.
 @since 1.8
 */
- (void)routeTask:(AGSRouteTask*)routeTask operation:(NSOperation*)op didRetrieveDefaultRouteTaskParameters:(AGSRouteTaskParameters*)routeParams;

/** Tells the delegate that an error was encountered while retrieving the default
 route parameters.
 @param routeTask The route task that performed the request for default parameters.
 @param op <code>NSOperation</code> that performed the request.
 @param error The error encountered by the request.
 @since 1.8
 */
- (void)routeTask:(AGSRouteTask*)routeTask operation:(NSOperation*)op didFailToRetrieveDefaultRouteTaskParametersWithError:(NSError*)error;

/** Tells the delegate that the transportation network description wes retrieved successfully.
 @param routeTask The route task that performed the request for network description.
 @param op <code>NSOperation</code> that performed the request.
 @param networkDescription The transportation network description for the task.
 @since 10.2
 */
- (void)routeTask:(AGSRouteTask*)routeTask operation:(NSOperation*)op didRetrieveNetworkDescription:(AGSNetworkDescription*)networkDescription;

/** Tells the delegate that an error was encountered while retrieving the transportation
 network description.
 @param routeTask The route task that performed the request for network description.
 @param op <code>NSOperation</code> that performed the request.
 @param error The error encountered by the request.
 @since 10.2
 */
- (void)routeTask:(AGSRouteTask*)routeTask operation:(NSOperation*)op didFailToRetrieveNetworkDescriptionWithError:(NSError*)error;

@end

