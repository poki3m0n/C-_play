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