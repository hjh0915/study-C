CC = gcc
CFLAGS = -Wall -g -std=c99
LDFLAGS = -lm
LIB_DIR = ../lib
BIN_DIR = ../bin
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))

all: circle
	mv $< $(BIN_DIR)
	mv $(OBJS) $(LIB_DIR)

circle: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	
$(OBJS):%.o:%.c
	$(CC) $(CFLAGS) -c $<
