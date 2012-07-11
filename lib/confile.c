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
			case '=':  // identifier end
				isKey = 0;
				break; 
			case '\n': // line end
				isKey = 1; 
				install(conf, k, v);
				free(k);
				free(v);
				break; 
			default: 
				if (isKey) str_append(k, ch); else str_append(v, ch); 
				break;
		}
	}

	// catching the last install but only if they are formed!
	// in case of EOF before \n
	install(conf, k, v);

}