//
// Jeffrey Blinks
// z1647644
// CSCI 340 Section 4
//
// makechange.cc
//
// This program will make the most coin-efficient
// change for any given set of coin denominations
// and change needed.
//

#include <cstdlib>

/**
 * given a set of tokens with various
 * denominations, find the most efficient
 * number of tokens to produce correct change
 *
 * @param c Change to be made
 * @param a The array containing token denominations
 * @param len The length of the array
 *
 * @return finalcount The minimum tokens required to
 *                     produce correct change
 ****************************************************/
int mintokens( int c, int a[], int len)
{
    int finalcount = c; // overall minimum of all permutations
    int mincount = c; // minimum coins to produce remaining change
    int coin_count = 0; // coins used
    int new_c; // change needed for next recursive call

    for( int i = 0; i < len; i++)
    {
        int this_token = a[i];
        if ( this_token == c ) return 1;
        if ( this_token > c ) continue;
        if ( this_token < c )
        {
            coin_count = c / this_token;
            if ( coin_count == 0 ) continue;
            new_c = c % this_token;
            mincount = mintokens( new_c, a, len ) + coin_count;
            finalcount = ( mincount < finalcount ) ? mincount : finalcount;
        }
    }
    // if change could not be made
    if (coin_count == 0) return -1;

    // I'm unsure if this conditional is logically necessary
    if (mincount == 0) return -1;

    return finalcount;
}
