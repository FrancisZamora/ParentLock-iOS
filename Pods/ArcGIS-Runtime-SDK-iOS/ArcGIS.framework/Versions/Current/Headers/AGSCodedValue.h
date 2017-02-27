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

/** @file AGSCodedValue.h */ //Required for Globals API doc

/**  Represents coded values of  AGSCodedValueDomain. 
 
 Instances of this class represent coded values of  AGSCodedValueDomain.
 @since 1.0
 */
@interface AGSCodedValue : NSObject <AGSCoding>

/** A user-friendly name of the coded value.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *name;

/** The actual value of the coded value. The data type of the value depends upon 
 the data type of the field it is associated with.
 @since 1.0
 */
@property (nonatomic, strong, readonly) id code;

@end
