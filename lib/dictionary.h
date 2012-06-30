#ifndef DICT_PROPS
#define DICT_PROPS

typedef struct _nlist { /* table entry: */
    struct _nlist *next; /* next entry in chain */
    char *name; 		/* defined name */
    char *defn; 		/* replacement text */
} dict;

dict *dict_init();
void *install(dict *hashtab[], char *name, char *defn);
void *lookup(dict *hashtab[], char *s);
unsigned hash(char *s);
//char *strdup(char *s);

#endif