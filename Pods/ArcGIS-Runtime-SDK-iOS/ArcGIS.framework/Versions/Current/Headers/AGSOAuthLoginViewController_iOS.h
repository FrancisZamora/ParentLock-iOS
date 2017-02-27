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

#if TARGET_OS_MAC && (!TARGET_OS_IPHONE)
#import <Cocoa/Cocoa.h>
#import <WebKit/WebKit.h>
#endif

/*@file AGSOAuthLoginViewController.h */

@class AGSCredential;

/**  A view controller to facilitate secure authorization via OAuth2 .
 
 This view controller provides an authentication page that allows users to sign into
 portals such as ArcGIS Online via OAuth 2 protocol.
 
 @see 
 */
@interface AGSOAuthLoginViewController : UIViewController

/** The URL of the portal to authenticate against. For example, https://www.arcgis.com
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSURL *URL;

/** The requested expiration interval (in minutes) for the refreshToken generated by the
 OAuth request. The max interval can be overridden by the portal administrator.
 NOTE: For a permanent refreshToken, send -1.
 @since 10.2
 */
@property (nonatomic, assign) NSInteger refreshTokenExpirationInterval;

/** Defaults to <code>YES</code>. When set to <code>NO</code> a "Cancel" button will be displayed
 next to "Sign In" on the OAuth web page. When clicked, the completion handler will be called 
 with an NSUserCancelledError.
 @since 10.2
 */
@property (nonatomic, assign) BOOL cancelButtonHidden;

/** Block called when the user either successfully logs in or explicitly cancels the login. This is the point
 at which the login view controller should be dismissed.
 @param credential A credential created from the response of the OAuth2 login page.
 @param error The error encountered when attempting to retrieve an OAuth2 token. If nil, then a
 credential was successfully populated.
 @since 10.2
 */
@property (nonatomic, copy) void (^completion)(AGSCredential *credential, NSError *error);

/** Block called when the OAuth web page has completely loaded. This will also be called
 when the reload method finishes.
 @note The view controller must be presented for the web page to begin loading.
 @param error The error encountered when loading the OAuth web view.
 @since 10.2.3
 @see  activityIndicatorViewColor,  activityIndicatorHidden
 */
@property (nonatomic, copy) void (^loadCompletion)(NSError *error);

/** KVO enabled property to indicate if the OAuth view has completed loaded.
 @since 10.2.3
 */
@property (nonatomic, assign, readonly) BOOL loaded;

#if TARGET_OS_IPHONE
/** The color of the UIActivityIndicatorView that is shown while the OAuth web page is being loaded.
 The default is black. This will automatically be removed once the OAuth view has loaded.
 @since 10.2.3
 */
@property (nonatomic, strong) UIColor *activityIndicatorViewColor;
#endif

/** Specifies whether an activity indicator should be visible/hidden while the OAuth web page is being loaded.
 The default is NO. Set this to YES to show your own indicator.
 @since 10.2.3 
 */
@property (nonatomic, assign) BOOL activityIndicatorHidden;

/**
 @param url The URL for the portal in which to authenticate against. For example, https://www.arcgis.com
 @param clientID The clientID for the application registered with the portal.
 @since 10.2
 */
- (id)initWithPortalURL:(NSURL*)url clientID:(NSString*)clientID;

/** This method will reload the authentication page. 
 @since 10.2
 */
- (void)reload;
@end
