/*
 COPYRIGHT 2009 ESRI
 
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

/** @file AGSRequest.h */ //Required for Globals API doc

/**  Wrapper class to request data from a URL
 
 This class provides some simple methods for requesting data from a URL
 synchronously. You are responsible for running this on a background thread if you don't
 want to block the calling thread.
 
 @see  AGSJSONRequestOperation to fetch JSON asynchronously
 @see  AGSImageRequestOperation to fetch an image asynchronously
 @since 1.0
 */
@interface AGSRequest : NSObject

/** Creates a request object for a URL with the specified arguments
 NOTE: If @p post is set to <code>YES</code> the method used will be AGSRequestHTTPMethodPostFormEncodeParameters.
 @param url to request data from
 @param cred <code>AGSCredential</code> to be used if the resource is secured
 @param operation The specific resource to access at @p url
 @param query parameters to submit to the @p url
 @param post Boolean to determine whether to perform a <code>GET</code> or 
 <code>POST</code>
 @since 1.0
 */
+ (NSURLRequest *)requestForURL:(NSURL *)url credential:(AGSCredential*)cred resource:(NSString *)operation queryParameters:(NSDictionary *)query doPOST:(BOOL)post;

/** Creates a request object for a URL with the specified arguments
 NOTE: If @p post is set to <code>YES</code> the method used will be AGSRequestHTTPMethodPostFormEncodeParameters.
 @param url to request data from
 @param cred <code>AGSCredential</code> to be used if the resource is secured
 @param operation The specific resource to access at @p url
 @param queryParams parameters to submit to the @p url
 @param post Boolean to determine whether to perform a <code>GET</code> or <code>POST</code>
 @param cachePolicy The cache policy that the request will honor.
 @param timeoutInterval The timeout interval (in seconds) of this request. Default is 60.
 @since 10.1.1
 */
+ (NSURLRequest *)requestForURL:(NSURL *)url credential:(AGSCredential*)cred resource:(NSString *)operation queryParameters:(NSDictionary *)queryParams doPOST:(BOOL)post cachePolicy:(NSURLRequestCachePolicy)cachePolicy timeoutInterval:(NSTimeInterval)timeoutInterval;

/** Creates a request object for a URL with the specified arguments
 NOTE: If @p httpMethod is specified as AGSRequestHTTPMethodGet and the length of the URL + query causes a POST or
 [AGSRequest setForcePostForAllRequests] has been set to <code>YES</code>, then the httpMethod will switch to AGSRequestHTTPMethodPostFormEncodeParameters.
 @param url to request data from
 @param cred <code>AGSCredential</code> to be used if the resource is secured
 @param operation The specific resource to access at @p url
 @param queryParams parameters to submit to the @p url
 @param method The method by which the request will be made.
 @param cachePolicy The cache policy that the request will honor.
 @param timeoutInterval The timeout interval (in seconds) of this request. Default is 60.
 @since 10.2
 */
+ (NSURLRequest *)requestForURL:(NSURL *)url
                     credential:(AGSCredential*)cred
                       resource:(NSString *)operation
                queryParameters:(NSDictionary *)queryParams
                         method:(AGSRequestHTTPMethod)httpMethod
                    cachePolicy:(NSURLRequestCachePolicy)cachePolicy
                timeoutInterval:(NSTimeInterval)timeoutInterval;

/** Creates a request object for a URL with the specified arguments
 NOTE: If @p httpMethod is specified as AGSRequestHTTPMethodGet and the length of the URL + query causes a POST or
 [AGSRequest setForcePostForAllRequests] has been set to <code>YES</code>, then the httpMethod will switch to AGSRequestHTTPMethodPostFormEncodeParameters. 
 @param url to request data from
 @param cred <code>AGSCredential</code> to be used if the resource is secured
 @param operation The specific resource to access at @p url
 @param queryParams parameters to submit to the @p url
 @param httpMethod The method by which the request will be made.
 @param cachePolicy The cache policy that the request will honor.
 @param timeoutInterval The timeout interval (in seconds) of this request. Default is 60.
 @param userHeaders Any custom headers you would like to set on the request with the exception of User-Agent, Referer, and Content-Type. If you need to add info to the User-Agent header use   setAdditionalUserAgentInfo: .
 @since 10.2
 */
+ (NSURLRequest *)requestForURL:(NSURL *)url
                     credential:(AGSCredential *)cred
                       resource:(NSString *)operation
                queryParameters:(NSDictionary *)queryParams
                         method:(AGSRequestHTTPMethod)httpMethod
                    cachePolicy:(NSURLRequestCachePolicy)cachePolicy
                timeoutInterval:(NSTimeInterval)timeoutInterval
                    userHeaders:(NSDictionary *)userHeaders;

/** Requests data synchronously from the url with the specified arguments
 @param url to request data from
 @param operation The specific resource to access at @p url
 @param query parameters to submit to the @p url
 @param post Boolean to determine whether to perform a <code>GET</code> or 
 <code>POST</code>
 @param error Information about the request if it fails
 @since 1.0
 */
+ (NSData *)dataForURL:(NSURL *)url resource:(NSString *)operation queryParameters:(NSDictionary *)query doPOST:(BOOL)post error:(NSError**)error;

/** Requests data synchronously from the url with the specified arguments
 @param url to request data from
 @param cred <code>AGSCredential</code> to access the secured resource
 @param operation The specific resource to access at @p url
 @param query parameters to submit to the @p url
 @param post Boolean to determine whether to perform a <code>GET</code> or 
 <code>POST</code>
 @param error Information passed back if the request fails
 @since 1.0
 */
+ (NSData *)dataForURL:(NSURL *)url credential:(AGSCredential*)cred resource:(NSString *)operation queryParameters:(NSDictionary *)query doPOST:(BOOL)post error:(NSError**)error;

/** Requests data synchronously for the specified request.
 @param request object containing url and query parameters
 @param error Information passed back if the request fails
 @since 1.0
 */
+ (NSData *)dataForRequest:(NSURLRequest *)request error:(NSError**)error;

/** Used to set some specific user agent information. This is useful for 
 analytics.
 @param additionalInfo to send along in the user agent string
 @since 1.0
 */
+ (void) setAdditionalUserAgentInfo:(NSString*)additionalInfo;

/** Class method to retrieve the user agent string
 @since 1.0
 */
+ (NSString*)userAgent;

/** Whether or not the http/s method is forced to be POST for all AGSRequests.
 @since 2.2
 */
+(BOOL)forcePostForAllRequests;

/** Whether or not the http/s method is forced to be POST for all AGSRequests.
 @since 2.2
 */
+(void)setForcePostForAllRequests:(BOOL)forcePost;

#if TARGET_OS_IPHONE
/** Specifies whether or not cellular access can be used to download files. This will only affect AGSRequestOperation's that
 have set the @p outputPath parameter. The default setting is YES.
 @param allowsCellular Boolean indicating whether or not to allow cellular access for file downloads.
 @since 10.2.2
 */
+(void)setAllowsCellularAccessForDownloads:(BOOL)allowsCellular;

/** Whether or not cellular access can be used to download files when the @p outputPath parameter is specified on an
 AGSRequestOperation. The default is YES.
 @since 10.2.2
 */
+(BOOL)allowsCellularAccessForDownloads;
#endif

@end
