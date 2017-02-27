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

/** @file AGSGDBEditErrors */ //Required for Globals API doc

/**  Edit errors encountered during sync.
 
 Instances of this class represent the set of errors that occurred while applying local edits to the
 remote service during a sync operation.
 
 
 @since 10.2.2
*/
@interface AGSGDBEditErrors : NSObject

/** An array of  AGSGDBFeatureEditError objects representing the errors related to any feature edits.
 @since 10.2.2
 */
@property (nonatomic, copy, readonly) NSArray *featureErrors;

/** An array of  AGSGDBFeatureEditError objects representing the errors related to any attachment edits.
 @since 10.2.2
 */
@property (nonatomic, copy, readonly) NSArray *attachmentErrors;

@end
