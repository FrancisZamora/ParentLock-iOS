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

#import <Foundation/Foundation.h>

@class AGSPortalInfo;

/** @file AGSLicenseInfo.h */ //Required for Globals API doc

#pragma mark -

/**  Class representing a license info object.
 
 A class representing a license info used by the ArcGIS Runtime Environment.
 
 */
@interface AGSLicenseInfo : NSObject <AGSCoding>

/** Initialize the license information based upon a connection to an on-premise ArcGIS Portal or ArcGIS Online organization subscription.
 @param portalInfo representing information about the connected  AGSPortal
 @since 10.2.2
 */
-(id)initWithPortalInfo:(AGSPortalInfo *)portalInfo;

@end
