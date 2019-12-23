	#include "ContactList.h"
	
		/** Tests whether this database is empty.
				@return True if the database is empty, or false if not. */
	bool ContactList :: isEmpty() const {
		return Index.empty();
	}

	/** Determines the number of entries (records) in the database.
	        @return The number of entries/records in the database. */
	unsigned ContactList :: getSize() const {
		return Index.size();
	}

	/** Adds a new record into the database.
	        @param newData  The new record to add to the database.
	        @post  The database contains the new record.
	        @return  True if the addition is successful, or false if not. */
	bool ContactList :: add( const Contact& newData )
	{
		unsigned position = Record.size();
		string lastName = newData.getLastName();
		Index.insert(pair<string,unsigned >(lastName,position));
		Record.push_back(newData);
		return true;
	}

	/** Removes the record with the given key from this database.
		    Returns false if duplicate records matching the key exist.
			Default format for aKey is the value of the key (based on index);
	        otherwise, two values may be provided, separated by commas,
	        to identify a particular record that matches the extended key
	        (done if there are duplicates).
	        @param aKey  The key of the record to remove from the database.
	        @return  True if the removal is successful, or false if not. */
	bool ContactList :: remove( const string& aKey )
	{
		unsigned count = 0;
		pair<multimap<string, unsigned>::iterator, multimap<string, unsigned>::iterator > ret;
		ret = Index.equal_range(aKey);
		for(multimap<string,unsigned>::iterator it=ret.first; it!=ret.second; ++it)
		{
			count++;
		}

		if(count == 1)
		{
			auto itx = Index.find(aKey);
			unsigned position = itx->second;
			unsigned lastElement = Record.size()-1;
			Contact ct = Record[lastElement];
			
			for(multimap<string, unsigned>::iterator fh = Index.begin() ;fh!=Index.end();++fh)
			{
				if(fh->second == lastElement)
				{
					Index.erase(fh);
					fh=Index.begin();
				}
			}
			Record[position] = ct;
			auto x = Record.begin();
			Index.erase(itx);
			Record.erase(x+lastElement);
			if(position!=lastElement)
			Index.insert(pair<string,unsigned>(ct.getLastName(),position));
			return true;
		}
		else
		return false;
	}

	/** Removes all record(s) with the given key from this database.
	        @param aKey  The key of the record(s) to remove from the database.
	        @return  True if the removal is successful, or false if not. */
	bool ContactList :: removeAll( const string& aKey )
	{

		for(multimap<string,unsigned>::iterator it=Index.begin(); it!=Index.end(); ++it)
		{
			if(it->first == aKey)
			{
				
				unsigned position = it->second;
				auto x = Record.begin();
				unsigned lastElement = Record.size()-1;
				Contact ct = Record[lastElement];
				Record[position] = ct;
				Index.erase(it);
				Record.erase(x+lastElement);
				for(auto fh = Index.begin() ;fh!=Index.end();++fh)
				{
					if(fh->second == lastElement)
					{
						Index.erase(fh);
						fh = Index.begin();
					}
				}
				if(position != lastElement)
				Index.insert(pair<string,unsigned>(ct.getLastName(),position));
				it = Index.begin();
			}
			
		}
		return true;
	}

	/** Removes all records from this database. */
	void ContactList :: clear()
	{
		Index.clear();
		Record.clear();

	}

	/** Gets an entry (or entries) with the matching key from this database.
	        @post  The desired entry/entries has been returned in a set, and the
	            database is unchanged. If no such entry was found, an exception
	            is thrown.
	        @param aKey  The key of the record to locate from the database.
	        @return  The set containing the entry (or entries) in the database
	            that matches the given search key.
	        @throw  NotFoundException if the given entry is not in the database. */
	set<Contact> ContactList :: getEntry( const string& aKey ) const throw(NotFoundException)
	{

		set<Contact> ct;
		pair<multimap<string, unsigned>::const_iterator, multimap<string, unsigned>::const_iterator > ret;
		ret = Index.equal_range(aKey);
		
		for(multimap<string,unsigned>::const_iterator it=ret.first; it!=ret.second; ++it)
		{
			unsigned position = it->second;
			ct.insert(Record[position]);
		}

		try{
			if(ct.empty()==false)
			return ct;
			else
			{
				int x=1;
				throw(x);
			}
		}
		catch(int x){
			string s="Not Found";
			NotFoundException NFE(s);
		}

		return ct;
		
	}

	/** Tests if an entry matching the given key occurs in this database.
	        @post  The database is unchanged.
	        @param aKey  The search key of the entry to find.
	        @return  True if the entry occurs in the database, or false if not. */
	bool ContactList :: contains( const string& aKey ) const
	{
		multimap<string,unsigned> :: const_iterator it = Index.find(aKey);
		if(it != Index.end())
		return true;
		else
		return false;
	}

	//diplays the database contents
	void ContactList :: displayDatabase() const 
	{
		cout<<"Showing contact list:"<<endl;
		for(auto itr = Index.begin(); itr!=Index.end();++itr)
		{
			unsigned position = itr->second;
			cout<<"  "<<Record[position].getFirstName()<<" ";
			cout<<Record[position].getLastName()<<", ";
			cout<<Record[position].getBirthMonth()<<"/"<<Record[position].getBirthDay()<<"/"<<Record[position].getBirthYear()<<endl;
		}
	}

	//wites the final vector contents to the file after performing all the operations
	void ContactList :: getFinal(string filename)
	{
		ofstream outputFile (filename);
				
		if(outputFile.is_open())
		{
			for(unsigned k = 0; k<Record.size();k++)
			{
				outputFile<<Record[k].getFirstName()<<","<<Record[k].getLastName()<<","<<Record[k].getBirthMonth()<<","<<Record[k].getBirthDay()<<","<<Record[k].getBirthYear()<<endl;
			}
			outputFile.close();
		}

	}
