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

@class AGSLayer;
@class AGSQuery;
@class AGSSymbol;
@class AGSFeatureTable;
@class AGSRenderer;
@protocol AGSGDBFeatureSourceInfo;
@protocol AGSInfoTemplateDelegate;
@protocol AGSFeature;

/**  A layer that can display features from local datasets
 
 Instances of this class represent layers that can display features from a local dataset on a map.
 The local dataset is typically accessed through instances of  AGSFeatureTable
 
 @see  AGSFeatureTable to access the local dataset
 
 @since 10.2
 */
@interface AGSFeatureTableLayer : AGSLayer <AGSHitTestable, AGSLayerCalloutDelegate>

/** Initialize the layer with the given  AGSFeatureTable
 @param table The backing dataset whose features need to be drawn on the map by this layer.
 @since 10.2
 */
-(id)initWithFeatureTable:(AGSFeatureTable*)table;

/** The backing dataset whose features are drawn on the map by this layer.
 @since 10.2
*/
@property (nonatomic, strong, readonly) AGSFeatureTable *table;

/** Indicates whether features should be displayed with labels on the map.
 @since 10.2
 */
@property (nonatomic, assign, readwrite) BOOL showLabels;

/** Property that determines if the layer allows it to be hit tested or if it is bypassed.
 @since 10.2
 */
@property (nonatomic, assign) BOOL allowHitTest;

/** Property that determines if the layer allows callouts to be shown for its features.
 @since 10.2
 */
@property (nonatomic, assign) BOOL allowCallout;

/** The symbol to use for drawing selected features
 @since 10.2
 */
@property (nonatomic, strong, readwrite) AGSSymbol *selectionSymbol;

/** The color to use for drawing a halo around selected features
 @since 10.2
 */
@property (nonatomic, copy) AGSColor *selectionColor;

/** Delegate that allows the layer to react to when a callout is shown for one of it's features.
 @since 10.2
 */
@property (nonatomic, weak) id<AGSLayerCalloutDelegate> calloutDelegate;

/**  AGSRenderer assigned to the layer. It is responsible for symbolizing the
 features.
 @since 10.2.2
 */
@property (nonatomic, strong, readwrite) AGSRenderer *renderer;

/** Sets a definition expression. A definition expression limits the features displayed by this layer based on some a SQL query.
 @since 10.2.5
 */
@property (nonatomic, copy, readwrite) NSString *definitionExpression;

/** Selects or un-selects the feature.
 Features with selection enabled will be drawn using selectionSymbol.
 If selectionSymbol is not specified, then selectionColor will be used to draw a halo around the feature.
 @param selected If YES, feature will be selected. Else it will be un-selected
 @param feature
 @since 10.2
 */
-(void)setSelected:(BOOL)selected forFeature:(id<AGSFeature>)feature;

/** Returns whether a given feature is selected or not.
 Features with selection enabled will be drawn using selectionSymbol.
 If selectionSymbol is not specified, then selectionColor will be used to draw a halo around the feature.
 @param feature
 @since 10.2
 */
-(BOOL)isFeatureSelected:(id<AGSFeature>)feature;

/** Clears selection on all features
 @since 10.2
 */
-(void)clearSelection;

/** An array of  AGSGDBFeature objects representing features that have selection enabled
 Features with selection enabled will be drawn using selectionSymbol.
 If selectionSymbol is not specified, then selectionColor will be used to draw a halo around the feature.
 @since 10.2
 */
-(NSArray*)selectedFeatures;

/** Sets the visibility of the feature.
 @param visible If YES, the feature will be visible at the appopriate map scale and extent.  Else it will be hidden.
 @param feature whose visibility needs to be changed
 @since 10.2.2
 */
-(void)setVisible:(BOOL)visible forFeature:(id<AGSFeature>)feature;

/** Returns whether a given feature is visible.
 @param feature
 @since 10.2.2
 */
-(BOOL)isFeatureVisible:(id<AGSFeature>)feature;

@end
