#include <stdio.h>

// Define the Time structure
typedef struct {
    int hour;
    int minute;
    int second;
} Time;

// Define the Student structure
typedef struct {
    int number;
    char name[128];
} Student;

// Function prototypes
Time readTime();
void printTime(Time t);
Student readStudent();
int calculateDuration(Time start, Time end);

int main() {
    Student student = readStudent();
    printf("Enter time of entry:\n");
    Time entry = readTime();
    printf("Enter time of exit:\n");
    Time exit = readTime();

    int duration = calculateDuration(entry, exit);

    if (duration == -1) {
        printf("Impossible\n");
    } else {
        printf("Student %s (ID: %d) was inside the DETI building for %d seconds.\n",
               student.name, student.number, duration);
    }
    return 0;
}

// Function to read time
Time readTime() {
    Time t;
    do {
        printf("Enter time (HH MM SS): ");
        scanf("%d %d %d", &t.hour, &t.minute, &t.second);
    } while (t.hour < 0 || t.hour > 23 || t.minute < 0 || t.minute > 59 || t.second < 0 || t.second > 59);
    return t;
}

// Function to print time
void printTime(Time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.minute, t.second);
}

// Function to read student details
Student readStudent() {
    Student s;
    printf("Enter student number: ");
    scanf("%d", &s.number);
    printf("Enter student name: ");
    scanf(" %[^\n]", s.name);
    return s;
}

// Function to calculate duration in seconds
int calculateDuration(Time start, Time end) {
    int startInSeconds = start.hour * 3600 + start.minute * 60 + start.second;
    int endInSeconds = end.hour * 3600 + end.minute * 60 + end.second;

    if (endInSeconds < startInSeconds) {
        return -1; // Impossible
    }
    return endInSeconds - startInSeconds;
}
