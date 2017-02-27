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

/** @file AGSNetworkDescription.h */

/**  Transportation network description.
 
 Instances of this class represent information about transportation network
 used by route task.
 
 Network description for an  AGSRouteTask can be retrieved by passing  AGSRouteTask
 the <code>retrieveNetworkDescription</code> message and listening to the
 <code>routeTask:operation:didRetrieveNetworkDescription:</code> delegate
 method.
 
 @since 10.2
 */
@interface AGSNetworkDescription : NSObject

/** Restriction usage attribute parameter values
 @since 10.2
 */
+ (NSArray *)restrictionUsageParameterValues;

/** Name of transportation network.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Array of  AGSCostAttribute objects. Each object represents a cost attribute. 
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *costAttributes;

/** Array of  AGSRestrictionAttribute objects. Each object represents a restriction attribute.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *restrictionAttributes;

/** Array of  NSString objects. Each object represents a supported directions language.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *supportedDirectionsLanguages;

/** Array of  NSString objects. Each object represents a supported directions style.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *supportedDirectionsStyles;

/** Array of  NSString objects. Each object represents allowed restriction attribute parameter value.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *restrictionUsageParameterValues;

@end
