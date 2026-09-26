#include<stdio.h>
#include<conio.h>

void main()
{
    char str[50];
    int i, j, count;

    clrscr();

    printf("Enter any string: ");
    scanf("%s", str);

    printf("\nFrequency of each letter:\n");

    for(i=0; str[i]!='\0'; i++)
    {
        count = 0;

        for(j=0; str[j]!='\0'; j++)
        {
            if(str[i] == str[j])
            {
                count++;
            }
        }

        printf("%c ==> %d\n", str[i], count);
    }

    getch();
}