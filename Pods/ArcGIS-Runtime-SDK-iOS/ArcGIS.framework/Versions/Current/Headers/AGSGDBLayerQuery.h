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

/** @file AGSGDBLayerQuery.h */ //Required for Globals API doc

/**  Parameters to download a sync-enabled geodatabase
 
  In addition to the  [AGSGDBGenerateParameters layerIDs] and  [AGSGDBGenerateParameters extent] parameters, parameters on this class can be used to further define what is included in the sync-enabled geodatabase for each layer or table.
 
  
 */
@interface AGSGDBLayerQuery : NSObject <NSCoding>

/** ID of the layer to which these parameters apply
 @since 10.2
 */
@property (nonatomic, assign) NSUInteger layerID;

/*
 where: Defines an attribute query for a layer or table. The default is no where clause.
 useGeometry: Determines whether or not to apply the geometry for the layer. The default is true. If set to false, features from the layer that intersect the geometry are not added.
 includeRelated: Determines whether or not to add related rows. The default is true. Value true is honored only for queryOption = none. This is only applicable if your data has relationship classes.
 queryOption: Defines whether and how filters will be applied to a layer. The queryOption is new at 10.2. See the compatibility notes topic for more information.
 Values: <none | useFilter | all>
 When the value is none, no features are returned based on where and filter geometry. If includeRelated is false, no features are returned. If includeRelated is true, features in this layer (that are related to the features in other layers in the geodatabase) are returned.
 When the value is useFilter, features that satisfy filtering based on geometry and where are retuned. Value of includeRelated is ignored.
 When the value is all, all the features from the layer are returned. All other parameters for the layer query are ignored.
 Syntax: layerQueries={ Layer_or_tableID1 : {"where":"attribute query" , "useGeometry" : true | false, "includeRelated" : true | false}, Layer_or_tableID2: {.}}
 Examples:
 layerQueries={"1":{"useGeometry " : false}}
 layerQueries={"0":{"where" : "requires_inspection = True" }, "1":{"useGeometry " : false}}
 layerQueries={"0":{"useGeometry " : false, "includeRelated" : false}}, "1":{"useGeometry " : false}}
 */

/** An attribute query to specify which features should be included.
 Can be nil, in which case, features are not filtered based on the where clause.
 @since 10.2
 @deprecated Deprecated at 10.2.4. Please use  [AGSGDBLayerQuery whereClause] instead.
 */
@property (nonatomic, copy) NSString *where __attribute__((deprecated));

/** An attribute query to specify which features should be included.
 Can be nil, in which case, features are not filtered based on the where clause.
 @since 10.2.4
 */
@property (nonatomic, copy) NSString *whereClause;

/** Determines whether or not to filter features based on geometry. Defaults to YES, and only features that intersect
  [AGSGDBGenerateParameters extent] are considered for inclusion.
 @since 10.2
 */
@property (nonatomic, assign) BOOL useGeometry;

/** Specifies whether to include any data from this layer that is related to data in other layers in the geodatabase.
 This parameters is only valid if the data has relationships and if  option is set to AGSGDBQueryOptionNone.
 @since 10.2
 */
@property (nonatomic, assign) BOOL includeRelated;

/** Specifies how features should be included in the sync-enabled geodatabase.
 @since 10.2
 */
@property (nonatomic, assign) AGSGDBQueryOption option;

@end
