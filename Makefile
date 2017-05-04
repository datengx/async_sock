TARGETS=ishell simple_client libevent_test
CC=gcc
CCOPTS=-Wall -Wextra
INC=

LIBS=-lstdc++ -libevent -libevent_core

all: rm_directory make_directory $(TARGETS)

rm_directory:
	rm -rf ./bin

make_directory:
	mkdir bin

ishell:
	$(CC) $(CCOPTS) $(INC) -o ush ush.c makeargv.c $(LIBS)
	mv ush ./bin

simple_client:
	$(CC) $(CCOPTS) $(INC) -o simple_client simple_client.c $(LIBS)
	mv simple_client ./bin

libevent_test:
	$(CC) $(CCOPTS) $(INC) -o libevent_test libevent_test.c ($LIBS)
	mv libevent_test ./bin
