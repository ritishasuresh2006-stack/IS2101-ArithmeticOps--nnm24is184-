#include <stdio.h>
#include <stdint.h>

// Function to print binary (8-bit view)
void print_binary(int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

// Function to perform Non-Restoring Division
void non_restoring_division(uint8_t dividend, uint8_t divisor) {
    int bits = 8;
    int A = 0;               // Accumulator (can go negative)
    int Q = dividend;        // Dividend (shifting right)
    int M = divisor;         // Divisor
    int Q_bit = 0;           // Q[0] — current quotient bit

    printf("\n--- Non-Restoring Division Steps ---\n");
    printf("Initial Values: A = 0, Q = %d, M = %d\n\n", Q, M);

    for (int i = 0; i < bits; i++) {
        // Step 1: Shift A and Q left together
        A = (A << 1) | ((Q & 0x80) >> 7); // bring MSB of Q into LSB of A
        Q = Q << 1;

        printf("Step %d:\n", i + 1);
        printf("After shift → A: ");
        print_binary(A, bits);
        printf(" | Q: ");
        print_binary(Q, bits);
        printf("\n");

        // Step 2: Subtract or Add based on A's sign
        if (A >= 0) {
            A = A - M;
            printf("A was >= 0 → A = A - M = %d\n", A);
        } else {
            A = A + M;
            printf("A was < 0 → A = A + M = %d\n", A);
        }

        // Step 3: Set Q0
        if (A >= 0) {
            Q = Q | 1; // Set Q0 = 1
            Q_bit = 1;
        } else {
            Q = Q & ~1; // Set Q0 = 0
            Q_bit = 0;
        }

        printf("Set Q0 = %d → Q: ", Q_bit);
        print_binary(Q, bits);
        printf("\n");
        printf("-------------------------------\n");
    }

    // Final correction: if A < 0, add M once
    if (A < 0) {
        A = A + M;
        printf("Final Correction → A was negative, added M: %d\n", A);
    }

    printf("\n✅ Final Quotient = %d\n", Q);
    printf("✅ Final Remainder = %d\n", A);
}

int main() {
    uint8_t dividend, divisor;

    printf("Enter dividend (positive integer): ");
    scanf("%hhu", &dividend);

    printf("Enter divisor (positive integer): ");
    scanf("%hhu", &divisor);

    if (divisor == 0) {
        printf("❌ Error: Division by zero is not allowed.\n");
        return 1;
    }

    non_restoring_division(dividend, divisor);
    return 0;
}
