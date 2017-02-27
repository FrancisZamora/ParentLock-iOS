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

@class AGSColorRamp;

/** @file AGSAlgorithmicColorRamp.h */ //Required for Globals API doc

/**  Algorithmic color ramp class
 
 Provides information describing an algorithmically generated color ramp
 to be used by a server when generating a class breaks or unique value renderer.
 The color ramp is defined by from and to colors and an algorithm that should
 be used to generate the intermediate colors.
 
 @since 10.2.4
 */
@interface AGSAlgorithmicColorRamp : AGSColorRamp

/** The starting color for the  AGSColorRamp.
 @since 10.2.4
 */
@property (nonatomic, strong) AGSColor *fromColor;

/** The ending color for the  AGSColorRamp.
 @since 10.2.4
 */
@property (nonatomic, strong) AGSColor *toColor;

/** The  AGSColorRamp algorithm used to generate intermediate colors
 between the from color and the to color.
 @since 10.2.4
 */
@property (nonatomic, assign) AGSColorRampAlgorithm algorithm;

/** Initialize a  AGSAlgorithmicColorRamp with the given fromColor, toColor, and algorithm.
 @param fromColor the starting color.
 @param toColor the ending color.
 @param algorithm the algorithm used to generate intermediate colors
 between the from color and the to color.
 @since 10.2.4
 */
-(id)initWithFromColor:(AGSColor *)fromColor toColor:(AGSColor *)toColor algorithm:(AGSColorRampAlgorithm)algorithm;

/** Create a new  AGSAlgorithmicColorRamp with the given fromColor, toColor, and algorithms.
 @param fromColor the starting color.
 @param toColor the ending color.
 @param algorithm the algorithm used to generate intermediate colors
 between the from color and the to color.
 @return A new algorithmic color ramp.
 @since 10.2.4
 */
+(id)algorithmicColorRampWithFromColor:(AGSColor *)fromColor toColor:(AGSColor *)toColor algorithm:(AGSColorRampAlgorithm)algorithm;

@end
