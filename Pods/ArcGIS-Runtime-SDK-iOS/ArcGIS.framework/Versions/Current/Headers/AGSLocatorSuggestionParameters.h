/*
 COPYRIGHT 2014 ESRI
 
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

/**  Parameters for a suggest operation on  AGSLocator
 
 Instances of this class represent parameters for  [AGSLocator suggestionsWithParameters:] operation.
 
 @since newAPI
 */

@interface AGSLocatorSuggestionParameters : NSObject <AGSCoding>

/**
 Specifies the location to be geocoded. This can be a street address, place name, postal code, or POI. It is a required parameter.
 @since newAPI
 */
@property (nonatomic, copy) NSString *text;

/**
 Defines an origin point location that is used with the distance parameter to sort geocoding candidates based upon their proximity to the location. The distance parameter specifies the radial distance from the location in meters. The priority of candidates within this radius is boosted relative to those outside the radius.
 
 This is useful in mobile applications where a user will want to search for places in the vicinity of their current GPS location; the location and distance parameters can be used in this scenario.
 
 @since newAPI
 */
@property (nonatomic, strong) AGSPoint *location;

/**
 Specifies the distance in meters around the search location to define a region that influences
 the candidates returned from a geocoding request. If this parameter is specified, location
 parameter must also be specified. The value is interpreted to be in meters. 
 
 If location parameter is specified without a distance, then it defaults to 2000 meters.
 
 @since newAPI
 */
@property (nonatomic, assign) CGFloat distance;

@end
