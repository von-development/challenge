// Write a program that reads N integers (value of N entered by the user) into a dynamically allocated array. Then, perform the following tasks:

// Print the integers in reverse order.
// Find and print the median of the numbers.
// Count and print how many numbers are greater than the median.



#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int readValidN();
void readArray(int *array, int n);
void printReverse(int *array, int n);
double findMedian(int *array, int n);
int countGreaterThanMedian(int *array, int n, double median);

int main() {
    int n = readValidN();
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    readArray(array, n);

    printf("Numbers in reverse order:\n");
    printReverse(array, n);

    double median = findMedian(array, n);
    printf("Median: %.2f\n", median);

    int count = countGreaterThanMedian(array, n, median);
    printf("Numbers greater than the median: %d\n", count);

    free(array); // Free allocated memory
    return 0;
}

// Read a valid value for N
int readValidN() {
    int n;
    do {
        printf("Enter the number of integers (N > 0): ");
        scanf("%d", &n);
    } while (n <= 0);
    return n;
}

// Read array elements
void readArray(int *array, int n) {
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
}

// Print array in reverse order
void printReverse(int *array, int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Find the median
double findMedian(int *array, int n) {
    for (int i = 0; i < n - 1; i++) { // Sort array
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    if (n % 2 == 0) {
        return (array[n / 2 - 1] + array[n / 2]) / 2.0;
    } else {
        return array[n / 2];
    }
}

// Count numbers greater than the median
int countGreaterThanMedian(int *array, int n, double median) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] > median) {
            count++;
        }
    }
    return count;
}
