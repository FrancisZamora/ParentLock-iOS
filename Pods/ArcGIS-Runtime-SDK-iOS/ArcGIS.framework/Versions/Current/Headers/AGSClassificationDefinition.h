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
@class AGSSymbol;
@class AGSColorRamp;

/** @file AGSClassificationDefinition.h */ //Required for Globals API doc

/** Create an <code>%AGSClassificationDefinition</code> object from JSON representation
 @param json The JSON representation of the classification definition to create.
 @since 10.2.4
 */
AGS_EXTERN AGSClassificationDefinition *AGSClassificationDefinitionWithJSON(NSDictionary *json);

#pragma mark -

/**  A base class for classification definitions.
 
 Instances of this class represent classification definitions used when requesting renderers
 from dynamic map services. This class provides a means of setting base symbols and color ramps
 to use in the requested renderer. Note that both the color ramp and base symbol are optional.
 If not specified, the service will use default values for both when generating the renderer.
 
 @since 10.2.4
 */
@interface AGSClassificationDefinition : NSObject <AGSCoding>

/** The base symbol that the requested renderer will base its symbols on.
 @since 10.2.4
 */
@property (nonatomic, strong) AGSSymbol *baseSymbol;

/** The color ramp that the requested renderer will use to set the symbol colors.
 @since 10.2.4
 */
@property (nonatomic, strong) AGSColorRamp *colorRamp;

@end
