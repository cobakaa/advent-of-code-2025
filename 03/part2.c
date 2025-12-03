#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long int ull;

int main() {

    char line[256];
    ull sum = 0;
    while (scanf("%s", line) == 1) {
        size_t sl = strlen(line);
        ull tmp = 0;
        int start = 0;
        for (size_t i = 12; i > 0; --i) {
            char cc = '9';
            int found = 0;
            while (cc != '0') {
                for (int j = start; line[j] != '\0'; ++j) {
                    if (line[j] == cc && sl - j >= i) {
                        tmp = tmp * 10 + (line[j] - '0');
                        line[j] = '0';
                        start = j;
                        found = 1;
                        break;
                    }
                }

                cc--;
                if (found) break;
            }
        }

        // printf("%llu\n", tmp);
        sum += tmp;
    }

    printf("%llu\n", sum);

    return 0;
}