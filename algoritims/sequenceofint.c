#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function prototypes
int readNumbersFromFile(const char *filename, int numbers[]);
void printNumbers(int numbers[], int count);
int findMaximum(int numbers[], int count);
int findMinimum(int numbers[], int count);
float findMedian(int numbers[], int count);
int isAllEven(int numbers[], int count);
void sortNumbers(int numbers[], int count);
int searchNumber(int numbers[], int count, int value);

int main() {
    int numbers[MAX_SIZE];
    int count = 0;
    char option;
    char filename[100];

    do {
        printf("\nAnalyzing a sequence of integers:\n");
        printf("1 - Read the numbers from file\n");
        printf("2 - Print the number sequence\n");
        printf("3 - Print the maximum of the sequence\n");
        printf("4 - Print the minimum of the sequence\n");
        printf("5 - Print the median of the sequence\n");
        printf("6 - Detect if the sequence is only made up of even numbers\n");
        printf("7 - Sort the sequence in ascending order\n");
        printf("8 - Search for a value in the sequence\n");
        printf("9 - End the program\n");
        printf("Option -> ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                printf("Enter the file name: ");
                scanf("%s", filename);
                count = readNumbersFromFile(filename, numbers);
                break;
            case '2':
                printNumbers(numbers, count);
                break;
            case '3':
                printf("Maximum: %d\n", findMaximum(numbers, count));
                break;
            case '4':
                printf("Minimum: %d\n", findMinimum(numbers, count));
                break;
            case '5':
                printf("Median: %.2f\n", findMedian(numbers, count));
                break;
            case '6':
                printf("All even: %s\n", isAllEven(numbers, count) ? "Yes" : "No");
                break;
            case '7':
                sortNumbers(numbers, count);
                printf("Sequence sorted in ascending order.\n");
                break;
            case '8': {
                int value;
                printf("Enter value to search: ");
                scanf("%d", &value);
                int index = searchNumber(numbers, count, value);
                if (index != -1) {
                    printf("Value found at index %d.\n", index);
                } else {
                    printf("Value not found.\n");
                }
                break;
            }
            case '9':
                printf("Program finished.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != '9');

    return 0;
}

// Read numbers from file
int readNumbersFromFile(const char *filename, int numbers[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    int count = 0;
    while (fscanf(file, "%d", &numbers[count]) != EOF && count < MAX_SIZE) {
        count++;
    }
    fclose(file);
    return count;
}

// Print numbers
void printNumbers(int numbers[], int count) {
    printf("Number sequence:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

// Find maximum
int findMaximum(int numbers[], int count) {
    int max = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] > max) max = numbers[i];
    }
    return max;
}

// Find minimum
int findMinimum(int numbers[], int count) {
    int min = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] < min) min = numbers[i];
    }
    return min;
}

// Find median
float findMedian(int numbers[], int count) {
    sortNumbers(numbers, count);
    if (count % 2 == 0) {
        return (numbers[count / 2 - 1] + numbers[count / 2]) / 2.0;
    } else {
        return numbers[count / 2];
    }
}

// Check if all numbers are even
int isAllEven(int numbers[], int count) {
    for (int i = 0; i < count; i++) {
        if (numbers[i] % 2 != 0) return 0;
    }
    return 1;
}

// Sort numbers in ascending order
void sortNumbers(int numbers[], int count) {
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

// Search for a value in the sequence
int searchNumber(int numbers[], int count, int value) {
    for (int i = 0; i < count; i++) {
        if (numbers[i] == value) return i;
    }
    return -1;
}
