#include <stdio.h>
struct pkt
{
    unsigned char ch1;
    unsigned char ch2[2];
    unsigned char ch3;
}; 

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);

    unsigned int first = a & (0x000000ff);
    unsigned int second = a & (0x0000ff00);
    unsigned int third = a & (0x00ff0000);
    unsigned int fourth = a & (0xff000000);

    struct pkt num;
    num.ch1 = first;
    num.ch2[0] = second >> 8;
    num.ch2[1] = third >> 16;
    num.ch3 = fourth >> 24;

    printf("\nThe input number: %u", a);
    printf("\nDigit in 1st byte: %u", first);
    printf("\nDigit in 2nd byte: %u", second >> 8);
    printf("\nDigit in 3rd byte: %u", third >> 16);
    printf("\nDigit in 4th byte: %u", fourth >> 24);

    printf("\n1st number of structure: %u", num.ch1);
    printf("\n2nd number of structure: %u, %u", num.ch2[0], num.ch2[1]);
    printf("\n3rd number of structure: %u", num.ch3);

    unsigned int regenerated_number = (first | second | third | fourth);

    printf("\nThe regenerated number: %u", regenerated_number);

    return 0;
}
