/* How to take this and make multiple dictionary objects???
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

//linking key -- need to minimize this later


dict *dict_init(){
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
	unsigned int hashval = hash(s);
	for (np = hashtab[hashval]; np != NULL; np = np->next) {
		printf("Entering lookup loop\n");
		if (strcmp(s, np->name) == 0)
			return np;
	}					/* found 	 */
	printf("returning null\n");
    return NULL;		/* not found */
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
	
	for (i = 0; i < HASHSIZE; i++)
		for (np = hashtab[i]; np != NULL; np = np->next)
			printf("Key: %s, Value: %s\n", np->name, np->defn);
		
	
}