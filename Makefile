TARGETS=ishell
CC=gcc
CCOPTS=-Wall -Wextra
INC=

LIBS=-lstdc++

all: rm_directory make_directory $(TARGETS)

rm_directory:
	rm -rf ./bin

make_directory:
	mkdir bin

ishell:
	$(CC) $(CCOPTS) $(INC) -o ush ush.c makeargv.c $(LIBS)
	mv ush ./bin
