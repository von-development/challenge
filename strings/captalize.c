#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function prototype
void capitalizeWords(char *str);

int main() {
    char str[129]; // Maximum 128 characters + null terminator
    printf("Enter a phrase (max 128 characters): ");
    fgets(str, 129, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline

    capitalizeWords(str);
    printf("Capitalized phrase: %s\n", str);
    return 0;
}

// Function definition
void capitalizeWords(char *str) {
    int capitalize = 1; // Flag to capitalize the next character
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            capitalize = 1;
        } else if (capitalize && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            capitalize = 0;
        }
    }
}
