#include<stdio.h>

void pusha();
void pushb();
void popa();
void popb();
void displaya();
void displayb();
int stack[10],topa=-1,topb=10;
void main()
{     
	int ch;
	do{
		printf("menu\n");
		printf("1.push in stack a\n");
		printf("2.push in stack b\n");
		printf("3.pop frm stack a\n");
		printf("4.pop frm stack b\n");
		printf("5.display a\n");
		printf("6.display b\n");
		printf("7.enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:pusha();
			break;
			case 2:pushb();
			break;
			case 3:popa();
			break;
			case 4:popb();
			break;
			case 5:displaya();
			break;
			case 6:displayb();
			break;
			case 7:break;
		}
	}while(ch!=7);
return 0;
}
void pusha()
{       int val;

	if(topb-topa==1)
		printf("stack full");
	else{
		printf("enter the value to be pushed\n");
		scanf("%d",&val);
		topa++;
		stack[topa]=val;
	}
}
void pushb()
{       int val;

	if(topb-topa==1)
		printf("stack full\n");
	else{
		printf("enter the value to be pushed\n");
		scanf("%d",&val);
		topb--;
		stack[topb]=val;
	}
}
void popa()
{        int val;
	if(topa==-1)
		printf("stack empty");
	else{
		val=stack[topa];
		topa--;
		printf("val popped is %d\n",val);
	}
}
void popb()
{        int val;
	if(topb==10)
		printf("stack empty\n");
	else{
		val=stack[topb];
		topb++;
		printf("val popped is %d\n",val);
	}
}
void displaya()
{       int i;
	if(topa==-1)
		printf("stack a is empty\n");
	for(i=topa;i>=0;i--)
	{
		printf("%d",stack[i]);
		printf("\n");
	}
}

void displayb()
{
int i;
	if(topb==10)
		printf("stack b empty");
	else{
		for(i=topb;i<=9;i++)
		printf("%d\n",stack[i]);

}}





