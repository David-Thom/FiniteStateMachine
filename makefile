#Name: <Thompson, Diekololaoluwa>
#NSID <scb597>
#Student Number: 11351837
#Course CMPT214-<02> 2025


CC = gcc

CFLAGS = -Wall -Wextra -std=c99 -pedantic

CPPFLAGS = -I cmpt214/a4

.PHONY: all

all: fsm_cli 
	

fsm_process: fsm_process.o
	$(CC) -o fsm_process $(CFLAGS) fsm_process.o $(CPPFLAGS) 

fsm_process.o: fsm_process.c fsm.h 
	$(CC) -o fsm_process.o -c $(CFLAGS) fsm_process.c $(CPPFLAGS) 

fsm_util: fsm_util.o 
	$(CC) -o fsm_util $(CFLAGS) fsm_util.o $(CPPFLAGS)

fsm_util.o: fsm_util.c fsm.h
	$(CC) -o fsm_util.o -c $(CFLAGS) fsm_util.c $(CPPFLAGS) 

fsm_remove: fsm_remove.o 
	$(CC) -o fsm_remove $(CFLAGS) fsm_remove.o $(CPPFLAGS) 

fsm_remove.o: fsm_remove.c fsm.h
	$(CC) -o fsm_remove.o -c $(CFLAGS) fsm_remove.c $(CPPFLAGS)

fsm_adder: fsm_adder.o 
	$(CC) -o fsm_adder $(CFLAGS) fsm_adder.o $(CPPFLAGS) 

fsm_adder.o: fsm_adder.c fsm.h 
	$(CC) -o fsm_adder.o -c $(CFLAGS) fsm_adder.c $(CPPFLAGS) 

fsm_init: fsm_init.o 
	$(CC) -o fsm_init $(CFLAGS) fsm_init.o $(CPPFLAGS) 

fsm_init.o: fsm_init.c fsm.h 
	$(CC) -o fsm_init.o -c $(CFLAGS) fsm_init.c $(CPPFLAGS) 


libfsm.a: fsm_init.o fsm_adder.o fsm_remove.o fsm_util.o fsm_process.o
	ar rcs libfsm.a fsm_init.o fsm_adder.o fsm_remove.o fsm_util.o fsm_process.o

libfsm.so: fsm_cli.o fsm_remove.o fsm_init.o fsm_adder.o fsm_util.o fsm_process.o
	$(CC) -o libfsm.so -shared fsm_init.o -I fsm_remove.o -I fsm_adder.o -I fsm_util.o -I fsm_process.o -I fsm_cli.o 

fsm_cli: fsm_cli.o fsm_remove.o fsm_init.o fsm_adder.o fsm_util.o fsm_process.o
	$(CC) -o fsm_cli $(CFLAGS) fsm_adder.o fsm_cli.o fsm_remove.o fsm_init.o fsm_util.o fsm_process.o 

fsm_cli.o: fsm_cli.c fsm.h 
	$(CC) -o fsm_cli.o -c $(CFLAGS) fsm_cli.c 

fsm_cli_static: fsm_cli_static.o
	$(CC) -o fsm_cli_static $(CFLAGS) fsm_cli_static.o $(CPPFLAGS) 

fsm_cli_static.o: libfsm.a fsm_cli.o
	$(CC) -o fsm_cli_static.o fsm_cli.o $(CFLAGS) $(CPPFLAGS) -L. libfsm.a 

fsm_cli_dynamic: fsm_cli_dynamic.o	
	$(CC) -o fsm_cli_dynamic $(CFLAGS) fsm_cli_static.o $(CPPFLAGS)

fsm_cli_dynamic.o: libfsm.so fsm_cli.o
	$(CC) -o fsm_cli_dynamic.o fsm_cli.o $(CFLAGS) $(CPPFLAGS) -L. libfsm.so 


fsmtest: fsmtest.o
	$(CC) -o fsmtest $(CFLAGS) $(CPPFLAGS)

fsmtest.o: fsmtest.c lib_test_static.a
	$(CC) -o fsmtest.o -c $(CFLAGS) fsmtest.c $(CPPFLAGS) -L. lib_test_static.a 

lib_test_static: fsm_adder.o
	ar rsc lib_test_static fsm_adder.o

clean:
	rm -f fsm_cli.o fsm_cli fsm_process.o fsm_process fsm_util.o fsm_util fsm_remove.o fsm_remove fsm_adder.o fsm_adder fsm_init.o fsm_init libfsm.a libfsm.so fsm_cli_static.o fsm_cli_dynamic.o
