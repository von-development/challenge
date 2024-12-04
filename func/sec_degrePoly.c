#include <stdio.h>

// Function prototype
float generalPolynomial(float a, float b, float c, float x);

int main() {
    float a = 1, b = 2, c = 3;  // Coefficients from exercise 2
    for (float x = 0; x <= 2; x += 0.1) {
        printf("g(%.1f) = %.2f\n", x, generalPolynomial(a, b, c, x));
    }
    return 0;
}

// Function definition
float generalPolynomial(float a, float b, float c, float x) {
    return a * x * x + b * x + c;
}
