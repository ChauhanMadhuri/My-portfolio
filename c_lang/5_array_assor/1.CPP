#include<stdio.h>
#include<conio.h>

void main()
{
    int a[10], i, n;

    clrscr();

    printf("Enter the array's size: ");
    scanf("%d", &n);

    printf("\nEnter array's elements:\n");

    for(i=0; i<n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("\nNegative elements from an Array: ");

    for(i=0; i<n; i++)
    {
        if(a[i] < 0)
        {
            printf("%d, ", a[i]);
        }
    }

    getch();
}