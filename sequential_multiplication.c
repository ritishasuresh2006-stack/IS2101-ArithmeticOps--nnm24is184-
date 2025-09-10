#include <stdio.h>
#include <stdint.h>

// Helper function to print binary (for 8-bit display)
void print_binary(int32_t num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

// Function to multiply two signed integers using shift-add method
int32_t shift_add_multiplication(int32_t multiplicand, int32_t multiplier) {
    int32_t result = 0;
    int steps = 0;

    printf("\n--- Shift-Add Multiplication Steps ---\n");

    while (multiplier != 0) {
        printf("\nStep %d:\n", ++steps);
        printf("Multiplier (Q) = %d (", multiplier); print_binary(multiplier); printf(")\n");

        // If the least significant bit is 1, add multiplicand to result
        if (multiplier & 1) {
            result += multiplicand;
            printf("LSB is 1 → Adding multiplicand (%d) to result → Result = %d\n", multiplicand, result);
        } else {
            printf("LSB is 0 → No addition\n");
        }

        multiplicand <<= 1; // Shift multiplicand left (like multiplying by 2)
        multiplier >>= 1;   // Shift multiplier right (like dividing by 2)

        printf("Shifted multiplicand = %d\n", multiplicand);
        printf("Shifted multiplier  = %d\n", multiplier);
    }

    printf("\nFinal Result = %d\n", result);
    return result;
}

int main() {
    int32_t multiplicand, multiplier;

    printf("Enter multiplicand: ");
    scanf("%d", &multiplicand);

    printf("Enter multiplier: ");
    scanf("%d", &multiplier);

    int32_t product = shift_add_multiplication(multiplicand, multiplier);

    printf("\n✅ Product of %d × %d = %d\n", multiplicand, multiplier, product);

    return 0;
}
