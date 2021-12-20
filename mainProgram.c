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
#include <string.h>
//Above I imported standard input output, my header file that contains declarations of my functions, ctype, and standard library.
float ans = 0;

float main(int argc, char** argv){ //Initializing my main program, below I will have all of my loops and functions. 
	struct welcomePrompt welcomePrompt1;
	strcpy_s(welcomePrompt1.welcomeMessage, 200, "Hello, Welcome to my calculator, I hope you enjoy!\n");
	strcpy_s(welcomePrompt1.welcomeInstruct, 200, "Enter (1) to start or any other key to exit.\n");
	strcpy_s(welcomePrompt1.welcomeFormula, 200, "The Formula is as follows:\na (+)(-)(*)(/) b = c\n");
	strcpy_s(welcomePrompt1.welcomeRules, 200, "This calculator supports a maximum of 9 numbers per variable. It also supports decimals!\nThis calculator also has a memory function\n");

	printf("%s", welcomePrompt1.welcomeMessage); //Greeting the user using a structure
	int l = 0;//Initailizing variables that I will use in my main loop. 
	/*Below I created a do while loop that runs while the entire calculator is operational, the only way to break this loop is for the user to
	prompt the program by exit when asked*/
	do {
		welcomePrompt1.previousAns = ans;
		int x = 0; //Variables for this do while loop
		int v = 0;
		printf("%s", welcomePrompt1.welcomeInstruct);// prompting the user to enter "1" to start the program, or any key to exit
		scanf_s("%d", &x); //scans the users input, and assigns it to variable "x"
		printf("-------------------\n"); 

		if (x == 1) //if user input == '1', program starts
		{
			printf("The stored answer is %f\n", welcomePrompt1.previousAns);
			printf("%s", welcomePrompt1.welcomeFormula);
			printf("%s", welcomePrompt1.welcomeRules);
			int v = 0; 
			do //second do while loop, this is the loop for prompting the user to enter their numbers, if the input does not equal a number, the program will loop.
			{
				int i;
				int firstNumLoop = 0;
				int secondNumLoop = 0;
				int statusDone = 0;
				//char previousAnswer[MAX];
				
				do //do while loop for user variable "a", the loops are set up so if you enter a number for a, but not for b, it will only loop to b, and will save your input for a.
				{
					char fn[MAX]; //character array to hold string from user input for 'a'
					int alphaCount = 0;
					int digitCount = 0;
					int unknown = 0;
					while ((getchar() != '\n'));
					printf("Please enter your value for (a), or type 'm' to use the stored previous answer:\n"); 
					fgets(fn, MAX, stdin); //using fgets to obtain user input, as it can read strings better	
					if (strncmp(fn, "m", 1) == 0) //if then statement to see if the user inputs 'm' for the memory feature
					{
						
						a = ans;
						printf("a = %f\n", a);
						firstNumLoop++;

					}
					else {
						for (i = 0; fn[i] != '\0'; i++) { //for loop to run through the string, and make sure all inputs are a numerical value
							if (isalpha(fn[i]) != 0) {
								alphaCount++; //if for loop detects a letter, it will add 1 to alphaCount
							}
							else if (isdigit(fn[i]) != 0) {
								digitCount++; // if a number is detected, it will add 1 to the digitCount					
							}

							else {
								unknown++; //if an unknown character is detected, unkown count will +1
							}
						}
						if (alphaCount == 0) {
							if (digitCount > 0) {
								firstNumLoop++; // if the alphaCount is equal to 0, and the digit count is more than 0, then the firstNumLoop value will add 1, breaking the loop.						

							}
						}
						else if (alphaCount > 0) {
							printf("Numbers only please!\n"); //if alpha count is > 1, then the loop will reset, and say numbers only.
						}
						a = atof(fn);
						//a = atoi(fn); //converts the user input "fn" into a integer "a".
					}
				} while (firstNumLoop == 0);
				do{ //same loop as before, just for b this time.
					char ln[MAX];
					int alphaCount = 0;
					int digitCount = 0;
					int unknown = 0;
					printf("Please enter your value for (b), or type 'm' to use the stored previous answer:\n");
					fgets(ln, MAX, stdin);
					if (strncmp(ln, "m", 1) == 0)
					{

						b = ans;
						printf("b = %f\n", b);
						secondNumLoop++;
						statusDone++;
					}
					else {
						for (i = 0; ln[i] != '\0'; i++) {
							if (isalpha(ln[i]) != 0) {
								alphaCount++;
							}
							else if (isdigit(ln[i]) != 0) {
								digitCount++;
							}
							else {
								unknown++;
							}
						}
						if (alphaCount == 0) {
							if (digitCount != 0) {
								secondNumLoop++;
								statusDone++; // there is also a second plus one in here, status done, this will break both the b loop, and also the entire loop that both are in.
							}
						}
						else if (alphaCount != 0) {
							printf("Please Only Enter Numbers!\n");
						}
						else {
							printf("Please Only Enter Numbers!\n");
						}
						b = atof(ln);
					}
									
				} while (secondNumLoop == 0);
				if (statusDone != 0){
					v++;
				}
				else{
					printf("Clearing Values!\n");
				}

					
			} while (v == 0);
			printf("Please select your arithmetic function by typing in the corresponding number.\n"); /* next is the loop for the user to select their arithametic function.
			It is essentially the same as the other loops, however it will look for a user to input a value 1-5 to select a funciton. Anything else will repeat the loop*/
			int f = 0;
			int choice;
			do{	
				printf("Value of a = %f\nValue of b = %f\n", a, b);
				printf("(1)-Addition\n");
				printf("(2)-Subtraction\n");
				printf("(3)-Multiplication\n");
				printf("(4)-Division\n");
				printf("(5)-Clear\n");
				printf("(Any Other Key)-Exit the program\n");
				scanf_s("%d", &choice);
				switch (choice)//here I used a switch case to select what function to call based on the input from the user, for example if they select "1", then case 1 will run.
				{
				case 1:
					printf("%f + %f = ", a, b);
					add(a, b); // here it will call the add function, which is defined below .
					break;
				case 2:
					printf("%f - %f = ", a, b);
					sub(a, b);
					break;
				case 3:
					printf("%f * %f = ", a, b);
					mult(a, b);
					break;
				case 4:
					printf("%f / %f = ", a, b);
					divi(a, b);					
					break;
				case 5:
					printf("Clearing\n");	
					break; // repeats the loop, to allow the user to re enter their values.
				default:
					printf("Exiting!\n");
					l++; // this option will break the loop and return 0, exiting the program.
					return 0;
				}
				
				f++;
				
			} while (f == 0);
		}
		else
		{
			printf("Goodbye!\n");
			l++; // exits the program
		}
	} while (l == 0);
}
/*
Here I Define my functions to be called into the main program, they are simple arithametic functions.  
*/
float add()
{
	float c = a;
	float d = b;
	float addResult = c + d;
	ans = addResult;
	printf("%f\n", addResult);
	printf("%f\n", ans);
	return 0;
}
float sub()
{
	float c = a;
	float d = b;
	float addResult = c - d;
	ans = addResult;
	printf("%f\n", ans);
	return 0;
}
float mult()
{
	float c = a;
	float d = b;
	float addResult = c * d;
	ans = addResult;
	printf("%f\n", ans);
	return 0;
}
float divi()// with division i had to create an if else statement as you cannot divide a number by 0. This prevents a syntax error.
{
	if (b == 0){
		printf("You cannot divide a number by zero silly!!! Try again.\n");
	}
	else{
		float divResult = a / b;
		ans = divResult;
		printf("%0.9f\n", divResult);
	}
	return 0;
}
