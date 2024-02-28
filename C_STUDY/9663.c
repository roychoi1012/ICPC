# include <stdio.h>
# include <stdlib.h>

void set(int i, int N, int *flag_a, int *flag_b, int *flag_c, int *pos);
void print(int N, int *pos);
int count = 0;

int main()
{
    int N;
    do {
        scanf("%d", &N);

        if (N < 1 || N >= 15)
            printf("'N' range is 1 <= N < 15, try again!\n");

    } while (N < 1 || N >= 15);

    int *flag_a = calloc(N, sizeof(int));
    int *flag_b = calloc(2 * N - 1, sizeof(int));
    int *flag_c = calloc(2 * N - 1, sizeof(int));
    int *pos    = calloc(N, sizeof(int));

    for (int i = 0; i < N; i++)
        flag_a[i] = 0;
    for (int i = 0; i < 2 * N - 1; i++)
        flag_b[i] = flag_c[i] = 0;

    set(0, N, flag_a, flag_b, flag_c, pos);                     // 0열에 배치

    free(flag_a);
    free(flag_b);
    free(flag_c);
    free(pos);

    printf("%d\n", count);

    return 0;

}

void print(int N, int *pos)
{
    // for (int i = 0; i < N; i++)
    //     printf("%2d", pos[i]);
    // putchar('\n');
    count++;
}

/*--- i열에서 알맞은 위치에 퀸을 배치 ---*/
void set(int i, int N, int *flag_a, int *flag_b, int *flag_c, int *pos)
{
    for (int j = 0; j < N; j++) {
        if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + (N - 1)]) {
            pos[i] = j;
            if (i == N - 1)         // 모든 열에 배치를 마침
                print(N, pos);
            else {
                flag_a[j] = flag_b[i + j] = flag_c[i - j + (N - 1)] = 1;
                set(i + 1, N, flag_a, flag_b, flag_c, pos);     // 다음 열에 배치
                flag_a[j] = flag_b[i + j] = flag_c[i - j + (N - 1)] = 0;
            }
        }
    }
}
