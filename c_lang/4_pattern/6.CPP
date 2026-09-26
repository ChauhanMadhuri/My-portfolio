#include<stdio.h>
#include<conio.h>

void main()
{
    int i,j,k;
    int n=5;
    int count;

    clrscr();

    for(i=1; i<=n; i++)
    {
        count=i;

        for(j=1; j<=count; j++)
        {
            printf("%d ",j);
        }

        for(k=1; k<=4*(n-count); k++)
        {
            printf(" ");
        }

        for(j=count; j>=1; j--)
        {
            printf("%d ",j);
        }

        printf("\n");
    }

    getch();
}