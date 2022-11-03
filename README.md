README

makechange.cc
programmed by Jeffrey Blinks

Make Change can accept an array of token value denominations
such as ```{1, 5, 10, 25}``` or non-standard denominations such as
```{2,7,9,11,17}``` and use these values to determine the minimum
number of tokens needed to make correct change for a given amount.

The function to call is
```
mintoken( int c, int a[], int len )
```
where ```c``` is the integer value of change to make;
```a``` is an array of token value denominations;
and ```len``` is the amount of token denominations.

The function will return the minimum tokens required to make change,
or it will return -1 if exact change could not be made

Ideas for future implementations:
-----
Return which and number of coins were used to make change

Add logic to determine 'convenient' change vs efficient change.
This would perhaps include or require inferring a number-base for
the denominations required. If denominations are ```{ 1, 2, 4, 8, 15 }```,
it may make more sense to give ```{8, 8, 8, 4, 2}``` for 30 change rather than
```{15, 15}```. Imagine having a 9 cent coin... frustrating.

This logic could extend into finding more efficient ways to store data
in fragmented disk space... but that is beyond me for now...
