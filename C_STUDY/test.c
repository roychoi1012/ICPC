#include <stdio.h>

#define MAX_N  15
#define Weight 500

int N, K;
int kit[MAX_N];
int result = 0;
int visited[MAX_N];

void find(int x, int n) {
    if (x < Weight) {
        return;
    }
    if (n == N) {
        result++;
        return;
    }
    x -= K;
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            find(x + kit[i], n + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &kit[i]);
    }

    find(Weight, 0);
    printf("%d\n", result);

    return 0;
}
    