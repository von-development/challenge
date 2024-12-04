// Write a program that reads integers from a file whose name is provided by the user. The program should dynamically allocate memory to store the numbers and provide the following functionalities:

// Count and print the total number of integers in the file.
// Calculate and print the average of the numbers.
// Sort the numbers in ascending order and save the sorted sequence to a new file named sorted_output.txt.


#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int readNumbersFromFile(const char *filename, int **numbers);
double calculateAverage(int *numbers, int count);
void sortNumbers(int *numbers, int count);
void saveToFile(const char *filename, int *numbers, int count);

int main() {
    char filename[100];
    int *numbers = NULL, count = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    count = readNumbersFromFile(filename, &numbers);
    if (count == 0) {
        printf("File is empty or could not be read.\n");
        return 1;
    }

    printf("Total numbers in the file: %d\n", count);
    printf("Average: %.2f\n", calculateAverage(numbers, count));

    sortNumbers(numbers, count);
    saveToFile("sorted_output.txt", numbers, count);
    printf("Sorted numbers saved to 'sorted_output.txt'.\n");

    free(numbers); // Free allocated memory
    return 0;
}

// Read numbers from file and dynamically allocate memory
int readNumbersFromFile(const char *filename, int **numbers) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    int capacity = 10, count = 0;
    *numbers = (int *)malloc(capacity * sizeof(int));
    while (fscanf(file, "%d", &(*numbers)[count]) != EOF) {
        count++;
        if (count >= capacity) {
            capacity *= 2;
            *numbers = (int *)realloc(*numbers, capacity * sizeof(int));
        }
    }
    fclose(file);
    return count;
}

// Calculate average
double calculateAverage(int *numbers, int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum / count;
}

// Sort numbers in ascending order
void sortNumbers(int *numbers, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (numbers[i] > numbers[j]) {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

// Save sorted numbers to a file
void saveToFile(const char *filename, int *numbers, int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", numbers[i]);
    }
    fclose(file);
}
