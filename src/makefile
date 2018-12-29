CC=gcc
CFLAGS=-I.
BIN_DIR = obj
DEPS = vector.h stack.h list.h queue.h set.h default_types.h
OBJ = gen.o vector.o stack.o list.o queue.o set.o 
BIN_OBJS := 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all:
	for TEMP_O in $(OBJ) ; do \
		$(BIN_OBJS) := $(BIN_OBJS) + "$(BIN_DIR)/"$$TEMP_O ; \
	done
	$(CC) -o  $(BIN_DIR)/gen $(BIN_OBJS)

clean:
	rm -f *.o

test:
	valgrind --leak-check=full ./gen