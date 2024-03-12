#define _GNU_SOURCE

#include "travel.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "misc.h"

int main(void) {
    ride(load_file());
    exit(EXIT_SUCCESS);
}

FILE* load_file() {
    FILE* fp = NULL;
    char* filename;

    scanf("%ms", &filename);
    fp = fopen(filename, "r");
    free(filename);
    if (fp == NULL) {
        achtung();
    }
    return fp;
}

void append_string(char** string, char* append) {
    *string = realloc(*string, strlen(*string) + strlen(append) + 2);
    sprintf(*string, "%s%s\n", *string, append);
}

void ride(FILE* fp) {
    int total_ride_hours = 0;
    int ride_hours = 0;
    int points_ride_hours = 0;
    char* result_string = calloc(1, sizeof(char));
    Point curr, prev;

    read_point(&prev, fp);
    append_string(&result_string, prev.name);
    while (read_point(&curr, fp)) {
        if ((points_ride_hours = ride_time(prev, curr, SPEED)) > MAX_RIDE_HOURS) {
            free(result_string);
            printf("Travel is impossible!");
            exit(EXIT_SUCCESS);
        } else {
            total_ride_hours += points_ride_hours;
            ride_hours += points_ride_hours;
            if (ride_hours > MAX_RIDE_HOURS) {
                append_string(&result_string, prev.name);
                total_ride_hours += RELAX_HOURS;
                ride_hours = 0;
            }
            prev = curr;
        }
    }
    append_string(&result_string, prev.name);
    printf("%s", result_string);
    printf("%d", total_ride_hours);

    free(result_string);
    fclose(fp);
}

int ride_time(Point point1, Point point2, int speed) {
    return ceil((abs(point2.x - point1.x) + abs(point2.y - point1.y)) / (double)speed);
}

bool read_point(Point* point, FILE* fp) {
    char* line;
    int x, y;
    bool result;
    if (fscanf(fp, "%ms %d %d", &line, &x, &y) == 3) {
        *point = build_point(line, x, y);
        result = true;
    } else {
        result = false;
    }
    free(line);
    return result;
}

Point build_point(char* name, int x, int y) {
    Point result = {
        .x = x,
        .y = y,
    };
    strncpy(result.name, name, 1023);
    return result;
}