#include <stdio.h>

// Function prototype
int countDigits(int num);

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("The number of digits is: %d\n", countDigits(num));
    return 0;
}

// Function definition
int countDigits(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}
