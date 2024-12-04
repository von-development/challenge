#include <stdio.h>

int main() {
    int lines;
    char buffer[256];
    char filename[] = "test.txt";

    printf("Input the number of lines to be written: ");
    scanf("%d", &lines);
    getchar(); // Consume newline left by scanf

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    printf(":: The lines are ::\n");
    for (int i = 0; i < lines; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        fprintf(file, "%s", buffer);
    }

    fclose(file);

    printf("The content of the file %s is:\n", filename);
    file = fopen(filename, "r");
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
    return 0;
}
