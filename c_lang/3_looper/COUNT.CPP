#include<stdio.h>
#include<conio.h>

void main()
{
    int n, count = 0;

    clrscr();

    printf("Enter any number: ");
    scanf("%d", &n);

    do
    {
        count++;
        n = n / 10;
    }
    while(n != 0);

    printf("Total number of digits: %d", count);

    getch();
}