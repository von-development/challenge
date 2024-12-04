#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototype
void analyzePhrase(char *str);

int main() {
    char str[129];
    printf("Enter a phrase (max 128 characters): ");
    fgets(str, 129, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline

    analyzePhrase(str);
    return 0;
}

// Function definition
void analyzePhrase(char *str) {
    int lowercase = 0, uppercase = 0, digits = 0, vowels = 0, consonants = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            lowercase++;
            if (strchr("aeiou", str[i])) vowels++;
            else consonants++;
        } else if (isupper(str[i])) {
            uppercase++;
            if (strchr("AEIOU", str[i])) vowels++;
            else consonants++;
        } else if (isdigit(str[i])) {
            digits++;
        }
    }
    printf("Phrase analysis:\n");
    printf(" phrase -> %s\n", str);
    printf(" number of lowercase characters -> %d\n", lowercase);
    printf(" number of uppercase characters -> %d\n", uppercase);
    printf(" number of numeric characters -> %d\n", digits);
    printf(" number of vowels -> %d\n", vowels);
    printf(" number of consonants -> %d\n", consonants);
}
