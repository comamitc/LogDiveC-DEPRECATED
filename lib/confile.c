
#include "confile.h"

dict * parse_conf(char * fname) 
{
	char ch;
    FILE *inif; 
	dict *conf = dict_init();
    str  *read_str = str_init();

	// read file first, then parse
	// would be faster to parse while reading string
	inif = fopen(fname, "r");
	
	if (!inif)
		nofile_error(fname, __FILE__, __FUNCTION__, __LINE__);
	
	while ((ch = fgetc(inif)) != EOF)
		str_append(read_str, ch);
	
	printf("Config File: %s", read_str->s);
	
	
}