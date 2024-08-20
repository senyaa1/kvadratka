CC=gcc
CFLAGS=-lm
NAME=kvadratka

${NAME}: *.c
	${CC} -o ${NAME} $^ ${CFLAGS}

clean:
	rm -f *.o ${NAME}


.PHONY: ${NAME}

