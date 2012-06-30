/***
	Main entry point for program
*/

// to be split into header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	Need to handle these definitions nicely
*/
#include "lib/errors.h"
#include "lib/stringobj.h"


// .c file
void main(void)
{

	char test_str[] = "SETTING UP LIB!";
	int i;
	str *main_str = str_init();

	//test function
	for (i = 0; i < strlen(test_str); i++) {
		str_append(main_str, test_str[i]);
	}
	
	printf("%s\n", main_str->s);
	printf("%d\n", main_str->len);
	printf("%d\n", main_str->b_size);
	
}