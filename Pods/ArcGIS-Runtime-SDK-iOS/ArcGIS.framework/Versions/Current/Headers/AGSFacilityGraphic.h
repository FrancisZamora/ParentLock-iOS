/*
 COPYRIGHT 2011 ESRI
 
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



@protocol AGSCoding;
@class AGSGraphic;
@class AGSPoint;

/**  Graphic used as input to the  AGSServiceAreaTask and  AGSClosestFacilityTask.
 
 A graphic that can be used as input to the solve operation of an  AGSServiceAreaTask or
  AGSClosestFacilityTask. This graphic will also be returned in an array if the <code>returnFacilities</code>
 parameter of an  AGSServiceAreaTask or  AGSClosestFacilityTask is set to <code>true</code>.
 @since 1.8
 */
@interface AGSFacilityGraphic : AGSGraphic<AGSCoding> {
    
}

/** An string representing the name of the facility.
 @since 1.8
 */
@property (nonatomic, weak) NSString *name;

/** Initialize a new  AGSFacilityGraphic.
 @param pt The location of the facility.
 @param name The name of the facility.
 @return A new  AGSFacilityGraphic.
 @since 1.8
 */
- (id)initWithPoint:(AGSPoint*)pt name:(NSString*)name;

/** Initialize a new, autoreleased  AGSFacilityGraphic.
 @param pt The location of the facility.
 @param name The name of the facility.
 @return A new, autoreleased  AGSFacilityGraphic.
 @since 1.8
 */
+ (id)graphicWithPoint:(AGSPoint*)pt name:(NSString*)name;

@end
