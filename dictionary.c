// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
int dictionary_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    //hash word to obtain hash value 
    int hash_value = hash(word);
    //access linked list at hash value
    node *cursor = table[hash_value];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        //re-run cursor to go to the next word in linked list
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
        /*int sum = 0;
    for (int i = -1; i < word(n - 1); i++)
    {
        sum += word[n-1];
    }*/
    
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    char word[LENGTH + 1];
    //reads string from file one at a time 
    while(fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free(n);
            return false;
        }

        //create a new node for each word
        strcpy(n->word, word);
        n->next = NULL;

        //sorts word into the correct bucket
        node *linked_list = table[hash(word)];

        //once we are in the right bucket, add word to linked list
        n->next = linked_list;
        table[hash(word)] = n;
        dictionary_size++;

    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dictionary_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *tmp = NULL;

        while (cursor != NULL)
        {
            tmp = cursor; 
            cursor = cursor->next; 
            free(tmp);
        }
    }

    return true;
}
