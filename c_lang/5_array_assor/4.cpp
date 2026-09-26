#include<stdio.h>
#include<conio.h>

void main()
{
    int a[10][10], i, j, r, c;
    int row, col, sum;

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

    printf("\nEnter row number: ");
    scanf("%d", &row);

    printf("Elements of row %d: ", row);

    sum = 0;

    for(j=0; j<c; j++)
    {
        printf("%d, ", a[row][j]);
        sum = sum + a[row][j];
    }

    printf("\nThe sum of a row %d: %d", row, sum);


    printf("\n\nEnter column number: ");
    scanf("%d", &col);

    printf("Elements of column %d: ", col);

    sum = 0;

    for(i=0; i<r; i++)
    {
        printf("%d, ", a[i][col]);
        sum = sum + a[i][col];
    }

    printf("\nThe sum of a column %d: %d", col, sum);

    getch();
}