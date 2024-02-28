#include <stdio.h>

int main() {
    int N, K; // 테스트 케이스의 개수

    do {
        scanf("%d %d", &N, &K);

        if (N < 1 || N > 8) {
            printf("Out of range 'N'. Try again! \n");
        }
        if (K < 1 || K > 50) {
            printf("Out of range 'K'. Try again! \n");
        }

    } while ((N < 1 || N > 8) || (K < 1 || K > 50));
    
    int A[N];

    for (int i = 0; i < N; i++) 
    {
        scanf("%d", &A[i]);
    }

    for (int j = 0; j < N; j++)
    {
        if (A[j] - K >= 0)
        {
            // if (/* condition */)
            // {
            //     /* code */
            // }
            
        }
        
        
    }
    


    return 0;
}

void enter_val()
{
    
}
