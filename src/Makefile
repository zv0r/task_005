CC := gcc
CFLAGS := -g -Wall -Wextra -Werror -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector
BIN_DIR := ../bin

all: build

build: house

house:
	${CC} ${CFLAGS} -o ${BIN_DIR}/house house.c
