CC = g++
exe_file = studentdb_app


DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS := -g -Wall
else
	CFLAGS := -DNDEBUG -O3
endif

$(exe_file): studentdb.o driver.o
	$(CC) studentdb.o driver.o -o $(exe_file) $(CFLAGS)
book.o: studentdb.cpp
	$(CC) -c studentdb.cpp $(CFLAGS)
prog.o: driver.cpp
	$(CC) -c driver.cpp $(CFLAGS)

clean:
	rm -f *.out *.o $(exe_file)

.PHONY: clean
