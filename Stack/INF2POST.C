// Evaluation of postix

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAX 100

float st[MAX];
int top = -1;
void push(float st[], float val);
float pop(float st[]);
float evalpostfix(char exp[]);

int main()
{
	float val;
	char exp[100];
	clrscr();
	printf("\n Enter postfix expression\n");
	gets(exp); // header file-<stdio.h>
	val = evalpostfix(exp);
	printf("\n Value of postfix exp=%2f", val);
	getch();
	return 0;
}

float evalpostfix(char exp[])
{
	int i = 0;
	float op1, op2, value;
	/**
	till the expression is not null
	@insert the element in the stack if it is a digit
	@pop two elements out of the stack and run switch case if it is an operator
	*/
	while (exp[i] != '\0')
	{
		if (isdigit(exp[i]))				 //headerfile-<ctype.h>
			push(st, (float)(exp[i] - '0')); //insert the expression inside the stack
		else
		{
			op2 = pop(st);
			op1 = pop(st);
			switch (exp[i])
			{
			case '+':
				value = op1 + op2;
				break;
			case '-':
				value = op1 - op2;
				break;
			case '*':
				value = op1 * op2;
				break;
			case '/':
				value = op1 / op2;
				break;
			}
			push(st, value); //insert the value in the stack
		}
		i++;
	}
	return (pop(st)); //returns top of stack
}

void push(float st[], float val)
{
	if (top == MAX - 1) //Stack is full
		printf("\n stack overflow");
	else
	{
		top++;
		st[top] = val; //value entered at top of stack
	}
}

float pop(float st[])
{
	int val = -1;
	if (top == -1) //Stack is empty
		printf("\n Stack Overflow");
	else
	{
		val = st[top];
		top--; //value at top of stack will be deleted
	}
	return val; //Returns value in function evalpostfix()
}
