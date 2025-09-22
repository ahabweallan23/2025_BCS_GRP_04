// calculator.c
#include <stdio.h>
#include "calculator.h"

// Addition
float add(float a, float b) {
    return a + b;
}

// Subtraction
float subtract(float a, float b) {
    return a - b;
}

// Multiplication
float multiply(float a, float b) {
    return a * b;
}

// Division (caller must check divide-by-zero before calling)
float divide(float a, float b) {
    return a / b;
}

// Modulus (works only with integers)
int modulus(int a, int b) {
    return a % b;
}
