#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

int main() {
    char filename[100];
    char lines[MAX_LINES][MAX_LENGTH];
    int count = 0;

    printf("Input the file name to be opened: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(lines[count], MAX_LENGTH, file) != NULL && count < MAX_LINES) {
        lines[count][strcspn(lines[count], "\n")] = '\0'; // Remove newline
        count++;
    }
    fclose(file);

    printf("The content of the file %s is:\n", filename);
    for (int i = 0; i < count; i++) {
        printf("%s\n", lines[i]);
    }

    return 0;
}
