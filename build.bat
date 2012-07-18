gcc -c lib/dictionary.c -I/lib
gcc -c lib/stringobj.c -I/lib
gcc -c lib/errors.c -I/lib
gcc -c lib/confile.c -I/lib
gcc -Wall -pg logdivec.c stringobj.o confile.o errors.o dictionary.o -o logdivec