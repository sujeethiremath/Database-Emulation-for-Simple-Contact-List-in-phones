Most contact lists are typically implemented using a simple database. 
The contact list contain the following data about contacts: their names and their birthdays. The program allows entry, removal, modification, or search of this data. For this version, you can assume that the names are unique. The
program is able to save the data in a file for use later. A class is designed to represent the database and another class to represent the contacts.A balanced binary search tree is used as
an index to the data. This index is based on the contacts’ last names.


Input


The program reads in two input text files. The filenames for these files are provided as command–line arguments/parameters; hence, given the name of the executable is myContacts then typing the command

myContacts contacts.txt commands.txt

would use contacts.txt and commands.txt as the filenames of the two input files. These files correspond to a data file and
an operations file needed by your program.


1. Data file (e.g. contacts.txt in the example above)

Overview: This file contains the raw data that makes up the contact list. Each record contains information for one
contact. The information for each contact includes: first name, last name, birth month, birth day, and birth year.
File format This is an ASCII text file. Each record occupies a single line. Each line will contain all 5 attributes
of a record with attributes separated by commas; hence, each line will have the form

first_name,last_name,birth_month,birth_day,birth_year

where 1≤birth month≤12, 1≤birth day≤31, and birth year is a 4–digit value representing a calendar year.


2. Operations file (e.g. commands.txt in the example above)


Overview:  This file contains a list of operations to be done on a contact list. Each operation is specified in a single
line.
File format This will be an ASCII text file. Each operation will have the form
operation argument
Here are the possible values for operation, listed alphabetically, and any argument it may need:

A record : Add a new record to the contact list. A new record will be provided using the same format as a record
in the input data file (see above); for example:


A Alice,Barber,3,14,1993


D key : Delete the unique record from the contact list with a key value (last name) indicated by key. Display the
matching record that is deleted. If multiple records match the given key, display all such records but do not
delete any of the records. Display an error message if the record is not found. Compare with Remove below.


F key : Find the record(s) from the contact list with a key value (last name) indicated by key. Display the record(s)
that match the given key; otherwise, display an error message if no record(s) match the given key.


R key : Remove all records from the contact list with a key value (last name) indicated by key. Display all matching
records that are deleted. Display an error message if no record matches the given key. Compare with Delete
above.


S : Show all the contacts. The contacts will be displayed based on the ordering managed by the binary search tree
index of the contact last names.

No error–checking is done on these input files.


Sample Input


1. Data file

            Nicole,Martinez,10,26,1990
            Peter,Butler,8,10,1991
            Kelly,Carter,4,7,1998
            Bobby,Garcia,2,27,1992
            Alan,Sanchez,2,20,1999
            Jeff,Powell,1,19,1999
            Debra,Wright,1,23,1990
            
2. Operations file


S

F Barber

A Alice,Barber,3,14,1993

S

F Barber


Output


The output consists of the results from each of the commands listed in the Operations file (see above). All output goes to
standard output. When the program terminates, the database is stored using the same filename as the Data file (see above).

Sample Output


For the sample input given above, the program produces the following output:

Loaded 7 records into contact list.

Showing contact list:

Peter Butler, 8/10/1991

Kelly Carter, 4/7/1998

Bobby Garcia, 2/27/1992

Nicole Martinez, 10/26/1990

Jeff Powell, 1/19/1999

Alan Sanchez, 2/20/1999

Debra Wright, 1/23/1990

Find "Barber"

 Not found.
 
 New contact added
 
 Alice Barber, 3/14/1993
 
 Showing contact list:
 
 Alice Barber, 3/14/1993
 
 Peter Butler, 8/10/1991
 
 Kelly Carter, 4/7/1998
 
 Bobby Garcia, 2/27/1992
 
 Nicole Martinez, 10/26/1990
 
 Jeff Powell, 1/19/1999
 
 Alan Sanchez, 2/20/1999
 
 Debra Wright, 1/23/1990
 
 Find "Barber"
 
Found.

 Alice Barber, 3/14/1993
 
 Wrote 7 records from contact list.
 

Notice that the Database template class takes two parameters. The first one, ItemType, is the type of record data to store
in the database. The second one, KeyType, is the type of the (primary) index used to organize the database. Since the index is by
the contacts’ last name, the Database template parameter KeyType would be type string.
The program uses the following built-in C++ container classes :

• vector to store the actual data records (contacts) of contact list; and

• multimap to maintain an index to the last name attribute of a record.

Basically, the multimap contains pair<string,unsigned> elements where the string denotes the last name and the
unsigned is the corresponding record’s index location in the vector.
