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

// configuration definitions
#define INIFILE "config/config.ini"
#define DIRECT "directory"
#define DELIM ","
//#define BUILD "\\build\\bin\0"


void ls_dir(char *dirpath);


// .c file
void main(void)
{

	dict *inif[HASHSIZE] = {}; // initialized to NULL 
	
	dict *dirs;
	char *dir;
	char *fpath = str_init();
	char *build_path = "\\build\\bin\0";
	
	parse_conf(inif, INIFILE);
	
	dirs = lookup(inif, DIRECT);
	
		
	dir = strtok(dirs->defn, DELIM);
	while (dir != NULL) {
		// str copy becuase of the null check at end
		strcpy(fpath, dir);
		str_concat(fpath, build_path); 			// built in concat func
		ls_dir(fpath);	
		dir = strtok(NULL, DELIM);
	}
}


void ls_dir(char *dirpath)
{
	int i = 0;
	DIR *dir = NULL;
	struct dirent *ent = NULL;
	char *files[256] = {};
	dir = opendir(dirpath);
	
	if (dir == NULL)
		printf("This directory sucks!");

	while (ent = readdir(dir))
		files[i++] = ent->d_name;

	closedir(dir);
}