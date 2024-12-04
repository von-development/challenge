#include <stdio.h>
#include <stdlib.h>

#define MAX_SAMPLES 50

// Function prototypes
int readPHValues(float phValues[]);
void printPHValues(float phValues[], int count);
float calculateAverage(float phValues[], int count);
void countAcidicAndBasic(float phValues[], int count, int *acidic, int *basic);
int countAboveAverage(float phValues[], int count, float avg);
void sortPHValues(float phValues[], int count);

int main() {
    float phValues[MAX_SAMPLES];
    int count = 0;
    char option;

    do {
        printf("\npH Analyzer:\n");
        printf("1 - Read pH values.\n");
        printf("2 - Print pH values.\n");
        printf("3 - Calculate the average pH of the samples.\n");
        printf("4 - Calculate the number of acidic and basic samples.\n");
        printf("5 - Calculate the number of samples with a pH higher than the average.\n");
        printf("6 - Sort (in ascending order) the list of pH values.\n");
        printf("7 - Finish the program.\n");
        printf("Option -> ");
        scanf(" %c", &option);

        switch (option) {
            case '1':
                count = readPHValues(phValues);
                break;
            case '2':
                printPHValues(phValues, count);
                break;
            case '3': {
                float avg = calculateAverage(phValues, count);
                printf("Average pH: %.2f\n", avg);
                break;
            }
            case '4': {
                int acidic = 0, basic = 0;
                countAcidicAndBasic(phValues, count, &acidic, &basic);
                printf("Acidic samples: %d, Basic samples: %d\n", acidic, basic);
                break;
            }
            case '5': {
                float avg = calculateAverage(phValues, count);
                int aboveAvg = countAboveAverage(phValues, count, avg);
                printf("Samples with pH above average: %d\n", aboveAvg);
                break;
            }
            case '6':
                sortPHValues(phValues, count);
                printf("pH values sorted in ascending order.\n");
                break;
            case '7':
                printf("Program finished.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != '7');

    return 0;
}

// Read pH values
int readPHValues(float phValues[]) {
    int count = 0;
    float value;
    printf("Enter pH values (0-14). Enter a value outside this range to stop:\n");
    while (count < MAX_SAMPLES) {
        scanf("%f", &value);
        if (value < 0 || value > 14) break;
        phValues[count++] = value;
    }
    return count;
}

// Print pH values
void printPHValues(float phValues[], int count) {
    printf("pH values:\n");
    for (int i = 0; i < count; i++) {
        printf("%.2f ", phValues[i]);
    }
    printf("\n");
}

// Calculate average pH
float calculateAverage(float phValues[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += phValues[i];
    }
    return sum / count;
}

// Count acidic and basic samples
void countAcidicAndBasic(float phValues[], int count, int *acidic, int *basic) {
    for (int i = 0; i < count; i++) {
        if (phValues[i] < 7) (*acidic)++;
        else if (phValues[i] > 7) (*basic)++;
    }
}

// Count samples above average
int countAboveAverage(float phValues[], int count, float avg) {
    int aboveAvg = 0;
    for (int i = 0; i < count; i++) {
        if (phValues[i] > avg) aboveAvg++;
    }
    return aboveAvg;
}

// Sort pH values in ascending order
void sortPHValues(float phValues[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (phValues[i] > phValues[j]) {
                float temp = phValues[i];
                phValues[i] = phValues[j];
                phValues[j] = temp;
            }
        }
    }
}
