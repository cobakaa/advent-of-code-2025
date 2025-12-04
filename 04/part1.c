#include <stdio.h>
#include <string.h>

int perm[3] = {-1, 0, 1};

int main() {

    char lines[256][256];
    int nl = 0;
    while (scanf("%s", lines[nl]) == 1) {
        nl++;
    }
    int sl = strlen(lines[0]);
    int sum = 0;
    for (int i = 0; i < nl; ++i) {
        for (int j = 0; j < sl; ++j) {
            if (lines[i][j] != '@') continue;

            int n = 0;
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    int ix = i + perm[x];
                    int jy = j + perm[y];
                    if (ix == i && jy == j) continue;
                    if (ix >= 0 && ix < nl && jy >= 0 && jy < sl) {
                        if (lines[ix][jy] == '@') {
                            n++;
                        }
                    }
                }
            }

            if (n < 4) {
              sum++;
            //   printf("%d %d\n", i, j);  
            } 
        }
    }

    printf("%d\n", sum);

    return 0;
}