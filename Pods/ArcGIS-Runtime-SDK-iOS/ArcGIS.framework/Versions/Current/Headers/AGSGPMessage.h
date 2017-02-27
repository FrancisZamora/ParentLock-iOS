/*
 COPYRIGHT 2012 ESRI
 
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

/** @file AGSGPMessage.h */ //Required for Globals API doc

/**  A message generated by a geoprocessing task.
 
 Instances of this class represent messages generated during the execution of a 
 geoprocessing task. They include information such as when the task started, what 
 parameter values are being used, the progress of the task, warnings of 
 potential problems, and errors.
 
 
 */
@interface AGSGPMessage : NSObject <AGSCoding>

/** The message type. Possible types include
 
 @li  AGSGPMessageTypeInformative
 @li  AGSGPMessageTypeProcessDefinition
 @li  AGSGPMessageTypeStart
 @li  AGSGPMessageTypeStop
 @li  AGSGPMessageTypeWarning
 @li  AGSGPMessageTypeError
 @li  AGSGPMessageTypeEmpty
 @li  AGSGPMessageTypeAbort
 
 @since 1.0
 */
@property (nonatomic, readonly) AGSGPMessageType type;

/** A description of the geoprocessing message.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *messageDescription;

@end