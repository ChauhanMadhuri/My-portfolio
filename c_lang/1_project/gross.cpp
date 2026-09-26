#include<stdio.h>
#include<conio.h>

void main()
{
    float salary, hra, da, ta, gross;

    clrscr();

    printf("Enter Base Salary: ");
    scanf("%f", &salary);

    printf("Enter HRA percentage: ");
    scanf("%f", &hra);

    printf("Enter DA percentage: ");
    scanf("%f", &da);

    printf("Enter TA percentage: ");
    scanf("%f", &ta);

    gross = salary + (salary * hra / 100) + (salary * da / 100) + (salary * ta / 100);

    printf("Gross Salary = Rs. %.2f", gross);

    getch();
}