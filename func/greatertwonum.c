#include <stdio.h>

// Function prototype
int max2(int a, int b);

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("The greatest number is: %d\n", max2(a, b));
    return 0;
}

// Function definition
int max2(int a, int b) {
    return (a > b) ? a : b;
}
