#include <stdio.h>
#include <stdlib.h>

int main()
{
    char operator;
    printf("Choose an Operator ['+','-','*','/']:");
    scanf("%c", &operator);
    double num1, num2;
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    double result;

    return 0;
}
