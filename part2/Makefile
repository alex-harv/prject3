CC = gcc -Wall -g

all: cacheattack

pre-build: cacheattack
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

cacheattack: pre-build
	$(CC) -o cacheattack csca.c -L. -Wl,-rpath=. -lvic -D_GNU_SOURCE

sharedlib: csca-utils.c
	$(CC) -shared -O3 -fPIC -o libvic.so csca-utils.c

clean:
	rm -rf *.o cacheattack