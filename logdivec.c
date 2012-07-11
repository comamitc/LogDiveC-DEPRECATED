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

#define INIFILE "config/config.ini"

// .c file
void main(void)
{

	dict *inif[HASHSIZE] = {}; // initialized to NULL 
	
	parse_conf(inif, INIFILE);
	
	//prnt_dict(inif);
	
}