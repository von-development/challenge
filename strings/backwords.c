#include <stdio.h>
#include <string.h>

// Function prototype
void printBackwards(char *str);

int main() {
    char str[33]; // Maximum 32 characters + null terminator
    printf("Enter a string (max 32 characters): ");
    fgets(str, 33, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline

    printf("Reversed string: ");
    printBackwards(str);
    return 0;
}

// Function definition
void printBackwards(char *str) {
    for (int i = strlen(str) - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");
}
