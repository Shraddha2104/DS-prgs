#include<stdio.h>
int stack[10];
int top=-1;
void push(int);
int main()
{
	int n,r,i;
	printf("enter an integer");
	scanf("%d",&n);
	while(n>0)
	{
		r=n%2;
		push(r);
		n/=2;
	}
	printf("binary equivalent is\n");
	if(top==-1)
		printf("empty\n");
	for(i=top;i>=0;i--)
	{
		printf("%d",stack[i]);
	}
return 0;
}
void push(int val)
{
	if(top==9)
		printf("full\n");
	else{
		top++;
		stack[top]=val;
		}
}
		