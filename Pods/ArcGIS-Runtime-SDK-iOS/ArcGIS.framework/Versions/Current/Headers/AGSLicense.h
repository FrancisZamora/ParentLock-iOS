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

@class AGSLicenseInfo;

/** @file AGSLicense.h */ //Required for Globals API doc

#pragma mark -

/**  Class representing a license object.
 
 A class representing a license used by the  AGSRuntimeEnvironment.
 
 */
@interface AGSLicense : NSObject

/** The  AGSLicenseLevel of the license.
 @since 10.2.2
 */
@property (nonatomic, assign, readonly) AGSLicenseLevel licenseLevel;

/** The date the license will expire.
 @since 10.2.2
 */
@property (nonatomic, strong, readonly) NSDate *expiry;

/** Set the  AGSLicenseInfo to be used by the Runtime Environment.
 @param licenseInfo the license info to set
 @return the result of the license operation
 @since 10.2.2
 */
-(AGSLicenseResult)setLicenseInfo:(AGSLicenseInfo *)licenseInfo;

/** Set the license code used by the Runtime Environment.
 @param licenseCode the license code provided by Esri
 @return the result of the license operation
 @since 10.2.2
 */
-(AGSLicenseResult)setLicenseCode:(NSString *)licenseCode;

@end
