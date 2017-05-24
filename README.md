# speller
Implementation of the program that spell-checks a file (the fastest spell checker I can! By "fastest," though, we consider actual, real-world, noticeable time — none of that asymptotic stuff this time.)


The challenge now before you is to implement load, check, size, and unload as efficiently as possible, in such a way that TIME IN load, TIME IN check, TIME IN size, and TIME IN unload are all minimized.

In speller.c, is created a program that’s designed to spell-check a file after loading a dictionary of words from disk into memory.
-  by way of getrusage, we’ll be "benchmarking" (i.e., timing the execution of) implementations of check, load, size, and unload functions.

In dictionary.c:
load() - Loads dictionary into memory. Returns true if successful else false;
check() - Returns true if word is in dictionary else false;
size() - Returns number of words in dictionary if loaded else 0 if not yet loaded
unload() - Unloads dictionary from memory.  Returns true if successful else false;

Info about dictionary-file, contains  words:
  Within the default dictionary, mind you, are 143,091 words, all of which must be loaded into memory! In fact, take a peek at that file to get a sense of its structure and size. Notice that every word in that file appears in lowercase (even, for simplicity, proper nouns and acronyms). From top to bottom, the file is sorted lexicographically, with only one word per line (each of which ends with \n). No word is longer than 45 characters, and no word appears more than once.

Spell checker does not leak any memory (analyzed by using valgrind). 
