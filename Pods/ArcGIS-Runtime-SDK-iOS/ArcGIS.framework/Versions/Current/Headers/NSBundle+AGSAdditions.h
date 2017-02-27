/*
 COPYRIGHT 2010 ESRI
 
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

@class AGSImage;

AGS_EXTERN NSString* AGSLocalizedString(NSString* key, NSString* comment);
AGS_EXTERN NSBundle* AGSBundle();

@interface NSBundle (AGSAdditions)

/**
 This is helpful, especially for Mac OS X, where there is a bug in retrieving 
 images from a bundle that is not the main bundle with imageForResource:. It is
 always returning the 2x image even on a non-retina display when retrieving
 images from a bundle that is not the main bundle.
 @since 10.2
 */
-(AGSImage*)ags_imageForResource:(NSString*)resource ofType:(NSString*)type;

@end