#ifndef CONFIG_HEAD
#define CONFIG_HEAD

#include <stdio.h>
#include <stdlib.h>

#include "stringobj.h"
#include "dictionary.h"
#include "errors.h"

dict * parse_conf(char * fname);

#endif /*config head */
