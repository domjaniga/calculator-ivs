CC=gcc
CFLAGS= -lm -rdynamic

all: ${wildcard ./*.c}
	${CC} ${CFLAGS} $(shell pkg-config --cflags gtk+-3.0) ${wildcard ./*.c} -o main $(shell pkg-config --libs gtk+-3.0)
