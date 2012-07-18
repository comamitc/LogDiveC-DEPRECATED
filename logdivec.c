/***
	LogDiveC: Copyright 2012
	Author(s): Mitch Comardo
	Description: Parses Apache log file sets recording errors on the way
*/

// to be split into header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Need to handle these definitions nicely
#include "lib/errors.h"
#include "lib/stringobj.h"
#include "lib/dictionary.h"
#include "lib/confile.h"

// ToDo: make this generic in config file (if not null check below)
#define BUILD_PATH "\\build\\bin"

void ls_dir(char *files[], char *dirpath);


// .c file
void main(void)
{
	dict *inif[HASHSIZE] = {}; // initialized to NULL 	
	dict *dirs;
	char *dir = str_init(), *d_cpy = str_init();
	char *files[256] = {};
	
	parse_conf(inif, INIFILE);
	dirs = lookup(inif, DIRECT);		
	dir = strtok(dirs->defn, DELIM);
	
	while (dir != NULL) {
		strcpy(d_cpy, dir);
		strcat(d_cpy, BUILD_PATH);
		ls_dir(files, d_cpy);	   // List files
		
		/*
			do parse here
		*/
		
		dir = strtok(NULL, DELIM); // for each until no more delimiters
	}
}


void ls_dir(char *files[], char *dirpath)
{
	int i = 0;
	DIR *dir = NULL;
	struct dirent *f_obj = NULL;
	
	dir = opendir(dirpath);
	if (dir == NULL)
		nodirectory_error(dirpath, __FILE__, __FUNCTION__, __LINE__);

	while ((f_obj = readdir(dir))) 
		files[i++] = strdup(f_obj->d_name);

	closedir(dir);
}