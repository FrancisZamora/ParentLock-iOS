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

/** @file AGSLayerCalloutDelegate.h */ //Required for Globals API doc


@protocol AGSFeature;
@protocol AGSHitTestable;
@class AGSCallout;
@class AGSLayer;
@class AGSPoint;

/**  Delegate to display callouts for a layer's features
 
 A protocol which must be adopted by any class wishing to control the display of callouts for a layer's features. An instance of the class must then be assigned to  [AGSHitTestable calloutDelegate]
 
 @see AGSCalloutDelegate
 
 */
@protocol AGSLayerCalloutDelegate <NSObject>

/** This method is called when a user taps on some features in a layer. Delegates should implement this method when they want to configure how a callout looks for a particular feature in a particular layer.
 Some properties delegates may want to configure are title, detail, image, customView, etc. The delegate should return YES for the callout to be shown. The delegate can return NO for those features for which a callout should not be shown. If this method is not implemented,  [AGSCallout delegate] will be consulted instead.
 
 @param callout The callout that will show.
 @param feature The feature to display the callout for.
 @param layer The layer the feature belongs to.
 @param mapPoint The coordinates at which the graphic callout will be displayed.
 @return Value indicating whether or not the callout should actually show. 
 @since 10.2
 */
-(BOOL)callout:(AGSCallout*)callout willShowForFeature:(id<AGSFeature>)feature layer:(AGSLayer<AGSHitTestable>*)layer mapPoint:(AGSPoint *)mapPoint;

@end
