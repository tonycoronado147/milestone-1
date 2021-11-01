/*
Antonio Coronado
ITT310
24 October 2021
Milestone Release:1
*/

#include <stdio.h>
#include "header1.h"
#include <ctype.h>
#include <stdlib.h>

float main(int argc, char** argv)
{
	printf("Hello, Welcome to my calculator, I hope you enjoy!\n");
	int l = 0;
	int a;
	int b;
	do
	{
		int x = 0;
		int v = 0;
		printf("Enter (1) to start or any other key to exit.\n");
		scanf_s("%d", &x);
		printf("-------------------\n");

		if (x == 1)
		{
			printf("The Formula is as follows:\n");
			printf("a (+)(-)(*)(/) b = c\n");
			printf("This calculator supports a maximum of 9 numbers per variable.\n");
			int v = 0;
			do
			{
				int i;
				int firstNumLoop = 0;
				int secondNumLoop = 0;
				int statusDone = 0;
				do
				{
					char fn[MAX];
					int alphaCount = 0;
					int digitCount = 0;
					int unknown = 0;
					while ((getchar() != '\n'));
					printf("Please enter your whole value for (a):\n");
					fgets(fn, MAX, stdin);
						
					for (i = 0; fn[i] != '\0'; i++)
					{
						if (isalpha(fn[i]) != 0)
						{
							alphaCount++;
						}
						else if (isdigit(fn[i]) !=0)
						{
							digitCount++;								
						}
								
						else 
						{
							unknown++;
						}
					}
					if (alphaCount == 0)
					{
						if (digitCount > 0)
						{
							firstNumLoop++;
						}
					}
					else if (alphaCount > 0)
					{
						printf("Numbers only please!\n");
					}

					a = atoi(fn);
				} while (firstNumLoop == 0);
				do
				{
					char ln[MAX];
					int alphaCount = 0;
					int digitCount = 0;
					int unknown = 0;
					printf("Please enter your whole value for (b):\n");
					fgets(ln, MAX, stdin);
					for (i = 0; ln[i] != '\0'; i++)
					{
						if (isalpha(ln[i]) != 0)
						{
							alphaCount++;
						}
						else if (isdigit(ln[i]) != 0)
						{
							digitCount++;
						}

						else
						{
							unknown++;
						}
					}
					if (alphaCount == 0)
					{
						if (digitCount != 0)
						{
							secondNumLoop++;
							statusDone++;
						}
					}
					else if (alphaCount != 0)
					{
						printf("Please Only Enter Numbers!\n");
					}
					else
					{
						printf("Please Only Enter Numbers!\n");
					}
					b = atoi(ln);						
				} while (secondNumLoop == 0);
				if (statusDone != 0)
				{
					v++;
				}
				else
				{
					printf("Clearing Values!\n");
				}

					
			} while (v == 0);
			printf("Please select your arithmetic function by typing in the corresponding number.\n");
			int f = 0;
			int choice;
			do
			{
					
				printf("(1)-Addition\n");
				printf("(2)-Subtraction\n");
				printf("(3)-Multiplication\n");
				printf("(4)-Division\n");
				printf("(5)-Clear\n");
				printf("(Any Other Key)-Exit the program\n");
				scanf_s("%d", &choice);

				switch (choice)
				{
				case 1:
					add(a, b);
					break;
				case 2:
					sub(a, b);
					break;
				case 3:
					mult(a, b);
					break;
				case 4:
					divi(a, b);
					break;
				case 5:
					printf("Clearing\n");	
					break;
				default:
					printf("Exiting!\n");
					l++;
					return 0;
				}
				f++;
				
			} while (f == 0);
		}
		else
		{
			printf("Goodbye!\n");
			l++;
		}
	} while (l == 0);
}

int add(a, b)
{
	int addResult = a + b;
	printf("%d + %d = ", a , b);
	printf("%d\n", addResult);
	return 0;
}
int sub(a, b)
{
	int subResult = a - b;
	printf("%d - %d = ", a, b);
	printf("%d\n", subResult);
	return 0;
}
int mult(a, b)
{
	int multResult = a * b;
	printf("%d * %d = ", a, b);
	printf("%d\n", multResult);
	return 0;
}
float divi(a, b)
{
	if (b == 0)
	{
		printf("You cannot divide a number by zero silly!!! Try again.\n");
	}
	else
	{
		float y = (float)a;
		float z = (float)b;

		
		float divResult = y / z;
		printf("%d / %d = ", a, b);
		printf("%0.9f\n", divResult);
		return 0;
	}
	return 0;
}
