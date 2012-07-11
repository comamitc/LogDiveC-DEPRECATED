#ifndef ERROR_MSGS
#define ERROR_MSGS

void generic_error(const char *_file, const char *_func, int _line);
void nomem_error(const char *_file, const char *_func, int _line);
void badconfile_error(const char *filename, const char *_file, const char *_func, int _line);

#endif