/***
	Main entry point for program
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


void ls_dir(char *files[], char *dirpath);


// .c file
void main(void)
{
	dict *inif[HASHSIZE] = {}; // initialized to NULL 	
	dict *dirs;
	char *dir;
	char *fpath = str_init();
	char *build_path = "\\build\\bin";
	char *files[256] = {};
	int i;
	
	parse_conf(inif, INIFILE);
	dirs = lookup(inif, DIRECT);		
	dir = strtok(dirs->defn, DELIM);
	
	while (dir != NULL) {
		// str copy becuase of the null check at end
		strcpy(fpath, dir);
		str_concat(fpath, build_path); 			// built in concat func
		ls_dir(files, fpath);
		dir = strtok(NULL, DELIM);
	}
	
	for (i = 0; i < 256; i++)
	{
		printf("%s\n", files[i]);
	}
}


void ls_dir(char *files[], char *dirpath)
{
	int i = 0;
	DIR *dir = NULL;
	char *fn = NULL;
	struct dirent *f_obj = NULL;
	
	dir = opendir(dirpath);
	
	if (dir == NULL)
		printf("This directory sucks!");

	while (f_obj = readdir(dir)) 
	{
		printf("%s - %d\n", f_obj->d_name, i);
		
	}

	closedir(dir);
	//return *files;
}