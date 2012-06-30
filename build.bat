gcc -c lib/dictionary.c -I/lib
gcc -c lib/stringobj.c -I/lib
gcc -c lib/errors.c -I/lib
gcc -c lib/confile.c -I/lib
gcc -Wall logdivec.c stringobj.o errors.o confile.o dictionary.o -o logdivec