#include<stdio.h>
#include<ctype.h>

int main()
{
	char postfix[20];
	int stack[20];
	int i=-1,a,b,c,top=-1;
	printf("enter the postfix expression\n");
	scanf("%s",postfix);
	for(i=0;postfix[i]!='\0';i++)
	{
		if (isalnum(postfix[i]))
		{
			top++;
			stack[top]=(int)(postfix[i]-'0');
			
		}
		else{
		a=stack[top];
		top--;
		b=stack[top];
		switch(postfix[i])
		{
			case '+':c=b+a;
			stack[top]=c;
			break;
			case '-':c=b-a;
			stack[top]=c;
			break;
			case '*':c=b*a;
			stack[top]=c;
			break;
			case '/':c=b/a;
			stack[top]=c;
			break;
		}
		}
	}
	printf("value at stacktop is %d \n",stack[top]);
	
			
	return 0;	
}
