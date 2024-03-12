CC := gcc
CFLAGS := -g -Wall -Wextra -Werror -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector
BIN_DIR := ../bin

all: build

build: house travel morse

house:
	${CC} ${CFLAGS} -o ${BIN_DIR}/house house.c

travel:
	${CC} ${CFLAGS} -o ${BIN_DIR}/travel travel.c misc.c -lm

morse:
	${CC} ${CFLAGS} -o ${BIN_DIR}/morse morse.c misc.c
