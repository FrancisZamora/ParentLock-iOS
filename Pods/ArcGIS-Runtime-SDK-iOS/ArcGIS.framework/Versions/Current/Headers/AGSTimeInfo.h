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

#pragma mark -

@class AGSTimeExtent;
@class AGSTimeReference;

/** @file AGSTimeInfo.h */
/**  Time information details.
 
 Instances of this class represent time information of a layer. It contains various time related
 info for dealing with time-aware layers.
 
 
 */
@interface AGSTimeInfo : NSObject <AGSCoding>

/** The name of the attribute field that contains the start time information.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *startTimeField;

/** The name of the attribute field that contains the end time information.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *endTimeField;

/** The field that contains the trackId.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *trackIdField;

/** The time extent for all the data in the layer.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSTimeExtent *timeExtent;

/** Information about how the time was referenced.
 @since 1.0
 */
@property (nonatomic, strong, readonly) AGSTimeReference *timeReference;

/** Time interval of the data in the layer.
 @since 1.0
 */
@property (nonatomic, assign, readonly) double timeInterval;

/** Temporal unit in which the time interval is measured. Possible values 
 include
 
 @li  AGSTimeIntervalUnitsCenturies
 @li  AGSTimeIntervalUnitsDays
 @li  AGSTimeIntervalUnitsDecades
 @li  AGSTimeIntervalUnitsHours
 @li  AGSTimeIntervalUnitsMilliseconds	
 @li  AGSTimeIntervalUnitsMinutes	
 @li  AGSTimeIntervalUnitsMonths
 @li  AGSTimeIntervalUnitsSeconds
 @li  AGSTimeIntervalUnitsUnknown	
 @li  AGSTimeIntervalUnitsWeeks
 @li  AGSTimeIntervalUnitsYears
 
 @since 1.0
 */
@property (nonatomic, assign, readonly) AGSTimeIntervalUnits timeIntervalUnits;

@end