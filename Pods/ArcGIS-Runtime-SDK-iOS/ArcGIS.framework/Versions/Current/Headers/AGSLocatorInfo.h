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

@class AGSLocatorField;
@class AGSSpatialReference;
@protocol AGSCoding;

/** @file AGSLocatorInfo.h */ //Required for Globals API doc

/**  Represents locator service information.
 
 Instances of this class represent meta information returned by  AGSLocator for
 service info operation.
 
 
 */
@interface AGSLocatorInfo : NSObject<AGSCoding>

/** Locator service human readable description.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *serviceDescription;

/** Array of  AGSLocatorField objects representing input address fields to be used for geocoding.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *addressFields;

/** Field for single line address geocoding. If feature is not supported then  nil.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSLocatorField *singleLineAddressField;

/** Array of  AGSLocatorField objects returned by locator for geocoded address candidates.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *candidateFields;

/** Array of  AGSLocatorField objects returned by locator for geocoded intersection candidates.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *intersectionCandidateFields;

/** Locator spatial reference.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSSpatialReference *spatialReference;

@end
