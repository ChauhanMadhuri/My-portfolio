// switch case
#include<stdio.h>
#include<conio.h>

void main()

{
	char grade;

	clrscr();

	printf("Enter your grade  :");
	scanf("%c",&grade);

	switch(grade)
     {

	case 'a':
		printf("Excellent work ");
		breck;

	case 'b':
		printf("well done");
		breck;

	case 'c':
		printf("good job");
		breck;

	case 'd':
		printf("you passed ,but not better");
		breck;

	case 'e':
		printf("sorry ,you failed");
		breck;

	default:
		printf("Invelid grade..");

     }

	getch();


}