/*
 COPYRIGHT 2012 ESRI
 
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

/** @file AGSRelationParameters.h */ //Required for Globals API doc

/**  Parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>relationWithParameters:</code> operation.
 
 Instances of this class represent parameters for <code>AGSGeometryServiceTask</code>'s 
 <code>relationWithParameters:</code> operation.
 
 
 @see AGSGeometryServiceTask
 */
@interface AGSRelationParameters : NSObject <AGSCoding>

/** The first array of geometries to compute the relations. All geometries in 
 this array should be of the type defined by @p geometryType.
 @since 1.0
 */
@property (nonatomic, copy) NSArray *geometries1;

/** The second array of geometries to compute the relations. All geometries in 
 this  array should be of the type defined by @p geometryType.
 @since 1.0
 */
@property (nonatomic, copy) NSArray *geometries2;

/** The spatial relationship to be tested between the two input geometry arrays. Note that
 if the relation is specified as  AGSGeometryRelationRelation, the relationParam 
 parameter describes the spatial relationship and must be specified.
 
 Possible values include
 @li  AGSGeometryRelationCross  
 @li  AGSGeometryRelationDisjoint
 @li  AGSGeometryRelationIn
 @li  AGSGeometryRelationInteriorIntersection
 @li  AGSGeometryRelationIntersection
 @li  AGSGeometryRelationLineCoincidence
 @li  AGSGeometryRelationLineTouch
 @li  AGSGeometryRelationOverlap
 @li  AGSGeometryRelationPointTouch
 @li  AGSGeometryRelationTouch
 @li  AGSGeometryRelationWithin
 @li  AGSGeometryRelationRelation
 @since 1.0
 */
@property (nonatomic, assign) AGSGeometryRelation relation;

/** The 'Shape Comparison Language' string to be evaluated. Strings such as 
 <code>RELATE (G1, G2, "FFFTTT***")</code> are accepted, in addition to other 
 kinds of strings. The string describes the spatial relationship
 to be tested when the relation parameter is specified as  AGSGeometryRelationRelation.
 @since 1.0
 @see [AGSQuery relationParam] for more information.
 */
@property (nonatomic, copy) NSString *relationParam;

/** Returns an autoreleased instance of the relation parameters object.
 @since 1.0
 */
+ (id)relationParameters;

@end