#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char stack[100];
char infix[100];
char postfix[100];
int top=-1;
void push(char item)
{
	top++;
	stack[top]=item;
}
char pop()
{
	if(top==-1)
	{
		printf("stack underflow \n");
		return -1;
	}
	else
	{
		return stack[top--];
	}
}
int is_operator(char item)
{
	if(item == '+' || item == '-' || item == '/' || item == '*' || item == '^')
	{
		return 1;
	}
	else
		return 0;
}
int priority(char item)
{
	if (item == '^')
		return 3;
	else if (item == '/' || item == '*')
		return 2;
	else if (item == '+' || item == '-')
		return 1;
	else
		return 0;
}
void infix_to_postfix()
{
	int i=0,j=0,x;
	while(infix[i]!='\0')
	{
		if(is_operator(infix[i])==1)
		{
			while(priority(stack[top]) >= priority(infix[i]))
			{
				postfix[j]=pop();
				j++;
			}
			push(infix[i]);
		}
		else if(isdigit(infix[i]) || isalpha(infix[i]))
		{
			postfix[j]=infix[i];
			j++;
		}
		else if(infix[i] == ')')
		{
			while((x=pop())!= '(')
			{
				postfix[j]=x;
				j++;
			}
		}
		else
		{
			printf("invalid input\n");
			exit(0);
		}
		i++;
	}
	while(top!=-1)
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';
}
int main()
{
	printf("enter postfix expression :  ");
	scanf("%s",infix);
	infix_to_postfix();
    printf("postfix = %s",postfix);
	return 0;
}
