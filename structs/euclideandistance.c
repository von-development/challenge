#include <stdio.h>
#include <math.h>

// Define the Point2D structure
typedef struct {
    double x;
    double y;
} Point2D;

// Function prototypes
Point2D readPoint();
void printPoint(Point2D p);
double euclideanDistance(Point2D p1, Point2D p2);
void processPoints();

int main() {
    processPoints();
    return 0;
}

// Function to read a point
Point2D readPoint() {
    Point2D p;
    printf("One point? ");
    scanf("%lf %lf", &p.x, &p.y);
    return p;
}

// Function to print a point
void printPoint(Point2D p) {
    printf("(%.3f,%.3f)", p.x, p.y);
}

// Function to calculate Euclidean distance
double euclideanDistance(Point2D p1, Point2D p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to process points
void processPoints() {
    Point2D origin = {0, 0}, point, farthestPoint = origin;
    int count = 0;
    double sumDistances = 0, maxDistance = 0;

    while (1) {
        point = readPoint();
        if (point.x == 0 && point.y == 0) break;

        count++;
        double distance = euclideanDistance(origin, point);
        sumDistances += distance;

        if (distance > maxDistance) {
            maxDistance = distance;
            farthestPoint = point;
        }
    }

    printf("The sum of the distances of the %d points to the origin is %.3f\n", count, sumDistances);
    printf("The point further away from the origin is: ");
    printPoint(farthestPoint);
    printf("\n");
}
