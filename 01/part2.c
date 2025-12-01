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
        pass += num / 100;
        num %= 100;
        int click = 0;
        if (dir == 'L') {
            start -= num;
            if (start < 0) {
                if (start + num != 0) click = 1;
                start += 100;
            }
        } else if (dir == 'R') {
            start += num;
            if (start > 99) {
                if (start - num != 0) click = 1;
                start %= 100;
            }
        }

        if (start == 0 || click) {
            pass++;
        }
        // printf("start=%d, pass=%d\n", start, pass);
    }
    
    printf("%d\n", pass);

    return 0;
}