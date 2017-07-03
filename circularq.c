#include<stdio.h>
struct st{
	int f,r,n;
	int queue[20];
	};
struct st s;
int count=0;
void add();
void del();
void display();
int main()
{
	int op;
	s.f=-1;
	s.r=-1;
	printf("enter the number of values in queue:\t");
	scanf("%d",&s.n);
	do{
		printf("\n1.add\n");
		printf("2.delete\n");
		printf("3.display\n");
		printf("4.exit\n");
		printf("enter your choice\t");
		scanf("%d",&op);
		switch(op)
		{
			case 1:add();
			break;
			case 2:del();
			break;
			case 3:display();
			break;
			case 4:
			break;
		}
	}while(op!=4);
return 0;
}
void add()
{
	int x;
	printf("enter the value to be added:\n");
	scanf("%d",&x);
	if(count==s.n)
		printf("queue is full\n");
	else if(count!=s.n && s.r==s.n-1)  //circular effect
	{
		s.r=0;
		s.queue[s.r]=x;
		count++;
	}
	else                         //normal queue
	{
		s.r++;
		s.queue[s.r]=x;
		count++;
	}
	if(s.f==-1)  //value added is the first entry
	s.f++;
	
}
void del()
{
		if(count==0)
		printf("underflow");
		else if(count==1)  //only 1 value left in queue to be deleted
			{
				s.f=-1;
				s.r=-1;
				count=0;
		}
		else if(s.f==s.n-1)
			{
				s.f=0;
				count--;
				printf("value deleted\n");
			}
			else
			{
				s.f++;
				count--;
				printf("value deleted\n");
			}
}
	


void display()
{
	int i;
	if(count==0)
		printf("queue is empty\n");
		
	else if(s.f<=s.r)
		{
			for(i=s.f;i<=s.r;i++)
				printf("%d\t",s.queue[i]);
		}
	else
		{
			for(i=s.f;i<s.n;i++)
				printf("%d\t",s.queue[i]);
			
			for(i=0;i<=s.r;i++)
				printf("%d\t",s.queue[i]);
		}
	
}
			
				
			
		
			
