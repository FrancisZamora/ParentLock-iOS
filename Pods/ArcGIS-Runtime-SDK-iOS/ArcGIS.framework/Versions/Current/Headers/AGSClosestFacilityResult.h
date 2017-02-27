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



/** @file AGSClosestFacilityResult.h */

@class AGSDirectionSet;
@class AGSGraphic;

/**  The result of the  AGSClosestFacilityTask. 
 
 The result of the  AGSClosestFacilityTask. This object should not be created manually.
 An array of  AGSClosestFacilityResult objects will be returned within an  AGSClosestFacilityTaskResult.
 @since 1.8
 */
@interface AGSClosestFacilityResult : NSObject

/** Route directions are returned if  AGSClosestFacilityTaskParameters <code>returnDirections</code>
 property is set to <code>true</code>.
 @since 1.8
 */
@property (nonatomic, strong, readonly) AGSDirectionSet *directions;

/** The route graphic that is returned if  AGSClosestFacilityTaskParameters 
 <code>returnRouteGraphics</code> property is <code>true</code>.
 @since 1.8
 */
@property (nonatomic, strong, readonly) AGSGraphic *routeGraphic;

/** The name of the route.
 @since 1.8
 */
@property (nonatomic, copy, readonly) NSString *routeName;

@end
