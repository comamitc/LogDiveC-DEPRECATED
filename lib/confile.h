#ifndef _CONFIG_H
#define _CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringobj.h"
#include "dictionary.h"
#include "errors.h"

// configuration definitions
#define INIFILE "config/config.ini"
#define DIRECT "directory"
#define DELIM ","

void parse_conf(dict *conf[], char * fname);

#endif /*config head */
