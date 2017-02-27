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

/** @file AGSDevice.h */ //Required for Globals API doc

/*
 The return values will be as follows:
 iPhone Simulator   == i386
 iPhone             == iPhone1,1
 3G iPhone          == iPhone1,2
 3GS iPhone         == iPhone2,1
 iPhone 4           == iPhone3,1 or iPhone3,3
 iPhone 4s          == iPhone4,1
 iPhone 5 and 5c    == iPhone5,1 or iPhone5,2 (iPhone5,*)
 iPhone 5S          == iPhone6,
 1st Gen iPod       == iPod1,1
 2nd Gen iPod       == iPod2,1
 3rd Gen iPod       == iPod3,1
 4th Gen iPod       == iPod4,1
 5th Gen iPod       == iPod5,1
 1st Gen iPad       == iPad1,1
 2nd Gen iPad       == iPad2,1 iPad2,2 iPad2,3 iPad2,4
 3rd Gen iPad       == iPad3,1 iPad3,2 iPad3,3
 4th Gen iPad       == iPad3,4 iPad3,5 iPad3,6
 iPad Air           == iPad4,1 iPad4,2
 iPad Mini          == iPad2,5 iPad2,6 iPad2,7
 iPad Mini 2nd Gen  == iPad4,4 iPad4,5
 */

/** List of supported devices.
 @since 10.1.1
 */
typedef NS_ENUM(NSInteger, AGSDeviceMachineType) {
	AGSDeviceMachineTypeUnknown = 0,		/*!< */
	AGSDeviceMachineTypeiPhoneSimulator,	/*!< */
	AGSDeviceMachineTypeiPhone,				/*!< */
	AGSDeviceMachineTypeiPhone3G,			/*!< */
	AGSDeviceMachineTypeiPhone3GS,			/*!< */
	AGSDeviceMachineTypeiPhone4,			/*!< */
    AGSDeviceMachineTypeiPhone5,			/*!< */
    AGSDeviceMachineTypeiPhone5C,			/*!< */
	AGSDeviceMachineTypeiPhone5S,			/*!< */
	AGSDeviceMachineTypeiPhone6,			/*!< */
	AGSDeviceMachineTypeiPhone6Plus,		/*!< */
	AGSDeviceMachineTypeiPod1stGen,			/*!< */
	AGSDeviceMachineTypeiPod2ndGen,			/*!< */
	AGSDeviceMachineTypeiPod3rdGen,			/*!< */
	AGSDeviceMachineTypeiPod4thGen,			/*!< */
    AGSDeviceMachineTypeiPod5thGen,			/*!< */
	AGSDeviceMachineTypeiPad1stGen,			/*!< */
	AGSDeviceMachineTypeiPad2ndGen,			/*!< */
    AGSDeviceMachineTypeiPhone4S,			/*!< */
	AGSDeviceMachineTypeiPad3rdGen,			/*!< */
    AGSDeviceMachineTypeiPad4thGen,			/*!< */
    AGSDeviceMachineTypeiPadAir,			/*!< */
    AGSDeviceMachineTypeiPadAir2ndGen,		/*!< */
    AGSDeviceMachineTypeiPadMini,			/*!< */
    AGSDeviceMachineTypeiPadMini2ndGen,		/*!< */
    AGSDeviceMachineTypeiPadMini3rdGen,		/*!< */
    AGSDeviceMachineTypeMac,                /*!< */
} ;


/**  An object to assist with device specific properties.
 
 Object to assist with determining the device we are running on.
 @since 10.1.1
 */
@interface AGSDevice : NSObject

/** The current device.
 @since 10.1.1
 */
+ (AGSDevice*)currentDevice;

/** A string representing the system version.
 @since 10.1.1
 */
- (NSString*)systemVersion;

/** Method to return a string corresponding to a device .
 @since 10.1.1
 */
-(NSString *)machine;

/** Method to return the type of device that is currently running.
 @since 10.1.1
 */
-(AGSDeviceMachineType)machineType;

/** Method to return whether or not the device is an iPad.
 True for any iPad, mini or not.
 @since 10.1.1
 */
-(BOOL)isIPad;

/** True if the device is recognized as an iPad mini.
 @since 10.2.2
 */
-(BOOL)isIPadMini;

/** True if the device is recognized as an iPhone 6.
 @since 10.2.4
 */
-(BOOL)isIPhone6;

/** True if the device is recognized as an iPhone 6 Plus.
 @since 10.2.4
 */
-(BOOL)isIPhone6Plus;

/** Returns whether or not the iOS version is at least 4.0.
 @since 10.1.1
 */
-(BOOL)isAtLeastiOS4;

/** Returns whether or not the iOS version is at least 5.0.
 @since 10.1.1
 */
-(BOOL)isAtLeastiOS5;

/** Returns whether or not the iOS version is at least 6.0.
 @since 10.1.1
 */
-(BOOL)isAtLeastiOS6;

/** Returns whether or not the iOS version is at least 7.0.
@since 10.2.4
 */
-(BOOL)isAtLeastiOS7;

/** Returns whether or not the iOS version is at least 8.0.
 @since 10.2.4
 */
-(BOOL)isAtLeastiOS8;

/** Returns whether or not the device is a Mac.
 @since 10.1.1
 */
- (BOOL)isMac;

/** Method to return the points per inch that should be used for a given device.
 @since 10.1.1
 */
-(int)ppi;


@end




