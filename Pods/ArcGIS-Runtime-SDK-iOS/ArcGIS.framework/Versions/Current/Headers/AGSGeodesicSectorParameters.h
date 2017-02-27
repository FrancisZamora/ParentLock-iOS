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

/** @file AGSGeodesicSectorParameters.h */ //Required for Globals API doc

/**  Parameters for  [AGSGeometryEngine geodesicSectorWithParameters:] 
 
  This class holds options for the  [AGSGeometryEngine geodesicSectorWithParameters:] operation.
 
  
 */
@interface AGSGeodesicSectorParameters : NSObject

/** The center AGSPoint of the ellipse. The ellipse is used to contruct the sector's arc.
  @since 10.2
 */
@property (nonatomic, strong) AGSPoint *center;

/** The length of the semi-major or the semi-minor axis of the ellipse. The ellipse is used to contruct the sector's arc.
 @since 10.2
 */
@property (nonatomic, assign) double semiAxis1Length;

/** The length of the semi-major or the semi-minor axis of the ellipse. The ellipse is used to contruct the sector's arc. If semiAxis1 = semiAxis2 then a geodesic circle is created.
 @since 10.2
 */
@property (nonatomic, assign) double semiAxis2Length;

/** The linear units of the lengths maxSegment, semiAxis1 and semiAxis2. The default is AGSSRUnitMeter.
 @since 10.2
 */
@property (nonatomic, assign) AGSSRUnit unit;

/** The direction of the longest axis of the ellipse as an angle (in degrees). The ellipse is used to contruct the sector's arc.
 @since 10.2
 */
@property (nonatomic, assign) double axisDirection;

/** The direction of the starting radius of the sector as an angle in degrees. 0 is East.
 @since 10.2
 */
@property (nonatomic, assign) double startDirection;

/** The angle of the sector in degrees. An absolute value is used only. Should be greater than zero and less than 360. A positive sector angle goes clockwise from the startDirection.
 @since 10.2
 */
@property (nonatomic, assign) double sectorAngle;

/** The maximum distance between vertices used to construct the sector's arc.
 @since 10.2
 */
@property (nonatomic, assign) double maxSegmentLength;

/** The type of output geometry created. Acceptable values are AGSMultipoint, AGSPolyline and AGSPolygon. Defaults to AGSGeometryTypePolgon. 
 @since 10.2
 */
@property (nonatomic, assign) AGSGeometryType geometryType;

/**Initializes an AGSGeodesicSectorParameters object.
 @param center The center AGSPoint of the ellipse. The ellipse is used to contruct the sector's arc.
 @param maxSegmentLength The maximum distance between vertices used to construct the sector's arc.
 @param semiAxisLength The length of the semi-major or the semi-minor axis of the ellipse. This ellipse is used to contruct the sector's arc.
 @return A new geodesic sector parameter object.
 @since 10.2
 */
-(id)initWithCenter:(AGSPoint*)center maxSegmentLength:(double)maxSegmentLength semiAxisLength:(double)semiAxisLength;

/**Initializes an AGSGeodesicSectorParameters object.
@param center The center AGSPoint of the ellipse. The ellipse is used to contruct the sector's arc.
@param maxSegmentLength The maximum distance between vertices used to construct the sector's arc.
@param semiAxisLength The length of the semi-major or the semi-minor axis of the ellipse. This ellipse is used to contruct the sector's arc.
@return A new, autoreleased, geodesic sector parameter object.
 @since 10.2
 */
+(id)parametersWithCenter:(AGSPoint*)center maxSegmentLength:(double)maxSegmentLength semiAxisLength:(double)semiAxisLength;

@end




