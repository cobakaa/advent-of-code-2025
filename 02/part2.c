#include <stdio.h>

int dcount(unsigned long long int x) {
    int res = 0;
    while (x != 0) {
        x /= 10;
        res++;
    }
    return res;
}

unsigned long long int mpow10(int c) {
    unsigned long long int res = 1;

    while (c-- != 0) {
        res *= 10;
    }
    
    return res;
}

unsigned long long int pow9(int c) {
    unsigned long long int res = 0;

    while (c-- != 0) {
        res = res * 10 + 9;
    }

    return res;
}

unsigned long long int lucky_sum(unsigned long long int lhs, unsigned long long int rhs, int c) {
    unsigned long long int sum = 0;
    // printf("lhs=%lu, rhs=%lu, c=%d\n", lhs, rhs, c);
    for (;lhs <= rhs; lhs += 1) {
        for (int i = 1; i <= c; ++i) {
            int f = 1;
            unsigned long long int td = mpow10(i);
            unsigned long long int t = lhs;
            unsigned long long int cmp = t % td;
            if (dcount(cmp) < i) continue;
            int count = 0;
            while (t != 0) {
                if (cmp != t % td) {
                    f = 0;
                    break;
                }

                t /= td;
                count++;
            }

            if (f && count >= 2) {
                sum += lhs;
                // printf("ln = %llu, cmp=%llu\n", lhs, cmp);
                break;
            }
        }
    }
    
    return sum;
}

int main() {

    unsigned long long int lhs, rhs;
    unsigned long long int sum = 0;
    while (scanf("%llu-%llu,", &lhs, &rhs) == 2) {
        int rdc = dcount(rhs);
        unsigned long long int ls = lucky_sum(lhs, rhs, rdc/2);
        sum += ls;
    }

    printf("%llu\n", sum);

    return 0;
}