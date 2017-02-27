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

/**  Result from a suggest operation on  AGSLocator
 
 Instances of this class represent individual results returned by  [AGSLocator suggestionsWithParameters:] operation.
 
 @since newAPI
 */

@interface AGSLocatorSuggestionResult : NSObject <AGSCoding>

/**
 The suggestion text, which can be used to populate a list of suggestions as a user enters characters in a search text box. It can also be included with magicKey in a Find operation to quickly retrieve a address/POI candidate.
 
 @since newAPI
 */
@property (nonatomic, copy) NSString *text;

/**
 Indicates if the suggestion item represents a collection of places, as opposed to a specific place.
 
 If isCollection = True for a suggestion item, it means that the item represents a search term for a common place name or POI category; suggestion items such as "Starbucks", "McDonald's", "Gas Station", and "Airport" will have isCollection = true.
 
 If isCollection = False then the suggestion item represents a specific place name or address; suggestion items such as "Disneyland" or "380 New York St, Redlands, CA" will have isCollection = false.
 
 This flag can be used by application developers to apply different behavior to cases where isCollection = True versus cases where isCollection = False.
 
 @since newAPI
 */
@property (nonatomic, assign) BOOL isCollection;

@end
