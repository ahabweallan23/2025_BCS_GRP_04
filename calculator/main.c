#include <stdio.h>
int main(){
    // DisplayMenue
    printf("====== Simple Clculator======");
    printf("\n1. Addition(+)");
    printf("\n2. Subtraction(-)");
    printf("\n3. Multiplication(*)");
    printf("\n4. Division(/)");
    printf("\n5. Modulus(%%)");


    int operator = 0;
    double num1,num2;
    double result;
    printf("\nEnter operator(1-(+) 2-(-) 3-(*) 4-(/) 5-(%%):");
    scanf("%d", &operator);

    printf("Enter num1:\n");
    scanf("%lf", &num1);

    printf("Enter num2:\n");
    scanf("%lf", &num2);

    switch(operator){
        case 1:
            result = num1 + num2;
            printf("result: %.2lf", result);
            break;
        case 2:
            result = num1 - num2;
            printf("result: %.2lf", result);
            break;
        case 3:
            result = num1 * num2;
            printf("result: %.2lf", result);
            break;
        case 4:
            if (num2 == 0){
                printf("Division by zero is not allowed!");
            }
            else{
                result = num1 / num2;
                printf("result: %.2lf", result);
            }
            break;
        case 5:
            if (num2 == 0){
                printf("Modulus by zero is not allowed!");
            }
            else{
                result = (int)num1 % (int)num2;
                printf("result: %d", (int)result);
            }
            break;
        default:
            printf("The operator is invalid!!", operator);
    }



}
