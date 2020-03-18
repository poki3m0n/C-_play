
# Include<iostream>

int  main ()
{
    int input = 0 ;
    int base = 0 ;
    initialize_alphabet ();

    // execution loop
    int control = 0 ;
    while (control! = 1 )
    {
        clear_screen ();
        cout << " Enter the value to be converted: " ;
        cin >> input;

        cout << " Enter the base to be converted: " ;
        cin >> base;
        // Check if the base is valid
        if ((base < 2 ) || (base> 36 )) {
            close << " Invalid base! " << endl;
            carry on ;
        }

        string final_value = convert (input, base);

        cout << input << " on base " << base << " = " <<
            final_value << endl << endl;

        // Prevents cin buffering from causing problems in future instances of the loop.
        cin. clear ();
        cin. ignore ();

        cout << " (1) to exit the program .. " << endl;
        cout << " Enter another value to continue execution ... " << endl;
        cin >> control;
    }

    return  0 ;
}

/ * Algorithm that, by successive divisions and comparisons of the rest values, converts an x ​​(input) value represented in the decimal base
for a representation in base b (base).
* /
string convert ( int input, base int ) {
    int n = input;
    string result;
    from {
        result push_back ((((n% base) < 10 )? ((n% base) + ' 0 ' ): (alphabet [(n% base)])));
        n = ( int ) (n / base);
    } while (n! = 0 );
    return  invert_string (result);
}

/ * Function that initializes a map with all letters of the alphabet as values ​​to be mapped, with its keys being the values
which they correspond to.
* /
void  initialize_alphabet () {
    char val = ' A ' ;
    for ( int i = 10 ; i < 36 ; i ++) {
        alphabet [i] = val ++;
    }
}

/ * Function to invert a string, needed because the convert function returns the opposite number.
* /
string invert_string (string s) {
    int start = 0 , end = s. size () - 1 ;

    while (start <end) {
        char tmp = s [start];
        s [start] = s [end];
        s [end] = tmp;
        start ++;
        end--;
    }

    return s;
}