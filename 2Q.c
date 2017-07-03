#include<stdio.h>
int queue[10],rearA=1,frontA=-1,rearB=10,frontB=10;
void displayA();
void insertA();
void insertB();
void deleteA();
void deleteB();
void displayB();
int main()
{
	int op;
	do{
		printf("menu\n");
		printf("1.add in queue A\n");
		printf("2.add in queue B\n");
		printf("3.delete frm q A\n");
		printf("4.delete from q B\n");
		printf("5.display A\n");
		printf("6.display B\n");
		printf("7.exit\n");
		printf("enter your choice\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:insertA();
			break;
			case 2:insertB();
			break;
			case 3:deleteA();
			break;
			case 4:deleteB();
			break;
			case 5:displayA();
			break;
			case 6:displayB();
			break;
			case 7:break;
		}
	}while(op!=7);
return 0;
}
void insertA()
{
	int val;
	printf("enter the value to be added in queue A");
	scanf("%d",&val);
	if(rearA==rearB-1)
	{
		printf("overflow\n");
	}
	else if(rearA==-1 && frontA==-1)
	{
		frontA=rearA=0;
		queue[rearA]=val;
	}
	else
	{
		rearA++;
		queue[rearA]=val;
	}
}
void insertB()
{
	int val;
	printf("enter the value to be added in queue B");
	scanf("%d",&val);
	if(rearA-rearB== -1)
	{
		printf("overflow\n");
	}
	else if(rearB==10 && frontB==10)
	{
		rearB=frontB=9;
		queue[rearB]=val;
	}
	else
	{
		rearB--;
		queue[rearB]=val;
	}
}
void deleteA()
{
	int val;
	if(frontA==-1)
		printf("queue empty\n");
	else{
		val=queue[frontA];
		printf("value to be deleted is %d\n",val);
		if(frontA==rearA)
		{
			frontA=-1;
			rearA=-1;
		}
		else
			frontA++;
	}
		
}
void deleteB()
{
	int val;
	if(frontB==10)
		printf("queue is full\n");
	else if(frontB==rearB)
		frontB=rearB=10;
	else{
		val=queue[frontB];
		frontB--;
	}
	printf("value to be deleted is %d\n",val);
	
}
void displayA()
{
	int i;
	if(frontA==-1)
		printf("empty \n");
	else{
		for(i=frontA;i<=rearA;i++)
			printf("%d\t",queue[i]);
		}
}
void displayB()
{
	int i;
	if(frontB==10)
		printf("empty \n");
	else{
		for(i=frontB;i>=rearB;i--)
			printf("%d\t",queue[i]);
		}
}


		
	 
	
		
	
	
		