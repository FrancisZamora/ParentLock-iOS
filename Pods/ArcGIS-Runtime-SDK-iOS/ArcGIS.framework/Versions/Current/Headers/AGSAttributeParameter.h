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

/** @file AGSAttributeParameter.h */

/**  Transportation network parameter descriptor.
 
 Instances of this class represent transportation network parameter information.
 @since 10.2
 */
@interface AGSAttributeParameter : NSObject

/** Transportation network parameter name.
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Transportation network parameter default value.
 @since 10.2
 */
@property (nonatomic, copy, readonly) id defaultValue;

@end
