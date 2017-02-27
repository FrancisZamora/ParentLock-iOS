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

@protocol AGSLocationDisplayDataSourceDelegate;

/** @file AGSLocationDisplayDataSource.h */ //Required for Globals API doc

/**  An abstract source of location updates
 
 Instances of this class represent datasources that provide location information.
 
 
 
 */

@protocol AGSLocationDisplayDataSource <NSObject>
/**
 The datasource conveys the most recent location information to this delegate.
 The delegate is typically an  AGSLocationDisplay. The framework will set this.
 If you implement a custom datasource, you must invoke appropriate methods on the 
 delegate to pass the location information.
 @since 10.1.1
 */
@property (nonatomic, weak) id<AGSLocationDisplayDataSourceDelegate> delegate;

/**
 Starts the datasource. The framework will call this method when   AGSLocationDisplay::startDataSource is invoked. You should not call this directly.
 @since 10.1.1
 */
-(void)start;

/**
 Stops the datasource. The framework will call this when  AGSLocationDisplay::stopDataSource is invoked. You should not call this directly.
 @since 10.1.1
 */
-(void)stop;

/** Indicates whether or not the datasource is started.
 @since 10.1.1
 */
@property (nonatomic, readonly, getter = isStarted) BOOL started;

/** Indicates any error that may have occurred on the datasource.
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) NSError *error;

@end
