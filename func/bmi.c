#include <stdio.h>

// Function prototype
float BMI(float weight, float height);

int main() {
    float weight, height;
    printf("Enter weight (kg): ");
    scanf("%f", &weight);
    printf("Enter height (m): ");
    scanf("%f", &height);

    printf("Your BMI is: %.2f\n", BMI(weight, height));
    return 0;
}

// Function definition
float BMI(float weight, float height) {
    return weight / (height * height);
}
