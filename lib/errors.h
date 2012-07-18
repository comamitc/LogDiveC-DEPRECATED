#ifndef _ERR_H
#define _ERR_H

void generic_error(const char *_file, const char *_func, int _line);
void nomem_error(const char *_file, const char *_func, int _line);
void badconfile_error(const char *filename, const char *_file, const char *_func, int _line);
void nodirectory_error(const char *dir, const char *_file, const char *_func, int _line);

#endif