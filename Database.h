// A simple database abstract class.


/**
 @file Database.h */

#ifndef DATABASE_
#define DATABASE_

#include <set>
using namespace std;

#include "NotFoundException.h"

template< class ItemType , class KeyType >
class Database
{
public:

    /** Tests whether this database is empty.
        @return True if the database is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    /** Determines the number of entries (records) in the database.
        @return The number of entries/records in the database. */
    virtual unsigned getSize() const = 0;

    /** Adds a new record into the database.
        @param newData  The new record to add to the database.
        @post  The database contains the new record.
        @return  True if the addition is successful, or false if not. */
    virtual bool add( const ItemType& newData ) = 0;

    /** Removes the record with the given key from this database.
	    Returns false if duplicate records matching the key exist.
		Default format for aKey is the value of the key (based on index);
        otherwise, two values may be provided, separated by commas,
        to identify a particular record that matches the extended key
        (done if there are duplicates).
        @param aKey  The key of the record to remove from the database.
        @return  True if the removal is successful, or false if not. */
    virtual bool remove( const KeyType& aKey ) = 0;

    /** Removes all record(s) with the given key from this database.
        @param aKey  The key of the record(s) to remove from the database.
        @return  True if the removal is successful, or false if not. */
    virtual bool removeAll( const KeyType& aKey ) = 0;

    /** Removes all records from this database. */
    virtual void clear() = 0;

    /** Gets an entry (or entries) with the matching key from this database.
        @post  The desired entry/entries has been returned in a set, and the
            database is unchanged. If no such entry was found, an exception
            is thrown.
        @param aKey  The key of the record to locate from the database.
        @return  The set containing the entry (or entries) in the database
            that matches the given search key.
        @throw  NotFoundException if the given entry is not in the database. */
    virtual set<ItemType> getEntry( const KeyType& aKey ) const
        throw(NotFoundException) = 0;

    /** Tests if an entry matching the given key occurs in this database.
        @post  The database is unchanged.
        @param aKey  The search key of the entry to find.
        @return  True if the entry occurs in the database, or false if not. */
    virtual bool contains( const KeyType& aKey ) const = 0;

    /** Destroys object and frees memory allocated by object. */
    virtual ~Database() {  }

}; // end Database
#endif
