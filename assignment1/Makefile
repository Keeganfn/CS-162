CC = g++
exe_file = wiz_app

Debug ?= 1
ifeq ($(DEBUG), 1)
	CFLAGS := -g -Wall
else
	CFLAGS := -DNDEBUG -O3
endif

$(exe_file): prog.o wizard.o
	$(CC) prog.o wizard.o -o $(exe_file) $(CFLAGS)
wizard.o: wizard.cpp
	$(CC) -c wizard.cpp $(CFLAGS)
prog.o: prog.cpp
	$(CC) -c prog.cpp $(CFLAGS)

clean:
	rm -f *.out *.o $(exe_file)
.PHONY: clean
