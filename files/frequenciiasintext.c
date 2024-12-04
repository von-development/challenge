#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int letters[26] = {0};
    char ch;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            letters[ch - 'a']++;
        }
    }
    fclose(file);

    printf("Letter frequencies:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, letters[i]);
    }
    return 0;
}
