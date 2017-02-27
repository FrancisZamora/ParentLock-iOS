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

@class AGSGDBFeature;

/** @file AGSGDBAttachment.h */ //Required for Globals API doc

/**  An attachment in a local geodatabase
 
 Instances of this class represent an attachment in a local geodatabase.
 
 
 */
@interface AGSGDBAttachment : NSObject

/** Initialize a geodatabase attachment with @p image and named @p name.
 The image will be converted to jpg. If you want to preserve your image type then use  initWithData:name:contentType:
 @param image used to create the attachment
 @param name to be given to the attachment, including file extension
 @since 10.2.2
 */
-(instancetype)initAsJpgWithImage:(AGSImage*)image name:(NSString*)name;

/** Initialize a geodatabase attachment with @p data of type @p contentType and named @p name.
 @param data The raw binary data of the attachment
 @param name to be given to the attachment, including file extension
 @param contentType The MIME type of the data. For eg <i>image/png</i>
 @since 10.2.2
 */
-(instancetype)initWithData:(NSData*)data name:(NSString*)name contentType:(NSString*)contentType;

/** Returns a geodatabase attachment created with @p image and named @p name.
 The image will be converted to jpg. If you want to preserve your image type then use  attachmentWithData:name:contentType:
 @param image used to create the attachment
 @param name to be given to the attachment, including file extension
 @since 10.2.2
 */
+(instancetype)attachmentAsJpgWithImage:(AGSImage*)image name:(NSString*)name;

/** Returns a geodatabase attachment created with @p data of type @p contentType and named @p name.
 @param data The raw binary data of the attachment
 @param name to be given to the attachment, including file extension
 @param contentType The MIME type of the data. For eg <i>image/png</i>
 @since 10.2.2
 */
+(instancetype)attachmentWithData:(NSData*)data name:(NSString*)name contentType:(NSString*)contentType;

#if TARGET_OS_IPHONE
/** Returns a geodatabase attachment for the item chosen in a UIImagePickerController
 @param info The dictionary provided by UIImagePickerController
 @since 10.2
 @deprecated Deprecated at 10.2.2 due to memory issues with large files. Use  [AGSGDBAttachment attachmentWithUIImagePickerControllerInfoDictionary:completion] instead.
 */
+(instancetype)attachmentWithUIImagePickerControllerInfoDictionary:(NSDictionary*)info;

/** Creates a geodatabase attachment for the item chosen in a UIImagePickerController
 @param info The dictionary provided by UIImagePickerController
 @param completion The completion block called when the operation completes
 @since 10.2
 */
+(void)attachmentWithUIImagePickerControllerInfoDictionary:(NSDictionary*)info
                                                   completion:(void (^)(AGSGDBAttachment* attachment))completion;

#endif

/** Fetches the data for the attachment if the attachment is remote.
 If isLocal is NO you must call fetchDataWithCompletion: before accessing the attachment data, filename or thumbnail.
 @since 10.2.2
 */
-(void)fetchDataWithCompletion:(void(^)(NSData* attachmentData, NSError *error))completionBlock;

/** The name of the attachment
 @since 10.2
 */
@property (nonatomic, copy) NSString *name;

/** The MIME type of the attachment
 @since 10.2
 */
@property (nonatomic, copy) NSString *contentType;

/** The size of the attachment in bytes
 @since 10.2
 */
@property (nonatomic, assign, readonly) NSInteger size;

/** Whether the attachment data is local or it needs to be fetched.
 If this is NO then you must call fetchDataWithCompletion: before accessing the data, filename or thumbnail.
 @since 10.2.2
 */
@property (nonatomic, assign) BOOL isLocal;

/** The attachment data in binary format.
 If the attachment is not local, you must call fetchDataWithCompletion: before calling the data getter.
 Only works when isLocal is YES.
 @since 10.2
 */
@property (nonatomic, copy) NSData *data;

/** The unique ID of the attachment.
 */
@property (nonatomic, assign, readonly) long long attachmentID;

/** Returns a thumbnail image the attachment.
 Only works with some types of attachments - mainly images and videos.
 Only works when isLocal is YES.
 @since 10.2
 */
-(AGSImage*)thumbnail;

/** Location on disk where the attachment data is available.
 The data will be saved to this location if it hasn't been already.
 Creates a temporary file if one doesn't exist for this attachment.
 Only works when isLocal is YES.
 @since 10.2
 */
-(NSString*)filepath;


@end
