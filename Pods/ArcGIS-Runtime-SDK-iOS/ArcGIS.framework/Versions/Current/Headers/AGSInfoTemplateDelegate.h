/*
 COPYRIGHT 2009 ESRI
 
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

@protocol AGSFeature;
@class AGSGraphic;
@class AGSPoint;

/** @file AGSInfoTemplateDelegate.h */ //Required for Globals API doc

/**  A template describing the contents of  AGSCallout for a graphic.
 
 A protocol which must be adopted by any class wishing to display content for an 
  AGSGraphic in the callout window. An instance of the class must then be set as the 
 @p infoTemplateDelegate on the graphic.
 
 The methods are optional. If the custom view method is implemented and does not return nil,
 then the other methods will not be called. This is because if a custom view is displayed
 in the callout then it is the only content in the callout. 
 
 
 @deprecated Deprecated at 10.2. Use  AGSCalloutDelegate or  AGSLayerCalloutDelegate instead.
 @see AGSMapViewCalloutDelegate for events related to showing the callout.
 */
__attribute__((deprecated))
@protocol AGSInfoTemplateDelegate <NSObject>
@optional

/** Title text to be displayed in the callout.
 @param graphic The graphic to display a title for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @param mapPoint The coordinates at which the graphic callout will be displayed.
 @return The title text for the callout.
 @deprecated Deprecated at 10.2. Use  [AGSCalloutDelegate callout:willShowForFeature:layer:mapPoint:] or [AGSLayerCalloutDelegate callout:willShowForFeature:layer:mapPoint:] instead.
 @since 1.0
 */
- (NSString *)titleForGraphic:(AGSGraphic *)graphic screenPoint:(CGPoint)screen mapPoint:(AGSPoint *)mapPoint __attribute__((deprecated));

/** Detail string to be displayed in the callout.
 @param graphic The graphic to display detail for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @param mapPoint The coordinates at which the graphic callout will be displayed.
 @return The detail text for the callout.
 @deprecated Deprecated at 10.2. Use  [AGSCalloutDelegate callout:willShowForFeature:layer:mapPoint:] or [AGSLayerCalloutDelegate callout:willShowForFeature:layer:mapPoint:] instead.
 @since 1.0
 */
- (NSString *)detailForGraphic:(AGSGraphic *)graphic screenPoint:(CGPoint)screen mapPoint:(AGSPoint *)mapPoint __attribute__((deprecated));

#if TARGET_OS_IPHONE

/** Image to be displayed in the callout to the left of the text. The image will be scaled to
 40x40 points.
 @param graphic The graphic to display the image for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @param mapPoint The coordinates at which the graphic callout will be displayed.
 @return The image to be displayed in the callout.
 @deprecated Deprecated at 10.2. Use  [AGSCalloutDelegate callout:willShowForFeature:layer:mapPoint:] or [AGSLayerCalloutDelegate callout:willShowForFeature:layer:mapPoint:] instead.
 @since 1.8
 */
-(AGSImage*)imageForGraphic:(AGSGraphic *)graphic screenPoint:(CGPoint)screen mapPoint:(AGSPoint *)mapPoint __attribute__((deprecated));

/** The custom view to be displayed in the callout. If you implement this function then the title, detail
 and image methods will not get called, as only the custom view will be displayed in the callout. The callout will be expanded
 to the dimensions of the custom view.
 @param graphic The graphic to display the custom view for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @param mapPoint The coordinates at which the graphic callout will be displayed.
 @return The custom view to be displayed in the callout.
 @deprecated Deprecated at 10.2. Use  [AGSCalloutDelegate callout:willShowForFeature:layer:mapPoint:] or [AGSLayerCalloutDelegate callout:willShowForFeature:layer:mapPoint:] instead.
 @since 1.8
 */
-(AGSView*)customViewForGraphic:(AGSGraphic *)graphic screenPoint:(CGPoint)screen mapPoint:(AGSPoint *)mapPoint __attribute__((deprecated));

#endif

@end



