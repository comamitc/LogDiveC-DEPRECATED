/* How to take this and make multiple dictionary objects???
*/

#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

//linking key
#define HASHSIZE 101

dict *dict_init(){
	dict *new_dict[HASHSIZE];
	return new_dict;
}

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != ’\0’; s++)
      hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
void *lookup(dict *hashtab[], char *s)
{
    dict *np;
	unsigned hashval = hash(s);
    for (np = hashtab[hashval]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
          return np; /* found 	  */
    return NULL;     /* not found */
}

/* install: put (name, defn) in hashtab */
void *install(dict *hashtab[], char *name, char *defn)
{
    dict *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (nlist *) malloc(sizeof(*np));
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

 /* make a duplicate of s */
 char *strdup(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s)+1); /* +1 for ’\0’ */
    if (p != NULL)
       strcpy(p, s);
    return p;
}