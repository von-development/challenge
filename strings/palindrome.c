#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototype
int isPalindrome(char *str);

int main() {
    char str[33];
    printf("Enter a string (max 32 characters): ");
    fgets(str, 33, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}

// Function definition
int isPalindrome(char *str) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}
