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

@class AGSColor;
@class AGSColorRamp;

/** @file AGSColorRamp.h */ //Required for Globals API doc

/** Create an <code>%AGSColorRamp</code> object from JSON representation
 @param json The JSON representation of the color ramp to create.
 @since 10.2.4
 */
AGS_EXTERN AGSColorRamp *AGSColorRampWithJSON(NSDictionary *json);

#pragma mark -

/**  A base class for color ramps.
 
 Instances of this class represent color ramps that should be used by a server
 when generating a renderer from either  AGSUniqueValueDefinition or  AGSClassBreaksDefinition.
 
 
 @since 10.2.4
 */
#import <Foundation/Foundation.h>

@interface AGSColorRamp : NSObject <AGSCoding>

@end
