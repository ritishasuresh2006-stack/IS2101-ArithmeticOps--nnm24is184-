#include <stdio.h>
#include <stdint.h>

// Function to print binary (for visualization)
void print_binary(uint32_t num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

// Function to perform restoring division
void restoring_division(uint32_t dividend, uint32_t divisor) {
    uint32_t quotient = 0;
    int bits = 8; // number of bits (adjust for larger numbers)
    int32_t remainder = 0; // signed to handle negative temporarily

    printf("\n--- Restoring Division Steps ---\n");
    printf("Dividend = %u, Divisor = %u\n\n", dividend, divisor);

    for (int i = bits - 1; i >= 0; i--) {
        // Left shift remainder and bring down next bit of dividend
        remainder = (remainder << 1) | ((dividend >> i) & 1);
        printf("Step %d:\n", bits - i);
        printf("Shifted Remainder: %d (", remainder); print_binary(remainder, bits); printf(")\n");

        // Subtract divisor
        remainder = remainder - divisor;
        printf("After Subtracting Divisor: %d\n", remainder);

        if (remainder >= 0) {
            quotient = quotient | (1 << i); // Set bit in quotient
            printf("Remainder >= 0 → Set Q[%d] = 1\n", i);
        } else {
            remainder = remainder + divisor; // Restore
            printf("Remainder < 0 → Restore Remainder. Set Q[%d] = 0\n", i);
        }

        printf("Current Quotient: ");
        print_binary(quotient, bits);
        printf("\n-------------------------\n");
    }

    printf("\n✅ Final Quotient = %u\n", quotient);
    printf("✅ Final Remainder = %d\n", remainder);
}

int main() {
    uint32_t dividend, divisor;

    printf("Enter dividend (positive integer): ");
    scanf("%u", &dividend);

    printf("Enter divisor (positive integer): ");
    scanf("%u", &divisor);

    if (divisor == 0) {
        printf("❌ Error: Division by zero is not allowed.\n");
        return 1;
    }

    restoring_division(dividend, divisor);
    return 0;
}
