#include<stdio.h>
#include<conio.h>

void main()
{
	clrscr();
	int r,c;

	for(r=5;r>=1; r--)
	{
	  for(int s=1; s<r; s++)
	   {
	     printf(" ");
	   }
	for(c=r; c<=5; c++)
	 {
	 printf("%d ",r);
	 }
	 printf("\n");
	}
	getch();
}