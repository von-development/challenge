#include <stdio.h>

int main() {
    char filename[100];
    int lineCount = 0;
    char buffer[256];

    printf("Input the file name to be opened: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        lineCount++;
    }
    fclose(file);

    printf("The lines in the file %s are: %d\n", filename, lineCount);
    return 0;
}
