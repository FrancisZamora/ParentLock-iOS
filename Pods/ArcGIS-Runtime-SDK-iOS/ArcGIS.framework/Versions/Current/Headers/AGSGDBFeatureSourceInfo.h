/*
 COPYRIGHT 2013 ESRI
 
 TRADE SECRETS: ESRI PROPRIETARY AND CONFIDENTIAL
 Unpublished material - all rights reserved under the
 Copyright Laws of the United States and applicable international
 laws, treaties, and conventions.
 
 For additional information, contact:j
 Environmental Systems Research Institute, Inc.
 Attn: Contracts and Legal Services Department
 380 New York Street
 Redlands, California, 92373
 USA
 
 email: contracts@esri.com
 */

/** @file AGSGDBFeatureSourceInfo.h */ //Required for Globals API doc

@class AGSRenderer;
@class AGSEditFieldsInfo;
@class AGSCredential;
@protocol AGSFeature;

/**  Information about a feature source
 
 Instances of this class respresent information about features sources such as a remote ArcGIS Feature or Map service layer, or a local geodatabase table. These sources ususally contain geographic features that can be displayed on a map, although sometimes, they may contain non-geographic records also.
 
 
 */
@protocol AGSGDBFeatureSourceInfo <NSObject>

/** The credential to be used to access the secured feature source.
@since 10.2
 */
@property (nonatomic, copy, readonly) AGSCredential *credential;

/** The geometry type of features contained in source.
 All features will have the same geometry type.
 Possible types include
 @li  AGSGeometryTypePoint
 @li  AGSGeometryTypePolyline
 @li  AGSGeometryTypePolygon
 
  AGSGeometryTypeMultipoint and  AGSGeometryTypeEnvelope types are not supported.
@since 10.2
 */
@property (nonatomic, readonly) AGSGeometryType geometryType; 

/** The primary display field of features. This field will contain information about the feature that is most relevant to a user.
@since 10.2
 */
@property (nonatomic, copy, readonly) NSString *displayField;

/** The fields available in the source as an
 array of  AGSField objects. The value of each field is available as feature attributes.
@since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *fields;

/** The name of field which contains the @em OBJECTID for each feature
@since 10.2
 @see objectIdForFeature: to conveniently get a feature's @em OBJECTID.
 */
@property (nonatomic, copy, readonly) NSString *objectIdField;

/** The name of the field which contains the sub-type information for each feature.
 @note This feature is only available for ArcGIS services v10.0 or greater.
@since 10.2
 */
@property (nonatomic, copy, readonly) NSString *typeIdField;

/** A collection of  AGSFeatureType objects representing feature sub-types. For example, a @em source representing roads may contain 2 feature sub-types : highways
 and streets.
 @note This feature is only available for ArcGIS services v10.0 or greater.
@since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *types;

/** A collection of  AGSFeatureTemplate objects representing feature templates. Usually only present if feature
 sub-types are unavialable.
@since 10.2
 */
@property (nonatomic, copy, readonly) NSArray *templates;

/** Metadata regarding which fields or attributes of a feature contain information
 about who created/edited the feature and when was it created/edited.
@since 10.2
 */
@property (nonatomic, strong, readonly) AGSEditFieldsInfo *editFieldsInfo;


/** If <code>YES</code>, features may have attachments.
@since 10.2
 */
@property (nonatomic, readonly, getter=hasAttachments) BOOL attachments;

/** If  YES, the source contains non-geographic data.
 @since 10.2
 */
@property (nonatomic, assign, readonly) BOOL isTableOnly;

/** Indicates whether the source allows new features to be created.
 You should check this property before allowing the ability to create a new feature in your app.
@since 10.2
 */
@property (nonatomic, assign, readonly) BOOL canCreate;

/** Indicates whether the source allows a feature to be updated.
 It is preferable to use canUpdateFeature: instead because this property
 does not take into account any ownership-based access control policies for the specific feature you are trying to edit.
 It only provides general information about whether the source is capable of allowing feature updates at all.
@since 10.2
 */
@property (nonatomic, assign, readonly) BOOL canUpdate;

/** Indicates whether the layer allows features to be deleted.
 It is preferable to use canDeleteFeature: instead because this property
 does not take into account any ownership-based access control policies for the specific feature you are trying to delete.
 It only provides general information about whether the layer is capable of allwoing feature deletions at all.
@since 10.2
 @see canDeleteFeature:
 */
@property (nonatomic, assign, readonly) BOOL canDelete;

/** Indicates whether the source allows geometries of features to be updated.
 You should check this property before allowing the ability to update a feature's geometry in your app.
@since 10.2
 */
@property (nonatomic, assign, readonly) BOOL canUpdateGeometry;

/** The version of the service backing the feature source.
 @since 10.2.5
 */
@property (nonatomic, assign, readonly) CGFloat version;

/** Indicates whether the data backing the source is versioned.
 @note This feature is only available for ArcGIS services v10.1 or greater.
 @since 10.2.5
 */
@property (nonatomic, assign, readonly) BOOL hasVersionedData;

/** Indicates whether the source allows updating this particular feature. The method first checks canUpdate to verify if the layer is capable of updating any features in general. It also checks ownership-based access control policies of the source to see if the  user specified in the credential has persmissions to edit this specific feature.
 You should check this property before allowing the ability to update this feature in your app.
 @param feature Can be nil, in which case, this method is the same as canUpdate
 @return A boolean value
@since 10.2
 */
- (BOOL)canUpdateFeature:(id<AGSFeature>)feature;

/** Indicates whether the source allows this particular feature to be delete. The method first checks canDelete to verify if the source is capable of deleting any features in general. It also checks ownership-based access control policies of the source to see if the  user specified in the credential has persmissions to delete this specific feature.
 @param feature Can be nil, in which case, this method is the same as canDelete
 @return A boolean value
@since 10.2
 */
- (BOOL)canDeleteFeature:(id<AGSFeature>)feature;

/** Returns a localized string representing the most recent activity on this feature.
 For example, <i>Created by John Doe 5 hours ago.</i>
@since 10.2
 */
- (NSString*)editSummaryForFeature:(id<AGSFeature>)feature;

/** A convenience method to get the @em OBJECTID for specified feature.
 @param feature The feature to get @em OBJECTID for.
 @return The @em OBJECTID for @p feature.
@since 10.2
 */
- (long long)objectIdForFeature:(id<AGSFeature>)feature;

/** The name of the layer as defined by the service.
@since 10.2.2
 */
@property (nonatomic, copy, readonly) NSString *serviceLayerName;

@end
