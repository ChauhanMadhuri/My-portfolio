#include<stdio.h>
#include<conio.h>

void main()
{
    int n, first, last, sum;

    clrscr();

    printf("Enter any number: ");
    scanf("%d", &n);

    last = n % 10;

    do
    {
        first = n % 10;
        n = n / 10;
    }
    while(n != 0);

    sum = first + last;

    printf("The sum of the first and last digit: %d", sum);

    getch();
}