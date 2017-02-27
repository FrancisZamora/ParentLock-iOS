/*
 COPYRIGHT 2011 ESRI
 
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

/** @file AGSEnumerations.h */ 

/**
 Specifies the wrap around status of an AGSMapView.
 If Uninitialized, you need to call  [AGSMapView enableWrapAround]
 if Unsupported,  the basemap layer is either not in WGS84 or WebMercator spatial reference, or because it does not cover the entire world.
 @since 10.1.1
 */
typedef NS_ENUM(NSInteger, AGSMapViewWrapAroundStatus) {
    AGSMapViewWrapAroundStatusDisabled,             /*!< Disabled */
    AGSMapViewWrapAroundStatusUninitialized,        /*!< Uninitalized  */
    AGSMapViewWrapAroundStatusUnsupported,          /*!< Unsupported */
    AGSMapViewWrapAroundStatusEnabled               /*!< Enabled */
} ;

/** Specifies how a text symbol should be vertically aligned.
 @since 1.8
 */
typedef NS_ENUM(NSInteger, AGSTextSymbolVAlignment) {
	AGSTextSymbolVAlignmentBottom = 0,		/*!< Bottom */
	AGSTextSymbolVAlignmentMiddle,			/*!< Middle */
	AGSTextSymbolVAlignmentTop,				/*!< Top */
} ;

/** Specifies how a text symbol should be horizontally aligned.
 @since 1.8
 */
typedef NS_ENUM(NSInteger, AGSTextSymbolHAlignment) {
	AGSTextSymbolHAlignmentLeft = 0,		/*!< Left  */
	AGSTextSymbolHAlignmentCenter,			/*!< Center */
	AGSTextSymbolHAlignmentRight			/*!< Right */
} ;


/** Supported marker styles.
 @since 1.0
 */
typedef NS_ENUM(NSInteger, AGSSimpleMarkerSymbolStyle) {
    AGSSimpleMarkerSymbolStyleCircle = 0,	/*!< Circle */
    AGSSimpleMarkerSymbolStyleCross,		/*!< Cross */
    AGSSimpleMarkerSymbolStyleDiamond,		/*!< Diamond */
    AGSSimpleMarkerSymbolStyleSquare,		/*!< Square */
    AGSSimpleMarkerSymbolStyleX,			/*!< X*/
    AGSSimpleMarkerSymbolStyleTriangle		/*!< Triange */
} ;

/** Supported interpolations.
 @since 1.8
 */
typedef NS_ENUM(NSUInteger, AGSInterpolation) {
	AGSInterpolationBilinear = 0,                       /*!< Bilinear */
	AGSInterpolationCubicConvolution,                   /*!< Convolution */
	AGSInterpolationMajority,                           /*!< Majority */
	AGSInterpolationNearestNeighbor = NSUIntegerMax		/*!< Nearest Neighbor */
} ;

/** Return interpolation string for  AGSInterpolation.
 @param interpolation The interpolation.
 @return String representation of @p interpolation.
 @since 10.2.4
 @see AGSInterpolation
 */
AGS_EXTERN NSString *AGSInterpolationAsString(AGSInterpolation interpolation);

/** Return  AGSInterpolation from interpolation.
 @param interpolation The interpolation.
 @return  AGSInterpolation for @p interpolation.
 @since 10.2.4
 @see AGSInterpolation
 */
AGS_EXTERN AGSInterpolation AGSInterpolationFromString(NSString *interpolation);

/** Supported no data interpretations.  These are the interpretations of the
  AGSImageServiceLayer noData property.
 @since 10.2.4
 */
typedef NS_ENUM(NSUInteger, AGSNoDataInterpretation) {
	AGSNoDataInterpretationMatchAny = 0,              /*!< Match any band */
	AGSNoDataInterpretationMatchAll                   /*!< Match all bands */
} ;

/** Return interpretation string for  AGSNoDataInterpretation.
 @param interpretation The interpretation.
 @return String representation of @p interpretation.
 @since 10.2.4
 @see AGSNoDataInterpretation
 */
AGS_EXTERN NSString *AGSNoDataInterpretationAsString(AGSNoDataInterpretation interpretation);

/** Return  AGSNoDataInterpretation from interpretation.
 @param interpretation The interpretation.
 @return  AGSNoDataInterpretation for @p interpretation.
 @since 10.2.4
 @see AGSNoDataInterpretation
 */
AGS_EXTERN AGSNoDataInterpretation AGSNoDataInterpretationFromString(NSString *interpretation);

/** Possible relationships between geometries.
 @since 1.0
 */
typedef NS_ENUM(NSUInteger, AGSGeometryRelation) {
    AGSGeometryRelationCross = 0,				/*!< Cross */
    AGSGeometryRelationDisjoint,				/*!< Disjoint */
    AGSGeometryRelationIn,						/*!< In */
    AGSGeometryRelationInteriorIntersection,	/*!< Interior Intersection */
    AGSGeometryRelationIntersection,			/*!< Intersection */
    AGSGeometryRelationLineCoincidence,			/*!< Line Coincidence */
    AGSGeometryRelationLineTouch,				/*!< Line Touch */
    AGSGeometryRelationOverlap,					/*!< Overlap */
    AGSGeometryRelationPointTouch,				/*!< Point Touch */
    AGSGeometryRelationTouch,					/*!< Touch */
    AGSGeometryRelationWithin,					/*!< Within */
    AGSGeometryRelationRelation					/*!< Relation */
} ;

/** Supported geometry types.
 @since 1.0
 */
typedef NS_ENUM(NSInteger, AGSGeometryType)  {
    AGSGeometryTypeUndefined = -1,  /*!< Undefined */
    AGSGeometryTypePoint,           /*!< Point */
    AGSGeometryTypePolyline,        /*!< Polyline */
    AGSGeometryTypePolygon,         /*!< Polygon */
    AGSGeometryTypeMultipoint,      /*!< Multipoint */
    AGSGeometryTypeEnvelope         /*!< Envelope */
} ;

/** Supported raster function types. These types correspond to the names of
 raster functions.
 @since 1.8
 */
typedef NS_ENUM(NSInteger, AGSRasterFunctionType) {
	AGSRasterFunctionTypeAspect = 0,            /*!< Aspect */
	AGSRasterFunctionTypeColormap,              /*!< Colormap */
	AGSRasterFunctionTypeHillshade,             /*!< Hillshade */
	AGSRasterFunctionTypeNDVI,                  /*!< NDVI */
	AGSRasterFunctionTypeShadedRelief,          /*!< Shaded Relief */
	AGSRasterFunctionTypeSlope,                 /*!< Slope */
	AGSRasterFunctionTypeStatistics,            /*!< Statistics */
	AGSRasterFunctionTypeStretch,               /*!< Stretch */
	AGSRasterFunctionTypeBandArithmetic,        /*!< BandArithmetic - added at 10.1 */
	AGSRasterFunctionTypeClip,                  /*!< Clip - added at 10.1 */
	AGSRasterFunctionTypeConvolution,           /*!< Convolution - added at 10.1 */
	AGSRasterFunctionTypeGeometric,             /*!< Geometric - added at 10.1 */
	AGSRasterFunctionTypeRemap,                 /*!< Remap - added at 10.1 */
	AGSRasterFunctionTypeMask,                  /*!< Mask - added at 10.2.1 */
	AGSRasterFunctionTypeArithmetic,			/*!< Arithmetic - added at 10.2.1 */
	AGSRasterFunctionTypeContrastBrightness,    /*!< ContrastBrightness - added at 10.2.1 */
	AGSRasterFunctionTypeExtractBand,			/*!< ExtractBand - added at 10.2.1 */
	AGSRasterFunctionTypeCompositeBand,			/*!< CompositeBand - added at 10.2.1 */
	AGSRasterFunctionTypeMLClassify,			/*!< MLClassify - added at 10.2.1 */
	AGSRasterFunctionTypeLocal,                 /*!< Local - added at 10.2.1 */
	AGSRasterFunctionTypeThreshold,             /*!< Threshold - added at 10.2.1 */
} ;

/** List of supported <code>%AGSFieldType</code>'s
 @since 1.0
 */
typedef NS_ENUM(NSInteger, AGSFieldType) {
    AGSFieldTypeInteger = 0,        /*!< Integer */
    AGSFieldTypeSmallInteger,       /*!< Small Integer */
	AGSFieldTypeDouble,             /*!< Double */
	AGSFieldTypeSingle,             /*!< Single */
	AGSFieldTypeString,             /*!< String */
	AGSFieldTypeDate,               /*!< Date */
	AGSFieldTypeGeometry,           /*!< Geometry */
	AGSFieldTypeOID,                /*!< OID */
	AGSFieldTypeBlob,               /*!< Blob */
	AGSFieldTypeGlobalID,           /*!< Global ID */
	AGSFieldTypeRaster,             /*!< Raster */
	AGSFieldTypeGUID,               /*!< GUID */
	AGSFieldTypeXML                 /*!< XML */
} ;


/** Supported time interval units.
 @since 1.0
 */
typedef NS_ENUM(NSInteger, AGSTimeIntervalUnits) {
    AGSTimeIntervalUnitsMilliseconds = 0,	/*!< Milliseconds */
    AGSTimeIntervalUnitsSeconds,            /*!< Seconds */
    AGSTimeIntervalUnitsMinutes,            /*!< Minutes */
    AGSTimeIntervalUnitsHours,              /*!< Hours */
    AGSTimeIntervalUnitsDays,               /*!< Days */
    AGSTimeIntervalUnitsWeeks,              /*!< Weeks */
    AGSTimeIntervalUnitsMonths,             /*!< Months */
    AGSTimeIntervalUnitsYears,              /*!< Years */
    AGSTimeIntervalUnitsDecades,            /*!< Decades*/
    AGSTimeIntervalUnitsCenturies,          /*!< Centuries */
    AGSTimeIntervalUnitsUnknown             /*!< Unknown */	
} ;

/** Return time interval units string for  AGSTimeIntervalUnits.
 @param unit The time interval units.
 @return String representation of @p unit.
 @since 10.2.4
 @see AGSTimeIntervalUnits
 */
AGS_EXTERN NSString *AGSTimeIntervalUnitsAsString(AGSTimeIntervalUnits unit);

/** Return  AGSTimeIntervalUnits from @p unit.
 @param unit The time interval units.
 @return  AGSTimeIntervalUnits for @p unit.
 @since 10.2.4
 @see AGSTimeIntervalUnits
 */
AGS_EXTERN AGSTimeIntervalUnits AGSTimeIntervalUnitsFromString(NSString *unit);

/** Possible spatial relationships.
 @since 1.8
 */
typedef NS_ENUM(NSUInteger, AGSSpatialRelationship) {
    AGSSpatialRelationshipIntersects = 0,		/*!< Intersects */
    AGSSpatialRelationshipContains,				/*!< Contains */
    AGSSpatialRelationshipCrosses,				/*!< Crosses */
    AGSSpatialRelationshipEnvelopeIntersects,	/*!< Envelope Intersects */
    AGSSpatialRelationshipIndexIntersects,		/*!< Index Intersects */
    AGSSpatialRelationshipOverlaps,				/*!< Overlaps */
    AGSSpatialRelationshipTouches,				/*!< Touches */
    AGSSpatialRelationshipWithin,				/*!< Within */
	AGSSpatialRelationshipRelation				/*!< Relation */
} ;

/** Supported linear units.
 @since 1.0
 */
typedef NS_ENUM(NSUInteger, AGSUnits) {
    AGSUnitsCentimeters = 0,	/*!< Centimenters */
    AGSUnitsDecimalDegrees,		/*!< Decimal Degrees */
    AGSUnitsDecimeters,			/*!< Decimeters */
    AGSUnitsFeet,				/*!< Feet */
    AGSUnitsInches,				/*!< Inches */
    AGSUnitsKilometers,			/*!< Kilometers */
    AGSUnitsMeters,				/*!< Meters */
    AGSUnitsMiles,				/*!< Miles */
    AGSUnitsMillimeters,		/*!< Millimeters */
    AGSUnitsNauticalMiles,		/*!< Nautical miles */
    AGSUnitsPoints,				/*!< Points */
    AGSUnitsUnknown,			/*!< Unknown */
    AGSUnitsYards				/*!< Yards */
} ;

/** Supported area units.
 @since 1.0
 */
typedef NS_ENUM(NSUInteger, AGSAreaUnits) {
    AGSAreaUnitsSquareInches = 0,		/*!< Sq Inches */
    AGSAreaUnitsSquareFeet,				/*!< Sq Feet */
    AGSAreaUnitsSquareYards,			/*!< Sq Yards */
    AGSAreaUnitsAcres,					/*!< Acres */
    AGSAreaUnitsSquareMiles,			/*!< Sq Miles */
    AGSAreaUnitsSquareMillimeters,		/*!< Sq Millimeters */
    AGSAreaUnitsSquareCentimeters,		/*!< Sq Centimeters */
    AGSAreaUnitsSquareDecimeters,		/*!< Sq Decimeters */
    AGSAreaUnitsSquareMeters,			/*!< Sq Meters */
    AGSAreaUnitsAres,					/*!< Sq Ares */
    AGSAreaUnitsHectares,				/*!< Sq Hectares */
    AGSAreaUnitsSquareKilometers		/*!< Sq Kilometers */
} ;

/** Supported esriSRUnits.
 @since 1.0
 */
typedef NS_ENUM(NSUInteger, AGSSRUnit) {
    AGSSRUnitMeter					= 9001,     /*!< International meter. */
    AGSSRUnitGermanMeter			= 9031,     /*!< German legal meter. */
    AGSSRUnitFoot					= 9002,     /*!< International foot. */
    AGSSRUnitSurveyFoot				= 9003,     /*!< US survey foot. */
    AGSSRUnitClarkeFoot				= 9005,     /*!< Clarke's foot. */
    AGSSRUnitFathom					= 9014,     /*!< Fathom. */
    AGSSRUnitNauticalMile			= 9030,     /*!< International nautical mile. */
    AGSSRUnitSurveyChain			= 9033,     /*!< US survey chain. */
    AGSSRUnitSurveyLink				= 9034,     /*!< US survey link. */
    AGSSRUnitSurveyMile				= 9035,     /*!< US survey mile. */
    AGSSRUnitKilometer				= 9036,     /*!< Kilometer. */
    AGSSRUnitClarkeYard				= 9037,     /*!< Yard (Clarke's ratio). */
    AGSSRUnitClarkeChain			= 9038,     /*!< Chain (Clarke's ratio). */
    AGSSRUnitClarkeLink				= 9039,     /*!< Link (Clarke's ratio). */
    AGSSRUnitSearsYard				= 9040,     /*!< Yard (Sears). */
    AGSSRUnitSearsFoot				= 9041,     /*!< Sears' foot. */
    AGSSRUnitSearsChain				= 9042,     /*!< Chain (Sears). */
    AGSSRUnitSearsLink				= 9043,     /*!< Link (Sears). */
    AGSSRUnitBenoit1895AYard		= 9050,     /*!< Yard (Benoit 1895 A). */
    AGSSRUnitBenoit1895AFoot		= 9051,     /*!< Foot (Benoit 1895 A). */
    AGSSRUnitBenoit1895AChain		= 9052,     /*!< Chain (Benoit 1895 A). */
    AGSSRUnitBenoit1895ALink		= 9053,     /*!< Link (Benoit 1895 A). */
    AGSSRUnitBenoit1895BYard		= 9060,     /*!< Yard (Benoit 1895 B). */
    AGSSRUnitBenoit1895BFoot		= 9061,     /*!< Foot (Benoit 1895 B). */
    AGSSRUnitBenoit1895BChain		= 9062,     /*!< Chain (Benoit 1895 B). */
    AGSSRUnitBenoit1895BLink		= 9063,     /*!< Link (Benoit 1895 B). */
    AGSSRUnitIndianFoot				= 9080,     /*!< Indian geodetic foot. */
    AGSSRUnitIndian1937Foot			= 9081,     /*!< Indian foot (1937). */
    AGSSRUnitIndian1962Foot			= 9082,     /*!< Indian foot (1962). */
    AGSSRUnitIndian1975Foot			= 9083,     /*!< Indian foot (1975). */
    AGSSRUnitIndianYard				= 9084,     /*!< Indian yard. */
    AGSSRUnitIndian1937Yard			= 9085,     /*!< Indian yard (1937). */
    AGSSRUnitIndian1962Yard			= 9086,     /*!< Indian yard (1962). */
    AGSSRUnitIndian1975Yard			= 9087,     /*!< Indian yard (1975). */
    AGSSRUnitFoot1865				= 9070,     /*!< Foot (1865). */
    AGSSRUnitRadian					= 9101,     /*!< Radian. */
    AGSSRUnitDegree					= 9102,     /*!< Degree. */
    AGSSRUnitArcMinute				= 9103,     /*!< Arc-minute. */
    AGSSRUnitArcSecond				= 9104,     /*!< Arc-second. */
    AGSSRUnitGrad					= 9105,     /*!< Grad. */
    AGSSRUnitGon					= 9106,     /*!< Gon. */
    AGSSRUnitMicroradian			= 9109,     /*!< Microradian. */
    AGSSRUnitArcMinuteCentesimal	= 9112,     /*!< Centesimal arc-minute. */
    AGSSRUnitArcSecondCentesimal	= 9113,     /*!< Centesimal arc-second. */
    AGSSRUnitMil6400				= 9114,     /*!< Mil. */
    AGSSRUnitBritish1936Foot		= 9095,		/*!< British Foot (1936). */
    AGSSRUnitGoldCoastFoot			= 9094,		/*!< Gold Coast Foot. */
    AGSSRUnitInternationalChain		= 109003,	/*!< International Chain. */
    AGSSRUnitInternationalLink		= 109004,	/*!< International Link. */
    AGSSRUnitInternationalYard		= 109001,	/*!< International Yard. */
    AGSSRUnitStatuteMile			= 9093,		/*!< Statute Mile. */
    AGSSRUnitSurveyYard				= 109002,	/*!< US survey Yard. */
    AGSSRUnit50KilometerLength		= 109030,	/*!< 50 Kilometer Length. */
    AGSSRUnit150KilometerLength		= 109031,	/*!< 150 Kilometer Length. */
    AGSSRUnitDecimeter				= 109005,	/*!< Decimeter. */
    AGSSRUnitCentimeter				= 109006,	/*!< Centimeter. */
    AGSSRUnitMillimeter				= 109007,	/*!< Millimeter. */
    AGSSRUnitInternationalInch		= 109008,	/*!< International inch. */
    AGSSRUnitUSsurveyInch			= 109009,	/*!< US survey inch. */
    AGSSRUnitInternationalRod		= 109010,	/*!< International rod. */
    AGSSRUnitUSsurveyRod			= 109011,	/*!< US survey rod. */
    AGSSRUnitUSNauticalMile			= 109012,	/*!< US nautical mile (pre-1954). */
    AGSSRUnitUKNauticalMile			= 109013	/*!< UK nautical mile (pre-1970). */
} ;

/** Supported @p offsetHow types.
 Square only applicable with the AGSGeometryEngine
 @since 1.0
 */
typedef NS_ENUM(NSInteger, AGSGeometryOffsetType) {
	AGSGeometryOffsetTypeMitered = 0,   /*!< Mietered */
	AGSGeometryOffsetTypeBevelled,      /*!< Bevelled  */
	AGSGeometryOffsetTypeRounded,       /*!< Rounded */
	AGSGeometryOffsetTypeSquare         /**  Square  */
} ;


/** Specifies the way of timeOfDay property is used.
 @since 2.3
 @note This feature is only available for ArcGIS services v10.1 or greater.
 */
typedef NS_ENUM(NSInteger, AGSNATimeOfDayUse) {
    AGSNATimeOfDayUseAsStartTime = 0, /*!<  Use as the start time.*/
    AGSNATimeOfDayUseAsEndTime        /*!<  Use as the end time.*/
} ;

/** Defines content, verbosity of returned directions.
 @since 2.3
 @note This feature is only available for ArcGIS services v10.1 or greater.
 */
typedef NS_ENUM(NSInteger, AGSNADirectionsOutputType) {
    AGSNADirectionsOutputTypeStandard = 0,		/*!< Standard directions output ﾖ direction text instructions, geometry, time, length, ETA. Does not include events, new types*/
	AGSNADirectionsOutputTypeComplete,      	/*!< Directions output that includes all directions properties.*/
    AGSNADirectionsOutputTypeCompleteNoEvents,  /*!< Directions output that includes all directions properties except events.*/
    AGSNADirectionsOutputTypeInstructionsOnly,  /*!< Directions output that includes text instructions, time, length and ETA. Does not include geometry.*/
    AGSNADirectionsOutputTypeSummaryOnly        /*!< Directions output that contains only summary (time and length). Detailed text instructions and geometry are not provided.*/
} ;

/** Specifies the type of lines generated by the network analyst solvers.
 
 Note: <code>AGSNAOutputLineTrueShapeWithMeasure</code> is only available at 10.1 and beyond.
 @since 1.8
 */
typedef NS_ENUM(NSUInteger, AGSNAOutputLine) {
	AGSNAOutputLineNone = 0,				/*!< No polylines are generated. */
	AGSNAOutputLineStraight,				/*!< Straight polylines between the two endpoints are generated. */
	AGSNAOutputLineTrueShape,				/*!< Polylines based on the true network feature geometry are generated. */
    AGSNAOutputLineTrueShapeWithMeasure     /*!< Polylines based on the true network feature geometry are generated, and measures are added whenever possible. */
} ;

/** Constants representing how U-Turns are handled
 @since 1.8
 */
typedef NS_ENUM(NSUInteger, AGSNAUTurn) {
	AGSNAUTurnAllowBacktrack = 0,			/*!<  Allow U-turns anywhere.*/
	AGSNAUTurnAtDeadEndsOnly,				/*!<  Allow U-turns only at dead ends only.*/
	AGSNAUTurnNoBacktrack,					/*!<  Don't allow U-turns anywhere.*/
	AGSNAUTurnAtDeadEndsAndIntersections,	/*!<  Allow U-turns at dead ends and intersections only. */
    AGSNAUTurnAtIntersectionsOnly,          /*!<  Allow U-turns at intersections only. */
} ;

/** Constants representing directions length units for the  AGSRouteTask.
 @since 1.8
 */
typedef NS_ENUM(NSUInteger, AGSNAUnit) {
	AGSNAUnitCentimeters = 0,	/*!< Centimeters */
	AGSNAUnitDays,				/*!< Days */
	AGSNAUnitDecimalDegrees,	/*!< Decimal Degrees */
	AGSNAUnitDecimeters,		/*!< Decimeters */
	AGSNAUnitFeet,				/*!< Feet */
	AGSNAUnitHours,				/*!< Hours */
	AGSNAUnitInches,			/*!< Inches */
	AGSNAUnitKilometers,		/*!< Kilometers */
	AGSNAUnitMeters,			/*!< Meters */
	AGSNAUnitMiles,				/*!< Miles */
	AGSNAUnitMillimeters,		/*!< Millimeters */
	AGSNAUnitMinutes,			/*!< Minutes */
	AGSNAUnitNauticalMiles,		/*!< Nautical Miles */
	AGSNAUnitPoints,			/*!< Points */
	AGSNAUnitSeconds,			/*!< Seconds */
	AGSNAUnitUnknown,			/*!< Unknown */
	AGSNAUnitYards,				/*!< Yards */
} ;

/** Constant representing the type of network layer.
 @since 1.8
 */
typedef NS_ENUM(NSInteger, AGSNALayerType) {
	AGSNALayerTypeRoute = 0,			/*!<  Route Layer. */
	AGSNALayerTypeServiceArea,			/*!<  Service Area Layer. */
	AGSNALayerTypeClosestFacility,		/*!<  Closest Facility Layer. */
} ;

/** Constants representing how the geometry is returned.
 @since 1.8
 */
typedef NS_ENUM(NSUInteger, AGSNATravelDirection) {
	AGSNATravelDirectionFromFacility = 0,	/*!< Tavel to the facility. */
	AGSNATravelDirectionToFacility,			/*!< Travel from the facility. */
} ;

/** Constants representing maneuver types for a direction.
 @since 1.8
 */
typedef NS_ENUM(NSInteger, AGSNADirectionsManeuver) {
	AGSNADirectionsManeuverUnknown = 0,		/*!< Unknown */
	AGSNADirectionsManeuverStop,			/*!< Arrive At Stop. */
	AGSNADirectionsManeuverStraight,		/*!< Go straight. */
	AGSNADirectionsManeuverBearLeft,		/*!< Bear left.*/
	AGSNADirectionsManeuverBearRight,		/*!< Bear righty. */
	AGSNADirectionsManeuverTurnLeft,		/*!< Turn left.*/
	AGSNADirectionsManeuverTurnRight,		/*!< Turn right. */
	AGSNADirectionsManeuverSharpLeft,		/*!< Make sharp left. */
	AGSNADirectionsManeuverSharpRight,		/*!< Make sharp right. */
	AGSNADirectionsManeuverUTurn,			/*!< Make a U-turn. */
	AGSNADirectionsManeuverFerry,			/*!< Take ferry. */
	AGSNADirectionsManeuverRoundabout,		/*!< Take roundabout. */
	AGSNADirectionsManeuverHighwayMerge,	/*!< Merge to highway. */
	AGSNADirectionsManeuverHighwayExit,		/*!< Exit highway. */
	AGSNADirectionsManeuverHighwayChange,	/*!< Go on another highway. */
    AGSNADirectionsManeuverForkCenter,		/*!< At fork keep center. */
	AGSNADirectionsManeuverForkLeft,		/*!< At fork keep left. */
	AGSNADirectionsManeuverForkRight,		/*!< At fork keep right. */
	AGSNADirectionsManeuverDepart,			/*!< Depart stop. */
	AGSNADirectionsManeuverTripItem,		/*!< Trip planning item. */
	AGSNADirectionsManeuverEndOfFerry,		/*!< End of ferry. */
    AGSNADirectionsManeuverRampRight,       /*!< Ramp right. */
    AGSNADirectionsManeuverRampLeft,        /*!< Ramp left. */
    AGSNADirectionsManeuverTurnLeftRight,	/*!< Turn left and immediately turn right. */
    AGSNADirectionsManeuverTurnRightLeft,	/*!< Turn right and immediately turn left. */
	AGSNADirectionsManeuverTurnRightRight,	/*!< Turn right and immediately turn right. */
    AGSNADirectionsManeuverTurnLeftLeft,	/*!< Turn left and immediately turn left. */
    AGSNADirectionsManeuverPedestrianRamp,  /*!< Pedestrian ramp. */
    AGSNADirectionsManeuverElevator,        /*!< Elevator. */
    AGSNADirectionsManeuverEscalator,       /*!< Escalator. */
    AGSNADirectionsManeuverStairs,          /*!< Stairs. */
    AGSNADirectionsManeuverDoorPassage,     /*!< Door passage. */
} ;

/** Types of direction strings. These are associated with the more detailed
 direction info passed back from a route solving operation.
 @since 2.3
 @note This feature is only available for ArcGIS services v10.1 or greater.
 */
typedef NS_ENUM(NSInteger, AGSNADirectionsStringType) {
    AGSNADirectionsStringGeneral = 0,           /*!< General directions string type.*/
    AGSNADirectionsStringDepart,                /*!< Depart directions string type.*/
    AGSNADirectionsStringArrive,                /*!< Arrive directions string type.*/
    AGSNADirectionsStringLength,                /*!< Length directions string type.*/
    AGSNADirectionsStringTime,                  /*!< Time directions string type.*/
    AGSNADirectionsStringSummary,               /*!< Time directions string type.*/
    AGSNADirectionsStringTimeWindow,            /*!< Time Window directions string type.*/
    AGSNADirectionsStringViolationTime,         /*!< Violation Time directions string type.*/
    AGSNADirectionsStringWaitTime,              /*!< Wait Time directions string type.*/
    AGSNADirectionsStringServiceTime,           /*!< Service Time directions string type.*/
    AGSNADirectionsStringEstimatedArrivalTime,  /*!< Estimated Arrival Time directions string type.*/
    AGSNADirectionsStringCumulativeLength,      /*!< Cumulative Length directions string type.*/
    AGSNADirectionsStringStreetName,            /*!< Street name directions string type.*/
    AGSNADirectionsStringAltName,               /*!< Alternate street name directions string type.*/
    AGSNADirectionsStringBranch,                /*!< Sign branch information directions string type.*/
    AGSNADirectionsStringToward,                /*!< Sign toward information directions string type.*/
    AGSNADirectionsStringCrossStreet,           /*!< Cross street name directions string type.*/
    AGSNADirectionsStringExit,                  /*!< Sign exit number directions string type.*/
} ;

/** Constants representing the network analyst message type.
 @since 1.8
 */
typedef NS_ENUM(NSInteger, AGSNAMessageType) {
	AGSNAMessageTypeAbort = 0,					/*!< Abort */
	AGSNAMessageTypeEmpty = 1,					/*!< Empty */
	AGSNAMessageTypeError = 2,					/*!< Error */
	AGSNAMessageTypeInformative = 3,			/*!< Informative */
	AGSNAMessageTypeProcessDefinition = 50,		/*!< Process Definition */
	AGSNAMessageTypeProcessStart = 100,			/*!< Process Start */
	AGSNAMessageTypeProcessStop = 101,			/*!< Process Stop */
	AGSNAMessageTypeWarning = 200,				/*!< Warning */
} ;

/** Supported message types for the  AGSGeoprocessor.
 @since 1.0
 */
typedef NS_ENUM(NSInteger, AGSGPMessageType) {
	AGSGPMessageTypeInformative = 0,		/*!< Informative */
    AGSGPMessageTypeProcessDefinition,      /*!< Process Definition */
    AGSGPMessageTypeStart,                  /*!< Start */
    AGSGPMessageTypeStop,					/*!< Stop */
    AGSGPMessageTypeWarning,				/*!< Warning */
    AGSGPMessageTypeError,                  /*!< Error */
    AGSGPMessageTypeEmpty,                  /*!< Empty */
    AGSGPMessageTypeAbort					/*!< Abort */
} ;

/** Constants representing the rotationType in  AGSRenderer.
 @since 10.2.2
 */
typedef NS_ENUM(NSInteger, AGSRotationType) {
    AGSRotationTypeGeographic = 0, /*!<  Geographic. Rotation begins from North in a clockwise direction where North is the 0° axis*/
    AGSRotationTypeArithmetic      /*!<  Arithmetic. Rotation begins from East in a counter-clockwise direction where East is the 0° axis*/
} ;

/** Return message type string for  AGSGPMessageType.
 @param messageType The type for message.
 @return String representation of @p messageType.
 @since 10.2.2
 @see AGSGPMessageType
 */
AGS_EXTERN NSString *AGSGPMessageTypeAsString(AGSGPMessageType messageType);

/** Return  AGSGPMessageType from message type string.
 @param messageType The string representation of the message type.
 @return  AGSGPMessageType for @p messageType.
 @since 10.2.2
 @see AGSGPMessageType
 */
AGS_EXTERN AGSGPMessageType AGSGPMessageTypeFromString(NSString *messageType);

/** Contstants representing how the geometry is returned.
 @since 1.8
 */
typedef NS_ENUM(NSUInteger, AGSNAOutputPolygon) {
	AGSNAOutputPolygonDetailed = 0,			/*!< No polygons are generated. */	
	AGSNAOutputPolygonNone,					/*!< Simplified polygons are generated. */
	AGSNAOutputPolygonSimplified			/*!< Detailed polygons are generated. */
} ;

/** Conversion mode for MGRS coordinates
 @since 2.3
 */
typedef NS_OPTIONS(NSUInteger, AGSMGRSConversionMode) {
    AGSMGRSConversionModeNewStyle = 0,      /*!< New Style */
} ;

/** Constants representing error codes.
 @since 2.1
 */
typedef NS_ENUM(NSInteger, AGSErrorCode) {
	AGSErrorCodeOperationNotSupported = 10000,          /*!< Op Not Supported */
    AGSErrorCodeNoDataTile = 10001,                     /*!< No Data Tile */
    AGSErrorCodeSpatialReferenceNotSupported = 10002,   /*!< Spatial Reference Not Supported */
    AGSErrorCodeInvalidArgument = 10003,                /*!< Invalid Argument */
    AGSErrorCodeOperationFailed = 10004,                /*!< This error indicates that, for an unknown reason, the operation failed on the server. This error is only possible when adding items on an AGSPortal or updating properties of an AGSPortalItem.*/
    AGSErrorCodeErrorParsingJSON = 10005                /*!< An error occured while parsing JSON from the server */
} ;



///** Defines the drawing behavior for a dynamic layer when
// the map's location display is in an autopan mode other than off.
// @since 2.1
// */
//typedef enum {
//	AGSDynamicLayerAutoPanDrawingModeNormal = 0,	/*!< Dynamic layer draws normally. */
//    AGSDynamicLayerAutoPanDrawingModeConservative, /*!< Dynamic layer draws only when it doesn't currently have a drawing operation in progress. 
//                                                       This lessens the load on the server.*/
//    AGSDynamicLayerAutoPanDrawingModeNone /*!< Dynamic layer does not draw when the map is in navigation mode. */
//} AGSDynamicLayerAutoPanDrawingMode;


/**
 @since 2.2
 */
typedef NS_ENUM(NSUInteger, AGSPortalItemType) {
    AGSPortalItemTypeOther = 0,                          /*!< Other */
    AGSPortalItemTypeMapDocument,               /*!< ArcMap Document (mxd) */
    AGSPortalItemTypeExplorerMap,                   /*!< ArcGIS Explorer Document (nmf) */
    AGSPortalItemTypeGlobeDocument,                 /*!< ArcGlobe Document (3dd) */
    AGSPortalItemTypeSceneDocument,                 /*!< ArcScene Document (sxd) */
    //AGSPortalItemTypeExplorerMap,                  /*!< ArcGIS Explorer Application Configuration (ncfg) */
    AGSPortalItemTypePublishedMap,                  /*!< ArcReader Document (pmf) */
    AGSPortalItemTypeMapPackage,                    /*!< ArcGIS Map Package (mpk)  */
    AGSPortalItemTypeGeoprocessingPackage,          /*!< ArcGIS Geoprocessing Package (gpk) */
    AGSPortalItemTypeLocatorPackage,                /*!< ArcGIS Locator Package (apk) */
    AGSPortalItemTypeTilePackage,                   /*!< ArcGIS Server Tile Package (tpk)*/
    AGSPortalItemTypeWindowsMobilePackage,          /*!< ArcGIS Windows Mobile Package */
    AGSPortalItemTypeDesktopApplicationTemplate,    /*!< The Desktop Application Template (.zip) includes either a desktop add in or a toolbar.exe */
    AGSPortalItemTypeMapTemplate,                   /*!< The Map Template (.zip) contains documentation, a map and GDB folder */
    AGSPortalItemTypeCodeSample,                    /*!< Developer Sample */
    AGSPortalItemTypeGeoprocessingSample,           /*!< Tool, Geoprocessing Sample */
    AGSPortalItemTypeLayer,                         /*!< Layer File (lyr) */
    AGSPortalItemTypeLayerPackage,                  /*!< Layer Package (lpk) */
    AGSPortalItemTypeExplorerLayer,                 /*!< ArcGIS Explorer Layer (nmc) */
    AGSPortalItemTypeDesktopAddIn,                  /*!< ArcGIS Add In (esriaddin) */
    AGSPortalItemTypeExplorerAddIn,                 /*!< ArcGIS Explorer Layer (eaz) */
    AGSPortalItemTypeMapService,                    /*!< ArcGIS Server Map Service */
    AGSPortalItemTypeGeocodingService,              /*!< ArcGIS Server Geocoding Service */
    AGSPortalItemTypeNetworkAnalysisService,        /*!< ArcGIS Server Network Analyst Service */
    AGSPortalItemTypeGlobeService,                  /*!< ArcGIS Server Globe Service */
    AGSPortalItemTypeGeoprocessingService,          /*!< ArcGIS Server Geoprocessing Service */
    AGSPortalItemTypeGeodataService,                /*!< ArcGIS Server Geodata Service */
    AGSPortalItemTypeImageService,                  /*!< ArcGIS Server Image Service */
    AGSPortalItemTypeGeometryService,               /*!< ArcGIS Server Geometry Service */
    AGSPortalItemTypeFeatureService,                /*!< ArcGIS Feature Service */
    AGSPortalItemTypeKML,                           /*!< Data, Map, kml */
    AGSPortalItemTypeWMS,                           /*!< Data, Service, Web Map Service, OGC */
    AGSPortalItemTypeWMTS,                          /*!< Data, Service, Web Map Tile Service, OGC */
    AGSPortalItemTypeWebMap,                        /*!< Web Map authored using the arcgis.com Javascript Web Map viewer or using ArcGIS Explorer online. Usable by web, mobile, and desktop clients */
    AGSPortalItemTypeWebMappingApplication,         /*!< A web mapping application built using ArcGIS API for Javascript, ArcGIS API for Flex, ArcGIS API for Silverlight, Java Web Application Developer Framework, .NET Web Application Developer Framework */
    AGSPortalItemTypeMobileApplication,             /*!< A mobile application build using the ArcGIS for iPhone SDK, ArcGIS for Android SDK, ArcGIS Mobile SDK for the Windows Mobile Platform, or the JavaScript or Flex API */
    AGSPortalItemTypeCodeAttachment,                /*!< Code Attachment */
    AGSPortalItemTypeFeaturedItems,                 /*!< Empty Item type with relationships to items that user wants featured */
    AGSPortalItemTypeFeatureCollection,             /*!< A feature collection is a saved web map feature layer with layer definition and a feature set */
    AGSPortalItemTypeFeatureCollectionTemplate,     /*!< Feature Collection, Feature Service Template, Map Notes Template */
    AGSPortalItemTypeSymbolSet,                     /*!< Symbol Set*/
    AGSPortalItemTypeColorSet,                      /*!< Color Set */
    AGSPortalItemTypeCollectionDefinition,          /*!< The definition for a feature collection/web map feature layer */
    AGSPortalItemTypeOperationView,                 /*!< An Operation View */
    AGSPortalItemTypeOperationsDashboardAddin,      /*!< An Operations Dashboard Addin */
    AGSPortalItemTypeCityEngineWebScene,            /*!< A CityEngine Web Scene */
    AGSPortalItemTypeWorkflowManagerPackage,        /*!< A Workflow Manager Package (wpk) */
    AGSPortalItemTypeArcPadPackage,                 /*!< An ArcPad Package (appk) */
    AGSPortalItemTypeShapefile,                     /*!< A shapefile */
    AGSPortalItemTypeCSV,                           /*!< A text file of data values separated by commas or other delimiters */
    AGSPortalItemTypeImage,                         /*!< An image document (.jpg, .jpeg, .png, .tif, .tiff) */
    AGSPortalItemTypeMSWordDocument,                /*!< A Microsoft Word Document (.doc, .docx) */
    AGSPortalItemTypeMSExcelDocument,               /*!< A Microsoft Excel Document (.xls, .xlsx) */
    AGSPortalItemTypeMSPowerPointDocument,          /*!< A Microsoft Power Point Document (.ppt, .pptx) */
    AGSPortalItemTypeVisioDocument,                 /*!< A Visio Document (.vsd) */
    AGSPortalItemTypePDFDocument,                   /*!< A PDF Document (.pdf) */
    AGSPortalItemTypeDocumentLink,                   /*!< A link to a document on the web (URL) */
    AGSPortalItemTypeServiceDefinition              /*!< A Service Definition that can be published to create a geospatial web service */
} ;

/** Access types on Portal, Item, Group or User. 
 
 <b> For Portal or Organization </b>
 
 Determines who can view your organization as an anonymous user. <code>AGSPortalAccessPublic</code> 
 means it allows anonymous users to access your organization's custom URL. <code>AGSPortalAccessPrivate </code> restricts access to only members of your organization.  
 
 <b> For Portal Item </b>
 
 Indicates the access level of the item. If <code>AGSPortalAccessPrivate</code>, only the item owner can
 access. <code>AGSPortalAccessShared</code> allows the item to be shared with a specific group. <code>
 AGSPortalAccessOrganization</code> restricts item access to members of your organization. If <code>
 AGSPortalAccessPublic</code>, all users can access the item.
 
 <b> For Portal Group </b>
 
 Determines who can access the group. <code>AGSPortalAccessPrivate</code> gives access to only the group
 members. If <code>AGSPortalAccessOrganization</code>, all members of this organization can access the
 group. <code>AGSPortalAccessPublic</code> makes the group accessible to all.
 
 <b> For Portal User </b>
 
 Determines if other users can search for this user's name to find content and groups owned by this user
 and to invite this user to join their groups. <code>AGSPortalAccessPrivate</code> hides the user from
 user searches and invites. If <code>AGSPortalAccessOrganization</code>, only members of this user's 
 organization can search for this user, the content and groups. <code>AGSPortalAccessPublic</code> makes 
 the user findable.
 
 @since 2.2
 */
typedef NS_ENUM(NSInteger, AGSPortalAccess) { 
    AGSPortalAccessPrivate = 0,                     /*!< Applicable for All  */
    AGSPortalAccessShared,                          /*!< Applicable for only Items  */
    AGSPortalAccessOrganization,                    /*!< Applicable for Items, Groups and Users  */
    AGSPortalAccessPublic                           /*!< Applicable for All  */
} ;

/** Indicates the order of results of the portal query.  
 @since 2.2
 */
typedef NS_ENUM(NSInteger, AGSPortalQuerySortOrder){
	AGSPortalQuerySortOrderAscending = 0,   	/*!< Ascending */
	AGSPortalQuerySortOrderDescending,			/*!< Descending */
} ;


/** Indicating whether the portal contains multiple organizations or not. 
 @since 2.2
 */
typedef NS_ENUM(NSInteger, AGSPortalMode) {
	AGSPortalModeSingleTenant = 0,   	/*!< Only one organization*/
	AGSPortalModeMultiTenant,			/*!< Multiple organizations*/
} ;

/** Indicates the role of the portal user within an organization.
 @since 10.1.1
 */
typedef NS_ENUM(NSInteger, AGSPortalUserRole) {
    AGSPortalUserRoleNone = 0,              /*!< The user does not belong to an organization */
    AGSPortalUserRoleUser,                  /*!< Information worker */
    AGSPortalUserRolePublisher,             /*!< Publisher */
    AGSPortalUserRoleAdmin,                 /*!< Administrator */
} ;

/** Indicates the desired sorting criterion for group items.
 @since 10.2
 */
typedef NS_ENUM(NSInteger, AGSPortalGroupSortField) {
	AGSPortalGroupSortFieldTitle = 0,       /*!< Title */
	AGSPortalGroupSortFieldOwner,           /*!< Ownder */
	AGSPortalGroupSortFieldAvgRating,       /*!< Average Rating */
	AGSPortalGroupSortFieldNumViews,        /*!< Number of Views */
	AGSPortalGroupSortFieldCreated,         /*!< Created Date */
	AGSPortalGroupSortFieldModified,        /*!< Modified Date */
} ;

/** Return sort field string for  AGSPortalGroupSortField.
 @param sortField The sort field.
 @return String representation of @p sortField.
 @since 10.2
 @see AGSPortalGroupSortField
 */
AGS_EXTERN NSString *AGSPortalGroupSortFieldToString(AGSPortalGroupSortField sortField);

/**
 @since 2.3
 */
typedef NS_ENUM(NSInteger, AGSWMTSServiceMode) {
    AGSWMTSServiceModeRESTful = 0,              /*!< RESTful */
    AGSWMTSServiceModeKVP                       /*!< Key-value */
} ;


/** Supported image formats.
 @since 1.0
 */
typedef NS_ENUM(NSInteger, AGSImageFormat) {
    AGSImageFormatUnknown = -1, /*!< Unknown */
    AGSImageFormatPNG32 = 0,	/*!< PNG 32 */
    AGSImageFormatPNG24,		/*!< PNG 24 */
    AGSImageFormatPNG8,			/*!< PNG 8 */
    AGSImageFormatPNG,			/*!< PNG */
    AGSImageFormatJPG,			/*!< JPG */
    AGSImageFormatGIF,			/*!< GIF */
	AGSImageFormatBMP,			/*!< BMP */
	AGSImageFormatTIFF,			/*!< TIFF */
	AGSImageFormatJPGPNG,		/*!< JPG if image fully opaque, PNG if transparent */
    //For most layers JPEG should be treated the same as JPG using jpg for the files extension, however for some (only WMTS so far)
    //the file extension used for JPEG needs to be jpeg.
	AGSImageFormatJPEG          /*!< JPEG */
} ;

/** Returns the image format as a string.
 @since 1.0
 */
AGS_EXTERN NSString *AGSFileFormatForImageFormat(AGSImageFormat imageFormat);

/** Returns the image format as a string.
 @since 10.1.1
 */
AGS_EXTERN NSString *AGSFileFormatForImageFormatWithJPEGEqualToJPG(AGSImageFormat imageFormat, BOOL IsJPEGEqualToJPG);

/** Return the image format enumeration from a string
 @param imageFormatString The image format string.
 @return An enumeration representing the @p imageFormatString.
 @since 10.2.4
 @see AGSImageFormat
 */
AGS_EXTERN AGSImageFormat AGSImageFormatFromString(NSString *imageFormatString);

/** An enumeration that is used for defining the style of an AGSPopupsContainer.
 @since 2.0
 */
typedef NS_ENUM(NSInteger, AGSPopupsContainerStyle) {
	AGSPopupsContainerStyleDefault = 0, /*!< Default */
	AGSPopupsContainerStyleBlack,       /*!< Black */
	AGSPopupsContainerStyleCustomColor  /*!< CustomColor */
} ;

/** An enumeration that is used for defining the editing style of an AGSPopupsContainer.
 @since 2.0
 */
typedef NS_ENUM(NSInteger, AGSPopupsContainerEditingStyle) {
	AGSPopupsContainerEditingStyleGeometryTool,     /*!< Shows a toolbar with a button for attachments and a button for collecting the geometry */
	AGSPopupsContainerEditingStyleGeometryInline    /*!< Has a view to switch between attributes and attachments.
                                                     There is no button for the collecting the geometry, as this is assumed
                                                     the user has access to the map while the popup is up (think ipad), or
                                                     the user will not be collecting a geometry at all. */
} ;

/** An enumeration that is used for defining the Paging style of an AGSPopupsContainer.
 @since 2.0
 */
typedef NS_ENUM(NSInteger, AGSPopupsContainerPagingStyle) {
	AGSPopupsContainerPagingStylePageControl,   /*!< Page Control */
	AGSPopupsContainerPagingStyleToolbar        /*!< Toolbar */
} ;

/** An enumeration that is used for defining statistic calculations in AGSOutStatistics.
 @since 10.1.1
 */
typedef NS_ENUM(NSInteger, AGSQueryStatisticsType) {
    AGSQueryStatisticsTypeCount,            /*!< Count */
    AGSQueryStatisticsTypeSum,              /*!< Sum */
    AGSQueryStatisticsTypeMin,              /*!< Minimum value */
    AGSQueryStatisticsTypeMax,              /*!< Maximum value */
    AGSQueryStatisticsTypeAvg,              /*!< Average */
    AGSQueryStatisticsTypeStdDev,           /*!< Standard Deviation */
    AGSQueryStatisticsTypeVar,              /*!< Variance */
} ;

/** Military symbology dictionary type
 @since 10.1.1
 */
typedef NS_ENUM(NSInteger, AGSMPSymbolDictionaryType) {
    AGSMPSymbolDictionaryTypeMil2525C,              /*!< Mil-2525C */
    AGSMPSymbolDictionaryTypeApp6B,                 /*!< App-6B */
    AGSMPSymbolDictionaryTypeSimple                 /*!< Simple */
} ;

/** An enumeration that is used for converting GARS coordinates
 @since 10.2
 */
typedef NS_ENUM(NSInteger, AGSGARSConversionMode) {
    AGSGARSConversionModeLowerLeft = 0, /*!< Lower Left */
    AGSGARSConversionModeCenter = 1     /*!< Center */
} ;


/** An enumeration that is used for converting UTM coordinates
 @since 10.2
 */
typedef NS_ENUM(NSInteger, AGSUTMConversionMode) {
    AGSUTMConversionModeNoIndicators = 0,               /*!< No Indicators */
    AGSUTMConversionModeNorthSouthIndicators = 1        /*!< North South Indicators */
} ;


/** Status of the current job being executed on the AGSGDBSyncTask.
 @since 10.2
 */
typedef NS_ENUM(NSUInteger, AGSGDBSyncTaskJobStatus) {
    AGSGDBSyncTaskJobStatusPending = 0,                             /*!< Pending */
    AGSGDBSyncTaskJobStatusInProgress,                              /*!< In Progress */
    AGSGDBSyncTaskJobStatusCompleted,                               /*!< Completed */
    AGSGDBSyncTaskJobStatusFailed,                                  /*!< Failed */
    AGSGDBSyncTaskJobStatusImportChanges,                           /*!< Importing Changes */
    AGSGDBSyncTaskJobStatusExportChanges,                           /*!< Exporting Changes */
    AGSGDBSyncTaskJobStatusExportingData,                           /*!< Exporting Data */
    AGSGDBSyncTaskJobStatusExportAttachments,                       /*!< Exporting Attachments */
    AGSGDBSyncTaskJobStatusImportAttachments,                       /*!< Importing Attachments */
    AGSGDBSyncTaskJobStatusProvisioningSyncEnabledGeodatabase,      /*!< Provisioning sync-enabled geodatabase */
    AGSGDBSyncTaskJobStatusUnRegisteringSyncEnabledGeodatabase,     /*!< Unregistering sync-enabled geodatabase */
    AGSGDBSyncTaskJobStatusCompletedWithErrors                      /*!< Completed with errors */
} ;

/** Defines whether and how filters will be applied to a layer/table when including its data in a geodatabase.
 @since 10.2
 */
typedef NS_ENUM(NSInteger, AGSGDBQueryOption){
    AGSGDBQueryOptionNone = 0,      /*!< No features are included, unless they are related to feature in other layers in the geodatabase and @c AGSGDBLayerQuery::includeRelated is @c YES  */
    AGSGDBQueryOptionUseFilter,		/*!< Features that satisfy filtering based on @c AGSGDBLayerQuery::where clause and optionally, @c AGSGDBGenerateParameters#extent (only if @c AGSGDBLayerQuery#useGeometry is @c YES) are included.  */
    AGSGDBQueryOptionAll			/*!< All the features from the layer are included */
} ;

/**
 @since 10.2
 */
typedef NS_ENUM(NSInteger, AGSGDBSyncTaskResponseType){
    AGSGDBSyncTaskResponseTypeData,				/*!< Data */
    AGSGDBSyncTaskResponseTypeRegisterData,		/*!< Register Data */
    AGSGDBSyncTaskResponseTypeEdits,			/*!< Edits */
    AGSGDBSyncTaskResponseTypeReplacementData,	/*!< Replacement Data */
    AGSGDBSyncTaskResponseTypeEditsAndData,		/*!< Edits & Data */
    AGSGDBSyncTaskResponseTypeNoEdits			/*!< No Edits*/
} ;

/** The sync model defines how layers in a sync-enabled geodatabase can be synced.
 @see  AGSGDBSyncDirection
 @since 10.2
 */
typedef NS_ENUM(NSInteger, AGSGDBSyncModel) {
    AGSGDBSyncModelPerGeodatabase,	/*!< Layers within a geodatabase cannot be synchronized independently. The sync operation and sync direction applies to all the layers in the geodatabase. */
    AGSGDBSyncModelPerLayer         /*!< Layers within a geodatabase can be synchronized independently. A chosen subset of the layers can be synchronized when running the sync operation. Also, each layer can independently choose its sync direction */
} ;

/** Status of an operation initiated by  AGSExportTileCacheTask
 @since 10.2
 */
typedef NS_ENUM(NSInteger, AGSExportTileCacheJobStatus){
    AGSExportTileCacheJobNew = 0,		/*!< New */
    AGSExportTileCacheJobSubmitted,	/*!< Submitted */
    AGSExportTileCacheJobWaiting,		/*!< Waiting */
    AGSExportTileCacheJobExecuting,	/*!< Executing */
    AGSExportTileCacheJobSucceeded,	/*!< Succeeded */
    AGSExportTileCacheJobFailed,		/*!< Failed */
    AGSExportTileCacheJobTimedOut,	/*!< Timed Out */
    AGSExportTileCacheJobCancelling,	/*!< Cancelling */
    AGSExportTileCacheJobCancelled,	/*!< Cancelled */
    AGSExportTileCacheJobDeleting,	/*!< Deleting */
    AGSExportTileCacheJobDeleted		/*!< Deleted */
};

/** The HTTP method being used by the network request.
 @since 10.2
 */
typedef NS_ENUM(NSInteger, AGSRequestHTTPMethod) {
    AGSRequestHTTPMethodGet = 0,						/*!< GET */
    AGSRequestHTTPMethodPostFormEncodeParameters = 1,	/*!< POST Form Encoded Params */
    AGSRequestHTTPMethodPostJSON = 2					/*!< POST Json */
};


/** Return field type string for  AGSFieldType.
 @param fieldType The type for field.
 @return String representation of @p fieldType.
 @since 10.2
 @see AGSFieldType
 */
AGS_EXTERN NSString *AGSFieldTypeToString(AGSFieldType fieldType);

/** Return  AGSFieldType from field.
 @param fieldType The string representation of the field type.
 @return  AGSFieldType for @p fieldType.
 @since 10.2
 @see AGSFieldType
 */
AGS_EXTERN AGSFieldType AGSFieldTypeFromString(NSString *fieldType);

/** Return relation type string for  AGSGeometryRelation.
 @param relation The type for relation.
 @return String representation of @p relation.
 @since 10.2
 @see AGSGeometryRelation
 */
AGS_EXTERN NSString *AGSGeometryRelationAsString(AGSGeometryRelation relation);

/** Return  AGSGeometryRelation from relation.
 @param relation The relation to determine relation type.
 @return  AGSGeometryRelation for @p relation.
 @since 10.2
 @see AGSGeometryRelation
 */
AGS_EXTERN AGSGeometryRelation AGSGeometryRelationFromString(NSString *relation);

/** Return relation type string for  AGSGeometryOffsetType.
 @param offsetType The type for relation.
 @return String representation of @p offsetType.
 @since 10.2
 @see AGSGeometryOffsetType
 */
AGS_EXTERN NSString *AGSGeometryOffsetTypeAsString(AGSGeometryOffsetType offsetType);

/** Return  AGSGeometryOffsetType from offsetType.
 @param offsetType The offset to determine offset type.
 @return  AGSGeometryOffsetType for @p offsetType.
 @since 10.2
 @see AGSGeometryOffsetType
 */
AGS_EXTERN AGSGeometryOffsetType AGSGeometryOffsetTypeFromString(NSString* offsetType);

/** An enumeration that is used for defining the sync direction.
 @since 10.2
 */
typedef NS_ENUM(NSInteger, AGSGDBSyncDirection) {
    AGSGDBSyncDirectionNone = 0,		/*!< None */
    AGSGDBSyncDirectionDownload,		/*!< Download changes only */
    AGSGDBSyncDirectionUpload,			/*!< Upload changes only */
    AGSGDBSyncDirectionBidirectional,	/*!< Download and Upload changes */
} ;

/** Return sync direction string for  AGSGDBSyncDirection.
 @param syncDirection The direction for sync.
 @return String representation of @p syncDirection.
 @since 10.2
 @see AGSGDBSyncDirection
 */
AGS_EXTERN NSString *AGSGDBSyncDirectionAsString(AGSGDBSyncDirection syncDirection);

/** Return  AGSGDBSyncDirection from syncDirection.
 @param syncDirection The direction to determine the sync.
 @return  AGSGDBSyncDirection for @p syncDirection.
 @since 10.2
 @see AGSGDBSyncDirection
 */
AGS_EXTERN AGSGDBSyncDirection AGSGDBSyncDirectionFromString(NSString *syncDirection);

/** Return job status string for  AGSGDBSyncTaskJobStatus.
 @param jobStatus The job status.
 @return String representation of @p jobStatus.
 @since 10.2
 @see AGSGDBSyncTaskJobStatus
 */
AGS_EXTERN NSString *AGSGDBSyncTaskJobStatusAsString(AGSGDBSyncTaskJobStatus jobStatus);

/** Return  AGSGDBSyncTaskJobStatus from jobStatus.
 @param jobStatus The job status.
 @return  AGSGDBSyncTaskJobStatus for @p jobStatus.
 @since 10.2
 @see AGSGDBSyncTaskJobStatus
 */
AGS_EXTERN AGSGDBSyncTaskJobStatus AGSGDBSyncTaskJobStatusFromString(NSString *jobStatus);

/** Return query option string for  AGSGDBQueryOption.
 @param queryOption The query option.
 @return String representation of @p queryOption.
 @since 10.2
 @see AGSGDBQueryOption
 */
AGS_EXTERN NSString *AGSGDBQueryOptionAsString(AGSGDBQueryOption queryOption);

/** Return  AGSGDBQueryOption from queryOption.
 @param queryOption The query option.
 @return  AGSGDBQueryOption for @p queryOption.
 @since 10.2
 @see AGSGDBQueryOption
 */
AGS_EXTERN AGSGDBQueryOption AGSGDBQueryOptionFromString(NSString* queryOption);

/** Return the response type string for an  AGSGDBSyncTask.
 @param responseType The response type to retrieve a string for.
 @return An NSString representing the @p responseType.
 @since 10.2
 @see AGSGDBSyncTaskResponseType
 */
AGS_EXTERN NSString *AGSGDBSyncTaskResponseTypeAsString(AGSGDBSyncTaskResponseType responseType);

/** Return the response type enumeration from a JSON response string
 @param responseType The response type string.
 @return An enumeration representing the @p responseType string.
 @since 10.2
 @see AGSGDBSyncTaskResponseType
 */
AGS_EXTERN AGSGDBSyncTaskResponseType AGSGDBSyncTaskResponseTypeFromString(NSString *responseType);

/** Return the sync model enumeration from a JSON syncModel string.
 @param syncModel The sync model string.
 @return An enumeration representing the @p syncModel string.
 @since 10.2
 @see AGSGDBSyncModel
 */
AGS_EXTERN AGSGDBSyncModel AGSGDBSyncModelFromString(NSString *syncModel);

/** Return the sync model enumeration from a JSON sync model string.
 @param syncModel The sync model string.
 @return An enumeration representing the @p syncModel string.
 @since 10.2
 @see AGSGDBSyncModel
 */
AGS_EXTERN NSString *AGSGDBSyncModelAsString(AGSGDBSyncModel syncModel);

/** Relationship cardinality.
 @since 10.2.2
 @see  AGSRelationshipCardinalityFromString()
 @see  AGSRelationshipCardinalityAsString()
 */
typedef NS_ENUM(NSInteger, AGSRelationshipCardinality){
    AGSRelationshipCardinalityOneToOne = 0,     /*!< One origin feature is related to at most one destination feature */
    AGSRelationshipCardinalityOneToMany,        /*!< One origin feature could be related to multiple destination features */
    AGSRelationshipCardinalityManyToMany        /*!< Multiple origin features could be related to multiple destinate features*/
};

/** Return the relationship cardinality enumeration from a JSON response string
 @param cardinalityString The relationship cardinality string.
 @return An enumeration representing the @p cardinalityString.
 @since 10.2.2
 @see  AGSRelationshipCardinality
 */
AGS_EXTERN AGSRelationshipCardinality AGSRelationshipCardinalityFromString(NSString *cardinalityString);

/** Return the relationship cardinality string for an  AGSRelationshipCardinality.
 @param relationshipCardinality The relationship cardinality to retrieve a string for.
 @return An NSString representing the @p relationshipCardinality.
 @since 10.2.2
 @see  AGSRelationshipCardinality
 */
AGS_EXTERN NSString *AGSRelationshipCardinalityAsString(AGSRelationshipCardinality relationshipCardinality);

/** Relationship role. Helpful in determining the direction in which edits cascade (origin -> destination).
 @since 10.2.2
 @see  AGSRelationshipRoleFromString()
 @see  AGSRelationshipRoleAsString()
 */
typedef NS_ENUM(NSInteger, AGSRelationshipRole){
    AGSRelationshipRoleOrigin = 0,      /*!< Origin */
    AGSRelationshipRoleDestination      /*!< Destination */
};

/** Return the relationship role enumeration from a JSON response string
 @param roleString The relationship role string.
 @return An enumeration representing the @p roleString.
 @since 10.2.2
 @see  AGSRelationshipRole
 */
AGS_EXTERN AGSRelationshipRole AGSRelationshipRoleFromString(NSString *roleString);

/** Return the relationship role string for an  AGSRelationshipRole.
 @param relationshipRole The relationship role to retrieve a string for.
 @return An NSString representing the @p relationshipRole.
 @since 10.2.2
 @see  AGSRelationshipRole
 */
AGS_EXTERN NSString *AGSRelationshipRoleAsString(AGSRelationshipRole relationshipRole);


/** Status for jobs that you kick off on the server and wait for them to finish and then download the result.
 Examples of this are generating geodatabases, generating tile caches, and syncing geodatabases.
 @since 10.2
 */
typedef NS_ENUM(NSInteger, AGSResumableTaskJobStatus) {
    AGSResumableTaskJobStatusNotStarted = 1,					/*!< Not Started */
    AGSResumableTaskJobStatusWaitingForDefaultParameters,		/*!< Waiting for defaults */
    AGSResumableTaskJobStatusPreProcessingJob,				/*!< Pre Processing */
    AGSResumableTaskJobStatusStartingJob,						/*!< Starting */
    AGSResumableTaskJobStatusPolling,							/*!< Polling */
    AGSResumableTaskJobStatusFetchingResult,					/*!< Fetching Result */
    AGSResumableTaskJobStatusInBGWaitingToFinish,				/*!< Backgrounded; waiting to finish */
    AGSResumableTaskJobStatusPaused,						/*!< Paused */
    AGSResumableTaskJobStatusDone,							/*!< Done */
    AGSResumableTaskJobStatusCancelled						/*!< Cancelled */
};

/** Return the job status enumeration from a string
 @param jobStatusString The job status string.
 @return An enumeration representing the @p jobStatusString.
 @since 10.2.2
 @see AGSResumableTaskJobStatus
 */
AGS_EXTERN AGSResumableTaskJobStatus AGSResumableTaskJobStatusFromString(NSString *jobStatusString);

/** Return the job status string for an  AGSResumableTaskJobStatus.
 @param jobStatus The job status to retrieve a string for.
 @return An NSString representing the @p jobStatus.
 @since 10.2.2
 @see AGSResumableTaskJobStatus
 */
AGS_EXTERN NSString *AGSResumableTaskJobStatusAsString(AGSResumableTaskJobStatus jobStatus);

/* Key to lookup the number of downloaded bytes from the userInfo dictionary of @c AGSGDBSyncTask or @c AGSExportTileCacheTask's
 status block.
 @since 10.2.2
 */
AGS_EXTERN NSString *const AGSDownloadProgressTotalBytesDownloadedKey;

/* Key to lookup the expected bytes for a download from the userInfo dictionary of @c AGSGDBSyncTask or @c AGSExportTileCacheTask's
 status block.
 @since 10.2.2
 */
AGS_EXTERN NSString *const AGSDownloadProgressTotalBytesExpectedKey;

/* The string representation of @p jobType for generating a geodatabase.
 @since 10.2.2
 */
AGS_EXTERN NSString *const AGSResumableTaskJobTypeGenerateGeodatabase;

/* The string representation of @p jobType for synchronizing a geodatabase.
 @since 10.2.2
 */
AGS_EXTERN NSString *const AGSResumableTaskJobTypeSyncGeodatabase;

/* The string representation of @p jobType for estimating the size of a tile cache.
 @since 10.2.2
 */
AGS_EXTERN NSString *const AGSResumableTaskJobTypeExportTileCacheSizeEstimate;

/* The string representation of @p jobType for generating a tile cache.
 @since 10.2.2
 */
AGS_EXTERN NSString *const AGSResumableTaskJobTypeExportTileCache;


/** Marker alignment when map is rotated
 @since 10.2
*/
typedef NS_ENUM(NSInteger, AGSMarkerSymbolAngleAlignment){
    AGSMarkerSymbolAngleAlignmentScreen,    /*!< Marker top edge always aligned with screen top edge*/
    AGSMarkerSymbolAngleAlignmentMap      /*!< Marker top edge always aligned with map north */
} ;            /*!< */

/** Result for license operations
 @since 10.2.2
 */
typedef NS_ENUM(NSInteger, AGSLicenseResult) {
    AGSLicenseResultInvalid = 0,            /*!< License is invalid */
    AGSLicenseResultValid,					/*!< License is valid */
    AGSLicenseResultLoginRequired,          /*!< License from portal authentication has exceeded login period, user will need to login in again */
    AGSLicenseResultExpired		    		/*!< License has expired */
};

/** Return the license result enumeration from a string
 @param licenseResultString The license result string.
 @return An enumeration representing the @p licenseResultString.
 @since 10.2.2
 @see AGSLicenseResult
 */
AGS_EXTERN AGSLicenseResult AGSLicenseResultFromString(NSString *licenseResultString);

/** Return the license result string for an  AGSLicenseResult.
 @param licenseResult The license result to retrieve a string for.
 @return An NSString representing the @p licenseResult.
 @since 10.2.2
 @see AGSLicenseResult
 */
AGS_EXTERN NSString *AGSLicenseResultAsString(AGSLicenseResult licenseResult);

/** Available license levels
 @since 10.2.2
 */
typedef NS_ENUM(NSInteger, AGSLicenseLevel) {
    AGSLicenseLevelDeveloper = 0,           /*!< All functionality is available */
    AGSLicenseLevelBasic,					/*!< All functionality available but map display is watermarked */
    AGSLicenseLevelStandard					/*!< Standard functionality is available. There is no watermark */
};

/** Return the license level enumeration from a string
 @param licenseLevelString The license level string.
 @return An enumeration representing the @p licenseLevelString.
 @since 10.2.2
 @see AGSLicenseLevel
 */
AGS_EXTERN AGSLicenseLevel AGSLicenseLevelFromString(NSString *licenseLevelString);

/** Return the license level string for an  AGSLicenseLevel.
 @param licenseLevel The license level to retrieve a string for.
 @return An NSString representing the @p licenseLevel.
 @since 10.2.2
 @see AGSLicenseLevel
 */
AGS_EXTERN NSString *AGSLicenseLevelAsString(AGSLicenseLevel licenseLevel);

/** Return the rotation type enumeration from a string
 @param rotationTypeString The rotation type string.
 @return An enumeration representing the @p rotationTypeString.
 @since 10.2.2
 @see AGSRotationType
 */
AGS_EXTERN AGSRotationType AGSRotationTypeFromString(NSString *rotationTypeString);

/** Return the rotation type string for an  AGSRotationType.
 @param rotationType The rotation type to retrieve a string for.
 @return An NSString representing the @p rotationType.
 @since 10.2.2
 @see AGSRotationType
 */
AGS_EXTERN NSString *AGSRotationTypeAsString(AGSRotationType rotationType);

/** An enumeration that shows what type of edit caused an error during geodatabase synchronization.
 @since 10.2.2
 */
typedef NS_ENUM(NSInteger, AGSGDBSyncEditType) {
    AGSGDBSyncEditTypeUnknown = 0,		/*!< Unknown */
    AGSGDBSyncEditTypeAdd,              /*!< Add */
    AGSGDBSyncEditTypeUpdate,			/*!< Update */
    AGSGDBSyncEditTypeDelete,           /*!< Delete */
} ;

/** Return sync edit type string for  AGSGDBSyncEditType.
 @param syncEditType The sync edit type.
 @return String representation of @p syncEditType.
 @since 10.2.2
 @see AGSGDBSyncEditType
 */
AGS_EXTERN NSString *AGSGDBSyncEditTypeAsString(AGSGDBSyncEditType syncEditType);

/** Return  AGSGDBSyncEditType from syncEditType.
 @param syncEditType The type of edit.
 @return  AGSGDBSyncEditType for @p syncEditType.
 @since 10.2.2
 @see AGSGDBSyncEditType
 */
AGS_EXTERN AGSGDBSyncEditType AGSGDBSyncEditTypeFromString(NSString *syncEditType);

/** An enumeration that shows what type of units the user prefers, according to their portal settings.
 @since 10.2.3
 */
typedef NS_ENUM(NSInteger, AGSPortalUserUnits) {
    AGSPortalUserUnitsEnglish = 0,     /*!< English units */
    AGSPortalUserUnitsMetric,          /*!< Metric units */
} ;

/** Return user units string for  AGSPortalUserUnits.
 @param userUnits The user units.
 @return String representation of @p userUnits.
 @since 10.2.3
 @see AGSPortalUserUnits
 */
AGS_EXTERN NSString *AGSPortalUserUnitsAsString(AGSPortalUserUnits userUnits);

/** Return  AGSPortalUserUnits from userUnits.
 @param userUnits The type of units.
 @return  AGSPortalUserUnits for @p userUnits.
 @since 10.2.3
 @see AGSPortalUserUnits
 */
AGS_EXTERN AGSPortalUserUnits AGSPortalUserUnitsFromString(NSString *userUnits);

#pragma mark Mosaic Rule

/** Supported mosaic rule methods.
 @since 1.8
 */
typedef NS_ENUM(NSInteger, AGSMosaicMethod) {
	AGSMosaicMethodNone = 0,		/*!<  */
	AGSMosaicMethodCenter,			/*!<  */
	AGSMosaicMethodNadir,			/*!<  */
	AGSMosaicMethodViewpoint,		/*!<  */
	AGSMosaicMethodAttribute,		/*!<  */
	AGSMosaicMethodLockRaster,		/*!<  */
	AGSMosaicMethodNorthwest,		/*!<  */
	AGSMosaicMethodSeamline			/*!<  */
} ;

/** Supported mosaic rule operation types.
 @since 1.8
 */
typedef NS_ENUM(NSInteger, AGSMosaicOperationType) {
	AGSMosaicOperationTypeFirst = 0,	/*!<  */
	AGSMosaicOperationTypeLast,			/*!<  */
	AGSMosaicOperationTypeMin,			/*!<  */
	AGSMosaicOperationTypeMax,			/*!<  */
	AGSMosaicOperationTypeMean,			/*!<  */
	AGSMosaicOperationTypeBlend, 		/*!<  */
	AGSMosaicOperationTypeSum			/*!<  */
} ;

/** Return mosaic method string for  AGSMosaicMethod.
 @param mosaicMethod The mosaic method.
 @return String representation of @p mosaicMethod.
 @since 10.2.4
 @see AGSMosaicMethod
 */
AGS_EXTERN NSString *AGSMosaicMethodAsString(AGSMosaicMethod mosaicMethod);

/** Return  AGSMosaicMethod from mosaicMethod.
 @param mosaicMethod The mosaic method.
 @return  AGSMosaicMethod for @p mosaicMethod.
 @since 10.2.4
 @see AGSMosaicMethod
 */
AGS_EXTERN AGSMosaicMethod AGSMosaicMethodFromString(NSString *mosaicMethod);

/** Return mosaic operation string for  AGSMosaicOperationType.
 @param mosaicOperation The mosaic operation.
 @return String representation of @p mosaicOperation.
 @since 10.2.4
 @see AGSMosaicOperationType
 */
AGS_EXTERN NSString *AGSMosaicOperationAsString(AGSMosaicOperationType mosaicOperation);

/** Return  AGSMosaicOperationType from mosaicOperation.
 @param mosaicOperation The mosaic operation.
 @return  AGSMosaicOperationType for @p mosaicOperation.
 @since 10.2.4
 @see AGSMosaicOperationType
 */
AGS_EXTERN AGSMosaicOperationType AGSMosaicOperationFromString(NSString *mosaicOperation);

/** Return  AGSMosaicMethod from mosaicMethodService.
 The values for the mosaic methods as returned from the service differ
 from those that are required to be sent to the service.  The variable method below translates
 from the service-returned values to our enumerations.  More information from:
 
 [http://resources.arcgis.com/en/help/arcgis-rest-api/ /Image_Service/02r3000000q8000000/]
 
 //New in 10.1. Optional. Default mosaic method.
 "defaultMosaicMethod": "<defaultMosaicMethod>",
 
 //New in 10.1. Optional. Comma separated list of allowed mosaic methods. Can be one or more of the following:
 None,Center,NorthWest,LockRaster,ByAttribute,Nadir,Viewpoint,Seamline. Corresponds to the following enums:
 esriMosaicNone | esriMosaicCenter | esriMosaicNorthwest | esriMosaicLockRaster | esriMosaicAttribute | esriMosaicNadir | esriMosaicViewpoint | esriMosaicSeamline
 @param mosaicMethodService The mosaic method returned by the service.
 @return  AGSMosaicMethod for @p mosaicMethodService.
 @since 10.2.4
 @see AGSMosaicMethod
 */
AGS_EXTERN AGSMosaicMethod AGSMosaicMethodFromServiceString(NSString *mosaicMethodService);

/** Return mosaic method service string for  AGSMosaicMethod.
 @param mosaicMethod The mosaic method.
 @return String representation of @p mosaicMethod for a service.
 @since 10.2.4
 @see AGSMosaicMethod
 */
AGS_EXTERN NSString *AGSMosaicMethodAsServiceString(AGSMosaicMethod mosaicMethod);

/** Return  AGSMosaicOperationType from mosaicOperationService.
 The values for the mosaic operations as returned from the service differ
 from those that are required to be sent to the service.  The method below translates
 from the service-returned values to our enumerations.  More information on:
 
 [http://resources.arcgis.com/en/help/arcgis-rest-api/ /Image_Service/02r3000000q8000000/]
 @param mosaicOperationService The mosaic operation.
 @return  AGSMosaicOperationType for @p mosaicOperationService.
 @since 10.2.4
 @see AGSMosaicOperationType
 */
AGS_EXTERN AGSMosaicOperationType AGSMosaicOperationFromServiceString(NSString *mosaicOperationService);

/** Return mosaic operation service string for  AGSMosaicOperationType.
 @param mosaicOperation The mosaic operation.
 @return String representation of @p mosaicOperation for a service.
 @since 10.2.4
 @see AGSMosaicOperationType
 */
AGS_EXTERN NSString *AGSMosaicOperationAsServiceString(AGSMosaicOperationType mosaicOperation);

#pragma mark Color Ramp

/** Supported color ramp types.
 @since 10.2.4
 */
typedef NS_ENUM(NSInteger, AGSColorRampType) {
	AGSColorRampTypeAlgorithmic = 0,		/*!<  */
	AGSColorRampTypeMultipart			/*!<  */
};

/** Return color ramp type string for  AGSColorRampType.
 @param colorRampType The color ramp type.
 @return String representation of @p colorRampType.
 @since 10.2.4
 @see AGSColorRampType
 */
AGS_EXTERN NSString *AGSColorRampTypeAsString(AGSColorRampType colorRampType);

/** Return  AGSColorRampType from colorRampType.
 @param colorRampType The color ramp type.
 @return  AGSColorRampType for @p colorRampType.
 @since 10.2.4
 @see AGSColorRampType
 */
AGS_EXTERN AGSColorRampType AGSColorRampTypeFromString(NSString *colorRampType);

/** Supported color ramp algorithms.
 @since 10.2.4
 */
typedef NS_ENUM(NSInteger, AGSColorRampAlgorithm) {
	AGSColorRampAlgorithmHSV = 0,	/*!<  */
	AGSColorRampAlgorithmCIELab,	/*!<  */
	AGSColorRampAlgorithmLabLCh     /*!<  */
};

/** Return color ramp algorithm string for  AGSColorRampAlgorithm.
 @param colorRampAlgorithm The color ramp algorithm.
 @return String representation of @p colorRampAlgorithm.
 @since 10.2.4
 @see AGSColorRampAlgorithm
 */
AGS_EXTERN NSString *AGSColorRampAlgorithmAsString(AGSColorRampAlgorithm colorRampAlgorithm);

/** Return  AGSColorRampAlgorithm from colorRampAlgorithm.
 @param colorRampAlgorithm The color ramp algorithm.
 @return  AGSColorRampAlgorithm for @p colorRampAlgorithm.
 @since 10.2.4
 @see AGSColorRampAlgorithm
 */
AGS_EXTERN AGSColorRampAlgorithm AGSColorRampAlgorithmFromString(NSString *colorRampAlgorithm);

#pragma mark Classification Definition

/** Supported class breaks classification methods.
 @since 10.2.4
 */
typedef NS_ENUM(NSInteger, AGSClassBreaksDefinitionClassificationMethod) {
	AGSClassBreaksDefinitionClassificationMethodNaturalBreaks = 0,	/*!<  */
	AGSClassBreaksDefinitionClassificationMethodEqualInterval,		/*!<  */
	AGSClassBreaksDefinitionClassificationMethodQuantile,           /*!<  */
	AGSClassBreaksDefinitionClassificationMethodStdDeviation,       /*!<  */
	AGSClassBreaksDefinitionClassificationMethodGeoInterval			/*!<  */
};

/** Return class breaks classification method string for  AGSColorRampType.
 @param classificationMethod The class breaks classification method.
 @return String representation of @p classificationMethod.
 @since 10.2.4
 @see AGSClassBreaksDefinitionClassificationMethod
 */
AGS_EXTERN NSString *AGSClassBreaksDefinitionClassificationMethodAsString(AGSClassBreaksDefinitionClassificationMethod classificationMethod);

/** Return  AGSClassBreaksDefinitionClassificationMethod from classificationMethod.
 @param classificationMethod The class breaks classification method.
 @return  AGSClassBreaksDefinitionClassificationMethod for @p classificationMethod.
 @since 10.2.4
 @see AGSClassBreaksDefinitionClassificationMethod
 */
AGS_EXTERN AGSClassBreaksDefinitionClassificationMethod AGSClassBreaksDefinitionClassificationMethodFromString(NSString *classificationMethod);

/** Supported class breaks classification normalization types.
 @since 10.2.4
 */
typedef NS_ENUM(NSInteger, AGSClassBreaksDefinitionNormalizationType) {
	AGSClassBreaksDefinitionNormalizationTypeByField = 0,       /*!<  */
	AGSClassBreaksDefinitionNormalizationTypeByLog,             /*!<  */
	AGSClassBreaksDefinitionNormalizationTypeByPercentOfTotal,	/*!<  */
	AGSClassBreaksDefinitionNormalizationTypeNone               /*!<  */
};

/** Return normalization type string for  AGSClassBreaksDefinitionNormalizationType.
 @param normalizationType The normalization type.
 @return String representation of @p normalizationType.
 @since 10.2.4
 @see AGSClassBreaksDefinitionNormalizationType
 */
AGS_EXTERN NSString *AGSClassBreaksDefinitionNormalizationTypeAsString(AGSClassBreaksDefinitionNormalizationType normalizationType);

/** Return  AGSClassBreaksDefinitionNormalizationType from normalizationType.
 @param normalizationType The normalization type.
 @return  AGSClassBreaksDefinitionNormalizationType for @p normalizationType.
 @since 10.2.4
 @see AGSClassBreaksDefinitionNormalizationType
 */
AGS_EXTERN AGSClassBreaksDefinitionNormalizationType AGSClassBreaksDefinitionNormalizationTypeFromString(NSString *normalizationType);

#pragma mark - layer source types

/** Supported layer source types.
 @since 10.2.4
 */
typedef NS_ENUM(NSInteger, AGSLayerSourceType) {
	AGSLayerSourceTypeMapLayer = 0,       /*!<  */
	AGSLayerSourceTypeDataLayer           /*!<  */
};

/** Return layer source type string for  AGSLayerSourceType.
 @param layerSourceType The layer source type.
 @return String representation of @p layerSourceType.
 @since 10.2.4
 @see AGSLayerSourceType
 */
AGS_EXTERN NSString *AGSLayerSourceTypeAsString(AGSLayerSourceType layerSourceType);

/** Return  AGSLayerSourceType from layerSourceType.
 @param layerSourceType The layer source type.
 @return  AGSLayerSourceType for @p layerSourceType.
 @since 10.2.4
 @see AGSLayerSourceType
 */
AGS_EXTERN AGSLayerSourceType AGSLayerSourceTypeFromString(NSString *layerSourceType);
