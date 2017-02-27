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


/**  A convenience class to store and retrieve objects in the keychain.
 
 This class represents a generic keychain wrapper to store an object (or part of it) securely in the keychain.
 The object must implement  NSCoding. For example, you can store an  AGSCredential representing a user's identity 
 and retrieve it when the app is restarted so that the user does not have to log in again.
 
 
 @since 10.2
 */
@interface AGSKeychainItemWrapper : NSObject

/** Initialize the wrapper 
 @param identifier Must be unique, for example - com.acme.appname
 @param accessGroup  If you want the new keychain item to be shared among multiple applications, the value of this key must be the name of a keychain access group to which all of the programs that will share this item belong. Otherwise, nil.
 @since 10.2
*/
- (id)initWithIdentifier: (NSString *)identifier accessGroup:(NSString *) accessGroup;

/** Set an archivable object as the  kSecValueData in the keychain item.
 If the object is an  AGSCredential that is retrieved from the  AGSOAuthLoginViewController, ensure that the credential is fully setup 
 by connecting to a portal with it before invoking this method.
 @since 10.2
 */
- (void)setKeychainObject:(id<NSCoding>)obj;

/** Set an archivable object as the  kSecValueData in the keychain item.
 If the object is an  AGSCredential that is retrieved from the  AGSOAuthLoginViewController, ensure that the credential is fully setup
 by connecting to a portal with it before invoking this method.
 @param obj The archivable object to store in the keychain.
 @param error The error encountered while storing the item in the keychain. May be nil.
 @return Boolean indicating the success or failure storing item in the keychain.
 @since 10.2.3
 */
- (BOOL)setKeychainObject:(id<NSCoding>)obj error:(NSError**)error;

/** Retrieve the archivable object from the kSecValueData in the keychain item
 @since 10.2
 */
- (id<NSCoding>)keychainObject;

/** Initializes and resets the default generic keychain item data.
 @since 10.2
 */
- (void)reset;

@end
