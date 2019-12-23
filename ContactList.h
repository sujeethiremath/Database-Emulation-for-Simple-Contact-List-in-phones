	#ifndef CONTACTLIST_H_
		#define CONTACTLIST_H_

		#include<map>
		#include<fstream>
		#include<iostream>
		#include "string_tools.h"
		#include "Contact.h"
		#include <functional> 
		#include<set>
		#pragma GCC diagnostic ignored "-Wdeprecated"
		//#include "NotFoundException.cpp" 
		#include "Database.h"

		using namespace std;



		class ContactList : public Database<Contact,string>
		{
			private:
			vector<Contact> Record;
			multimap<string, unsigned> Index;

			public:
			 bool isEmpty() const;
			 unsigned getSize() const;
			 bool add( const Contact& newData );
			 bool remove( const string& aKey );
			 bool removeAll( const string& aKey );
			 void clear();
			 set<Contact> getEntry( const string& aKey ) const throw(NotFoundException);
			 bool contains( const string& aKey ) const;
			 void displayDatabase() const;
			 void getFinal(string filename);
			 ~ContactList(){	}


		};
		//#include "ContactList.cpp"
	#endif
