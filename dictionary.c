/**
 * Implements a dictionary's functionality.
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

#include <stdbool.h>

#include "dictionary.h"

# define LENGTH 45
# define TABLESIZE 500  

// global boolean for tracking load/unload dictionary operations
bool loaded = false;

static unsigned word_count = 0;

typedef struct node
{
	char word[LENGTH + 1];
	struct node* next;
}
node;

// init hash-table
node* hashtable[TABLESIZE]; 

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
	// solve case-insensitive problem	
    //to store copy of word , cause word is a const char* and non-read actions cannot be performed on it
    int len = strlen(word);
    char word_copy[len + 1];
    
    // convert word to lowercase and store it in word_copy
    for (int i = 0; i < len; i++)
    {
       word_copy[i] = tolower(word[i]);
    }
    
    // add null terminator to end of char array
    word_copy[len] = '\0';
    
	unsigned int hashkey= 0;
        for (int counter = 0; word_copy[counter]!= '\0'; counter++)
        {
            	hashkey = (hashkey*word_copy[counter] + word_copy[counter] + counter) % TABLESIZE;
        }

	node* crawler = hashtable[hashkey];

	while (crawler != NULL)
	{
		if (strcmp(word_copy, crawler->word) == 0)
		{
			return true;
		}
		crawler = crawler->next;
	}

   	return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{	
	// open ductionary-file 
	FILE* dict = fopen(dictionary, "r");
    	if (dict == NULL)
    	{
        	printf("Could not open file %s\n", dictionary);
       		return false;
    	}
	
	// dict_word stores current word (+1 for \0)
	char* dict_word = malloc((LENGTH+1) * sizeof(char));
	if (dict_word == NULL)
	{
		printf ("Run out of memory :(");
		return false;
	}
	
	// go through file and read every word
	while (fscanf(dict, "%s", dict_word) != EOF)
	{
		// create node
		node* new_node = malloc(sizeof(node));
		if (new_node == NULL)
		{
			unload();
			return false;
		}
		strcpy(new_node->word, dict_word);

    		//find spot in hash table and put it in that bucket
		unsigned int hashkey= 0;
        	for (int counter = 0; dict_word[counter]!= '\0'; counter++)
        	{
            		hashkey = (hashkey*dict_word[counter] + dict_word[counter] + counter) % TABLESIZE;
        	}

        	//check if spot in table exists; if not, start the linked list
        	if (hashtable[hashkey] == NULL)
        	{    
            		hashtable[hashkey] = new_node;
            		new_node->next = NULL;
        	}
        	//otherwise made current node the first, shift rest over
        	else
        	{
            		new_node->next = hashtable[hashkey];
            		hashtable[hashkey] = new_node;
        	} 
      
        	//count added words 
        	word_count++;
	}
		// do not forget to free memory 
		free (dict_word);	

	    fclose(dict);
	    loaded = true;
    	    return true; 
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (loaded)
	return word_count;
    else
	return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
	for (int i = 0; i < TABLESIZE; i++)
	{
    		node* cursor = hashtable[i];
		while (cursor != NULL) 
		{
			node* tmp = cursor;
			cursor = cursor->next;
			free(tmp);
		}	
	}

	loaded = false;

    return true;
}
