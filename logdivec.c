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
#include "lib/dictionary.h"

#include "lib/confile.h"

// configuration definitions
#define INIFILE "config/config.ini"
#define DIRECT "directory"
#define DELIM ","

// .c file
void main(void)
{

	
	dict *inif[HASHSIZE] = {}; // initialized to NULL 
	
	dict *dirs;
	char *dir;
	
	parse_conf(inif, INIFILE);
	
	dirs = lookup(inif, DIRECT);
	
	dir = strtok(dirs->defn, DELIM);
	while (dir != NULL) {
		dir = strtok(NULL, DELIM);
	}
	
}