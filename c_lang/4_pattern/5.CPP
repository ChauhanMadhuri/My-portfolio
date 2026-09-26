#include<stdio.h>
#include<conio.h>

void main()
{
    int r,c,s;

    clrscr();

    for(r=5; r>=1; r--)
    {
        for(s=1; s<r; s++)
        {
            printf("  ");
        }

        for(c=r; c<=5; c++)
        {
            printf("%d ",c);
        }

        for(c=4; c>=r; c--)
        {
            printf("%d ",c);
        }

        printf("\n");
    }

    getch();
}