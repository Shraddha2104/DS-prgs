#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};struct node *newnode,*start,*temp,*news,*temp2,*start2,*start1,*starttemp,*chammat;

struct node *createnew()
{
	int n,i;
	printf("Enter the number of nodes to create a list to verify the wished command \n");
	scanf("%d",&n);
	start=(struct node*) malloc(sizeof(struct node));
	temp=start;
	for(i=1;i<=n;i++)
	{
			scanf("%d",&temp->data);
			if(i==n)
			{
				continue;
			}
			else
			{
				newnode=(struct node*) malloc(sizeof(struct node));
				temp->next=newnode;
				temp=newnode;
			}
	}
	return start;
}
void display(struct node *starttemp)
{
	temp=starttemp;
	if(starttemp=='\0')
	{
		printf("nthng");
	}
	else
	{
		while(temp!='\0')
		{
			printf("%d \n",temp->data);
			temp=temp->next;
		}
	}
}
void copy()
{
start1=createnew();
temp=start1;
start2=(struct node*) malloc(sizeof(struct node));
temp2=start2;
	while(temp!=NULL)
	{
		temp2->data=temp->data;
		if(temp->next!=NULL)
		{
			newnode=(struct node*) malloc(sizeof(struct node));
			temp2->next=newnode;
		}
		temp=temp->next;
		temp2=temp2->next;
	}
printf("\n copy list has :");
display(start2);
}
void concatenate()
{
	start1=createnew();
	start2=createnew();
	temp=start1;
	while(temp->next!=NULL)
	{
	temp=temp->next;
	}
	temp->next=start2;
	display(start1);
}
void split()
{       int sp;
	start1=createnew();
	printf("Enter the value after which u wish to split :");
	scanf("%d",&sp);
	temp=start1;
	while(temp->next!=NULL && temp->data!=sp)
	{
		  temp=temp->next;
	}
		if(temp->data==sp)
		{
			start2=temp->next;
			temp->next=NULL;
			printf("\n list 1 is: \n");
			display(start1);
			printf("\n list 2 is: \n");
			display(start2);
		}
}
void reverse()
{
start=createnew();
chammat=start;
while(chammat->next!=NULL)
{
	temp=chammat;
	temp=temp->next;
	temp2=temp->next;
	temp->next=start;
	chammat->next=temp2;
	start=temp;
}
display(start);
}
int main()
{
int c;
clrscr();
while(1)
{
printf("\n***choose an option*** \n 1-copy \n 2-concatenate \n 3-split \n 4-reverse \n 5-exit\n");
scanf("%d",&c);
switch(c)
{
	case 1:copy();
		break;
	case 2:concatenate();
		break;
	case 3:split();
		break;
	case 4:reverse();
		break;
	case 5:exit(0);
	default:printf("error");
		break;
}
}
return 0;
}

