#include<stdio.h>
#include<conio.h>

void main()
{
    int r,c;

    clrscr();

    for(r=1; r<=5; r++)
    {
        for(c=1; c<=5; c++)
        {
            if(r==1 || r==3 || c==1 || (r==2 && c==5))
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }

        printf("\n");
    }

    getch();
}