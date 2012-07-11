#include "confile.h"

void parse_conf(dict *conf[], char * fname) 
{
	char ch;
	int isKey = 1;

    FILE *inif; 

	char *k = str_init();
	char *v = str_init();

	// read file first, then parse
	// would be faster to parse while reading string
	inif = fopen(fname, "r");
	
	if (!inif)
		nofile_error(fname, __FILE__, __FUNCTION__, __LINE__);
	
	while ((ch = fgetc(inif)) != EOF) 
	{
		switch (ch)
		{
			case '=': 
				isKey = 0;
				break; // this should finish the key value
			case '\n': 
				isKey = 1; 
				printf("Installing: %s - %s\n", k, v);
				install(conf, k, v);
				str_fdestroy(k);
				str_fdestroy(v);
				break; // this should finish the value value
			default: 
				if (isKey) str_append(k, ch); else str_append(v, ch); 
				break;
		}
	}

	// catching the last install but only if they are formed!
	printf("Installing: %s - %s\n", k, v);
	install(conf, k, v);

}