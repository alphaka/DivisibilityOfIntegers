# DivisibilityOfIntegers

## Description

The purpose of this program is to produce all divisors of a number
other than 1 and itself (which are called non-trivial divisors), separated by a
comma. The numbers are read from 'input.txt' file and the output (the divisors of
the number separated by a comma) is return in 'output.txt'.

To achieve this, I used the modulo operator to retrieve and print divisors lower
or equal to the square root of the number read from 'input.txt', and simulateneously
keep divisors higher than the square root of the number in the 'arr' integer array.

I finally use the 'reverseArray and swapInt' methods to sort the descending 'arr'
array into an ascending array.
