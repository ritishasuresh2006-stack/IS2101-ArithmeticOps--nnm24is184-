#include <stdio.h>
#include <math.h>

void print_binary(int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

void restoring_division(int dividend, int divisor) {
    if (divisor == 0) {
        printf("Error: Division by zero is undefined.\n");
        return;
    }

    if (dividend < 0 || divisor < 0) {
        printf("Error: Only positive integers are supported in this implementation.\n");
        return;
    }

    // Number of bits needed for the operation (sufficient to hold dividend)
    int n = (int)(log2(dividend)) + 1;

    int A = 0;               // Accumulator (initially 0)
    int Q = dividend;        // Dividend (will become the quotient)
    int M = divisor;         // Divisor (unchanged)
    int Qn = n;              // Number of bits to shift

    printf("Initial Values:\n");
    printf("A: %d\tQ: %d\tM: %d\n", A, Q, M);
    printf("-----------------------------\n");

    for (int i = 0; i < Qn; i++) {
        // Left shift A and Q (combined shift)
        A = (A << 1) | ((Q >> (n - 1)) & 1);  // Get MSB of Q into LSB of A
        Q = Q << 1;

        // Subtract M from A
        A = A - M;

        printf("Step %d:\n", i + 1);
        printf("After Shift and Subtract:\n");
        printf("A: %d\tQ: %d\n", A, Q);

        if (A < 0) {
            Q = Q & (~1);   // Set Q0 = 0
            A = A + M;      // Restore A
            printf("A was negative. Restored A and set Q0 = 0\n");
        } else {
            Q = Q | 1;      // Set Q0 = 1
            printf("A was positive. Kept A and set Q0 = 1\n");
        }

        printf("A: %d\tQ: %d\n", A, Q);
        printf("-----------------------------\n");
    }

    int quotient = Q & ((1<<n)-1);      // Final Q is the quotient
    int remainder = A;          // Final A is the remainder

    printf("Final Result:\n");
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);
}

int main() {
    int dividend, divisor;

    printf("Enter the dividend (positive integer): ");
    scanf("%d", &dividend);

    printf("Enter the divisor (positive integer): ");
    scanf("%d", &divisor);

    restoring_division(dividend, divisor);

    return 0;
}