/*
 COPYRIGHT 2012 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and 
 Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */



@class AGSWMTSLayerInfo;
@class AGSWMTSLayer;
@protocol AGSSecuredResource;
@protocol AGSWMTSInfoDelegate;

extern NSString *const kWMTSVersion;

/** @file AGSWMTSInfo.h */ //Required for Globals API doc


/**  A class to facilitate the creation of an  AGSWMTSLayer from a WMTS Server map service

 An instance of this class allows you to interact with a WMTS map service
 and create a layer from one of the tile sets provided by the service. When
 instantiated with a URL to a WMTS map service, an object of this class
 will issue a GetCapabilities request to the server, and report the layer 
 options in its layerInfos property. Using one of these
  AGSWMTSLayerInfo objects one can create the desired layer.
 
 
*/
@interface AGSWMTSInfo : NSObject <AGSSecuredResource>

/** The delegate of the class.
 @since 10.1.1
*/
@property (nonatomic, weak) id <AGSWMTSInfoDelegate> delegate;

/** An array of  AGSWMTSLayerInfo objects, each one representing
 the information for a different layer provided by a WMTS service.
 @since 10.1.1
*/
@property (nonatomic, copy, readonly) NSArray *layerInfos;

/** The credential to be used to access the secured map service.
 @since 10.1.1
 */
@property (nonatomic, copy, readwrite) AGSCredential *credential;

/** The credential cache to be used for this resource. By default this will be set to the global cache.
 @since 10.1.1
 */
@property (nonatomic, strong, readwrite) AGSCredentialCache *credentialCache;

/** The URL for the WMTS map service
@since 10.1.1
*/
@property (nonatomic, copy, readonly) NSURL *URL;

/** The WMTS version
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *version;

/** Initializes an  AGSWMTSInfo object with a URL of a WMTS service.
 @param url URL to a WMTS service.
 @return A new  AGSWMTSInfo object.
 @since 10.1.1
*/
- (id)initWithURL:(NSURL*)url;

/** Initializes an  AGSWMTSInfo object with a URL of a WMTS service,
 as well as a credential to a secured resource.
 @param url URL to a WMTS service.
 @param credential  AGSCredential to access a secured resource.
 @return A new  AGSWMTSInfo object.
 @since 10.1.1
 */
- (id)initWithURL:(NSURL *)url credential:(AGSCredential*)credential;

/** A method to get an initialized, autoreleased  AGSWMTSInfo with a URL of a WMTS map service.
 @param url URL to a WMTS map service.
 @return A new autoreleased  AGSWMTSInfo object.
 @since 10.1.1
 */
+ (id)wmtsInfoWithURL:(NSURL*)url;

/** A method to get an initialized, autoreleased  AGSWMTSInfo with a URL of a WMTS map service,
 as well as a credential to a secured resource.
 @param url URL to a WMTS map service.
 @param credential  AGSCredential to access a secured resource.
 @return A new autoreleased  AGSWMTSInfo object.
 @since 10.1.1
 */
+ (id)wmtsInfoWithURL:(NSURL *)url credential:(AGSCredential*)credential;


/** A method to get an initialized, autoreleased  AGSWMTSLayer.
 @param layerInfo  AGSWMTSLayerInfo object used to create an  AGSWMTSLayer object.
 @param sr  AGSSpatialReference desired for the layer, if this parameter is nil
        a WMTSLayer will be returned in the first spatial reference found.
 @return A new autoreleased  AGSWMTSLayer.
 @since 10.1.1
 */
- (AGSWMTSLayer*)wmtsLayerWithLayerInfo:(AGSWMTSLayerInfo*)layerInfo andSpatialReference:(AGSSpatialReference *)sr;

@end


/**  A protocol that must be adopted in order create an  AGSWMTSLayer
 
 This protocol allows one to be informed when the  AGSWMTSInfo object has
 completed extracting the layer information from a GetCapabilities request
 to a WMTS service. An instance of this class must be set as  [AGSWMTSInfo delegate] .
 
 @since 10.1.1
 */
@protocol AGSWMTSInfoDelegate <NSObject>
@required
/** This method tells the delegate when the  AGSWMTSInfo
 object is finished loading. A class implementing this function
 would typically create an instance of an  AGSWMTSLayer
 by calling wmtsLayerWithLayerInfo:andSpatialReference:.
 @param wmtsInfo The  AGSWMTSInfo object which has finished loading.
 @since 10.1.1
*/
- (void)wmtsInfoDidLoad:(AGSWMTSInfo*)wmtsInfo;

@optional
/** This method tells the delegate if the WMTSInfo object failed to load
 @param error Information regarding the cause of the failure to load.
 @since 10.1.1
 @deprecated Deprecated at 10.2. Use  [AGSWMTSInfoDelegate wmtsInfo:didFailToLoad] instead.
 */
- (void)wmtsInfo:(AGSWMTSInfo*)wmtsInfo DidFailToLoad:(NSError*)error __attribute__((deprecated));

/** This method tells the delegate if the WMTSInfo object failed to load
 @param error Information regarding the cause of the failure to load.
 @since 10.2
 */
- (void)wmtsInfo:(AGSWMTSInfo*)wmtsInfo didFailToLoad:(NSError*)error;

@end


