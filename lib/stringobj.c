#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringobj.h"
/**
	Initialize the string object
*/


char * str_init() {
	/* string fast alloc to char pointer for lightweight strings */
	char *s;
	s = (char *) malloc(sizeof(char)*BUFFER);
	
	if (!s)
		nomem_error(__FILE__, __FUNCTION__, __LINE__); // bad alloc

	s[0] = '\0'; // termination
}

void __resize_str(char * s, size_t buff) {
	char *tmp =  (char *) malloc(sizeof(char)*buff);
	
	if (!tmp)
			nomem_error(__FILE__, __FUNCTION__, __LINE__);

	strcpy(tmp, s); 
	
	s = tmp;

}

void str_append(char * s, char c) {
	
	int len = strlen(s)+1;
	
	if ((len % BUFFER) == 0 && len >= BUFFER) { 	// len is not 0 and exceeds buffer
		size_t b_size = ((len/BUFFER) + 1)*BUFFER; 	// how to optimize this arithemtic
		__resize_str(s, b_size);
	}
	
	s[len-1] = c;
	s[len] = '\0';
}

void str_concat(char *s, char *ss)
{
	int i;
	for (i = 0; i < strlen(ss); i++)
		str_append(s, ss[i]);
}

void str_realloc(char *s){
	free(s);
	s = str_init();
}


