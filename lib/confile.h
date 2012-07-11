#ifndef CONFIG_HEAD
#define CONFIG_HEAD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringobj.h"
#include "dictionary.h"
#include "errors.h"

void parse_conf(dict *conf[], char * fname);

#endif /*config head */
