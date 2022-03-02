// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) { return 1.; }
    if (n == 1) { return value; }
    double x = value;
    for (uint64_t i = 1; i < n; i++) {
        value *= x;
    }
    return value;
}

uint64_t fact(uint16_t n) {
    uint64_t ans = 1;
    for (uint64_t i = 2; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

double calcItem(double x, uint16_t n) {
    double ans = 1.;
    for (uint64_t i = 0; i <= n; i++) {
        ans += pown(x, n) / fact(n);
    }
    return ans;
}

double expn(double x, uint16_t count) {
    double ans = 1.;
    for (uint64_t i = 1; i <= count; i++) {
        ans += pown(x, i) / fact(i);
    }
    return ans;
}

double sinn(double x, uint16_t count) {
    double ans = x;
    for (uint64_t i = 2; i <= count; i++) {
        ans += pown(-1, i-1) * (pown(x, i*2-1) / fact(i*2-1));
    }
    return ans;
}

double cosn(double x, uint16_t count) {
    double ans = 1;
    for (uint64_t i = 2; i <= count; i++) {
        ans += pown(-1, i - 1) * (pown(x, i * 2 - 2) / fact(i * 2 - 2));
    }
    return ans;
}
