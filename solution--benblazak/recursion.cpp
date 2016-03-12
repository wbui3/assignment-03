/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Implements `recursion.h`.
 */

#include <string>

#include "recursion.h"

// ----------------------------------------------------------------------------

int gcd(int a, int b) {
    // normalize input
    if (a < 0) return gcd(-a, b);
    if (b < 0) return gcd(a, -b);

    // base case
    if (a == 0 || b == 0) return a+b;  // return the nonzero number

    // recursive case
    if (a > b) return gcd(a-b, b);
    else       return gcd(a, b-a);
}
// ----------------------------------------------------------------------------

int fib(int n) {
    // check for invalid input
    if (n < 1) throw "ERROR: fib: n less than 1";

    // base cases
    if (n == 1 || n == 2) return 1;

    // recursive case
    return fib(n-1) + fib(n-2);
}

// ----------------------------------------------------------------------------

int pow(int a, int b) {
    // check for invalid input
    if (b < 0) throw "ERROR: pow: b less than 0";

    // base cases
    if (b == 0) return 1;
    if (b == 1) return a;

    // recursive case
    return a * pow(a, b-1);
}

// ----------------------------------------------------------------------------

int tri(int n) {
    // check for invalid input
    if (n < 1) throw "ERROR: tri: n less than 1";

    // base case
    if (n == 1) return 1;

    // recursive case
    return n + tri(n-1);
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

int gcd_iter(int a, int b) {
    // normalize input
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    // while a and b are both nonzero
    while (a && b) {
        // subtract the smaller one from the larger one
        if (a > b) a -= b;
        else       b -= a;
    }

    // return the value of whichever is nonzero
    return a+b;
}

int fib_iter(int n) {
    // check for invalid input
    if (n < 1) throw "ERROR: fib_iter: n less than 1";

    // set up the first and second elements of the sequence
    int a = 1;
    int b = 1;

    // make a the 2nd element and b the 3rd, then a the 3rd element and b the
    // 4th, and so on until a is the nth element
    while (n > 1) {
        int c = a + b;
        a = b;
        b = c;
        n--;
    }

    return a;
}

int pow_iter(int a, int b) {
    // check for invalid input
    if (b < 0) throw "ERROR: pow_iter: b less than 0";

    // start with 1 and multiply it by a b times
    int ans = 1;
    for (; b > 0; b--)
        ans *= a;

    return ans;
}

int tri_iter(int n) {
    // check for invalid input
    if (n < 1) throw "ERROR: tri_iter: n less than 1";    

    // sum all the numbers from n down to 1
    int ans = 0;
    for (; n > 0; n--)
        ans += n;

    return ans;
}

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

std::string int_to_roman(int n) {
    const std::string numerals[] = {
        "M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
    };
    const int values[] = {
        1000, 900,  500, 400,  100, 90,   50,  40,   10,  9,    5,   4,    1,
    };

    // check for invalid input
    if (n < 0)     throw "ERROR: int_to_roman: n is too small";
    if (n >= 4000) throw "ERROR: int_to_roman: n is too large";

    // base case
    if (n == 0) return "";

    // recursive case
    // - equivalent to a chain of if ... else if statements
    for (int a = 0; a < sizeof(values)/sizeof(int); a++)
        if (n >= values[a])
            return numerals[a] + int_to_roman(n-values[a]);

    // shouldn't get here
    // - but if we don't put this (or a return) "control may reach end of
    //   non-void function"
    throw "ERROR: int_to_roman: unable to convert";
}

// ----------------------------------------------------------------------------

std::string int_to_words(int n) {
    const std::string sep = " ";  // word separation character

    const std::string small[] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
    };

    const std::string tens[] = {
        "", "ten", "twenty", "thirty", "forty",
        "fifty", "sixty", "seventy", "eighty", "ninety",
    };

    // indexed by the power of 10 divided by 3 (since in english numbers are
    // grouped into sets of 3)
    const std::string suffixes[] = {
        "", "thousand", "million", "billion", "trillion",
        "quadrillion", "quintillion",
    };

    if (n < 0)    return "negative" + sep + int_to_words(-n);
    if (n < 20)   return small[n];
    if (n < 100)  return tens[n/10] + ((n%10) ? sep + small[n%10] : "");
    if (n < 1000) return small[n/100] + sep + "hundred"
                         + ((n%100) ? sep + int_to_words(n%100) : "");

    // - we could avoid having to find the suffix this way if we included a
    //   "suffix" argument that told us which of the suffixes to use, and took
    //   groups of three numbers from the least significant side (the right
    //   side of the number) first rather than processing the most significant
    //   groups first
    int suffix = 1;
    int divisor = 1000;
    for (; n / divisor; suffix++, divisor *= 1000);
    suffix--;
    divisor /= 1000;

    return int_to_words(n/divisor) + sep + suffixes[suffix]
           + ((n%divisor) ? sep + int_to_words(n%divisor) : "");

    // shouldn't get here
    // - but if we don't put this (or a return) "control may reach end of
    //   non-void function"
    throw "ERROR: int_to_words: unable to convert";
}

// ----------------------------------------------------------------------------

std::string magic_number(int n) {
    std::string current = int_to_words(n);
    std::string next = int_to_words(current.length());

    if (current.compare(next) == 0)
        return std::to_string(n) + " is the magic number!\n";

    return std::to_string(n) + " is " + std::to_string(current.length()) + "\n"
           + magic_number(current.length());
}

