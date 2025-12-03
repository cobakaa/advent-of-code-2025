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
            int found = 0;
            char m = '0';
            int mi = start;
            for (int j = start; j <= sl - i; ++j) {
                if (line[j] > m) {
                    mi = j;
                    m = line[j];
                    start = j + 1;
                }
            }

            tmp = tmp * 10 + (m - '0');
        }

        printf("%llu\n", tmp);
        sum += tmp;
    }

    printf("%llu\n", sum);

    return 0;
}
