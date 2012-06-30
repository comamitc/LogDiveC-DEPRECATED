#ifndef DICT_PROPS
#define DICCT_PROPS

typedef struct _nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; 		/* defined name */
    char *defn; 		/* replacement text */
} dict;

void *install(dict *hashtab[], char *name, char *defn);
void *lookup(dict *hashtab[], char *s);
unsigned hash(char *s);
char *strdup(char *s);

#endif