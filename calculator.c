#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function declarations
void basicOperations();
void advancedOperations();
void trigonometricOperations();
long long factorial(int n);

int main() {
    int choice;
    while(1) {
        printf("\n===== Advanced CLI Calculator =====\n");
        printf("1. Basic Operations (+, -, *, /)\n");
        printf("2. Advanced Operations (Power, Factorial, Square Root)\n");
        printf("3. Trigonometric Operations (sin, cos, tan)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: basicOperations(); break;
            case 2: advancedOperations(); break;
            case 3: trigonometricOperations(); break;
            case 4: 
                printf("Exiting... Thank you!\n");
                exit(0);
            default: 
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Basic arithmetic operations
void basicOperations() {
    double a, b;
    char op;
    printf("\nEnter expression (example: 5 + 3): ");
    scanf("%lf %c %lf", &a, &op, &b);

    switch(op) {
        case '+': printf("Result = %.2lf\n", a + b); break;
        case '-': printf("Result = %.2lf\n", a - b); break;
        case '*': printf("Result = %.2lf\n", a * b); break;
        case '/': 
            if(b != 0) printf("Result = %.2lf\n", a / b);
            else printf("Error: Division by zero!\n");
            break;
        default: printf("Invalid operator!\n");
    }
}

// Advanced math operations
void advancedOperations() {
    int choice, n;
    double x, result;

    printf("\n--- Advanced Operations ---\n");
    printf("1. Power (x^y)\n");
    printf("2. Factorial (n!)\n");
    printf("3. Square Root\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter base and exponent: ");
            double base, exp;
            scanf("%lf %lf", &base, &exp);
            result = pow(base, exp);
            printf("Result = %.2lf\n", result);
            break;
        case 2:
            printf("Enter number: ");
            scanf("%d", &n);
            if(n < 0) printf("Error: Factorial of negative number doesn't exist.\n");
            else printf("Result = %lld\n", factorial(n));
            break;
        case 3:
            printf("Enter number: ");
            scanf("%lf", &x);
            if(x < 0) printf("Error: Square root of negative number is not real.\n");
            else printf("Result = %.2lf\n", sqrt(x));
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// Trigonometric operations
void trigonometricOperations() {
    int choice;
    double angle, rad;

    printf("\n--- Trigonometric Operations ---\n");
    printf("1. sin(x)\n");
    printf("2. cos(x)\n");
    printf("3. tan(x)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter angle in degrees: ");
    scanf("%lf", &angle);

    rad = angle * M_PI / 180.0; // Convert to radians

    switch(choice) {
        case 1: printf("sin(%.2lf) = %.4lf\n", angle, sin(rad)); break;
        case 2: printf("cos(%.2lf) = %.4lf\n", angle, cos(rad)); break;
        case 3: printf("tan(%.2lf) = %.4lf\n", angle, tan(rad)); break;
        default: printf("Invalid choice!\n");
    }
}

// Factorial function
long long factorial(int n) {
    if(n == 0 || n == 1) return 1;
    else return n * factorial(n - 1);
}
