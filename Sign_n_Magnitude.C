// ECE 528/L - HW1
// sign_and_magnitude.c
// Cristian Garcia

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int num;

    printf("ECE 528/L - Cristian Garcia - HW1\n");
    printf("Enter an integer: ");

    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (num > 0) {
        printf("%d is positive.\n", num);
    } else if (num < 0) {
        printf("%d is negative.\n", num);
    } else {
        printf("%d is zero.\n", num);
    }

    // abs(INT_MIN) doesn't fit in an int, so handle that one separately
    if (num == INT_MIN) {
        printf("Absolute value: %lld\n", -(long long)num);
    } else {
        printf("Absolute value: %d\n", abs(num));
    }

    return 0;
}