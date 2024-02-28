#include <stdio.h>

int main() {
    int T; 
    scanf("%d", &T);

    while (T--) {
        int n; 

        do {
            scanf("%d", &n);

            if (n < 5 || n > 100) {
                printf("Out of range. Try again!\n");
            }

        } while (n < 5 || n > 100);

        int opened[n + 1];
        for (int i = 1; i <= n; ++i) {
            opened[i] = 0;
        }

        for (int j = 1; j <= n; ++j) {
            for (int room = j; room <= n; room += j) {
                opened[room] = !opened[room];       // ! 1 참 0 거짓
            }
        }

        int escaped = 0;
        for (int i = 1; i <= n; ++i) {
            if (opened[i] == 1) {
                ++escaped;
            }
        }

        printf("%d\n", escaped);
    }

    return 0;
}
