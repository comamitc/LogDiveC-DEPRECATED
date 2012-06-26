gcc -c lib/stringobj.c -I/lib
gcc -c lib/errors.c -I/lib
gcc -Wall logdivec.c stringobj.o errors.o -o logdivec