#include <stdio.h>

int N, K;
int weights[8];
int used[8]; // 사용한 운동 키트 표시

int isWeightValid(int *order) {
    int currentWeight = 500;
    for (int i = 0; i < N; i++) {
        currentWeight += weights[order[i]]; // 운동 키트의 중량 증가
        currentWeight -= K; // 매일 중량 감소
        if (currentWeight < 500) {
            return 0; // 중량이 500 미만이면 조건 불만족
        }
    }
    return 1; // 모든 날에 대해 중량이 500 이상이면 조건 만족
}

void generatePermutations(int *order, int depth) {
    if (depth == N) {
        if (isWeightValid(order) == 1) {
            // 조건을 만족하는 경우 출력 또는 원하는 작업 수행
            for (int i = 0; i < N; i++) {
                printf("%d ", order[i] + 1); // 배열은 0부터 시작이지만, 문제에서는 1부터 시작이므로 +1
            }
            printf("\n");
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (used[i] == 0) {
            order[depth] = i;
            used[i] = 1; // 해당 운동 키트 사용 표시
            generatePermutations(order, depth + 1);
            used[i] = 0; // 해당 운동 키트 사용 취소
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i]);
    }

    int order[8]; // 순열을 저장할 배열
    generatePermutations(order, 0);

    return 0;
}
