# speller
Implementation of the program that spell-checks a file

The challenge was to implement the fastest spell checker I can! By "fastest," though, we consider actual, real-world, noticeable time — none of that asymptotic stuff this time.

In speller.c, is created a program that’s designed to spell-check a file after loading a dictionary of words from disk into memory.
-  by way of getrusage, we’ll be "benchmarking" (i.e., timing the execution of) implementations of check, load, size, and unload functions.


