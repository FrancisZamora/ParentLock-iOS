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

/** @file AGSGPLinearUnit.h */ //Required for Globals API doc

/**  A data object containing a linear distance.
 
 Instances of this class represent a linear distance and its measuring unit.
  
 */
@interface AGSGPLinearUnit : NSObject <AGSCoding>

/** The measuring unit. Possible types include
 
 @li  AGSUnitsCentimeters 
 @li  AGSUnitsDecimalDegrees
 @li  AGSUnitsDecimeters
 @li  AGSUnitsFeet
 @li  AGSUnitsInches
 @li  AGSUnitsKilometers
 @li  AGSUnitsMeters
 @li  AGSUnitsMiles
 @li  AGSUnitsMillimeters
 @li  AGSUnitsNauticalMiles
 @li  AGSUnitsPoints
 @li  AGSUnitsUnknown
 @li  AGSUnitsYards
 
 @since 1.0
 */
@property (nonatomic) AGSUnits units;

/** The distance value.
 @since 1.0
 */
@property (nonatomic) double distance;

@end