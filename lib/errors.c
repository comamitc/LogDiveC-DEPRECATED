#include <stdlib.h>
#include <stdio.h>
#include "errors.h"
/**
  generic error wrapper for application exit
*/
void generic_error(const char *_file, const char *_func, int _line) 
{
	printf("\tin file: %s,\n\tfunction: %s,\n\tline: %d\n", \
						 _file, _func, _line);
	printf("\texiting...");
	exit(1);
}

/**
	no memory allocation was successfully executed
*/
void nomem_error(const char *_file, const char *_func, int _line) 
{
	printf("Exception: error allocating memory for pointer!\n");
	generic_error(_file, _func, _line); 
}

void nofile_error(const char *filename, const char *_file, const char *_func, int _line)
{
	printf("Exception: Cannot open file: %s\n", filename);
	generic_error(_file, _func, _line); 
}

void badconfile_error(const char *filename, const char *_file, const char *_func, int _line) 
{
	printf("Exception: Malformed config file: %s\n", filename);
	generic_error(_file, _func, _line); 
}

void nodirectory_error(const char *dir, const char *_file, const char *_func, int _line)
{
	printf("Exception: |%s| not a valid directory\n", dir);
	generic_error(_file, _func, _line); 
}