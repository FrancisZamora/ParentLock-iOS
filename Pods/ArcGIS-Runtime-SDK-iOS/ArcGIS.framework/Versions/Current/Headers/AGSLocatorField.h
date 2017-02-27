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

/** @file AGSLocatorField.h */ //Required for Globals API doc

/**  An object that represents information about a locator field.
 
 Instances of this class represent information about locator field.
 @since 10.2
 */
@interface AGSLocatorField : NSObject <AGSCoding>

/** Name of the field.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Type of values in the field. Possible field types include
 
 @li  AGSFieldTypeInteger
 @li  AGSFieldTypeSmallInteger
 @li  AGSFieldTypeDouble
 @li  AGSFieldTypeSingle
 @li  AGSFieldTypeString
 @li  AGSFieldTypeDate
 @li  AGSFieldTypeGeometry
 @li  AGSFieldTypeOID
 @li  AGSFieldTypeBlob
 @li  AGSFieldTypeGlobalID
 @li  AGSFieldTypeRaster
 @li  AGSFieldTypeGUID
 @li  AGSFieldTypeXML
 
 @since 10.2
 */
@property (nonatomic, assign, readonly) AGSFieldType type;

/** Alias name of the field. Alias name is usually more user friendly than the
 actual field name which may use underlying datasource naming conventions.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *alias;

/** Indicates if the field is mandatory.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL mandatory;

/** The field length.
 @since 10.2
 */
@property (nonatomic, assign, readonly) NSInteger length;

@end