# speller

###### Implementation of the program that spell-checks a file (the fastest spell checker I can! By "fastest," though, it is considered actual, real-world, noticeable time — none of that asymptotic stuff this time.)

In *speller.c* there is a program that’s designed to spell-check a file after loading a dictionary of words from disk into memory. Coded by CS50 staff
-  by way of getrusage, we’ll be "benchmarking" (i.e., timing the execution of) implementations of check, load, size, and unload functions.


In a *dictionary.c* there are some finctions:
* load() - Loads dictionary into memory. Returns true if successful else false;
* check() - Returns true if word is in dictionary else false;
* size() - Returns number of words in dictionary if loaded else 0 if not yet loaded
* unload() - Unloads dictionary from memory.  Returns true if successful else false;

Spell checker does not leak any memory (analyzed by using **valgrind**). 
