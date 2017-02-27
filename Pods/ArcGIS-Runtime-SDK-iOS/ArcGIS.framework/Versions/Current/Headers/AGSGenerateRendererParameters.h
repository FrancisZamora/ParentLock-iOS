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

@class AGSClassificationDefinition;

/** @file AGSGenerateRendererParameters.h */ //Required for Globals API doc

/**  Parameters for a  AGSGenerateRendererTask
 
 Instances of this class represent parameters for  AGSGenerateRendererTask operation.
 
 @since 10.2.4
 */
@interface AGSGenerateRendererParameters : NSObject <AGSCoding>

/** The where clause to narrow the range of the data to be classified by the renderer.
 @since 10.2.4
 */
@property (nonatomic, copy) NSString *whereClause;

/** Denotes how the generate renderer task operation should group data along with
 providing optional base symbols and color ramps used when generating the renderer.
 @since 10.2.4
 */
@property (nonatomic, strong) AGSClassificationDefinition *classificationDefinition;

/** Initialize a  AGSGenerateRendererParameters with the given classification definition and where class.
 @param classificationDefinition the classification definition used to define the renderer.
 @param whereClause the where clause to narrow the range of the data to be classified by the renderer
 between the from color and the to color.
 @since 10.2.4
 */
-(id)initWithClassificationDefinition:(AGSClassificationDefinition *)classificationDefinition
                          whereClause:(NSString *)whereClause;

/** Create a new  AGSGenerateRendererParameters with the given classification definition and where class.
 @param classificationDefinition the classification definition used to define the renderer.
 @param whereClause the where clause to narrow the range of the data to be classified by the renderer
 between the from color and the to color.
 @return A new generate renderer parameters.
 @since 10.2.4
 */
+(id)generateRendererParametersWithClassificationDefinition:(AGSClassificationDefinition *)classificationDefinition
                                                whereClause:(NSString *)whereClause;

@end
