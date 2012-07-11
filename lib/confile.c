#include "confile.h"



void parse_conf(dict *conf[], char * fname) 
{
	char ch;
	int isKey = 1;
	int isCom = 0;

    FILE *inif; 

	char *k = str_init();
	char *v = str_init();
	
	inif = fopen(fname, "r");
	
	if (!inif)
		nofile_error(fname, __FILE__, __FUNCTION__, __LINE__);
	
	/*
		Ghetto parser
	*/
	while ((ch = fgetc(inif)) != EOF) 
	{
		switch (ch)
		{
			case '=':  // identifier end
				isKey = 0;
				break;
			case '#': // comment begin - ignore until line end
				isCom = 1;
				break;
			case '\n': // line end
				isKey = 1; 
				isCom = 0;
				if (strlen(k) > 0 && strlen(v) > 0) {
					install(conf, k, v);
					str_realloc(k);
					str_realloc(v);
				}
				break;
			case ' ': // consume whitespace in path
				break;
			default: // if character other than specified
				if (!isCom) 
				{
					if (isKey) 
						str_append(k, ch); 
					else 
						str_append(v, ch);
				}
				break;
		}
	}

	// catching the last install but only if they are formed!
	// in case of EOF before \n
	if (strlen(k) > 0 && strlen(v) > 0)
		install(conf, k, v);
	else
		badconfile_error(fname, __FILE__, __FUNCTION__, __LINE__);
		

}