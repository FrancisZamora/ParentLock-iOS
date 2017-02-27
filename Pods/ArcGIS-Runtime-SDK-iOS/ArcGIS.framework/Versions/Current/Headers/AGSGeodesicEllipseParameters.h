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

#import <Foundation/Foundation.h>
@class AGSPoint;

/** @file AGSGeodesicEllipseParameters.h */ //Required for Globals API doc

/**  Parameters for  [AGSGeometryEngine geodesicEllipseWithParameters:]
 
 This class holds options for the  [AGSGeometryEngine geodesicEllipseWithParameters:] operation.
 
  
 */
@interface AGSGeodesicEllipseParameters : NSObject

/** The center AGSPoint of the ellipse.
  @since 10.2
 */
@property (nonatomic, strong) AGSPoint *center;

/** The length of the semi-major or the semi-minor axis of the ellipse. 
 @since 10.2
 */
@property (nonatomic, assign) double semiAxis1Length;

/** The length of the semi-major or the semi-minor axis of the ellipse. If semiAxis1 = semiAxis2 then a geodesic circle is created.
 @since 10.2
 */
@property (nonatomic, assign) double semiAxis2Length;

/** The linear units of the lengths maxSegment, semiAxis1 and semiAxis2. The default is AGSSRUnitMeter.
 @since 10.2
 */
@property (nonatomic, assign) AGSSRUnit unit;

/** The direction of the longest axis of the ellipse as an angle (in degrees).
 @since 10.2
 */
@property (nonatomic, assign) double axisDirection;

/** The maximum distance between vertices used to construct the ellipse.
 @since 10.2
 */
@property (nonatomic, assign) double maxSegmentLength;

/** The type of output geometry created. Acceptable values are AGSMultipoint, AGSPolyline and AGSPolygon. Defaults to AGSGeometryTypePolgon.
 @since 10.2
 */
@property (nonatomic, assign) AGSGeometryType geometryType;

/**Initializes an AGSGeodesicEllipseParameters object.
 @param center The center point of the ellipse.
 @param maxSegmentLength The maximum distance between vertices used to construct the ellipse.
 @param semiAxisLength The length of the semi-major or the semi-minor axis of the ellipse. 
 @return A new geodesic ellipse parameter object.
 @since 10.2
 */
-(id)initWithCenter:(AGSPoint*)center maxSegmentLength:(double)maxSegmentLength semiAxisLength:(double)semiAxisLength;

/**Initializes an AGSGeodesicEllipseParameters object.
 @param center The center AGSPoint of the ellipse.
 @param maxSegmentLength The maximum distance between vertices used to construct the ellipse.
 @param semiAxisLength The length of the semi-major or the semi-minor axis of the ellipse.
 @return A new, autoreleased, geodesic ellipse parameter object.
 @since 10.2
 */
+(id)parametersWithCenter:(AGSPoint*)center maxSegmentLength:(double)maxSegmentLength semiAxisLength:(double)semiAxisLength;

@end




