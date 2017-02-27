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

#import <Foundation/Foundation.h>

@class AGSLayerSource;

/** @file AGSLayerSource.h */ //Required for Globals API doc

/** Create an <code>%AGSLayerSource</code> object from JSON representation
 @param json The JSON representation of the layer source to create.
 @since 10.2.4
 */
AGS_EXTERN AGSLayerSource *AGSLayerSourceWithJSON(NSDictionary *json);

/**  A base class for layer source objects.
 
 There are two types of layer source objects:
 Dynamic map layer - refers to an existing map service layer. If supported
 use geodatabaseVersion to specify an alternate geodatabase version.
 
 Dynamic data layer - refers to an on-the-fly layer created off of data
 from a registered workspace. Depending on the type of data source these
 layers are classified as:
 
    Dynamic table data layer: sources data from a table data source
    Dynamic queryTable data layer: sources data from a queryTable data source
    Dynamic raster data layer: sources data from a raster data source
    Dynamic join data layer: sources data from a joinTable data source
 
 
 @since 10.2.4
 */
@interface AGSLayerSource : NSObject <AGSCoding>

@end
