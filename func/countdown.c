#include <stdio.h>

// Function prototype
void countdown(int n);

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    countdown(n);
    return 0;
}

// Function definition
void countdown(int n) {
    for (int i = n; i >= 0; i--) {
        printf("%d\n", i);
    }
}
