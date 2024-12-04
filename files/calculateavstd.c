#include <stdio.h>
#include <math.h>

#define MAX_LINES 100

// Function prototypes
void readNumbersFromFile(const char *filename, double numbers[], int *count);
double calculateAverage(double numbers[], int count);
double calculateStdDev(double numbers[], int count, double avg);

int main() {
    char filename[100];
    double numbers[MAX_LINES];
    int count = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    readNumbersFromFile(filename, numbers, &count);
    if (count == 0) {
        printf("File is empty or not found.\n");
        return 1;
    }

    double avg = calculateAverage(numbers, count);
    double stdDev = calculateStdDev(numbers, count, avg);

    printf("Average: %.2f, Standard Deviation: %.2f\n", avg, stdDev);
    printf("Values larger than the average:\n");
    for (int i = 0; i < count; i++) {
        if (numbers[i] > avg) {
            printf("%.2f\n", numbers[i]);
        }
    }

    return 0;
}

void readNumbersFromFile(const char *filename, double numbers[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    while (fscanf(file, "%lf", &numbers[*count]) != EOF && *count < MAX_LINES) {
        (*count)++;
    }
    fclose(file);
}

double calculateAverage(double numbers[], int count) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum / count;
}

double calculateStdDev(double numbers[], int count, double avg) {
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += pow(numbers[i] - avg, 2);
    }
    return sqrt(sum / count);
}
