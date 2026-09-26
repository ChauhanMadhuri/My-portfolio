#include<stdio.h>
#include<conio.h>

void main()
{
    int a[10][10], i, j, r, c, max;

    clrscr();

    printf("Enter the array's row size: ");
    scanf("%d", &r);

    printf("Enter the array's column size: ");
    scanf("%d", &c);

    printf("\nEnter array's elements:\n");

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    max = a[0][0];

    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(a[i][j] > max)
            {
                max = a[i][j];
            }
        }
    }

    printf("\nThe largest element is: %d", max);

    getch();
}