#include <stdio.h>
#include <math.h>

void print_binary(int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

void non_restoring_division(int dividend, int divisor) {
    if (divisor == 0) {
        printf("Error: Division by zero is undefined.\n");
        return;
    }

    if (dividend < 0 || divisor < 0) {
        printf("Error: This implementation supports only positive integers.\n");
        return;
    }

    int n = (int)(log2(dividend > divisor ? dividend : divisor)) + 1; // bit-width

    int A = 0;
    int Q = dividend;
    int M = divisor;

    printf("Initial Values:\n");
    printf("A: %d\tQ: %d\tM: %d\n", A, Q, M);
    printf("-----------------------------\n");

    for (int i = 0; i < n; i++) {
        // Step 1: Shift A and Q left (combined shift)
        A = (A << 1) | ((Q >> (n - 1)) & 1);  // Get MSB of Q into LSB of A
        Q <<= 1;

        // Step 2: A = A - M or A = A + M based on current sign
        if (A >= 0) {
            A = A - M;
            printf("Step %d: A >= 0, so A = A - M\n", i + 1);
        } else {
            A = A + M;
            printf("Step %d: A < 0, so A = A + M\n", i + 1);
        }

        // Step 3: Set Q0 based on sign of A
        if (A >= 0) {
            Q = Q | 1;  // Set Q0 = 1
        } else {
            Q = Q & (~1);  // Set Q0 = 0
        }

        // Trace Output
        printf("A: %d\tQ: %d\t", A, Q);
        printf("A(bin): "); print_binary(A, n + 1);
        printf(" | Q(bin): "); print_binary(Q, n + 1);
        printf("\n-----------------------------\n");
    }

    // Final correction if A < 0
    if (A < 0) {
        A = A + M;
        printf("Final correction: A was negative, so A = A + M\n");
    }

    int quotient = Q & ((1 << n) - 1);  // Mask only n bits
    int remainder = A;

    printf("\nFinal Result:\n");
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);
}

int main() {
    int dividend, divisor;

    printf("Enter the dividend (positive integer): ");
    scanf("%d", &dividend);

    printf("Enter the divisor (positive integer): ");
    scanf("%d", &divisor);

    non_restoring_division(dividend, divisor);

    return 0;
}