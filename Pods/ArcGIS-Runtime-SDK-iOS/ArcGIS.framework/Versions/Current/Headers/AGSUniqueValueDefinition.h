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

#import "AGSClassificationDefinition.h"

/** @file AGSUniqueValueDefinition.h */ //Required for Globals API doc

/**  This class defines a unique value renderer when requesting a renderer from a dynamic map service's
 generateRenderer REST endpoint.
 
 A unique value renderer is defined by up to three fields that when taken together define a unique value
 for a given feature. The user can specify an optional base symbol and color ramp to be used by the renderer.

 Note the following about optional parameters:
    - baseSymbol and colorRamp — Use these properties to include a symbol with varying color for each class.
 
    - If only baseSymbol is defined, a default color ramp is used to assign a color for each class.
 
    - If only colorRamp is defined, a default symbol is created based on geometryType of the feature class,
    and the colorRamp is used to assign color to the symbol for each class.
    
    - If baseSymbol and colorRamp are missing, the map server assumes default values for these properties
    and returns the results with an appropriate symbol and color.

 @since 10.2.4
 */
@interface AGSUniqueValueDefinition : AGSClassificationDefinition

/** An array holding up to three fields that when taken together define a unique value for a given feature.
 @since 10.2.4
 */
@property (nonatomic, copy) NSArray *uniqueValueFields;

/** Initialize a   AGSUniqueValueDefinition with the given array of unique value fields.
 @param uniqueValueFields array holding up to three fields used define a unique value for a given feature.
 @since 10.2.4
 */
-(id)initWithUniqueValueFields:(NSArray *)uniqueValueFields;

/** Create a new  AGSUniqueValueDefinition with the given array of unique value fields.
 @param uniqueValueFields array holding up to three fields used define a unique value for a given feature.
 @return A new unique value classification definition.
 @since 10.2.4
 */
+(id)uniqueValueDefinitionWithUniqueValueFields:(NSArray *)uniqueValueFields;

@end
