CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -Werror -O2 -pg --save-temps -fPIC
LDFLAGS=

SRC=src
OBJ=obj
HDR=hdr
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
HDRS=$(wildcard $(SRC)/*.h)

BINDER=bin
BIN=$(BINDER)/caesar-cipher
SUBMITNAME=caesar-cephir.zip

all: $(BIN)

release: CFLAGS=-Wall -Wextra -Wpedantic -Werror -O2 -DNDEBUG -pg --save-temps -fPIC
release: clean
release: $(BIN)

$(BIN): $(OBJ) $(OBJS) $(BINDER)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

$(BINDER):
	mkdir -p $@

leakcheck:
	valgrind -s --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes ./bin/main

clean:
	$(RM) -r $(BINDER)/* $(OBJ)/*
	$(RM) -r $(OBJ)
	$(RM) -r $(BINDER)
	$(RM) *.i
	$(RM) *.zip
	$(RM) *.s
	$(RM) *.bc
	$(RM) *.txt
	$(RM) *.out

submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN)