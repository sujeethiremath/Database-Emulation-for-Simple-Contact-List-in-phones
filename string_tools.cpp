#include <iostream>
#include <sstream>  // for istringstream
#include <string>
#include <vector>

using namespace std;

/** Function to split a string into tokens
    @param s The string that needs to be split into tokens.
    @param delimeter The character used to delimit/separate tokens.
    @return  A string vector containing the tokens in string s. */
    
    vector<string> split( string s , char delimiter )
    {
        vector<string> tokens;          // vector of tokens
        string token;                   // a single token
        istringstream tokenStream(s);   // an input string stream

        // Tokenize s by grabbing individual tokens
        while( getline( tokenStream , token , delimiter ) )
            tokens.push_back(token);    // add found token

        return tokens;
    }

/** Clean up a string of special/invisible characters.
    @param str The string that needs to be "cleaned".
    @return The cleaned up version of str. */
    
    string removeSpecials( string str )
    {
   	    int i=0,len=str.length();
   	    while(i<len) // Check every character
   	    {
            char c=str[i];
            if( !(((c>='0')&&(c<='9')) || ((c>='A')&&(c<='Z')) || ((c>='a')&&(c<='z')) || (c==' ') || (c=='-')) ) 
            {
                str.erase(i,1); // Delete "bad" character
                --len;          // and adjust length
            }
            i++;
        }
        return str;
    }