#include <stdio.h>
#include "calculator.h"

int main() {
    int choice;
    float num1, num2, ans = 0;
    char useAns, cont;
    int firstCalculationDone = 0;

    printf("\n===== Simple Calculator =====\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n\n");

    do {
        // Use previous answer if applicable
        if (firstCalculationDone) {
            do {
                printf("\nUse previous answer (ans = %.2f)? (y/n): ", ans);
                scanf(" %c", &useAns);

                if (useAns == 'y' || useAns == 'Y') {
                    num1 = ans;
                    break;
                } else if (useAns == 'n' || useAns == 'N') {
                    // First number input validation
                    while (1) {
                        printf("Enter first number: ");
                        if (scanf("%f", &num1) == 1) break;
                        printf("Invalid input! Please enter a number.\n");
                        while (getchar() != '\n');
                    }
                    break;
                } else {
                    printf("Invalid input! Please enter 'y' or 'n'.\n");
                }
            } while (1);
        } else {
            // First calculation, no previous answer
            while (1) {
                printf("Enter first number: ");
                if (scanf("%f", &num1) == 1) break;
                printf("Invalid input! Please enter a number.\n");
                while (getchar() != '\n');
            }
        }

        // Second number input validation
        while (1) {
            printf("Enter second number: ");
            if (scanf("%f", &num2) == 1) break;
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n');
        }

        // Operation input validation
        while (1) {
            printf("Enter operation (1-5): ");
            if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 5) break;
            printf("Invalid input! Enter a number between 1 and 5.\n");
            while (getchar() != '\n');
        }

        // Perform calculation
        switch (choice) {
            case 1:
                ans = add(num1, num2);
                printf("Result = %.2f + %.2f = %.2f\n", num1, num2, ans);
                firstCalculationDone = 1;
                break;
            case 2:
                ans = subtract(num1, num2);
                printf("Result = %.2f - %.2f = %.2f\n", num1, num2, ans);
                firstCalculationDone = 1;
                break;
            case 3:
                ans = multiply(num1, num2);
                printf("Result = %.2f * %.2f = %.2f\n", num1, num2, ans);
                firstCalculationDone = 1;
                break;
            case 4:
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    ans = divide(num1, num2);
                    printf("Result = %.2f / %.2f = %.2f\n", num1, num2, ans);
                    firstCalculationDone = 1;
                }
                break;
            case 5:
                if ((int)num2 == 0) {
                    printf("Error: Modulus by zero is not allowed.\n");
                } else {
                    int result = modulus((int)num1, (int)num2);
                    ans = result;
                    printf("Result = %d %% %d = %d\n", (int)num1, (int)num2, result);
                    firstCalculationDone = 1;
                }
                break;
        }

        // Continuous operations input validation
        do {
            printf("\nDo you want to continue? (y/n): ");
            scanf(" %c", &cont);

            if (cont == 'y' || cont == 'Y' || cont == 'n' || cont == 'N') break;
            printf("Invalid input! Please enter 'y' or 'n'.\n");
        } while (1);

    } while (cont == 'y' || cont == 'Y');

    printf("\nCalculator closed. Goodbye!\n");
    return 0;
}
