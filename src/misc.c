#include "misc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void achtung() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}

void append_string(char** string, char* append, char terminator) {
    char* old_string = malloc(strlen(*string) + 1);
    strcpy(old_string, *string);
    *string = realloc(*string, strlen(*string) + strlen(append) + 2);
    sprintf(*string, "%s%s%c", old_string, append, terminator);
    free(old_string);
}