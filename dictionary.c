// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 10000;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int n = strlen(word);
    char copy_word[LENGTH + 1];
    
    for (int i = 0 ; i < n; i++)
    {
        copy_word[i] = tolower(word[i]);
    }
    
    copy_word[n] = '\0';
    
    int h = hash(copy_word);
    
    node *temp = table[h];
    
    while (temp != NULL)
    {
        if (strcasecmp(copy_word,temp->word) == 0)
        {
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % N;
}

int word_count = 0;
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file;
    file= fopen (dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    
    char word[LENGTH + 1];
    while (fscanf( file,"%s",word ) != EOF)
    {
        node *n_node = malloc(sizeof(node));
        if (n_node == NULL)
        {           
            unload();
            return false;
 
        }
        
        strcpy (n_node->word,word);
        
        int h = hash(n_node->word);
        
        node *head = table[h];
        
        if (head == NULL)
        {
            table[h] = n_node;
            word_count++;
        }
        else
        {
            n_node->next = table[h];
            table[h] = n_node;
            word_count++;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
   return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // iterate through hashtable
    for (int i = 0; i < N; i++)
    {
        // set pointer to head of list
        node *tmp = table[i];

        // traverse list
        while (tmp != NULL)
        {
            node *temp = tmp;
            tmp = tmp->next;
            free(temp);
        }
    }
    return true;
}
