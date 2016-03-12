/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ben Blazak <bblazak@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Playing with recursion.
 */

#ifndef RECURSION_H
#define RECURSION_H
// ----------------------------------------------------------------------------

#include <string>

// ----------------------------------------------------------------------------

int gcd(int a, int b);  // returns the greatest common denominator
int fib(int n);         // returns the nth fibonacci number (starting with 1, 1)
int pow(int a, int b);  // returns a raised to b (for positive b)
int tri(int n);         // returns the nth triangular number

int gcd_iter(int a, int b);  // (see above)
int fib_iter(int n);         // (see above)
int pow_iter(int a, int b);  // (see above)
int tri_iter(int n);         // (see above)

std::string int_to_roman(int n);  // returns n in roman numerals
std::string int_to_words(int n);  // returns n in english
std::string magic_number(int n);  // ( it's a secret :-) )

// ----------------------------------------------------------------------------
#endif

