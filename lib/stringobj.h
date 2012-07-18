
#ifndef _STR_H
#define _STR_H

#define BUFFER 128

char * str_init();
void str_append(char *s, char c);
void str_realloc(char *s);
void str_concat(char *s, char *ss);

#endif /* string props */