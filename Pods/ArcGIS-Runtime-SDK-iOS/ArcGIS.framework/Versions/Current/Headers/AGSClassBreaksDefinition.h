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

/** @file AGSClassBreaksDefinition.h */ //Required for Globals API doc

/**  This class defines a class breaks renderer when requesting a renderer from a dynamic map service's
 generateRenderer REST endpoint.
 
 A class breaks renderer is defined by a classification method and field and number of class breaks desired.
 Optionally a normalization type can also be set. The user can also specify an optional base symbol and
 color ramp to be used by the renderer.
 
 If the StdDeviation classification method is used, a standard deviation interval can be set.
 If the ByField normalization type is used, the normalization field should also be specified.
 
 Note the following about optional parameters:
 - baseSymbol and colorRamp — Use these properties to include a symbol with varying color for each class.
 
 - If only baseSymbol is defined, a default color ramp is used to assign a color for each class.
 
 - If only colorRamp is defined, a default symbol is created based on geometryType of the feature class,
 and the colorRamp is used to assign color to the symbol for each class.
 
 - If baseSymbol and colorRamp are missing, the map server assumes default values for these properties
 and returns the results with an appropriate symbol and color.
 
 @since 10.2.4
 */
@interface AGSClassBreaksDefinition : AGSClassificationDefinition

/** The break count.
 @since 10.2.4
 */
@property (nonatomic, assign) NSUInteger breakCount;

/** The classification field.
 @since 10.2.4
 */
@property (nonatomic, copy) NSString *classificationField;

/** The classification method.
 @since 10.2.4
 */
@property (nonatomic, assign) AGSClassBreaksDefinitionClassificationMethod classificationMethod;

/** The normalization field.
 @since 10.2.4
 */
@property (nonatomic, copy) NSString *normalizationField;

/** The normalization type.
 @since 10.2.4
 */
@property (nonatomic, assign) AGSClassBreaksDefinitionNormalizationType normalizationType;

/** The standard deviation interval.
 @since 10.2.4
 */
@property (nonatomic, assign) CGFloat standardDeviationInterval;

/** Initialize a   AGSClassBreaksDefinition with the given classification field, method
 and desired number of breaks.
 @param classificationField field used to classify the data.
 @param classificationMethod method used to classify the data.
 @param breakCount number of breaks to be used.
 @since 10.2.4
 */
-(id)initWithClassificationField:(NSString *)classificationField
            classificationMethod:(AGSClassBreaksDefinitionClassificationMethod)classificationMethod
                      breakCount:(NSUInteger)breakCount;

/** Initialize a  AGSClassBreaksDefinition object with the given classification field, method,
 desired number of breaks and normalization method.
 @param classificationField field used to classify the data.
 @param classificationMethod method used to classify the data.
 @param breakCount number of breaks to be used.
 @param normalizationType defines how to normalize the data.
 @since 10.2.4
 */
-(id)initWithClassificationField:(NSString *)classificationField
            classificationMethod:(AGSClassBreaksDefinitionClassificationMethod)classificationMethod
                      breakCount:(NSUInteger)breakCount
               normalizationType:(AGSClassBreaksDefinitionNormalizationType)normalizationType;

/** Initialize a  AGSClassBreaksDefinition object with classification by standard deviation
 with the given classification field, and standard deviation interval.
 @param classificationField field used to classify the data.
 @param standardDeviationInterval the standard deviation interval.
 @since 10.2.4
 */
-(id)initWithClassificationField:(NSString *)classificationField
       standardDeviationInterval:(CGFloat)standardDeviationInterval;

/** Initialize a  AGSClassBreaksDefinition object with the given classification field and method,
 desired number of breaks and normalizing by a given field.
 @param classificationField field used to classify the data.
 @param classificationMethod method used to classify the data.
 @param breakCount number of breaks to be used.
 @param normalizationField field used to normalize the data.
 @since 10.2.4
 */
-(id)initWithClassificationField:(NSString *)classificationField
            classificationMethod:(AGSClassBreaksDefinitionClassificationMethod)classificationMethod
                      breakCount:(NSUInteger)breakCount
              normalizationField:(NSString *)normalizationField;

/** Create a new  AGSClassBreaksDefinition with the given classification field, method
 and desired number of breaks.
 @param classificationField field used to classify the data.
 @param classificationMethod method used to classify the data.
 @param breakCount number of breaks to be used.
 @return A new class breaks definition.
 @since 10.2.4
 */
+(id)classBreaksDefinitionWithClassificationField:(NSString *)classificationField
                             classificationMethod:(AGSClassBreaksDefinitionClassificationMethod)classificationMethod
                                       breakCount:(NSUInteger)breakCount;

/** Create a new  AGSClassBreaksDefinition object with the given classification field, method,
 desired number of breaks and normalization method.
 @param classificationField field used to classify the data.
 @param classificationMethod method used to classify the data.
 @param breakCount number of breaks to be used.
 @param normalizationType defines how to normalize the data.
 @return A new class breaks definition.
 @since 10.2.4
 */
+(id)classBreaksDefinitionWithClassificationField:(NSString *)classificationField
                             classificationMethod:(AGSClassBreaksDefinitionClassificationMethod)classificationMethod
                                       breakCount:(NSUInteger)breakCount
                                normalizationType:(AGSClassBreaksDefinitionNormalizationType)normalizationType;

/** Create a new  AGSClassBreaksDefinition object with classification by standard deviation
 with the given classification field, and standard deviation interval.
 @param classificationField field used to classify the data.
 @param standardDeviationInterval the standard deviation interval.
 @return A new class breaks definition.
 @since 10.2.4
 */
+(id)classBreaksDefinitionWithClassificationField:(NSString *)classificationField
                        standardDeviationInterval:(CGFloat)standardDeviationInterval;

/** Create a new  AGSClassBreaksDefinition object with the given classification field and method,
 desired number of breaks and normalizing by a given field.
 @param classificationField field used to classify the data.
 @param classificationMethod method used to classify the data.
 @param breakCount number of breaks to be used.
 @param normalizationField field used to normalize the data.
 @return A new class breaks definition.
 @since 10.2.4
 */
+(id)classBreaksDefinitionWithClassificationField:(NSString *)classificationField
                             classificationMethod:(AGSClassBreaksDefinitionClassificationMethod)classificationMethod
                                       breakCount:(NSUInteger)breakCount
                               normalizationField:(NSString *)normalizationField;

@end
