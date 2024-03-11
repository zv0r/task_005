#ifndef HOUSE_H
#define HOUSE_H

int roof_price(int n, int k, int h);
int basement_price(int n, int k);
int wall_price(int w, int h);
int calc_building(int n, int k, int h);
void out(int price, int sum);

#endif