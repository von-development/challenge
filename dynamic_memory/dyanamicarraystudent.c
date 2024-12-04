#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Time structure
typedef struct {
    int hour;
    int minute;
    int second;
} Time;

// Define Student structure
typedef struct {
    char name[128];
    Time entrance;
    Time exit;
} Student;

// Function prototypes
Student readStudent();
Time readTime();
void listStudents(Student *students, int count);
double calculateAverageStay(Student *students, int count);
int calculateDuration(Time start, Time end);

int main() {
    Student *students = NULL;
    int count = 0;
    char option;

    do {
        printf("\nMenu:\n");
        printf("a. Register a student\n");
        printf("b. List all students\n");
        printf("c. Calculate average length of stay\n");
        printf("d. Terminate\n");
        printf("Choose an option: ");
        scanf(" %c", &option);

        switch (option) {
            case 'a': {
                students = realloc(students, (count + 1) * sizeof(Student));
                if (students == NULL) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }
                students[count] = readStudent();
                count++;
                break;
            }
            case 'b':
                listStudents(students, count);
                break;
            case 'c':
                if (count == 0) {
                    printf("No students registered.\n");
                } else {
                    printf("Average stay: %.2f seconds\n", calculateAverageStay(students, count));
                }
                break;
            case 'd':
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (option != 'd');

    free(students); // Free allocated memory
    return 0;
}

// Read student details
Student readStudent() {
    Student s;
    printf("Enter student name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter entrance time:\n");
    s.entrance = readTime();
    printf("Enter exit time:\n");
    s.exit = readTime();
    return s;
}

// Read time
Time readTime() {
    Time t;
    do {
        printf("Enter time (HH MM SS): ");
        scanf("%d %d %d", &t.hour, &t.minute, &t.second);
    } while (t.hour < 0 || t.hour > 23 || t.minute < 0 || t.minute > 59 || t.second < 0 || t.second > 59);
    return t;
}

// List all students
void listStudents(Student *students, int count) {
    printf("List of students:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Entrance time: %02d:%02d:%02d\n", students[i].entrance.hour, students[i].entrance.minute, students[i].entrance.second);
        printf("Exit time: %02d:%02d:%02d\n", students[i].exit.hour, students[i].exit.minute, students[i].exit.second);
    }
}

// Calculate average length of stay
double calculateAverageStay(Student *students, int count) {
    double totalStay = 0;
    for (int i = 0; i < count; i++) {
        int duration = calculateDuration(students[i].entrance, students[i].exit);
        if (duration >= 0) {
            totalStay += duration;
        } else {
            printf("Invalid duration for student %s.\n", students[i].name);
        }
    }
    return totalStay / count;
}

// Calculate duration in seconds
int calculateDuration(Time start, Time end) {
    int startInSeconds = start.hour * 3600 + start.minute * 60 + start.second;
    int endInSeconds = end.hour * 3600 + end.minute * 60 + end.second;

    if (endInSeconds < startInSeconds) {
        return -1; // Invalid duration
    }
    return endInSeconds - startInSeconds;
}
