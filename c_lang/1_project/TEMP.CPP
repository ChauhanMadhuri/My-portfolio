#include<stdio.h>
#include<conio.h>

void main()
{
    float c, f;

    clrscr();

    printf("Enter temperature in Celsius: ");
    scanf("%f", &c);

    f = (9.0 / 5.0 * c) + 32;

    printf("Temperature in Fahrenheit: %.1f", f);

    getch();
}