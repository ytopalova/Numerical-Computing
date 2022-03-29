#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void convertToDecimal(int n) {
    int dec = 0, base = 1, rem;
    while (n > 0) {
        rem = n % 10;
        dec += rem * base;
        n /= 10;
        base = base * 2;
    }
    printf("Your number in decimal is %d", dec);
}

void convertToBinary(int m) {
    int bin = 0, rem, i = 1;
    while (m != 0) {
        rem = m % 2;
        bin += rem * i;
        i *= 10;
        m /= 2;
    }
    printf("Your number in binary is %d", bin);
}

int main() {
    int choice;
    int i;
    printf("Put 1 to conver to decimal and 2 to convert to binary: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter a binary number: ");
        scanf("%d", &i);
        convertToDecimal(i);
        break;
    case 2:
        printf("Enter a decimal number: ");
        scanf("%d", &i);
        convertToBinary(i);
        break;
    }
    return(0);
}