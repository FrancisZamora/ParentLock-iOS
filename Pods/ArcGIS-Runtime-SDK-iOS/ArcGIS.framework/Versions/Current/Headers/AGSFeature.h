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

#import <Foundation/Foundation.h>
@protocol AGSGDBFeatureSourceInfo;
@class AGSGeometry;

/**  An abstract geographic feature
 
 This protocol represents abstract geographic features. Conforming classes provide implementations of features which either
 reside in a local geodatabase ( AGSGDBFeature) or in memory ( AGSGraphic)
 
 A feature can contain a set of attributes (key-value paris) providing more
 information about the real-world entity it represents. Attribute types supported are basically NSNull, NSString, NSDate, and NSNumber.
 All other attribute types will be ignored. A feature can also have a geometry which describes the location and the shape of the 
 entity.
 
 
 @since 10.2
 */
@protocol AGSFeature <NSObject>

/** The geometry that defines the feature's shape and location.
 Note, the geometry object assigned to this property will be copied over. Any change you make to the geometry
 thereafter will not affect the feature, because the feature will continue to use its private copy.
 To update the feature's geometry, assign the gometry object to the feature again.
 @since 10.2
 */
@property (nonatomic, copy, readwrite) AGSGeometry *geometry;

/** An ID that uniquely identifies this feature.
 @since 10.2
 */
@property (nonatomic, assign, readonly) NSUInteger featureId;

#pragma mark attributes

/** Returns a dictionary containing all the attributes of the feature.
 Attribute types supported are basically NSNull, NSString, NSDate, and NSNumber.
 Other attribute types will be ignored.
 The dictionary returned is a copy. Any changes you make to it do not affect the feature.
 @since 10.2
 */
-(NSDictionary*)allAttributes;

/** Sets attributes for this feature based on key-value pairs specified in the provided
 dictionary. The dictionary is copied over. Any changes you make to the dictionary thereafter will not affect
 the feature. If you want to update the feature's attributes, you must call this method again.
 
 Attribute types supported are basically NSNull, NSString, NSDate, and NSNumber. Other attribute types will be ignored.
 @since 10.2
 */
-(void)setAttributes:(NSDictionary*)attributes;

/** Indicates whether the feature contains an attribute for the specified key.
 @param key Name of the attribute
 @since 10.2
 */
-(BOOL)hasAttributeForKey:(NSString*)key;

/** Returns the attribute value for the specified key.
 The type returned will be one of NSNull, NSString, NSDate, or NSNumber.
 @param key Name of the attribute
 @since 10.2
 */
-(id)attributeForKey:(NSString*)key;

/** Returns the attribute value for the specified key.
 Since this is the "safe" version, if the value is NSNull it will return nil.
 The type returned will be one of  NSString, NSDate, or NSNumber.
 @param key Name of the attribute
 @since 10.2
 */
-(id)safeAttributeForKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 If nil is passed in, it will remove the key.
 @param value of the attribute
 @param key Name of the attribute
 @since 10.2
 */
-(void)setAttribute:(id)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @since 10.1.1
 */
-(void)setAttributeWithString:(NSString*)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @since 10.1.1
 */
-(void)setAttributeWithDouble:(double)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @since 10.1.1
 */
-(void)setAttributeWithInt:(int)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @since 10.1.1
 */
-(void)setAttributeWithUnsignedInt:(uint)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @since 10.1.1
 */
-(void)setAttributeWithFloat:(float)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @since 10.1.1
 */
-(void)setAttributeWithBool:(BOOL)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @since 10.1.1
 */
-(void)setAttributeWithDate:(NSDate*)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @since 10.1.1
 */
-(void)setAttributeWithLong:(long)value forKey:(NSString*)key;

/** Sets an attribute value for the specified key.
 @since 10.1.1
 */
-(void)setAttributeWithInteger:(NSInteger)value forKey:(NSString*)key;

/** Sets an attribute value to NSNull for the specified key.
 @since 10.1.1
 */
-(void)setAttributeToNullForKey:(NSString*)key;

/** Returns the attribute value for the specified key as an  NSString value.  Returns nil if key doesn't exist.
 If you don't know the expected type of the value, use  attributeForKey: or  safeAttributeForKey:
 
 @param key Name of the attribute
 @since 10.1.1
 @see  allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(NSString*)attributeAsStringForKey:(NSString*)key;

/** Returns the attribute value for the specified key as an  NSDate value. Returns nil if key doesn't exist.
 
 If you don't know the expected type of the value, use  attributeForKey: or  safeAttributeForKey:
 @param key Name of the attribute
 @since 10.1.1
 @see  allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(NSDate*)attributeAsDateForKey:(NSString*)key;

/** Returns the attribute value for the specified key as a  double value.
 If you don't know the expected type of the value, use  attributeForKey: or  safeAttributeForKey:
 @param key Name of the attribute
 @param exists parameter is set to YES if the key existed and the value is not  NSNull.
 Note however, YES doesn't denote a successful conversion between data types with no loss.
 @since 10.1.1
 @see  allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(double)attributeAsDoubleForKey:(NSString*)key exists:(BOOL*)exists;

/** Returns the attribute value for the specified key as a  int value.
 If you don't know the expected type of the value, use  attributeForKey: or  safeAttributeForKey:
 @param key Name of the attribute
 @param exists parameter is set to YES if the key existed and the value is not  NSNull.
 Note however, YES doesn't denote a successful conversion between data types with no loss.
 @since 10.1.1
 @see  allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(int)attributeAsIntForKey:(NSString*)key exists:(BOOL*)exists;

/** Returns the attribute value for the specified key as a  uint value.
 If you don't know the expected type of the value, use  attributeForKey: or  safeAttributeForKey:
 @param key Name of the attribute
 @param exists parameter is set to YES if the key existed and the value is not  NSNull.
 Note however, YES doesn't denote a successful conversion between data types with no loss.
 @since 10.1.1
 @see  allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(uint)attributeAsUnsignedIntForKey:(NSString*)key exists:(BOOL*)exists;

/** Returns the attribute value for the specified key as a  float value.
 If you don't know the expected type of the value, use  attributeForKey: or  safeAttributeForKey:
 @param key Name of the attribute
 @param exists parameter is set to YES if the key existed and the value is not  NSNull.
 Note however, YES doesn't denote a successful conversion between data types with no loss.
 @since 10.1.1
 @see  allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(float)attributeAsFloatForKey:(NSString*)key exists:(BOOL*)exists;

/** Returns the attribute value for the specified key  as a  BOOL value.
 If you don't know the expected type of the value, use  attributeForKey: or  safeAttributeForKey:
 @param key Name of the attribute
 @param exists parameter is set to YES if the key existed and the value is not  NSNull.
 Note however, YES doesn't denote a successful conversion between data types with no loss.
 @since 10.1.1
 @see  allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(BOOL)attributeAsBoolForKey:(NSString*)key exists:(BOOL*)exists;

/** Returns the attribute value for the specified key as a  long value.
 If you don't know the expected type of the value, use  attributeForKey: or  safeAttributeForKey:
 @param key Name of the attribute
 @param exists parameter is set to YES if the key existed and the value is not  NSNull.
 Note however, YES doesn't denote a successful conversion between data types with no loss.
 @since 10.1.1
 */
-(long)attributeAsLongForKey:(NSString*)key exists:(BOOL*)exists;

/** Returns the attribute value for the specified key as an  NSInteger value.
 If you don't know the expected type of the value, use  attributeForKey: or  safeAttributeForKey:
 @param key Name of the attribute
 @param exists parameter is set to YES if the key existed. Note however, YES doesn't denote
 a successful conversion between data types with no loss.
 @since 10.1.1
 @see  allAttributes for getting a <b>copy</b> of all graphic attributes as an NSDictionary
 */
-(NSInteger)attributeAsIntegerForKey:(NSString*)key exists:(BOOL*)exists;

@end
