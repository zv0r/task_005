#include "house.h"

#include <stdio.h>
#include <stdlib.h>

#include "misc.h"

int main(void) {
    int n, k, h, sum;
    scanf("%d %d %d %d", &n, &k, &h, &sum);
    out(calc_building(n, k, h), sum);
    exit(EXIT_SUCCESS);
}

int roof_price(int n, int k, int h) { return (n * k * 700) + h * 100; }

int basement_price(int n, int k) { return n * k * 1000; }

int wall_price(int w, int h) { return w * h * 500; }

int calc_building(int n, int k, int h) {
    return roof_price(n, k, h) + basement_price(n, k) + 2 * wall_price(n, h) + 2 * wall_price(k, h);
}

void out(int price, int sum) {
    int diff = sum - price;
    printf(diff < 0 ? "NO " : "YES");
    if (diff < 0) {
        printf("%d", abs(diff));
    }
}