#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int perm[3] = {-1, 0, 1};

#define QUEUE_MAX_SIZE 256*256

typedef struct {
    int items[QUEUE_MAX_SIZE];
    int front;
    int back;
} Queue;

void queue_init(Queue *q) {
    q->front = -1;
    q->back = 0;
}

bool queue_is_empty(Queue *q) {
    return q->front == q->back - 1;
}

bool queue_is_full(Queue *q) {
    return q->back == QUEUE_MAX_SIZE;
}

void queue_insert(Queue *q, int val) {
    if (queue_is_full(q)) return;

    q->items[q->back++] = val;
}

int queue_pop(Queue *q) {
    if (queue_is_empty(q)) return -1; 
    return q->items[++(q->front)];
}

int main() {
    Queue q;
    queue_init(&q);


    char lines[256][256];
    char ns[256][256] = {0};
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

            ns[i][j] = n;
            if (n < 4) {
                queue_insert(&q, i*sl + j);
            }
        }
    }

    while (!queue_is_empty(&q)) {
        int c = queue_pop(&q);
        int y = c / sl;
        int x = c % sl;

        if (lines[y][x] == '.') continue;

        lines[y][x] = '.';
        ns[y][x] = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int ix = x + perm[i];
                int jy = y + perm[j];
                if (ix == x && jy == y) continue;
                if (ix >= 0 && ix < nl && jy >= 0 && jy < sl) {
                    if (ns[jy][ix] == 4) {
                        queue_insert(&q, jy*sl + ix);
                    }
                    ns[jy][ix]--;
                }
            }
        }
        sum++;
    }

    printf("%d\n", sum);

    return 0;
}
