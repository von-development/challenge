#include <stdio.h>

// Define the Complex structure
typedef struct {
    double re;
    double im;
} Complex;

// Function prototypes
Complex readComplex();
void printComplex(Complex c);
Complex addComplex(Complex c1, Complex c2);
Complex subtractComplex(Complex c1, Complex c2);
Complex multiplyComplex(Complex c1, Complex c2);
Complex divideComplex(Complex c1, Complex c2);

int main() {
    char operation;
    while (1) {
        printf("Operation: ");
        scanf(" %c", &operation);

        if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
            printf("Illegal operation. Good bye!\n");
            break;
        }

        Complex c1, c2, result;
        printf("Complex number #1 ? ");
        c1 = readComplex();
        printf("Complex number #2 ? ");
        c2 = readComplex();

        switch (operation) {
            case '+':
                result = addComplex(c1, c2);
                printf("(");
                printComplex(c1);
                printf(") + (");
                printComplex(c2);
                printf(") = ");
                printComplex(result);
                printf("\n");
                break;
            case '-':
                result = subtractComplex(c1, c2);
                printf("(");
                printComplex(c1);
                printf(") - (");
                printComplex(c2);
                printf(") = ");
                printComplex(result);
                printf("\n");
                break;
            case '*':
                result = multiplyComplex(c1, c2);
                printf("(");
                printComplex(c1);
                printf(") * (");
                printComplex(c2);
                printf(") = ");
                printComplex(result);
                printf("\n");
                break;
            case '/':
                result = divideComplex(c1, c2);
                printf("(");
                printComplex(c1);
                printf(") / (");
                printComplex(c2);
                printf(") = ");
                printComplex(result);
                printf("\n");
                break;
        }
    }
    return 0;
}

// Function to read a complex n
