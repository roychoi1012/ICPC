// int형 스택 IntStack(소스)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int max;    // 스택 용량
    int ptr;    // 스택 포인터
    int* stk;   // 스택의 첫 요소에 대한 포인터
} IntStack;

/*--- 스택 초기화 ---*/
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

/*--- 스택에 데이터 푸시 ---*/
int Push(IntStack *s, int x)
{
    if (s->ptr >= s->max)               // 스택이 가득 참
        return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

/*--- 스택에서 데이터를 제거 ---*/
int Pop(IntStack *s, int *x)
{
    if (s->ptr <= 0)                    // 스택이 비어 있음
        return -1;
    *x = s->stk[--s->ptr];
    return *x;
}

/*--- 스택에서 데이터 엿보기 ---*/
int Top(const IntStack *s, int *x)
{
    if (s->ptr <= 0)                    // 스택이 비어 있음
        return -1;
    *x = s->stk[s->ptr - 1];
    return *x;
}

/*--- 스택의 모든 요소 삭제 ---*/
void Clear(IntStack *s)
{
    s->ptr = 0;
}

/*--- 스택 용량 ---*/
int Capacity(const IntStack *s)
{
    return s->max;
}

/*--- 스택에 쌓여 있는 데이터 수 ---*/
int Size(const IntStack *s)
{
    return s->ptr;
}

/*--- 스택이 비어 있는가? ---*/
int IsEmpty(const IntStack *s)
{
    return s->ptr <= 0;
}

/*--- 스택은 가득 찼는가? ---*/
int IsFull(const IntStack *s)
{
    return s->ptr >= s->max;
}

/*--- 스택에서 검색 ---*/
int Search(const IntStack *s, int x)
{
    for (int i = s->ptr - 1; i >= 0; i--)   // 꼭대기(top) → 바닥(bottom)으로 선형 검색
        if (s->stk[i] == x)
            return i;       // 검색 성공
    return -1;              // 검색 실패
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntStack *s)
{
    for (int i = 0; i < s->ptr; i++)        // 바닥(bottom) → 꼭대기(top)로 스캔
        printf("%d ", s->stk[i]);
    putchar('\n');
}

/*--- 스택 종료 ---*/
void Terminate(IntStack *s)
{
    if (s->stk != NULL)
        free(s->stk);       // 배열을 삭제
    s->max = s->ptr = 0;
}

int main() 
{
    int N, X;
    IntStack stk;

    do {
        scanf("%d", &N);

        if (N < 1 || N > 10000) {
            printf("Invalid input. N must be between 1 and 10000.\n");
        }

    } while (N < 1 || N > 10000);

    Initialize(&stk, N);
    char order[10];

    while (N--)
    {
        scanf("%s", order);

        if (!strcmp(order, "push")) 
        {
            scanf("%d", &X);
            Push(&stk, X);
        }
        else if (!strcmp(order, "pop"))
        {
            printf("%d\n", Pop(&stk, &X));
        }
        else if (!strcmp(order, "size"))
        {
            printf("%d\n", Size(&stk));
        }
        else if (!strcmp(order, "empty"))
        {
            printf("%d\n", IsEmpty(&stk));
        }
        else if (!strcmp(order, "top"))
        {
            printf("%d\n", Top(&stk, &X));
        }
    }
    
    return 0;
}

