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

@class AGSPoint;
@protocol AGSCondig;

/**  A single direction event.
 
 Instances of this class represent an individual direction event.
 
 @since 10.2
 */
@interface AGSDirectionEvent : NSObject<AGSCoding>

/** Point geometry defining location for direction event.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSPoint *point;

/** Estimated arrival time for direction event.
 @since 10.2
 */
@property (nonatomic, strong, readonly) NSDate *ETA;

/** Array of  AGSNADirectionsString objects that give more verbose information regarding
 the current direction.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *eventStrings;

@end
