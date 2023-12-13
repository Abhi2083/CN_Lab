#include <stdio.h>

struct dob
{
    int day, month, year;
};

struct student_info
{
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void call_by_value(struct student_info stud1)
{
    printf("\nCall by value\n");
    printf("\nroll_no.: %d", stud1.roll_no);
    printf("\nname: %s", stud1.name);
    printf("\nCGPA: %f", stud1.CGPA);
    printf("\nage\ndate: %d\nmonth: %d\nyear: %d\n", stud1.age.day, stud1.age.month, stud1.age.year);
}
void call_by_reference(struct student_info *stud1)
{
    printf("\nCall by reference\n");
    printf("\nroll_no.: %d", stud1->roll_no);
    printf("\nname: %s", stud1->name);
    printf("\nCGPA: %f", stud1->CGPA);
    printf("\nage\ndate: %d\nmonth: %d\nyear: %d", stud1->age.day, stud1->age.month, stud1->age.year);
}

int main()
{
    struct student_info stud1;
    printf("Enter details of student-\n");
    printf("Enter roll_no.: ");
    scanf("%d", &stud1.roll_no);
    printf("Enter name: ");
    scanf("%s", &stud1.name);
    printf("Enter CGPA: ");
    scanf("%f", &stud1.CGPA);
    printf("Enter age\ndate/month/year ");
    getchar();
    scanf("%d/%d/%d", &stud1.age.day, &stud1.age.month, &stud1.age.year);

    call_by_value(stud1);
    call_by_reference(&stud1);
}