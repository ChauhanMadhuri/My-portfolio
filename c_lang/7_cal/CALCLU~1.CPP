/* wap to calclutaer in c lang*/
#include<stdio.h>
#include<conio.h>

void add(int a, int b)
{
    printf("Addition of %d and %d is %d\n", a, b, a+b);
}

void sub(int a, int b)
{
    printf("Subtraction of %d and %d is %d\n", a, b, a-b);
}

void mul(int a, int b)
{
    printf("Multiplication of %d and %d is %d\n", a, b, a*b);
}

void divi(int a, int b)
{
    printf("Division of %d and %d is %d\n", a, b, a/b);
}

void mod(int a, int b)
{
    printf("Modulus of %d and %d is %d\n", a, b, a%b);
}

void main()
{
    int choice, a, b;

    clrscr();

    do
    {
        printf("\nPress 1 for +");
        printf("\nPress 2 for -");
        printf("\nPress 3 for *");
        printf("\nPress 4 for /");
        printf("\nPress 5 for %%");
        printf("\nPress 0 for the exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice != 0)
        {
            printf("Enter the first number: ");
            scanf("%d", &a);

            printf("Enter the second number: ");
            scanf("%d", &b);
        }

        switch(choice)
        {
            case 1:
                add(a, b);
                break;

            case 2:
                sub(a, b);
                break;

            case 3:
                mul(a, b);
                break;

            case 4:
                divi(a, b);
                break;

            case 5:
                mod(a, b);
                break;

            case 0:
                printf("\nProgram Ended...");
                break;

            default:
                printf("\nInvalid choice");
        }

    }while(choice != 0);

    getch();
}