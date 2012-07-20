#include "t_parser.h"

/*
    _tsa = re.compile(r'^\d{4}-\d{2}-\d{2}[ T]\d{2}:\d{2}:\d{2}.*$')                    #19
    _tsb = re.compile(r'^\[?[a-zA-Z]{3}\s[a-zA-Z]{3}\s\d{2}[ T]\d{2}:\d{2}:\d{2}.*$')   #20
*/

int is_newline(char *line) //20 char line for regex matching
{
	
}


void t_parse(char *filename)
{
	FILE *fp;
	char c;
	
	fp = fopen(fname, "r");
	
	if (!fp)
		nofile_error(filename, __FILE__, __FUNCTION__, __LINE__);
		
	while ((c = fgetc(fp)) != EOF)
	{
		;
	}
}

