//ternery opertore
#include<stdio.h>
#include<conio.h>

void main()
{
	clrscr();
	int scroe;
	char grade;

	printf(" Enter your scrore  :");
	scanf("%d",&scroe);

	grade =  (scroe >= 90) ? 'a':
		(scroe >= 90) ? 'b':
		(scroe >= 90) ? 'c':
		(scroe >= 90) ? 'd':
		(scroe >= 90) ? 'e':'f';

		printf("your grade is %c",grade);


	getch();
}