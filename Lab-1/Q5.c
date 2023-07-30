#include <stdio.h>
int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    int lsb = a & 256;
    printf("Extracted byte from LSB of the Number: %d", lsb);

    printf("\n\nMemory representation of number\n");
    printf("\n------------------------\n");
    printf("Memory Address\t->\tValue");
    printf("\n------------------------\n"); 
    int *ptr = &a;
    char *ch = (char *)ptr;
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t\t->\t%d\n", ch, *ch);
        ch++;
    }
    printf("\nThe LSB of the number is stored in the lowest memory address\nHence the machine is little Endian\n");
    printf("\nThe machine is coverted to big Endian now\nMemory representation of the number\n");
    printf("\n------------------------\n");
    printf("Memory Address\t->\tValue");
    printf("\n------------------------\n");

    int num;
    *ch = (char *)ptr;
}