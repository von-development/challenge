#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function prototype
void getAbbreviation(char *str, char *abbrev);

int main() {
    char clubName[129];
    char abbreviation[4] = ""; // 3 characters + null terminator

    printf("Enter the football club name (max 128 characters): ");
    fgets(clubName, 129, stdin);
    clubName[strcspn(clubName, "\n")] = '\0'; // Remove newline

    getAbbreviation(clubName, abbreviation);
    printf("Abbreviation: %s\n", abbreviation);
    return 0;
}

// Function definition
void getAbbreviation(char *str, char *abbrev) {
    int count = 0;
    for (int i = 0; str[i] != '\0' && count < 3; i++) {
        if (isupper(str[i])) {
            abbrev[count++] = str[i];
        }
    }
    abbrev[count] = '\0';
}
