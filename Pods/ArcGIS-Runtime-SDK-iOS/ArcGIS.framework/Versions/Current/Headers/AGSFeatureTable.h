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

@class AGSField;
@class AGSQuery;
@class AGSSpatialReference;
@class AGSEnvelope;

/** @file AGSFeatureTable.h */ //Required for Globals API doc

/**  A dataset in a local storage
 
 This class represents an abstraction for a dataset in local storage (file, folder, database, etc).
 The dataset can contain geographic features or ordinary records that have no spatial information.
 You need to use an  AGSFeatureTableLayer to visualize the features on a map.

 @see  AGSGDBFeatureTable to access a dataset in a local *.geodatabase file
 
 */

@interface AGSFeatureTable : NSObject

/** Saves the specified feature to the table.
 If the feature is not yet in the table, this method will add it. If the feature is already in the table then
 this method will update it.
 @param feature to save.
 @param error if the operation encountered an error
 @return A boolean indicating succcess or failure
 @since 10.2.2
 */
-(BOOL)saveFeature:(id<AGSFeature>)feature error:(NSError**)error;

/** Deletes the specified feature in the dataset.
 @param feature to delete.
 @param error if the operation encountered an error
 @return A boolean indicating success or failure
 @since 10.2
 */
-(BOOL)deleteFeature:(id<AGSFeature>)feature error:(NSError**)error;

/**
 Indicates whether any edits have been made to the dataset.
 @since 10.2
 */
-(BOOL)hasLocalEdits;

/**
 Undo all edits made to the dataset.
 @since 10.2
 */
-(void)clearEdits;

/**
 Array of  AGSField objects representing the fields (columns) in the dataset.
 @since 10.2
 */
-(NSArray*)fields;

/**
 Get the field with specified name
 @param fieldName of the field
 @return field
 @since 10.2
 */
-(AGSField*)fieldWithName:(NSString*)fieldName;

/**
 Name of the dataset as defined in the storage medium.
 @since 10.2
 */
-(NSString*)tableName;

/**
 Indicates whether the dataset contains a geometry field (column).
 If YES, the dataset contains geographic features.
 If NO, the dataset contains records, similar to a database table.
 @since 10.2
 */
-(BOOL)hasGeometry;

/**
 Indicates whether the dataset can be edited.
 @since 10.2
 */
-(BOOL)isEditable;

/**
 The spatial reference of the dataset.
 @since 10.2.2
 */
-(AGSSpatialReference *)spatialReference;

/**
 The extent of the dataset.
 @since 10.2.2
 */
-(AGSEnvelope *)extent;

/**
 The total number of features in the dataset.
 @since 10.2.2
 */
-(NSUInteger)featureCount;

/**
 Query the dataset to find specific features or records.
 @param params representing the query criteria
 @param completion The block that is called when the query is complete, returning an array of results or an NSError if an error occured. The results are  id<AGSFeature> objects or, if statistics are requested, they are  NSDictionary objects.
 @since 10.2
 */
-(void)queryResultsWithParameters:(AGSQuery*)params completion:(void (^)(NSArray *results, NSError *error))completion;

@end
