#pragma once
#define MAX 11
//initializes main varaiables and the declares the functions for the program.
float a;
float b;
float add(a, b);
float sub(a, b);
float mult(a, b);
float divi(a, b);

struct welcomePrompt
{
	char welcomeMessage[200];
	char welcomeInstruct[200];
	char welcomeFormula[200];
	float previousAns;
	char welcomeRules[200];
};
