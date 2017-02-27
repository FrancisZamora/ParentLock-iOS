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


@class AGSLocation;
@class AGSGraphic;
@class AGSMapView;
@class AGSPoint;
@class AGSMarkerSymbol;
@class AGSSimpleFillSymbol;
@protocol AGSLocationDisplayDataSource;
@protocol AGSLocationDisplayDataSourceDelegate;
@protocol AGSLocationDisplayInfoTemplateDelegate;

/** @file AGSLocationDisplay.h */


/** Modes for automatically  panning the map in response to location updates
 @since 10.1.1
 */
typedef NS_ENUM(NSInteger, AGSLocationDisplayAutoPanMode) {
    AGSLocationDisplayAutoPanModeOff = 0,		/*!<  The map does not auto pan, and the location symbol may move off screen.*/
    AGSLocationDisplayAutoPanModeDefault,		/*!<  The map recenters on the location symbol whenever it moves out of the wander extent*/
    AGSLocationDisplayAutoPanModeNavigation,	/*!<  The location symbol is fixed and always points to the top edge of the device. The map pans and rotates based on location and course updates. */
	AGSLocationDisplayAutoPanModeCompassNavigation /*!< The location symbol is fixed and always points to the top edge of the device. The map pans and rotates based on location and heading (true) updates. */
} ;


/**  Provides a location display over an  AGSMapView.
 
 This object controls how the map displays location information. It relies on
 its dataSource which provides location updates on a frequent basis.
 
 To make the map start
 displaying location information, use the <code>startDataSource</code> method, but ensure the map is loaded successfully before you do..
 
 To make the map stop displaying location information, use the
 <code>stopDataSource</code> method.
 
 By default a blue, round symbol is used to display the device's location. The map will always try to get
 most accurate location available. Depending upon signal strength, satellite positions, and other factors, the location
 reported could be a best possible approximation. The map also displays a blue-circle around the location symbol to indicate the range of accuracy.
 As the device moves, the map will respond to location updates and appropriately udpate the position of the location symbol.
 
 If you wish to customize the symbol for the location display, add images named "LocationDisplay.png", "LocationDisplayCourse.png", and 
 "LocationDisplayHeading.png" as well as the corresponding @2x versions to your application's resources and the SDK will automatically pick them 
 up instead of the default blue images.
 
 @see oncept{map-gps.htm, Displaying %location on the map}
 @see 
 */
@interface AGSLocationDisplay : NSObject <AGSLocationDisplayDataSourceDelegate>

/** The source of location updates.
 Defaults to  AGSCLLocationManagerLocationDisplayDataSource.
 You can create your own datasource, or choose from one of the datasources provided.
 @since 10.1.1
 */
@property (nonatomic, strong) id<AGSLocationDisplayDataSource> dataSource;

/** Most recent location update provided by the datasource
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) AGSLocation *location;

/** Most recent error from the datasource. Will be nil'd out when/if a valid location is received from the datasource.
 @since 10.1.1
 */
@property (nonatomic, strong, readonly) NSError *dataSourceError;

/** Defines the map's auto-pan behavior when new location updates are recieved.
 Default is  AGSLocationDisplayAutoPanModeOff
 @since 10.1.1
 */
@property (nonatomic, assign) AGSLocationDisplayAutoPanMode autoPanMode;

/** The factor that is used to determine when the map recenters on the location. This is used only
 when autoPanMode is AGSLocationDisplayAutoPanModeDefault. The map automatically recenters when the location symbol moves outside the wander extent.  
 The default value for this property is 0.5. 
 The value expected is between 0 and 1. A value of 0.25 means that an extent 25% of the
 current extent is used as the "wander" extent.  A value of 1 means that the entire
 extent in view is used as the "wander" extent.
 @since 10.1.1
 */
@property (nonatomic, assign) CGFloat wanderExtentFactor;

/** Template describing how the callout should display information for location 
 updates.
 @since 10.1.1
 @deprecated Deprecated at 10.2. Please use  AGSCalloutDelegate instead.
 */
@property (nonatomic, weak) id<AGSLocationDisplayInfoTemplateDelegate> infoTemplateDelegate __attribute__((deprecated));

/** Scale that the AGSLocationDisplay will auto zoom to.
 The AGSLocationDisplay will only auto zoom when it receives it's first location after the autoPanMode goes from AGSLocationDisplayAutoPanModeOff
 to any other value.
 Defaults to 10,000.
 A value of 0 or less will tell the location display not to auto zoom at all.
 @since 10.1.1
 */
@property (nonatomic, assign) double zoomScale;

/** Indicates whether or not the display's datasource is started.
 @since 10.1.1
 */
@property (nonatomic, readonly, getter = isDataSourceStarted) BOOL dataSourceStarted;

#if TARGET_OS_IPHONE
/** The orientation of the interface. You must set this if you are using the compass
 navigation mode and your application user interface orientation is not portrait. This is 
 used for offsetting the compass heading based on the user interface orientation.
 @since 10.1.1
 */
@property (nonatomic, assign) UIInterfaceOrientation interfaceOrientation;
#endif

/** The current location the display is at on the map, projected into map coordinates.
 */
-(AGSPoint*)mapLocation;

/** Starts the location display's datasource.
 @since 10.1.1
 */
-(void) startDataSource;

/** Stops the location display's datasource.
 @since 10.1.1
 */
-(void) stopDataSource;

/** The height factor for placing the GPS location symbol when in navigation auto pan mode.
 The default is 0.125 (1/8th), which places it 1/8th of the height of the map view
 from the bottom of the map view.
 @since 2.1
 */
@property (nonatomic, assign) CGFloat navigationPointHeightFactor;

/** Sets an alpha on the location display.
 @since 10.1.1
 */
@property (nonatomic, assign) CGFloat alpha;

/** Sets whether or not the location display shows a 'ping' animation when a new location is received.
 @since 10.2
 */
@property (nonatomic, assign) BOOL showsPing;

/** Sets whether or not the location display shows a 'ping' animation when a new location is received.
 @since 10.2.2
 */
@property (nonatomic, assign) BOOL showsAccuracy;

/** The symbol that is used when the location display is not moving or doesn't have a course.
  @since 10.2.2
 */
@property (nonatomic, strong) AGSMarkerSymbol *defaultSymbol;

/** The symbol that is used when the location display has a velocity and course.
 @since 10.2.2
 */
@property (nonatomic, strong) AGSMarkerSymbol *courseSymbol;

/** The symbol that is used when the location display is in compass mode.
 @since 10.2.2
 */
@property (nonatomic, strong) AGSMarkerSymbol *headingSymbol;

/** The symbol that is used to signify that a location display received a location update.
 @since 10.2.2
 */
@property (nonatomic, strong) AGSMarkerSymbol *pingSymbol;

/** The symbol that is used to show the accuracy of the location.
 @since 10.2.2
 */
@property (nonatomic, strong) AGSSimpleFillSymbol *accuracySymbol;

@end


/**  A template describing the contents of  AGSCallout for a location display. 
 
 A protocol which must be adopted by any class wishing to display content in the
 callout window for the location display . An instance of the class must then be 
 set as the <code>infoTemplateDelegate</code> on the map's location display object.
 
 The methods are optional. If the custom view method is implemented and does not return nil,
 then the other methods will not be called. This is because if a custom view is displayed
 in the callout then it is the only content in the callout.
 
 @since 10.1.1
 @deprecated Deprecated at 10.2. Please use  AGSCalloutDelegate instead.
 */
__attribute__((deprecated))
@protocol AGSLocationDisplayInfoTemplateDelegate <NSObject> 
@optional

/** Title text to be displayed in the callout.
 @param ld The location display to display title for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @return The title text.
 @since 10.1.1
 */
- (NSString *)titleForLocationDisplay:(AGSLocationDisplay *)ld screenPoint:(CGPoint)screen;

/** Detail string to be displayed in the callout.
 @param ld The location display to display detail for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @return The detail string.
 @since 10.1.1
 */
- (NSString *)detailForLocationDisplay:(AGSLocationDisplay *)ld screenPoint:(CGPoint)screen;

#if TARGET_OS_IPHONE

/** Image to be displayed in the callout. The image will be scaled to 40x40 points.
 @param ld The location display to display image for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @return The image to be displayed in the callout.
 @since 10.1.1
 */
-(AGSImage*)imageForLocationDisplay:(AGSLocationDisplay *)ld screenPoint:(CGPoint)screen;

/** The custom view to be displayed in the callout. If you implement this function then the title, detail
 and image methods will not get called, as only the custom view will be displayed in the callout.
 The callout will expand to fit the dimensions of the custom view.
 @param ld The location display to display the custom view for.
 @param screen The coordinates at which the graphic callout will be displayed.
 @return The custom view to be displayed in the callout.
 @since 10.1.1
 */
-(AGSView*)customViewForLocationDisplay:(AGSLocationDisplay *)ld screenPoint:(CGPoint)screen;

#endif

@end
