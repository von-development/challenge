#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int readNumbersFromFile(const char *filename, int **numbers);
void sortNumbers(int *numbers, int count);
int binarySearch(int *numbers, int low, int high, int key);

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

    sortNumbers(numbers, count);

    int key;
    printf("Enter a number to search: ");
    scanf("%d", &key);

    int index = binarySearch(numbers, 0, count - 1, key);
    if (index != -1) {
        printf("Number found at index %d.\n", index);
    } else {
        printf("Number not found.\n");
    }

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

// Binary search algorithm
int binarySearch(int *numbers, int low, int high, int key) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (numbers[mid] == key) {
            return mid;
        } else if (numbers[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
