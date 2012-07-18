#ifndef _DICT_H
#define _DICT_H

#define HASHSIZE 101 

typedef struct _nlist { 	/* table entry: */
    struct _nlist *next; 	/* next entry in chain */
    char *name; 			/* defined name */
    char *defn; 			/* replacement text */
} dict;

void *install(dict *hashtab[], char *name, char *defn);
void *lookup(dict *hashtab[], char *s);
unsigned hash(char *s);
void prnt_dict(dict *hashtab[]);

#endif