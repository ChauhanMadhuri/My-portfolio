#include<stdio.h>
#include<conio.h>

void main()
{
    char str[100], *p;
    int len = 0;

    clrscr();

    printf("Enter any string: ");
    gets(str);

    p = str;

    while(*p != '\0')
    {
        len++;
        p++;
    }

    printf("The length of a string is: %d", len);

    getch();
}