// Write a C program to swap the content of 2 variables entered through the command line using function and pointer.
#include <stdio.h>
void swap(int *a, int *b){
        int temp = *b;
        *b=*a;
        *a=temp;
}
int main(){
        int a,b;
        printf("Enter the nos to be swapped:-\n");
        printf("Number 1 is:- ");
        scanf("%d",&a);
        printf("Number 2 is:- ");
        scanf("%d",&b);

printf("Before swap:- %d %d\n",a,b);
swap(&a,&b);
printf("After swap:- %d %d\n",a,b);

return 0;
}