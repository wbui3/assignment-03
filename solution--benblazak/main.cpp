/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Tying it all together.
 */

#include <iostream>

#include "test.h"
#include "recursion.h"

using std::cout;
using std::endl;

// ----------------------------------------------------------------------------

int main() {
    test_exceptions();  cout << "\n-------\n\n";
    test_templates();   cout << "\n-------\n\n";
    test_stl();

    cout << "\n-------"
         << "\n-------\n\n";

    cout << 7*7 << endl;
    cout << gcd(7*7*7*5*3, 7*7*11*13) << endl;
    cout << gcd_iter(7*7*7*5*3, 7*7*11*13) << endl;

    cout << endl;

    cout << 3*3 << endl;
    cout << gcd(3*3*3*5*7, 3*3*11*13) << endl;
    cout << gcd_iter(3*3*3*5*7, 3*3*11*13) << endl;

    cout << "\n.......\n\n";

    for (int i = 1; i <= 15; i++)
        cout << fib(i) << " ";
    cout << endl;
    for (int i = 1; i <= 15; i++)
        cout << fib_iter(i) << " ";
    cout << endl;

    cout << endl;

    cout << "error" << endl;
    try {
        fib(0);
    } catch (const char * s) {
        cout << s << endl;
    }
    try {
        fib_iter(0);
    } catch (const char * s) {
        cout << s << endl;
    }

    cout << "\n.......\n\n";

    for (int i = 1; i <= 15; i++)
        cout << pow(3, i) << " ";
    cout << endl;
    for (int i = 1; i <= 15; i++)
        cout << pow_iter(3, i) << " ";
    cout << endl;

    cout << endl;

    cout << "error" << endl;
    try {
        pow(3, -1);
    } catch (const char * s) {
        cout << s << endl;
    }
    try {
        pow_iter(3, -1);
    } catch (const char * s) {
        cout << s << endl;
    }

    cout << "\n.......\n\n";

    for (int i = 1; i <= 15; i++)
        cout << tri(i) << " ";
    cout << endl;
    for (int i = 1; i <= 15; i++)
        cout << tri_iter(i) << " ";
    cout << endl;

    cout << endl;

    cout << "error" << endl;
    try {
        tri(0);
    } catch (const char * s) {
        cout << s << endl;
    }
    try {
        tri_iter(0);
    } catch (const char * s) {
        cout << s << endl;
    }

    cout << "\n.......\n\n";

    cout << "        I == " << int_to_roman(1) << endl;
    cout << "       IX == " << int_to_roman(9) << endl;
    cout << "   CXXIII == " << int_to_roman(123) << endl;
    cout << "CDLXXXVII == " << int_to_roman(487) << endl;

    cout << "\n.......\n\n";

    cout << 0 << " == " << int_to_words(0) << endl;
    cout << 1 << " == " << int_to_words(1) << endl;
    cout << -1 << " == " << int_to_words(-1) << endl;
    cout << 123 << " == " << int_to_words(123) << endl;
    cout << 123123 << " == " << int_to_words(123123) << endl;
    cout << 123000123 << " == " << int_to_words(123000123) << endl;
    cout << 123123000 << " == " << int_to_words(123123000) << endl;

    cout << "\n.......\n\n";

    cout << magic_number(1) << endl;
    cout << magic_number(7) << endl;
    cout << magic_number(13) << endl;

    return 0;
}

