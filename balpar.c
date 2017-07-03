#include<stdio.h>
#include<string.h>
int top=-1;
int stack[10];
void push(char);
char pop();
int main()
{
	char exp[10],open;
	int i,flag=1;
	printf("enter an expression");
	scanf("%s",exp);
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
			push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(top==-1)
				flag=0;
		
			else{
				open=pop();
				if(exp[i]==')' && (open=='{' || open=='['))
					flag=0;
				else if(exp[i]==']' && (open=='{' || open=='('))
					flag=0;
				else if(exp[i]=='}' && (open=='(' || open=='['))
					flag=0;
				}
		}
	}
	if(top>=0)
		flag=0;
	if(flag==1)
		printf("valid\n");
	else
		printf("invalid\n");
return 0;
}
void push(char c)
{
	if(top==9)
		printf("overflow\n");
	else{
		top++;
		stack[top]=c;
	}
}
char pop()
{
	if(top==-1)
		printf("under \n");
	else
		return stack[top--];
	}

	
				
				
				
				