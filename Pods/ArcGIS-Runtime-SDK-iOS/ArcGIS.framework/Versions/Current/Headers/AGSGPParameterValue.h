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

/** @file AGSGPParameterValue.h */ //Required for Globals API doc

/** Supported parameter types for the  AGSGeoprocessor.
 @since 1.0
 */
typedef NS_ENUM(NSInteger, AGSGPParameterType) {
    AGSGPParameterTypeBoolean = 0,				/*!< Parameter must be of type @c NSValue					*/
    AGSGPParameterTypeDouble,					/*!< Parameter must be of type @c NSNumber					*/
    AGSGPParameterTypeLong,						/*!< Parameter must be of type @c NSNumber					*/
    AGSGPParameterTypeString,					/*!< Parameter must be of type @c NSString					*/
    AGSGPParameterTypeLinearUnit,				/*!< Parameter must be of type @c AGSGPLinearUnit */
    AGSGPParameterTypeFeatureRecordSetLayer,	/*!< Parameter must be of type @c AGSFeatureSet				*/
    AGSGPParameterTypeRecordSet,				/*!< Parameter must be of type @c AGSFeatureSet				*/
    AGSGPParameterTypeDataFile,					/*!< Parameter must be of type @c NSURL						*/
    AGSGPParameterTypeDate,						/*!< Parameter must be of type @c NSDate					*/
    AGSGPParameterTypeRasterData,				/*!< Parameter must be of type @c AGSGPRasterData */
    AGSGPParameterTypeRasterDataLayer,			/*!< Parameter must be of type @c AGSGPRasterData */
	AGSGPParameterTypeMultiValue				/*!< Parameter must be of type @c NSArray					*/
} ;

#pragma mark -

/**  An input/ouptut parameter of a geoprocessing task. 
 
 Instances of this class respresent input/output parameters of a geoprocessing 
 task. 
 
 
 */
@interface AGSGPParameterValue : NSObject <AGSCoding>

/** Data type of the parameter. Possible types include
 
 @li  AGSGPParameterTypeBoolean
 @li  AGSGPParameterTypeDouble 
 @li  AGSGPParameterTypeLong 
 @li  AGSGPParameterTypeString 
 @li  AGSGPParameterTypeLinearUnit 
 @li  AGSGPParameterTypeFeatureRecordSetLayer
 @li  AGSGPParameterTypeRecordSet
 @li  AGSGPParameterTypeDataFile 
 @li  AGSGPParameterTypeDate 
 @li  AGSGPParameterTypeRasterData 
 @li  AGSGPParameterTypeRasterDataLayer
 @li  AGSGPParameterTypeMultiValue
 
 @since 1.0
 */
@property (nonatomic, readonly) AGSGPParameterType type;

/** Name of the parameter.
 @since 1.0
 */
@property (nonatomic, copy, readonly) NSString *name;

/** Value of the parameter. The data structure of this value depends on the type.
 
 <table style="border-width:2px; border-style:solid; border-color: 84B0C7">
 <tr><td class="indexkey">Type</td> <td class="indexkey">Value</td></tr>
 <tr><td>@li  AGSGPParameterTypeBoolean </td><td> NSValue</td></tr>
 <tr><td>@li  AGSGPParameterTypeDouble  </td><td> NSNumber</td></tr>
 <tr><td>@li  AGSGPParameterTypeLong  </td><td> NSNumber</td></tr>
 <tr><td>@li  AGSGPParameterTypeString  </td><td> NSString</td></tr>
 <tr><td>@li  AGSGPParameterTypeLinearUnit  </td><td> AGSGPLinearUnit</td></tr>
 <tr><td>@li  AGSGPParameterTypeFeatureRecordSetLayer </td><td> AGSFeatureSet</td></tr>
 <tr><td>@li  AGSGPParameterTypeRecordSet </td><td> AGSFeatureSet</td></tr>
 <tr><td>@li  AGSGPParameterTypeDataFile  </td><td> NSURL</td></tr>
 <tr><td>@li  AGSGPParameterTypeDate  </td><td> NSDate</td></tr>
 <tr><td>@li  AGSGPParameterTypeRasterData  </td><td> AGSGPRasterData</td></tr>
 <tr><td>@li  AGSGPParameterTypeRasterDataLayer </td><td> AGSGPRasterData</td></tr>
 <tr><td>@li  AGSGPParameterTypeMultiValue </td><td> NSArray</td></tr>
 </table>
 
 */
@property (nonatomic, strong, readonly) id value;

/** Initialize an <code>AGSGPParameterValue</code> object.
 @param name The name of the parameter.
 @param type The type of the parameter.
 @param value The value of the parameter.
 @return A new geoprocessing parameter object.
 @since 1.0
 */
- (id)initWithName:(NSString*)name type:(AGSGPParameterType)type value:(id)value;

/** Initialize an <code>AGSGPParameterValue</code> object.
 @param name The name of the parameter.
 @param type The type of the parameter.
 @param value The value of the parameter.
 @return A new, autoreleased, geoprocessing parameter object.
 @since 1.0
 */
+ (id)parameterWithName:(NSString*)name type:(AGSGPParameterType)type value:(id)value;

@end
