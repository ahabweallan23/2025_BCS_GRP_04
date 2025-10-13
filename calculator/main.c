// main.c
#include <stdio.h>
#include "calculator.c"

int main() {
    int choice;
    float num1, num2, ans = 0;
    char useAns, cont;

        // Stage 1: Menu
        printf("\n===== Simple Calculator =====\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Modulus (%%)\n");

    do {
        // Stage 5: Reuse previous answer
        printf("\nUse previous answer (ans = %.2f)? (y/n): ", ans);
        scanf(" %c", &useAns);

        if (useAns == 'y' || useAns == 'Y') {
            num1 = ans;
        } else {
            printf("Enter first number: ");
            scanf("%f", &num1);
        }

        printf("Enter second number: ");
        scanf("%f", &num2);
        printf("Enter operation (1-5): ");
        scanf("%d", &choice);


        // Stage 3 + 4: Perform calculation
        switch (choice) {
            case 1:
                ans = add(num1, num2);
                printf("Result = %.2f + %.2f = %.2f\n", num1, num2, ans);
                break;
            case 2:
                ans = subtract(num1, num2);
                printf("Result = %.2f - %.2f = %.2f\n", num1, num2, ans);
                break;
            case 3:
                ans = multiply(num1, num2);
                printf("Result = %.2f * %.2f = %.2f\n", num1, num2, ans);
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    ans = divide(num1, num2);
                    printf("Result = %.2f / %.2f = %.2f\n", num1, num2, ans);
                }
                break;
            case 5:
                if ((int)num2 == 0) {
                    printf("Error: Modulus by zero is not allowed.\n");
                } else {
                    int result = modulus((int)num1, (int)num2);
                    ans = result; // store result in ans
                    printf("Result = %d %% %d = %d\n", (int)num1, (int)num2, result);
                }
                break;
            default:
                printf("Invalid choice.\n");
        }

        // Stage 6: Continuous operations
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    printf("\nCalculator closed. Goodbye!\n");
    return 0;
}
