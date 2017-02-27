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

/**  Model object for representing one element in a legend.
 
 Model object for representing one element in a legend.
 In the hierarchical tree representing the legend, a LegendElement
 is a leaf component and does not contain additional nodes.
 The Title and Swatch are both optional.
 
 @since 10.2
 */

@interface AGSMapContentsLegendElement : NSObject {}

/**
 label associated with legend element
 @since 10.2
 */
@property (nonatomic, copy, readonly) NSString*       title;

/**
 An image associated with legend element. May be nil if
 only a title is appropriate
 @since 10.2
 */
@property (nonatomic, strong, readonly) AGSImage*      swatch;

@end
