/*
 COPYRIGHT 2012 ESRI
 
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

@protocol AGSInfoTemplateDelegate;
@protocol AGSHitTestable;
@protocol AGSLayerCalloutDelegate;
@class AGSCallout;

/** @file AGSCalloutTemplate.h */ //Required for Globals API doc

/**  A token-based  AGSInfoTemplate.
 
 Instances of this class represent a simple implementation of 
  AGSInfoTemplateDelegate. Tokens of the form <i>${...}</i> in the 
 [titleTemplate/ detailTemplate] are replaced at runtime with corresponding values 
 from the graphic's attributes. The final text is then displayed in the 
 callout.
 
 For example, consider a graphic which has an attribute <b>STATE_NAME</b> with 
 the value <b>California</b>. To display the attribute's value in the callout's 
 title, you need to set <i>${STATE_NAME}</i> as the @p titleTemplate. The token 
 <i>${STATE_NAME}</i> will then be automatically substituted with the value 
 <b>California</b> when the callout is displayed.
 
 @see AGSMapViewDelegate for events related to showing the callout.
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
@interface AGSCalloutTemplate : NSObject <AGSInfoTemplateDelegate, AGSLayerCalloutDelegate>
#pragma clang diagnostic pop

/** Template used to display the title in the callout.
 @since 1.0
 */
@property (nonatomic, copy) NSString *titleTemplate;

/** Template used to display the detail string in the callout.
 @since 1.0
 */
@property (nonatomic, copy) NSString *detailTemplate;

@end