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

@class AGSLicense;

/** @file AGSRuntimeEnvironment.h */ //Required for Globals API doc

#pragma mark -

/**  Class representing the ArcGIS Runtime Environment.
 
 A class representing the ArcGIS Runtime Environment.
 
 */
@interface AGSRuntimeEnvironment : NSObject

/** Return the  AGSLicense used by the Runtime Environment.
 @return the license used by the Runtime Environment
 @since 10.2.2
 */
+(AGSLicense *)license;

/** Set the clientID to be used by the Runtime Environment.
 @param clientID application clientID
 @param error if the return value is NO, there will be more information available in @p error
 @return whether the client ID was set
 @since 10.2.2
 */
+(BOOL)setClientID:(NSString *)clientID error:(NSError **)error;

@end
