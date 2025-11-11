#include "myops.h"

double mymod(double a, double b) {
    int ia = (int)a;
    int ib = (int)b;
    if (ib == 0) return 0;
    return (double)(ia % ib);
}