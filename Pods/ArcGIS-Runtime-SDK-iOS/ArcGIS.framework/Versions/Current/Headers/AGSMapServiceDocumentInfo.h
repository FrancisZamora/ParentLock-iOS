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

/** @file AGSMapServiceDocumentInfo.h */ //Required for Globals API doc

#pragma mark -

/**  Information about the backing document for an ArcGIS service.
 
 This class holds information about the map document used to 
 publish an ArcGIS service.
 
 
 */

@interface AGSMapServiceDocumentInfo : NSObject <AGSCoding>

/** The author of the map document
 @since 10.2
 */
@property (nonatomic, copy) NSString *author;

/** Category
 @since 10.2
 */
@property (nonatomic, copy) NSString *category;

/** Comments
 @since 10.2
 */
@property (nonatomic, copy) NSString *comments;

/** Credits
 @since 10.2
 */
@property (nonatomic, copy) NSString *credits;

/** Keywords
 @since 10.2
 */
@property (nonatomic, copy) NSArray *keywords;

/** Subject
 @since 10.2
 */
@property (nonatomic, copy) NSString *subject;

/** Title
 @since 10.2
 */
@property (nonatomic, copy) NSString *title;

@end
