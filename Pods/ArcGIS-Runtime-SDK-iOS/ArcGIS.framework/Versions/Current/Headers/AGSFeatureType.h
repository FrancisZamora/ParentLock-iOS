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

/** @file AGSFeatureType.h */ //Required for Globals API doc

/**  Encapsulates properties of types of features in a feature layer.
 
 Instances of this class represent a feature type. A feature type describes the
 various types of features that can belong to a feature layer.
 @since 1.0
 @see (A quick tour of [subtypes)[http://resources.arcgis.com/en/help/main/10.2/index.html //005r00000001000000]]
 */
@interface AGSFeatureType : NSObject <AGSCoding>

/** The ID of this type.
 @since 1.0
 */
@property (nonatomic, copy, readonly) id typeId;

/** The name of this type.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Temlates that can be used for creating new features of this type.
 This property is an array of  AGSFeatureTemplate objects.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSArray *templates;

/** Domains describing permissible attribute values for features of this type.
 This property is a dictionary containing key-value pairs of field name and a 
 corresponding  AGSDomain object for this type.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSDictionary *domains;

@end
