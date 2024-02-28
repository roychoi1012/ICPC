#include <stdio.h>
#define SIZE 5

struct employee_info
{
    char name[7];
    char id[10];
    int salary;
};

int main()
{
    struct employee_info employee[SIZE];
    int average = 0, sum = 0, i;

    // 직원 5명의 정보 입력 및 급여 누적
    printf(">> 직원의 정보(이름, ID, 급여)를 입력하세요. << \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d번: ", i+1);
        scanf("%s %s %d",
                employee[i].name, employee[i].id, &employee[i].salary);
        sum += employee[i].salary;      // 급여 합계 계산
    }
    average = sum / SIZE;

    // 급여가 평균 이상인 직원의 id와 급여를 출력하기
    printf("\n----------------------------------------\n");
    printf(" 급여기 %d만원(평균) 이상인 직원 정보 ", average);
    printf("\n----------------------------------------\n");
    for ( i = 0; i < SIZE; i++)
    {
        if (employee[i].salary >= average)
            printf("\t%s\t %d만원 \n", employee[i].id, employee[i].salary);
    }   
    printf("\n----------------------------------------\n");

    return 0;
}
