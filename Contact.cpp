	#include "Contact.h"

	//constructor to add data to contact object
	Contact :: Contact(string f_name, string l_name, unsigned b_month, unsigned b_day, unsigned b_year)
	{
		first_name = f_name;
		last_name = l_name;
		birth_month = b_month;
		birth_day = b_day;
		birth_year = b_year;
	}


	//returns first name
	string Contact :: getFirstName() const
	{
		return first_name;
	}

	//returns last name	
	string Contact :: getLastName() const
	{
		return last_name;
	}

	//returns birth month	
	unsigned Contact :: getBirthMonth() const
	{
		return birth_month;
	}

	//returns birth day	
	unsigned Contact :: getBirthDay() const
	{
		return birth_day;
	}

	//return birth year	
	unsigned Contact :: getBirthYear() const
	{
		return birth_year;
	}

	//overloaded less than operator for set container of contact objects
	bool Contact :: operator<( const Contact& C2) const
	{
		return getFirstName() <  C2.getFirstName();		
	}
	