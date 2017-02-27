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

@class AGSPopupInfo;
@class AGSLayer;
@class AGSFeatureLayer;

/** @file AGSWebMapSubLayerInfo.h */ //Required for Globals API doc

/**  Information about sub-layers of a top level layer in a webmap.
 
 Instances of this class represent sub-layers of a top level layer in a webmap.
 The sub-layers may be individual feature layers belonging to an AGSWebMapFeatureCollection, or they may be sub-layers of a map service layer.
 
 @since 2.2
 */
@interface AGSWebMapSubLayerInfo : NSObject <AGSCoding>

/** The id of the layer
 @since 2.2
 */
@property (nonatomic, assign, readwrite) NSUInteger layerId;

/** The popup definition of the layer
 @since 2.2
 */
@property (nonatomic, strong, readwrite) AGSPopupInfo *popupInfo;

/** JSON representation of an AGSFeatureSet containing the features to be displayed by the layer. Only applicable if the layer is part of an  AGSWebMapFeatureCollection.
 @since 2.2
 */
@property (nonatomic, copy, readwrite) NSDictionary *featureSet;

/** JSON representation of the layer's properties. Only applicable if the layer is part of an  AGSWebMapFeatureCollection. This is the JSON returned by a Map or Feature Service for one of its layers, for example, http://sampleserver3.arcgisonline.com/ArcGIS/rest/services/SanFrancisco/311Incidents/FeatureServer/0?f=pjson. 
 @since 2.2
 */
@property (nonatomic, copy, readwrite) NSDictionary *layerDefinition;

/** URL of the sub-layer's backing service. This can be used to query the layer for popups.
 @since 2.3
 */
@property (nonatomic, strong, readwrite) NSURL *layerURL; 

/**
 @since 2.3
 */
@property (nonatomic, assign, readwrite) BOOL showLegend;

/** The layer on the map (if any) that this is associated with.
 If this is non-nil then this AGSWebMapSubLayerInfo is a child of an AGSWebMapFeatureCollection.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSLayer *mapLayer;

/** The AGSFeatureLayer that is associated with this. In some cases
 this will be the same as the mapLayer. In those cases then this is a child of an AGSWebMapFeatureCollection.
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSFeatureLayer *backingFeatureLayer;

/** Name of the sub-layer.
 @since 10.2.4
 */
@property (nonatomic, copy, readwrite) NSString *name;

@end
