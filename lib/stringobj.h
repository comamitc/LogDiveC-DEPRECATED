#ifndef DEBUG_PROPS
#define DEBUG_PROPS

#define __func__ __FUNCTION__
#define __file__ __FILE__
#define __line__ __LINE__

#endif /* DEBUG_PROPS */

#ifndef STRING_PROPS
#define STRING_PROPS

#define BUFFER 256

typedef struct {
	char *s;
	size_t len;
	size_t b_size;
} str;


str * str_init();
void str_append(str *s, char c);
void str_resize(str *old, int buff);

#endif /* string props */