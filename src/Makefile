CC=gcc
CFLAGS=`pkg-config --cflags --libs gtk+-3.0` -lm

all: ${wildcard ./*.c}
	${CC} ${CFLAGS} ${wildcard ./*.c} -o main
