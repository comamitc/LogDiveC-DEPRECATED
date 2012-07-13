/* How to take this and make multiple dictionary objects???
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// ToDo: depreciate this!
dict *dict_init()
{
	dict *new_dict[HASHSIZE] = {};
	return *new_dict;
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
void * lookup(dict *hashtab[], char *s)
{
    dict *np;
	unsigned hashval = hash(s);
	for (np = hashtab[hashval]; np != NULL; np = np->next) 
		if (strcmp(s, np->name) == 0)
			return np;			/* found 	 */
    return NULL;				/* not found */
}

/* install: put (name, defn) in hashtab */
void *install(dict *hashtab[], char *name, char *defn)
{
    dict *np;
    unsigned hashval;
    if ((np = lookup(hashtab, name)) == NULL) { /* not found */
        np = (dict *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
          return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np; /* keeps insert super quick! */
    } else /* already there */
        free((void *) np->defn); /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
       return NULL;
    return np;
}

void prnt_dict(dict *hashtab[])
{
	int i;
	dict *np;
	
	printf("{ ");
	for (i = 0; i < HASHSIZE; i++)
		for (np = hashtab[i]; np != NULL; np = np->next)
			printf("%s: %s, ", np->name, np->defn);
	printf("}\n");	
}