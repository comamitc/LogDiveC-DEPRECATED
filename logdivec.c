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
#include "lib/confile.h"

#define INIFILE "config/config.ini"


// .c file
void main(void)
{

	dict *config = parse_conf(INIFILE);

	
}