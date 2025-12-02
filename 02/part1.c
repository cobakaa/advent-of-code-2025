#include <stdio.h>

int dcount(unsigned long int x) {
    int res = 0;
    while (x != 0) {
        x /= 10;
        res++;
    }
    return res;
}

unsigned long int mpow10(int c) {
    unsigned long int res = 1;

    while (c-- != 0) {
        res *= 10;
    }
    
    return res;
}

unsigned long int pow9(int c) {
    unsigned long int res = 0;

    while (c-- != 0) {
        res = res * 10 + 9;
    }

    return res;
}

unsigned long int lucky_sum(unsigned long int lhs, unsigned long int rhs, int c) {
    unsigned long int sum = 0;
    unsigned long int d = mpow10(c);
    int f = 0;
    // printf("lhs=%lu, rhs=%lu, c=%d\n", lhs, rhs, c);
    for (;lhs <= rhs; lhs += f ? d + 1 : 1) {
        if (lhs % d == lhs / d) {
            sum += lhs;
            f = 1;
        }
    }
    
    return sum;
}

int main() {

    unsigned long int lhs, rhs;
    unsigned long int sum = 0;
    while (scanf("%lu-%lu,", &lhs, &rhs) == 2) {
        int ldc = dcount(lhs);
        int rdc =  dcount(rhs);
        if (ldc % 2 != 0 && rdc % 2 != 0) {
            continue;
        }

        if (ldc % 2 != 0 && rdc % 2 == 0) {
            lhs = mpow10(ldc++);
        } else if (ldc % 2 == 0 && rdc % 2 != 0) {
            rhs = pow9(--rdc);
        }

        unsigned long int ls = lucky_sum(lhs, rhs, ldc/2);
        sum += ls;
    }

    printf("%lu\n", sum);

    return 0;
}