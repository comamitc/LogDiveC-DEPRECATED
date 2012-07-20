#include "parser.h"

void parse_logs(char *files[])
{
	int i = 0;
	char *w_file = NULL;
	char *ext = NULL;
	
	while ((w_file = files[i++]) != NULL)
	{	
		// how to reverse order the str?
		// is it faster?
		ext  = strtok(w_file, EXT_DELIM);
		while (ext != NULL)
			ext = strtok(NULL, EXT_DELIM); // get extension
			
		if (strcmp(ext, "txt") || strcmp(ext, "log"))
			; //t_parser
		else if (strcmp(ext, "xml"))
			; //x_parser
		else
			; // invalid extensions
	}
}