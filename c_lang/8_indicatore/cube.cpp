#include<stdio.h>
#include<conio.h>

void cube(int a[10][10], int n)
{
    int i, j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ", a[i][j] * a[i][j] * a[i][j]);
        }

        printf("\n");
    }
}

void main()
{
    int a[10][10], n, i, j;

    clrscr();

    printf("Enter array's size: ");
    scanf("%d", &n);

    printf("\nEnter array elements:\n");

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nCubes of all elements:\n");

    cube(a, n);

    getch();
}