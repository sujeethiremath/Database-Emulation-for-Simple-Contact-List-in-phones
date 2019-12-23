	#ifndef CONTACT_H_
		#define CONTACT_H_

		#include<string>
		using namespace std;

		class Contact
		{
			private:
			string first_name;
			string last_name;
			unsigned birth_month;
			unsigned birth_day;
			unsigned birth_year;

			public:
			Contact(string f_name, string l_name, unsigned b_month, unsigned b_day, unsigned b_year);
			string getFirstName() const;
			string getLastName() const;
			unsigned getBirthMonth() const;
			unsigned getBirthDay() const;
			unsigned getBirthYear() const;


			bool operator<(const Contact& C2) const;

		};
		//#include "Contact.cpp"
	#endif
