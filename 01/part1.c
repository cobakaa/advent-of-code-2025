#include <stdio.h>
#include <stdlib.h>

int main() {
    int start = 50;
    int pass = 0;
    char line[256];
    while (scanf("%s", line) == 1) {
        char dir = line[0];
        line[0] = '0';
        int num = atoi(line);
        num %= 100;
        if (dir == 'L') {
            start -= num;
            if (start < 0) {
                start += 100;
            }
        } else if (dir == 'R') {
            start += num;
            start %= 100;
        }

        if (start == 0 ) {
            pass++;
        }
    }
    
    printf("%d\n", pass);

    return 0;
}