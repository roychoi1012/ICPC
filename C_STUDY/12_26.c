#include <stdio.h>

int main(){
    int a;
    scanf("%d", &a);
    if (a >= 1 && a <= 9)
    {
        for (int i = 1; i < 10; i++)
    {
        int b;
        b = a * i;
        printf("%d * %d = %d\n",a ,i, b);
    }
    }
}
