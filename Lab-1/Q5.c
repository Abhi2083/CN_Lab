#include <stdio.h>

int main() {
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);

    int lsb = a & 0xFF;
    printf("Extracted byte from LSB of the Number: %d\n\n", lsb);

    printf("Memory representation of number\n");
    printf("------------------------\n");
    printf("Memory Address\t->\tValue\n");
    printf("------------------------\n");
    char *ch = (char *)&a;
    for (int i = 0; i < sizeof(int); i++) {
        printf("%p\t->\t%d\n", (void *)ch, *ch);
        ch++;
    }

    int endianness_test = 1;
    if (*((char *)&endianness_test) == 1) {
        printf("\nThe LSB of the number is stored in the lowest memory address\nHence the machine is little Endian\n");
        printf("\nConverting the machine to big Endian\n");
        ch = (char *)&a;
        char temp;
        for (int i = 0; i < sizeof(int) / 2; i++) {
            temp = ch[i];
            ch[i] = ch[sizeof(int) - 1 - i];
            ch[sizeof(int) - 1 - i] = temp;
        }
    } else {
        printf("\nThe MSB of the number is stored in the lowest memory address\nHence the machine is big Endian\n");
    }

    printf("\nMemory representation of the number after conversion\n");
    printf("------------------------\n");
    printf("Memory Address\t->\tValue\n");
    printf("------------------------\n");
    ch = (char *)&a;
    for (int i = 0; i < sizeof(int); i++) {
        printf("%p\t->\t%d\n", (void *)ch, *ch);
        ch++;
    }

    return 0;
}
