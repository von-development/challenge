#include <stdio.h>

// Function prototype
int gcd(int a, int b);

int main() {
    int a, b;
    printf("Enter two positive integers: ");
    scanf("%d %d", &a, &b);

    printf("The GCD is: %d\n", gcd(a, b));
    return 0;
}

// Function definition
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
