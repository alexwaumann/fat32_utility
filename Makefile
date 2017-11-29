main: mfs.c
	gcc mfs.c -o mfs

debug: mfs.c
	gcc mfs.c -Wall -g -o mfs

clean:
	-rm -rf mfs mfs.dSYM
