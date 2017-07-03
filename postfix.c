#include<stdio.h>
#include<ctype.h>
int priority(char);
int main()
{
	char infix[20],postfix[20],stack[20];
	int n,top=-1,i=-1,j=-1;
	printf("enter infix expression\n");
	scanf("%s",infix);
	
	for(i=0;infix[i]!='\0';i++)
	{
		if(isalnum(infix[i]))
		{
			j=j+1;
			postfix[j]=infix[i];
		}
		else if(top==-1)
		{
			top++;
			stack[top]=infix[i];
		}
		else if(infix[i]==')')
		{
			while(stack[top]!='(')
			{
				j=j+1;
				postfix[j]=stack[top];
				top--;
			}
			top--;
		}
		else if(priority(infix[i])>priority(stack[top]))
		{
			top=top+1;
			stack[top]=infix[i];
			
		}
		else{
			while(priority(infix[i])<=priority(stack[top]) && top!=-1 && stack[top]!='(' && infix[i]!='(')
			{
				j=j+1;
				postfix[j]=stack[top];
				top--;
				if(top==-1)
				break;
				
			}
			top++;
			stack[top]=infix[i];
		}
		
	}

	while(top!=-1)
	{
		j=j+1;
		postfix[j]=stack[top];
		top--;
		
	}
	postfix[j+1]='\0';
	printf("postfix exp is %s \n ",postfix);
		return 0;
}
int priority(char ch)
{
	if(ch==')')
		return 4;
	else if(ch=='*'||ch=='/')
		return 3;
	else if(ch=='+'||ch=='-')
		return 2;
	else
	return 0;
	
}

	
	
