#include <stdio.h>

double calculate(char* op, double a, double b) {
    printf("Calculating.....\n");

    if (*op == '+') return a + b;
    else if (*op == '-') return a - b;
    else if (*op == '*') return a * b;
    else if (*op == '/') return b != 0 ? a / b : 0;
    else {
        printf("Invalid operator.\n");
        return 0;
    }
}

int main(void) {

    double a, b;
    char op[3];

    printf("~~~ Welcome to my calculator  ~~~\n");
    printf("Enter expression (e.g. 1 + 2): ");
    scanf("%lf %s %lf", &a, op, &b);

    printf("Result = %.2lf\n", calculate(op, a, b));

    return 0;
}
