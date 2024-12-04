#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function prototypes
int readValidN();
void readArray(double *array, int n);
double calculateAverage(double *array, int n);
double calculateStdDev(double *array, int n, double avg);
void printAboveAverage(double *array, int n, double avg);

int main() {
    int n = readValidN();
    double *array = (double *)malloc(n * sizeof(double));

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    readArray(array, n);
    double avg = calculateAverage(array, n);
    double stdDev = calculateStdDev(array, n, avg);

    printf("Average: %.2f, Standard Deviation: %.2f\n", avg, stdDev);
    printf("Values above the average:\n");
    printAboveAverage(array, n, avg);

    free(array); // Free allocated memory
    return 0;
}

// Read a valid value of N
int readValidN() {
    int n;
    do {
        printf("Enter a positive value for N: ");
        scanf("%d", &n);
    } while (n <= 0);
    return n;
}

// Read array elements
void readArray(double *array, int n) {
    printf("Enter %d real numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &array[i]);
    }
}

// Calculate average
double calculateAverage(double *array, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum / n;
}

// Calculate standard deviation
double calculateStdDev(double *array, int n, double avg) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(array[i] - avg, 2);
    }
    return sqrt(sum / n);
}

// Print values above the average
void printAboveAverage(double *array, int n, double avg) {
    for (int i = 0; i < n; i++) {
        if (array[i] > avg) {
            printf("%.2f\n", array[i]);
        }
    }
}
