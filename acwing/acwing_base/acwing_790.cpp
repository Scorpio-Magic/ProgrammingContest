/*
    Author: PeterAn
    Date: 2023-07-19
    Algorithm: binary search || double precision
*/
#include <cstdio>
#include <algorithm>

int main() {
    double x; scanf("%lf", &x);
    double l = -10000, r = 10000;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }
    printf("%.6lf\n", l);
    return 0;
}
