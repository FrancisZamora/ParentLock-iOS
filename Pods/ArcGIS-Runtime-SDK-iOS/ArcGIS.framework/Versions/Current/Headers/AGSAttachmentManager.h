/*
 COPYRIGHT 2010 ESRI
 
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



@class AGSAttachment;
@protocol AGSAttachmentManagerDelegate;
@protocol AGSFeatureLayerEditingDelegate;
@class AGSFeatureLayer;
@class AGSRequestOperation;

/** @file AGSAttachmentManager.h */ //Required for Globals API doc

/**  Manages attachments belonging to a feature
 
 
 Instances of this class represent a light-weight and coarse-grained object for managing attachments of a particular feature in a feature layer.
 This object allows the user to make changes on the client regarding the attachments collection
 for a feature and then later on either cancel these edits or sync (post) the changes to the server.
 You can get a handle to an attachment manager for a feature using the
  [AGSFeatureLayer attachmentManagerForFeature:] method.
 
 @see oncept{working-with-the-attachment-manager.htm, Working with the Attachment Manager}
 @see 
 */
@interface AGSAttachmentManager : NSObject <AGSFeatureLayerEditingDelegate>

/** The delegate that is notified when operations complete.
 @since 2.0
 */
@property (nonatomic, weak, readwrite) id<AGSAttachmentManagerDelegate> delegate;

/** The feature layer that this attachment manager is associated with. 
 @since 2.0
 */
@property (nonatomic, weak, readonly) AGSFeatureLayer *featureLayer;

/** The object id of the feature that this attachment manager is associated with. 
 @since 2.0
 */
@property (nonatomic, assign, readonly) NSInteger featureObjectId;

/** The error, if any, that occurred when attempting to download attachment metadata.
 @since 2.0
 */
@property (nonatomic, strong, readonly) NSError *downloadAttachmentInfosError;

/** Indicates whether or not the attachment manager is currently posting local edits to the remote server. 
 @since 2.0
 */
@property (nonatomic, assign, readonly) BOOL postingLocalEdits;

/** The attachments belonging to the feature that this attachment manager is associated with.
 @since 2.0
 */
@property (nonatomic, copy, readonly) NSArray *attachments;

/** Finds the attachment for a particular attachment id. 
 @since 2.0
 */
-(AGSAttachment*)attachmentForId:(NSInteger)attachmentId;

/** Indidcates whether the attachment manager contain any local edits on
 the client (i.e if any attachments have been added, or deleted).
 @since 2.0
 */
-(BOOL)hasLocalEdits;

/** Cancels all local edits. 
 @since 2.0
 */
-(void)cancelLocalEdits;

/** Adds an attachment.
 Does not upload it to the server until  postLocalEditsToServer is called.
 The image will be converted to jpg. If you want to preserve your image type then use  addAttachmentWithData:name:contentType:
 @param image to add as an attachment
 @param name to be given to the attachment, including file extension
 @since 2.0
 */
-(AGSAttachment*)addAttachmentAsJpgWithImage:(AGSImage*)image name:(NSString*)name;

#if TARGET_OS_IPHONE
/** Adds an attachment.
 Does not upload it to the server until  postLocalEditsToServer is called.
 @param info The dictionary provided by UIImagePickerController
 @since 2.0
 @deprecated Deprecated at 10.2.2 due to memory issues with large files. Use  [AGSAttachmentManager addAttachmentWithUIImagePickerControllerInfoDictionary:completion] instead.
 */
-(AGSAttachment*)addAttachmentWithUIImagePickerControllerInfoDictionary:(NSDictionary*)info;

/** Adds an attachment.
 Does not upload it to the server until  postLocalEditsToServer is called.
 @param info The dictionary provided by UIImagePickerController
 @param completion The completion block called when the operation completes
 @since 10.2.2
 */
-(void)addAttachmentWithUIImagePickerControllerInfoDictionary:(NSDictionary*)info
                                                   completion:(void (^)(AGSAttachment* attachment))completion;

#endif

/** Adds an attachment.
 Does not upload it to the server until  postLocalEditsToServer is called.
 @param data The raw binary data of the attachment
 @param name to be given to the attachment, including file extension
 @param contentType The MIME type of the data. For eg <i>image/png</i>
 @since 2.0
 */
-(AGSAttachment*)addAttachmentWithData:(NSData*)data name:(NSString*)name contentType:(NSString*)contentType;

/** Marks an attachment for deletion.
 Does not actually delete it from the server until  postLocalEditsToServer is called.
 @param attachment which must be marked for deletion
 @param del whether to mark or unmark the attachment for deletion
 @since 2.0
 */
-(void)markAttachment:(AGSAttachment*)attachment forDeletion:(BOOL)del;

/** Kicks off an asynchronous operation to download the attachment metadata for the feature
 that this attachment manager is associated with.
 This operation can be cancelled with the  cancelDownloadAttachmentInfos method.
 The  delegate will be informed when this operation is completed.
 @since 2.0
 @see  [AGSAttachmentManagerDelegate attachmentManager:didDownloadAttachmentInfos:] , method on delegate for success 
 @see  downloadAttachmentInfosError for error
 */
-(void)downloadAttachmentInfos;

/** Kicks off an asynchronous operation to download the attachment data for 
 an attachment with a particular id.
 This operation can be cancelled with the  cancelDownloadDataForId: method. The  delegate will be informed when this operation is completed. 
 @param attachmentId ID of the attachment for which to download the data
 @since 2.0
 @see  [AGSAttachmentManagerDelegate attachmentManager:didDownloadDataForAttachment:] , method on delegate for success or failure
 */
-(void)downloadAttachmentDataForId:(NSInteger)attachmentId;

/** Kicks off the asynchronous operations required to sync local edits contained in this attachment manager with the server.
 This operation can be cancelled with the  cancelPostLocalEditsToServer method.
The  delegate will be informed when this operation is completed.
 @since 2.0
 @see  [AGSAttachmentManagerDelegate attachmentManager:didPostLocalEditsToServer:] , method on delegate for success or failure
  */
-(void)postLocalEditsToServer;

/** Cancels the operations that are posting local edits to the server. It is  possible that some operations may already be done, only the outstanding
 ones will be cancelled.
 @since 2.0
 */
-(void)cancelPostLocalEditsToServer;

/** Cancels downloading data for a particular attachment.
 @since 2.0
 */
-(void)cancelDownloadDataForId:(NSInteger)attachmentId;

/** Cancels all download data operations that may be in progress or outstanding.
 @since 2.0
 */
-(void)cancelAllDownloadDataOperations;

/** Cancels the operation that is downloading the attachment metadata.
 @since 2.0
 */
-(void)cancelDownloadAttachmentInfos;

@end

/**  A delegate of  AGSAttachmentManager
 
 A protocol that must be adopted by any class wishing to be notified when operations
 performed by  AGSAttachmentManager are completed. An instance of the class must then be set as  [AGSAttachmentManager delegate] .
 
 All methods of this protocol are optional.
 
 @since 2.0
 */
@protocol AGSAttachmentManagerDelegate
@optional

/** Tells the delegate that the operation for downloading metadata for all
 attachments belonging to the feature associated with the AGSAttachmentManager is complete.
 
 When the operation completes, it is possible that an error may have been encountered. The
 delegate should always inspect the  [AGSAttachmentManager downloadAttachmentInfosError] property and handle the error appropriately.
 
 If no error was encountered, then the metadata was retrieved successfully, and  AGSAttachmentInfo objects containing the metadata are passed into this method. Also, the  [AGSAttachmentManager attachments] property is also populated with empty  AGSAttachment objects containing only metadata.
  
 @param attachmentManager that performed the operation
 @param attachmentInfos representing the attachment metadata. It is an array of  AGSAttachmentInfo objects.
 @since 2.0
 */
-(void)attachmentManager:(AGSAttachmentManager*)attachmentManager didDownloadAttachmentInfos:(NSArray*)attachmentInfos;

/** Tells the delegate that the operation for downloading data for 
 a particular attachment is complete.
 
 When the operation completes, it is possible that an error may have been encountered. The
 delegate should always inspect the  [AGSAttachment networkError] property of the attachment and
 handle the error appropriately.
 
 If no error was encountered, then the data was downloaded successfully, and you can invoke the
  [AGSAttachment data] method on the attachment object to get at the raw data.
 
 @param attachmentManager that performed the operation
 @param attachment containing the error or the raw data
 @since 2.0
 */
-(void)attachmentManager:(AGSAttachmentManager*)attachmentManager didDownloadDataForAttachment:(AGSAttachment*)attachment;

/** Tells the delegate that the  AGSAttachmentManager is done syncing 
 local edits with the remote server.
 
 
 If an error was encountered while posting the edits, the  [AGSAttachment networkError] or   [AGSAttachment editResultError] properties on individual attachment objects are set depending on whether a network error prevented the operation from succeeding, or if an underlying database error occurred on the server. A delegate should always inspect these properties and handle errors appropriately.
 
 
 @param attachmentManager that performed the operation
 @param attachmentsPosted representing the attachments that were to be synced with the server. It is an
 array of  AGSAttachment objects.
 @since 2.0
 */
-(void)attachmentManager:(AGSAttachmentManager*)attachmentManager didPostLocalEditsToServer:(NSArray*)attachmentsPosted;
@end