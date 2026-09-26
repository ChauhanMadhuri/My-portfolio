#include<stdio.h>
#include<conio.h>

void main()
{
    int marks;
    char grade;

    clrscr();

    printf("Enter your marks: ");
    scanf("%d", &marks);

    if(marks >= 90)
    {
        grade = 'A';
    }
    else if(marks >= 80)
    {
        grade = 'B';
    }
    else if(marks >= 70)
    {
        grade = 'C';
    }
    else if(marks >= 60)
    {
        grade = 'D';
    }
    else if(marks >= 50)
    {
        grade = 'E';
    }
    else
    {
        grade = 'F';
    }

    printf("Your grade is %c. ", grade);

    if(grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D')
    {
        printf("Congratulations! You are eligible for the next level.");
    }
    else
    {
        printf("Please try again next time.");
    }

    getch();
}