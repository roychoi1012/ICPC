#include <stdio.h>
#define DATE(Y, M, D) Y ## M ## D

int main() {
    printf("생년월일 : %d\n", DATE(11, 06, 10));
    printf("생년월일 : %d\n", DATE(10, 11, 25));

    return 0;
}