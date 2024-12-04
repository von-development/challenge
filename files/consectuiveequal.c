#include <stdio.h>
#include <string.h>

int repeats(char *word);
void processWords(char *filename);

int main() {
    char filename[] = "/etc/dictionaries-common/words";
    processWords(filename);
    return 0;
}

// Function to check consecutive repeated letters
int repeats(char *word) {
    int count = 0;
    for (int i = 1; word[i] != '\0'; i++) {
        if (word[i] == word[i - 1]) {
            count++;
        }
    }
    return count;
}

// Process words in a file
void processWords(char *filename) {
    char word[256];
    int totalWords = 0, repeatWords = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(file, "%s", word) != EOF) {
        totalWords++;
        if (repeats(word)) {
            repeatWords++;
            printf("%s\n", word);
        }
    }
    fclose(file);

    printf("Total words: %d\n", totalWords);
    printf("Words with repeated letters: %d\n", repeatWords);
}
