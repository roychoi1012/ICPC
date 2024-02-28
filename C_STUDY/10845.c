// int형 큐 IntQueue(소스)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int max;    // 큐의 최대 용량
    int num;    // 현재의 요소 개수
    int front;  // 프런트
    int rear;   // 리어
    int* que;   // 큐의 맨 앞 요소에 대한 포인터
} IntQueue;

/*--- 큐 초기화 ---*/
int Initialize(IntQueue* q, int max)
{
    q->num = q->front = q->rear = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;                             // 배열 생성에 실패
        return -1;
    }
    q->max = max;
    return 0;
}

/*--- 큐에 데이터를 인큐 ---*/
int Enque(IntQueue* q, int x)
{
    if (q->num >= q->max)
        return -1;                              // 큐가 가득 참
    else {
        q->num++;
        q->que[q->rear++] = x;
        if (q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}

/*--- 큐에서 데이터를 디큐 ---*/
int Deque(IntQueue* q, int* x)
{
    if (q->num <= 0)                            // 큐가 비어 있음
        return -1;
    else {
        q->num--;
        *x = q->que[q->front++];
        if (q->front == q->max)
            q->front = 0;
        return *x;
    }
}

/*--- 큐에서 데이터를 피크 ---*/
int Front(IntQueue* q, int* x)
{
    if (q->num <= 0)                            // 큐가 비어 있음
        return -1;
    *x = q->que[q->front];
    return *x;
}

int Back(IntQueue* q, int* x)
{
    if (q->num <= 0)                            // 큐가 비어 있음
        return -1;
    *x = q->que[q->rear -1];
    return *x;
}

/*--- 모든 데이터 삭제 ---*/
void Clear(IntQueue* q)
{
    q->num = q->front = q->rear = 0;
}

/*--- 큐의 최대 용량 ---*/
int Capacity(const IntQueue* q)
{
    return q->max;
}

/*--- 큐에 쌓여 있는 데이터 수 ---*/
int Size(const IntQueue* q)
{
    return q->num;
}

/*--- 큐가 비어 있는가? ---*/
int IsEmpty(const IntQueue* q)
{
    return q->num <= 0;
}

/*--- 큐가 가득 찼는가? ---*/
int IsFull(const IntQueue* q)
{
    return q->num >= q->max;
}

/*--- 큐에서 검색 ---*/
int Search(const IntQueue* q, int x)
{
    for (int i = 0; i < q->num; i++) {
        int idx;
        if (q->que[idx = (i + q->front) % q->max] == x)
            return idx;     // 검색 성공
    }
    return -1;              // 검색 실패
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntQueue* q)
{
    for (int i = 0; i < q->num; i++)
        printf("%d ", q->que[(i + q->front) % q->max]);
    putchar('\n');
}

/*--- 큐 종료 ---*/
void Terminate(IntQueue* q)
{
    if (q->que != NULL)
        free(q->que);                           // 배열을 해제
    q->max = q->num = q->front = q->rear = 0;
}

int main() {
    int N, X;
    IntQueue qst;

    do {
        scanf("%d", &N);

        if (N < 1 || N > 10000) {
            printf("Invalid input. N must be between 1 and 10000.\n");
        }

    } while (N < 1 || N > 10000);

    Initialize(&qst, N);
    char order[10];

    while (N--)
    {
        scanf("%s", order);

        if (!strcmp(order, "push")) 
        {
            scanf("%d", &X);
            Enque(&qst, X);
        }
        else if (!strcmp(order, "pop"))
        {
            printf("%d\n", Deque(&qst, &X));
        }
        else if (!strcmp(order, "size"))
        {
            printf("%d\n", Size(&qst));
        }
        else if (!strcmp(order, "empty"))
        {
            printf("%d\n", IsEmpty(&qst));
        }
        else if (!strcmp(order, "front"))
        {
            printf("%d\n", Front(&qst, &X));
        }
        else if (!strcmp(order, "back"))
        {
            printf("%d\n", Back(&qst, &X));
        }
    }

    return 0;
}
