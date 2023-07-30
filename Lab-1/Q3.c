#include <stdio.h>
int main()
{ 
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    int first = a & (0x000000ff);
    int second = a & (0x0000ff00);
    int third = a & (0x00ff0000);
    int fourth = a & (0xff000000);

    printf("\nThe input number: %d", a);
    printf("\nDigit in 1st byte: %d", first);
    printf("\nDigit in 2nd byte: %d", second >> 8);
    printf("\nDigit in 3rd byte: %d", third >> 16);
    printf("\nDigit in 4th byte: %d", fourth >> 24);
    return 0;
}