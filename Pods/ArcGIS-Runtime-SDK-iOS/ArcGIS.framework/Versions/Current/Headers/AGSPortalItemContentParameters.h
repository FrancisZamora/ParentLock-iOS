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

/** @file AGSPortalItemContentParameters.h */ //Required for Globals API doc

/**  Content for a new  AGSPortalItem
 
 Instances of this class represent content for a new portal item created by  [AGSPortal addPortalItem:withContentParams:toFolder:]
 
 
 @since 10.2
 */
@interface AGSPortalItemContentParameters : NSObject

/** The object representing the content to be added or updated. 
 Valid objects for adding/updating are:
 @li NSData - for file data
 @li NSURL - for service items
 @li NSDictionary - for json content, such as a web map
 @since 10.2
 */
@property (nonatomic, strong, readonly) id<NSObject> value;

/** The name of the file being uploaded for this content item, including extension.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *filename;

/** Initialize an AGSPortalItemContentParameter object with data.
 @param data The data representing the file to be added or updated on an  AGSPortalItem.
 @param filename The file name to be used for the file being uploaded for this content item.
 @return An autoreleased AGSPortalItemContentParameters object.
 @since 10.2
 */
+(id)portalItemContentParametersWithData:(NSData*)data filename:(NSString*)filename;

/** Initialize an AGSPortalItemContentParameter object with a url.
 @param url The url to be used for the  AGSPortalItem.
 @return An autoreleased AGSPortalItemContentParameters object.
 @since 10.2
 */
+(id)portalItemContentParametersWithURL:(NSURL*)url;

/** Initialize an AGSPortalItemContentParameter object with json.
 @param json The json representing the content (like a web map) for the  AGSPortalItem.
 @return An autoreleased AGSPortalItemContentParameters object.
 @since 10.2
 */
+(id)portalItemContentParametersWithJSON:(NSDictionary*)json;

@end
