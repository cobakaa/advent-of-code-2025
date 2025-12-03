#include <stdio.h>

int main() {

    char line[256];
    unsigned int sum = 0;
    while (scanf("%s", line) == 1) {
        char m = '1';
        int mi = 0;
        int len = 0;
        unsigned int tmp = 0;
        for (int i = 0; line[i] != '\0'; ++i) {
            if (line[i] > m) {
                m = line[i];
                mi = i;
            }
            len++;
        }

        tmp += m - '0';
        m = '1';
        if (mi != len - 1) {
            for (int i = mi + 1; line[i] != '\0'; ++i) {
                if (line[i] > m) {
                    m = line[i];
                }
            }
            tmp = tmp * 10 + (m - '0');
        } else {
            for (int i = 0; i < mi; ++i) {
                if (line[i] > m) {
                    m = line[i];
                }
            }    
            tmp = (m - '0') * 10 + tmp;
        }
        


        // printf("%u\n", tmp);
        sum += tmp;

    }

    printf("%u\n", sum);
    

    return 0;
}