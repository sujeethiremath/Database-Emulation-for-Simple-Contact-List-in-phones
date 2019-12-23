#ifndef STRING_TOOLS_
#define STRING_TOOLS_

#include <iostream>
#include <sstream>  // for istringstream
#include <string>
#include <vector>

using namespace std;

// Function prototypes for string tools

/** Function to split a string into tokens
    @param s The string that needs to be split into tokens.
    @param delimeter The character used to delimit/separate tokens.
    @return  A string vector containing the tokens in string s. */
    
    vector<string> split( string s , char delimiter );

/** Clean up a string of special/invisible characters.
    @param str The string that needs to be "cleaned".
    @return The cleaned up version of str. */
    
    string removeSpecials( string str );

#include "string_tools.cpp"
#endif
