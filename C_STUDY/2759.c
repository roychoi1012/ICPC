# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>

# define Max_Size 100

void flip(uint32_t arr[], uint32_t k) {
    int temp, i = 0;
    while (i < k) {
        temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
        i++;
        k--;
    }
}

int Max_idx(uint32_t arr[], uint32_t n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void pancakeSort(uint32_t arr[], uint32_t n) {
    int flipCount = 0; // 뒤집은 횟수를 저장하는 변수
    uint32_t flip_cnt_arr[Max_Size]; // 뒤집은 인덱스를 저장하는 배열

    for (uint32_t idx = n; idx > 1; idx--) {
        uint32_t maxIndex = Max_idx(arr, idx);

        if (maxIndex != idx - 1) {
            if (maxIndex != 0) {
                flip(arr, maxIndex);
                flipCount++;
                flip_cnt_arr[flipCount - 1] = maxIndex + 1;
            }

            flip(arr, idx - 1);
            flipCount++;
            flip_cnt_arr[flipCount - 1] = idx;
        }
    }

    // 뒤집은 횟수 출력
    printf("%d ", flipCount);

    // 배열의 값을 순차적으로 출력
    for (int i = 0; i < flipCount; i++) {
        printf("%d ", flip_cnt_arr[i]);
    }
    printf("\n");
}





int main() {
    uint32_t T, N, PK[Max_Size];
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);
        for (uint32_t i = 0; i < N; i++) {
            scanf("%d", &PK[i]);
        }
    pancakeSort(PK, N);
    }

    return 0;
}
