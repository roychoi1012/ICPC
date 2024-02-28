# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>

# define Max_Size 30

typedef struct {
    int max;    // 스택 용량
    int ptr;    // 스택 포인터
    int* stk;   // 스택의 첫 요소에 대한 포인터
} IntStack;

int Initialize(IntStack *s, int max)
{
    s->ptr = 0;
    if ((s->stk = calloc(max, sizeof(int))) == NULL) {
        s->max = 0;                     // 배열의 생성에 실패
        return -1;
    }
    s->max = max;
    return 0;
}

int main()
{
    IntStack stk;
    Initialize(&stk, Max_Size);

    int32_t diameter;

    while (scanf("%d", &diameter) == 1) {
        Push(&stk, diameter);
    }


}