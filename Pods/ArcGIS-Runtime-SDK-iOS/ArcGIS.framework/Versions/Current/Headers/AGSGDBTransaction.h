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

@class AGSGDBGeodatabase;
@class AGSEditResult;

/** @file AGSGDBTransaction.h */ //Required for Globals API doc

/**  A transaction for a local geodatabase.
 
 
 */
@interface AGSGDBTransaction : NSObject

/** Create and start a transaction object for a local geodatabase.  Multiple transaction objects can be created for a single
 geodatabase, but second and subsequent transactions are 'nested' in previous transactions.  See  commit:
 and  abort: for more information.
 @param geodatabase to use for the transaction
 @return A handle to the transaction object
 @since 10.2
 */
+(instancetype)startTransactionForGeodatabase:(AGSGDBGeodatabase*)gdb;

/** Commit the changes to the geodatabase.  The changes will still need to be applied to the server.
 See  AGSGDBSyncTask for information on syncing geodatabase changes.  Once you commit a transaction, you can no
 longer use that transaction and must create another if you want to continue using transaction-based edits.
 
 A note about mutliple transactions for a single geodatabase: commiting changes in a transaction will commit
 changes in any transactions created after the current transaction.
 @param error Returned if an error is encountered during the commit.  Only valid if the return result = NO.
 @return Value indicating whether or not the commit succeeded.
 @since 10.2
 */
-(BOOL)commit:(NSError **)error;

/** Abort and discard the changes to the geodatabase.  The changes will be removed and can no longer be
 applied to the server.  Once you abort a transaction, you can no longer use that transaction and must
 create another if you want to continue using transaction-based edits.
 
 A note about mutliple transactions for a single geodatabase: aborting changes in a transaction will abort
 changes in any transactions created after the current transaction.
 @param error Returned if an error is encountered during the commit.  Only valid if the return result = NO.
 @return Value indicating whether or not the abort succeeded.
 @since 10.2
 */
-(BOOL)abort:(NSError **)error;

@end
