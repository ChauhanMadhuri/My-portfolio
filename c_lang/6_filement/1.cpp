#include<stdio.h>
#include<conio.h>

void main()
{
    char str[30];
    int i, len = 0, flag = 1;

    clrscr();

    printf("Enter any string: ");
    scanf("%s", str);

    while(str[len] != '\0')
    {
        len++;
    }

    for(i=0; i<len/2; i++)
    {
        if(str[i] != str[len-1-i])
        {
            flag = 0;
            break;
        }
    }

    if(flag == 1)
    {
        printf("The given string is a Palindrome.");
    }
    else
    {
        printf("The given string is not a Palindrome.");
    }

    getch();
}