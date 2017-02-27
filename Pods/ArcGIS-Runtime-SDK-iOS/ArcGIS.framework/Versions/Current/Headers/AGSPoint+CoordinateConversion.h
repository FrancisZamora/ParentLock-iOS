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

#import "AGSPoint.h"

/** @file AGSPoint+CoordinateConversion.h */ //Required for Globals API doc

/**  Category methods for conversion between string and object representations
 
 This category contains methods to convert  AGSPoint objects into a variety of string representations and vice-versa. 
 
 
 */
@interface AGSPoint (CoordinateConversion)

#pragma mark -
#pragma mark Coordinate Conversion To Point

/** Returns a point for a given MGRS coordinate string, for eg "36RTJ1059034722575904" or "4Q 612341 2356781"
 @param mgrs The coordinate string. Can contain spaces.
 @param outputSR The spatial reference of the point to be returned.
 @return A point from the MGRS coordinate
 @since 10.2
 */
+(AGSPoint*)pointFromMGRSString:(NSString*)mgrs withSpatialReference:(AGSSpatialReference*)outputSR;

/** Returns a point for a given coordinate notation string in the Degrees Minutes Seconds (DMS) format, for eg "34 2 2.8 N, 117 53 24.66 E"
 @param degreesMinutesSeconds The coordinate string.
 @param outputSR The spatial reference of the point to be returned.
 @since 10.2
 */
+(AGSPoint*)pointFromDegreesMinutesSecondsString:(NSString*)degreesMinutesSeconds withSpatialReference:(AGSSpatialReference*)outputSR;

/** Returns a point for a given a coordinate notation string in the Decimal Degrees (DD) format, for eg "34.0547 N, 117.1825 W".
 @param decimalDegress The coordinate string.
 @param outputSR The spatial reference of the point to be returned.
 @since 10.2
 */
+(AGSPoint*)pointFromDecimalDegreesString:(NSString*)decimalDegrees withSpatialReference:(AGSSpatialReference*)outputSR;

/** Returns a point for a given coordinate notation string in the Degrees Decimal Minutes (DDM) format, for eg "7 5.123 N 94 17.765 E".
 @param ddm The coordinate string.
 @param outputSR The spatial reference of the point to be returned.
 @since 10.2
 */
+(AGSPoint*)pointFromDegreesDecimalMinutesString:(NSString*)ddm withSpatialReference:(AGSSpatialReference*)outputSR;

/** Returns a point for a given coordinate notation string in the Global Area Reference System (GARS) format, for eg "421LA37".
 @param gars The coordinate string.
 @param outputSR The spatial reference of the point to be returned.
 @param conversionMode A value determining whether the returned map point will represent the lower left or center of the cell, quadrant or area.
 @since 10.2
 */
+(AGSPoint*)pointFromGARSString:(NSString*)gars withSpatialReference:(AGSSpatialReference*)outputSR conversionMode:(AGSGARSConversionMode)conversionMode;

/** Returns a point for a given coordinate notation string in the Universal Transverse Mercator (UTM) format, for eg "31N1660210000000".
 @param utm The coordinate string.
 @param outputSR The spatial reference of the point to be returned.
 @param conversionMode A value indicating whether the coordinate string contains North or South Hemisphere indicators.
 @since 10.2
 */
+(AGSPoint*)pointFromUTMString:(NSString*)utm withSpatialReference:(AGSSpatialReference*)outputSR conversionMode:(AGSUTMConversionMode)conversionMode;

/** Returns a point for a given coordinate notation string in the Geographic Reference system (GEOREF) format, for eg "QJAA0000000000".
 @param georef The coordinate string.
 @param outputSR The spatial reference of the point to be returned.
 @since 10.2
 */
+(AGSPoint*)pointFromGEOREFString:(NSString*)georef withSpatialReference:(AGSSpatialReference*)outputSR;

/** Returns a point for a given coordinate notation string in the United States National Grid (USNG) format, for eg "32Q PH 04609324 11793556".
 @param usng The coordinate string.
 @param outputSR The spatial reference of the point to be returned.
 @since 10.2
 */
+(AGSPoint*)pointFromUSNGString:(NSString*)usng withSpatialReference:(AGSSpatialReference*)outputSR;


#pragma mark -
#pragma mark Coordinate Conversion To String

/** Returns a Military Grid Reference System (MGRS) coordinate for the current point. For example : 4Q 612341 2356781
 @param numDigits The number of digits to be included in the MGRS coordinate
 @param rounding Whether the numeric value should be rounded
 @param addSpaces Whether the MGRS coordinate string should include spaces
 @return The MGRS coordinate string
 @since 10.2
 */
-(NSString*)MGRSStringWithNumDigits:(NSInteger)numDigits rounding:(BOOL)rounding addSpaces:(BOOL)addSpaces;

/** Returns a string with degrees minutes seconds (DMS) for the current point.
 @param numDigits The number of digits to be included in the output string
 @return The DMS string
 @since 10.2
 */
-(NSString*)degreesMinutesSecondsStringWithNumDigits:(NSInteger)numDigits;

/** Returns a string with Decimal Degrees (DD) format for the current point.
 @param numDigits The number of digits to be included in the output string
 @return The DD string
 @since 10.2
 */
-(NSString*)decimalDegreesStringWithNumDigits:(NSInteger)numDigits;

/** Returns a string with degrees decimal minute (DDM) format for the current point.
 @param numDigits The number of digits to be included in the output string
 @return The DDM string
 @since 10.2
 */
-(NSString*)degreesDecimalMinutesStringWithNumDigits:(NSInteger)numDigits;

/** Returns a string with Global Area Reference System (GARS) format for the current point.
 @return The GARS string
 @since 10.2
 */
-(NSString*)GARSString;

/** Returns a string with United States National Grid (USNG) format for the current point.
 @param numDigits The number of digits to be included in the output string
 @param rounding Whether the numeric value should be rounded
 @param addSpaces Whether the coordinate string should include spaces
 @return The USNG string
 @since 10.2
 */
-(NSString*)USNGStringWithNumDigits:(NSInteger)numDigits
                           rounding:(BOOL)rounding
                          addSpaces:(BOOL)addSpaces;

/** Returns a string with World Geographic Reference system (GEOREF) format for the current point.
 @param numDigits The number of digits to be included in the output string
 @param rounding Whether the numeric value should be rounded
 @return The GEOREF string
 @since 10.2
 */
-(NSString*)GEOREFStringWithNumDigits:(NSInteger)numDigits
                             rounding:(BOOL)rounding;

/** Returns a string with Universal Transverse Mercator (UTM) format for the current point.
 @param conversionMode The mode to use during conversion
 @param addSpaces Whether the coordinate string should include spaces
 @return the UTM string
 @since 10.2
 */
-(NSString*)UTMStringWithConversionMode:(AGSUTMConversionMode)conversionMode addSpaces:(BOOL)addSpaces;

@end
