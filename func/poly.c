#include <stdio.h>

// Function prototype
float polynomialP(float x);

int main() {
    for (float x = 0; x <= 2; x += 0.1) {
        printf("p(%.1f) = %.2f\n", x, polynomialP(x));
    }
    return 0;
}

// Function definition
float polynomialP(float x) {
    return x * x + 2 * x + 3;
}
