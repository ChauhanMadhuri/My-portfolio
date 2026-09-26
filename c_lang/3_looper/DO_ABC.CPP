#include<stdio.h>
#include<conio.h>

void main()
{
    char ch;

    clrscr();

    ch = 'a';

    do
    {
	printf("%c ", ch);
	ch = ch + 4;
    }
    while(ch <= 'z');

    getch();

}