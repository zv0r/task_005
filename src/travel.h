#ifndef TRAVEL_H
#define TRAVEL_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_RIDE_HOURS 8
#define RELAX_HOURS 8
#define SPEED 60

typedef struct point_t {
    char name[1024];
    int x;
    int y;
} Point;

Point build_point(char* name, int x, int y);

bool read_point(Point* point, FILE* fp);

FILE* load_file();

void ride(FILE* fp);

int ride_time(Point point1, Point point2, int speed);

void append_string(char** string, char* append);

#endif