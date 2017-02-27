/*
 COPYRIGHT 2009 ESRI
 
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

@class AGSGeometry;
@class AGSGeometryError;
@class AGSEnvelope;
@class AGSMutablePoint;
@class AGSMutablePolygon;
@class AGSPoint;
@class AGSPolyline;
@class AGSPolygon;
@class AGSProximityResult;
@class AGSSpatialReference;
@class AGSGeodesicSectorParameters;
@class AGSGeodesicEllipseParameters;
@class AGSGeodesicDistanceResult;

/** @file AGSGeometryEngine.h */ //Required for Globals API doc

/**  An engine to perform geometric operations
 
 Instances of this class represents engines that can perform geometric operations locally on the device.
  AGSGeometryEngine is functionally similar to  AGSGeometryServiceTask except that it does not rely on a remote ArcGIS Geometry Service.
 You can use the engine even when the device does not have any network connectivity.
 
 @see oncept{geometry-operations.htm, Peforming geometric operations}
 @see 
 */
@interface AGSGeometryEngine : NSObject

/**  Projects the given geometry into a new spatial reference.
 @param geometry The geometry to be projected.
 @param spatialReference The spatial reference to which geometry need to be 
 projected.
 @return The projected geometry
 @since 1.8
 */
- (AGSGeometry*)projectGeometry:(AGSGeometry*)geometry toSpatialReference:(AGSSpatialReference*)spatialReference;

/** Gets the simple area for the AGSGeometry passed in. This is a planar measurement using 2D Cartesian mathematics to compute the area.

 The geometry must be topologically correct
 to get its accurate legth. Geometries returned by ArcGIS Server services are always correct.
 If you construct geometries programmatically or using the sketch layer, or if you modify geometries returned by ArcGIS Server, 
 you should simplify them using [<code> simplifyGeometry:</code>]
 @param geometry The geometry to calculate the area for.
 @return The computed area in the same units as the geometry's spatial reference unit.
 @since 1.8
 @see shapePreservingAreaOfGeometry:inUnit:
 */
-(double)areaOfGeometry:(AGSGeometry*)geometry;

/** Calculates the area of the geometry on the surface of the Earth ellipsoid. This method preserves the shape of the geometry in its coordinate system. This means the true area will be calculated for the geometry you see in the map.
 @param geometry whose area needs to be computed
 @param areaUnit The unit in which area needs to be computed
 @return The area of the geometry
 @since 2.2
 */
-(double)shapePreservingAreaOfGeometry:(AGSGeometry*)geometry inUnit:(AGSAreaUnits)areaUnit;

/** Gets the geodesic area for the AGSGeometry passed in. Will return NAN if the calculation
 results in a linear to angular conversion (for instance, Decimal Degrees to Meters)
 @param geometry The geometry to calculate the area for.
 @param areaUnit The unit at which the area is calculated.
 @return The calculated geodesic area in the specified unit.
 @since 10.2
 */
-(double)geodesicAreaOfGeometry:(AGSGeometry*)geometry inUnit:(AGSAreaUnits)areaUnit;

/** Gets the length for a specified  AGSGeometry. This is a planar measurement using 2D Cartesian mathematics to compute the length.
 
 The geometry must be topologically correct
 to get its accurate legth. Geometries returned by ArcGIS Server services are always correct.
 If you construct geometries programmatically or using the sketch layer, or if you modify geometries returned by ArcGIS Server, 
 you should simplify them using <code>simplifyGeometry:</code>

 @param geometry The geometry to calculate the length for.
 @return The calculated length in the same units as the geometry's spatial reference unit.
 @since 1.8
 @see shapePreservingLengthOfGeometry:inUnit:

 */
-(double)lengthOfGeometry:(AGSGeometry*)geometry;

/** Gets the geodesic length for the AGSGeometry passed in. Geodesic length is calculated  using only the vertices of the polygon and define the lines between the points as geodesic segments independent of the actual shape of the polygon. A geodesic segment is the shortest path between two points on an ellipsoid. Thus, if you have a line that spans the width of the world, with only two vertices, each on the edges of the map, the geodesic lenght would be zero (shortest distance between the two vertices).
 
 Will return NAN if the calculation
 results in a linear to angular conversion (for instance, Decimal Degrees to Meters)
 @param geometry The geometry to calculate the geodesic length for.
 @param lengthUnit The unit at which the area is calculated.
 @return The calculated geodesic length in the specified unit.
 @since 1.8
 @see shapePreservingLengthOfGeometry:inUnit:

 */
-(double)geodesicLengthOfGeometry:(AGSGeometry*)geometry inUnit:(AGSSRUnit)lengthUnit;

/** Calculates the length of the geometry on the surface of the Earth ellipsoid. This method preserves the shape of the geometry in its coordinate system. This means the true length will be calculated for the geometry you see in the map. Thus, if you have a line that spans the width of the world, with only two vertices, each on edges of the map, the length returned would be comparable to the distance on earth.
 
 
 @param geometry whose length needs to be computed
 @param lengthUnit The unit in which length needs to be computed
 @return The length of the geometry
 @since 2.2
 */
-(double)shapePreservingLengthOfGeometry:(AGSGeometry*)geometry inUnit:(AGSSRUnit)lengthUnit;

/** Simplifies the given geometry to make it topologically consistent according
 to their geometry type. For instance, it rectifies polygons that may be
 self-intersecting, or contain incorrect ring orientations.
 @param geometry The geometry to be simplified.
 @return The simplified geometry.
 @since 1.8
 */
-(AGSGeometry*)simplifyGeometry:(AGSGeometry*)geometry;

/** Splits the input polyline or polygon where it crosses a cutting polyline.
 @param geometry The geometry to be cut. 
 @param cutter The polyline that will be used to divide the target 
 into pieces where it crosses the target.
 @return Array of cut results.
 @since 1.8
 */
-(NSArray*)cutGeometry:(AGSGeometry*)geometry withCutter:(AGSPolyline*)cutter;

/** Creates a buffer polygon at the specified distance around the given geometry.
 @param geometry Specifies the input geometry.
 @param distance The distance in the unit of the geometry's spatial reference for which
 to buffer the geometry.
 @return The polygon that represents the buffered area.
 @since 1.8
 @see  [AGSSpatialReference convertValue:fromUnit:] and  [AGSSpatialReference convertValue:toUnit:] to convert values between different units
 */
-(AGSMutablePolygon*)bufferGeometry:(AGSGeometry*)geometry byDistance:(double)distance;

/** Creates buffers at the specified distance around the given geometries. Will
 union the results of all buffers.
 @param geometries Specifies the input geometries.
 @param distance The distance in the unit of the geometry's spatial reference for which
 to buffer the geometries.
 @return The polygon that represents the buffered area.
 @since 1.8
 @see  [AGSSpatialReference convertValue:fromUnit:] and  [AGSSpatialReference convertValue:toUnit:] to convert values between different units
 */
-(AGSMutablePolygon*)bufferGeometries:(NSArray*)geometries byDistance:(double)distance;

/** The union operation constructs the set-theoretic union of the geometries
 in the input array.
 @param geometries The array of geometries to be unioned.
 @return The union of all the input geometries.
 @since 1.8
 */
-(AGSGeometry*)unionGeometries:(NSArray*)geometries;

/** Densifies the input geometry by plotting points between existing vertices.
 @param geometry The input geometry
 @param maxSegmentLength The maximum distance between points after densification. This
 distance should be in the same unit as the geometry's spatial reference.
 @return The densified geometry.
 @since 1.8
 */
-(AGSGeometry*)densifyGeometry:(AGSGeometry*)geometry withMaxSegmentLength:(double)maxSegmentLength;

/** Generalizes the input geometry by removing vertices based on the Douglas-Poiker algorithm.
 @param geometry The input geometry
 @param maxDeviation the maximum distance that the generalized geometry can deviate from the original one, specified in the units of the input geometry's spatial reference
 @param removeDegenerateParts If YES, degenerate parts of the generalized geometry that are undesired for drawing will be removed.
 @since 10.2.3
 */
-(AGSGeometry*)generalizeGeometry:(AGSGeometry*)geometry withMaxDeviation:(double)maxDeviation removeDegenerateParts:(BOOL)removeDegenerateParts;

/** Densifies the input geometry by plotting points between existing vertices.
 @param geometry The input geometry
 @param maxSegmentLength The maximum distance between points after densification.
 @param lengthUnit The unit that the max segment length parameter is in.
 @return The geodesically densified geometry.
 @since 1.8
 */
-(AGSGeometry*)geodesicDensifyGeometry:(AGSGeometry*)geometry withMaxSegmentLength:(double)maxSegmentLength inUnit:(AGSSRUnit)lengthUnit;

/** Constructs the set-theoretic intersection between two geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry of dimension equal 
 to or greater than the elements of the first geometry.
 @return A geometry that represents the intersection of the two input geometries.
 @since 1.8
 */
-(AGSGeometry*)intersectionOfGeometry:(AGSGeometry*)geometry1 andGeometry:(AGSGeometry*)geometry2;

/** Constructs the polygon created by clipping geometry by envelope.
 @param geometry The geometry to be clipped by the given envelope.
 @param envelope The envelope in which to use in order to clip geometry.
 @return A geometry that represents the area clipped by envelope.
 @since 2.2
 */
-(AGSGeometry*)clipGeometry:(AGSGeometry*)geometry withEnvelope:(AGSEnvelope*)envelope;

/** Constructs the set-theoretic difference between two geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry of dimension equal 
 to or greater than the elements of the first geometry.
 @return A geometry that represents the difference of the two input geometries.
 @since 1.8
 */
-(AGSGeometry*)differenceOfGeometry:(AGSGeometry*)geometry1 andGeometry:(AGSGeometry*)geometry2;

/**
 @since 2.2
 */
-(AGSGeometry*)symmetricDifferenceOfGeometry:(AGSGeometry*)geometry1 andGeometry:(AGSGeometry*)geometry2;

/** Measures the simple planar distance between two geometries.
 @param geometry1 The first geometry.
 @param geometry2 The second geometry.
 @return The distance between the two input geometries in the same unit as the spatial reference of the
 input geometries.
 @since 1.8
 */
-(double)distanceFromGeometry:(AGSGeometry*)geometry1 toGeometry:(AGSGeometry*)geometry2;
 
/** Calculates an interior point for a specified polygon. This interior 
 point can be used by clients to place a label for the polygon.
 @param polygon The polygon to get label points for.
 @return The label point.
 @since 1.8
 */
-(AGSMutablePoint*)labelPointForPolygon:(AGSPolygon*)polygon;

/**
 *Creates offset version of the input geometries.
 
 The offset operation creates a geometry that is a constant distance from an input polyline or polygon.
 It is similar to buffering, but produces a one sided result. If offsetDistance > 0, then the offset
 geometry is constructed to the right of the oriented input geometry, otherwise it is constructed to
 the left. For a simple polygon, the orientation of outer rings is clockwise and for inner rings it is counter
 clockwise. So the “right side” of a simple polygon is always its inside.
 The bevelRatio is multiplied by the offset distance and the result determines how far a mitered
 offset intersection can be from the input curve before it is beveled.
 
 @param geometry The geometry to calculate offset for. Point and MultiPoint are not supported.
 @param distance The offset distance for the Geometries.
 @param joinType The join type of the offset geometry.
 @param bevelRatio The ratio used to produce a bevel join instead of a miter join (used only when joins is Miter)
 @param flattenError The maximum distance of the resulting segments compared to the true circular arc (used only when joins is Round).
 If flattenError is 0, tolerance value is used. Also, the algorithm never produces more than around 180 vetices for each round join.
 @return Returns the result of the offset operation.
 @since 1.8
 */

-(AGSGeometry*)offsetGeometry:(AGSGeometry*)geometry byDistance:(double)distance withJointType:(AGSGeometryOffsetType)joinType bevelRatio:(double)bevelRatio flattenError:(double)flattenError;

/** Returns YES if geometry1 intersects geometry2.
 @since 1.8
 */
-(BOOL)geometry:(AGSGeometry*)geometry1 intersectsGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 crosses geometry2.
 @since 1.8
 */
-(BOOL)geometry:(AGSGeometry*)geometry1 crossesGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 is within geometry2.
 @since 1.8
 */
-(BOOL)geometry:(AGSGeometry*)geometry1 withinGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 is disjoint to geometry2.
 @since 1.8
 */
-(BOOL)geometry:(AGSGeometry*)geometry1 disjointToGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 touches geometry2.
 @since 1.8
 */
-(BOOL)geometry:(AGSGeometry*)geometry1 touchesGeometry:(AGSGeometry*)geometry2;

/** Returns YES if geometry1 contains geometry2.
 @since 1.8
 */
-(BOOL)geometry:(AGSGeometry*)geometry1 containsGeometry:(AGSGeometry*)geometry2;

/** Performs relational operation Overlaps. It compares two geometries of the same dimension
 and returns TRUE if their intersection results in a geometry different from both but of the same dimension.
 @since 2.2
 */
-(BOOL)geometry:(AGSGeometry*)geometry1 overlapsGeometry:(AGSGeometry*)geometry2;

/** Finds the nearest vertex in a specified geometry to a specified point.
 @param geometry The geometry in which the nearest vertex to a specified point is to be found.
 @param point The point which to find the nearest vertex to.
 @return The proximity result.
 @since 1.8
 */
-(AGSProximityResult*)nearestVertexInGeometry:(AGSGeometry*)geometry toPoint:(AGSPoint*)point;

/** Finds the nearest coordinate in a specified geometry to a specified point.
 @param geometry The geometry in which the nearest coordinate to a specified point is to be found.
 @param point The point which to find the nearest coordinate to.
 @return The proximity result.
 @since 1.8
 */
-(AGSProximityResult*)nearestCoordinateInGeometry:(AGSGeometry*)geometry toPoint:(AGSPoint*)point;

/** Folds the geometry into a range of 360 degrees. This may be necessary when wrap around 
 is enabled on the map.
 @param geometry The geometry that you want folded.
 @return The folded geometry
 @since 1.8
 */
-(AGSGeometry*)normalizeCentralMeridianOfGeometry:(AGSGeometry*)geometry;

/** A singleton geometry engine that can be used. Since an instance of a geometry engine
 caches state, like the last projection transformation used, it may be
 beneficial to create one for each spatial reference that you are dealing with, instead of
 using this.
 @return A new, autoreleased geometry engine.
 @since 1.8
 */
+(AGSGeometryEngine*)defaultGeometryEngine;

#pragma mark -
#pragma mark Coordinate Conversions

/** Returns a point for a given MGRS coordinate string
 @param mgrs The MGRS coordinate string. Can contain spaces.
 @return A point from the MGRS coordinate. The point will be output in EPSG:4326.
 @since 2.2
 @deprecated Deprecated at 10.2. Use  [AGSPoint pointFromMGRSString:withSpatialReference:] instead.
 */
-(AGSPoint*)pointFromMGRS:(NSString*)mgrs __attribute__((deprecated));

#pragma mark -

/** Returns a Military Grid Reference System (MGRS) coordinate for the given point. For example : 4Q 612341 2356781
 @param pt The point for which MGRS coordinate is needed
 @param numDigits The number of digits to be included in the MGRS coordinate
 @param rounding Whether the numeric value should be rounded
 @param addSpaces Whether the MGRS coordinate string should include spaces
 @return The MGRS coordinate string
 @since 2.2
 @deprecated Deprecated at 10.2. Use  [AGSPoint MGRSStringWithNumDigits:rounding:addSpaces:] instead.
 */
-(NSString*)mgrsFromPoint:(AGSPoint*)pt numDigits:(NSInteger)numDigits rounding:(BOOL)rounding addSpaces:(BOOL)addSpaces __attribute__((deprecated));

#pragma mark - convex hull

/** Returns the minimum bounding geometry that completely encloses the given geometry.
 @param geometry for which convex hull needs to be calculated. Typically either an  AGSMultipoint,  AGSPolygon, or  AGSPolyline.
 @return minimum bounding geometry
 @since 10.2
 */
-(AGSGeometry*)convexHullForGeometry:(AGSGeometry*)geometry;

#pragma mark -
#pragma mark geodesic utility functions

/** Gets an array of AGSPoint objects that have been moved by geodetic calculation. Each point in the array is moved by the given distance and azimuth.
 @param points An array of points to be moved.
 @param degrees The angle for the points to be moved along (in degrees).
 @param distance The distance by which the points are moved.
 @param unit The linear units of the distance. The default is AGSSRUnitMeter.
 @return An array of points moved along a geodesic curve by distance and azimuth.
 @since 10.2
 */
-(NSArray*)geodesicMovePoints:(NSArray*)points byDistance:(double)distance inUnit:(AGSSRUnit)unit azimuth:(double)degrees;

/** Returns the geodesic distance between 2 given points and calculates the azimuth at both points for the geodesic curves that connects the points.
 @param point1 The first point
 @param point2 The second point
 @param unit The linear units of the distance returned in the AGSGeodesicDistanceResult object
 @return The AGSGeodesicDistanceResult object containing the shortest distance between the 2 points along the geodesic curve, and the azimuth at both those points.
 @since 10.2
 */
-(AGSGeodesicDistanceResult*)geodesicDistanceBetweenPoint1:(AGSPoint*)point1 point2:(AGSPoint*)point2 inUnit:(AGSSRUnit)unit;

/** Constructs a geodesic ellipse that is centered on a specified point and defined by it's 2 axes and the direction of it's longest axis. The ellipse is provided as a AGSPolygon, AGSPolyline or AGSMultipoint geometry.
 @param params Specifies the parameters for constructing the ellipse.
 @return The ellipse is returned in the format specified by the geometryType parameter. The ellipse is generalized according to the vertexCount.
 @since 10.2
 */
-(AGSGeometry*)geodesicEllipseWithParameters:(AGSGeodesicEllipseParameters*)params;

/** Constructs a geodesic sector defined by a geodesic arc and 2 radii. The arc is a portion of an ellipse that is centered on a specified point and is defined by it's 2 axes and the length of it's longest axis. The first radius angle is defined by the startDirection angle and the second radius angle is the sum of the startDirection and the sectorAngle. The sector is constructed as a AGSPolygon, AGSPolyline or AGSMultipoint geometry.
 @param params Specifies the parameters for constructing the sector.
 @return The sector is returned in the format specified by the geometryType and is generalized according to the arcVertexCount and the radiusVertexCount parameters.
 @since 10.2
 */
-(AGSGeometry*)geodesicSectorWithParameters:(AGSGeodesicSectorParameters*)params;

/** Determines if @p geometry1 is related to @p geometry2 by the @p relation specified.
 Example: To test if a polygon 'P' contains a point 'pt' you would pass the following:
 <code>-[AGSGeometryEngine geometry:P relatesToGeometry:pt byRelation:@"T*****FF*"]</code>.
 This checks:
    1. The interiors of both geometries intersect.
    2. The exterior of P does not intersect the interior of pt
    3. The exterior of P does not intersect the boundary of pt.
 
 @param geometry1 The input geometry to be compared.
 @param geometry2 The input geometry in which we are comparing @p geometry1 against.
 @param relation The DE-9IM string to be evaluated. Strings such as <code>"T*****FF*"</code> are accepted.
 @return A boolean indicating if the relation is <code>True</code> or <code>False</code>.
 @since 10.2
 */
-(BOOL)geometry:(AGSGeometry*)geometry1 relatesToGeometry:(AGSGeometry*)geometry2 byRelation:(NSString*)relation;
@end