#include<stdio.h>
y#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
struct node *p;
void create();
void delete_beg();
void delete_end();
void display();
void inbegin();
void delete_after();
int main()
{
	int op;
	p=NULL;
	
	do{
		printf("\n *******  MENU  ****** \n");
		printf("1.create\n");
		printf("2.delete from beginning\n");
		printf("3.display\n");
		printf("4.add in beg\n");
		printf("5.delete after\n");
		printf("6.exit\n");
		printf("enter your choice\t");
		scanf("%d",&op);
		switch(op)
		{
			case 1:create();
			break;
			case 2:delete_beg();
			break;
			case 3:display();
			break;
			case 4:inbegin();
			break;
			case 5:delete_after();
			break;
			case 6:break;
			
		}
	}while(op!=6);
return 0;
}

void create()
{
	int x;
	struct node *temp,*q;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter the val to be added:\n");
	scanf("%d",&x);
	temp->data=x;
	temp->link=NULL;
	if(p==NULL)
	{
		p=temp;
		temp->link=p;
	}
	else
	{
		q=p;
		while(q->link!=p)
			q=q->link;
		q->link=temp;
		temp->link=p;
	}
}
void inbegin()
{
	int x;
	struct node *temp,*q;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter the val to be added:\n");
	scanf("%d",&x);
	temp->data=x;
	temp->link=NULL;
	temp->link=p;
	q=p;
	while(q->link!=p)
		q=q->link;
	p=temp;
	q->link=temp;
	printf("vall added in beg\n");
}
void display()
{
	struct node *q;
	if(p==NULL)
	printf("its empty\n");
	else{
		q=p;
		while(q->link!=p)
		{
			printf("%d\t",q->data);
			q=q->link;
		}
		printf("%d\t",q->data);
	}
}
void delete_beg()
{
	struct node *q;
	q=p;
	while(q->link!=p)
		q=q->link;
	q->link=p->link;
	p=q->link;
}
void delete_end()
{
	struct node *old,*q;
	q=p;
	while(q->link!=p)
	{
		old=q;
		q=q->link;
	}
	old->link=q->link;
}
void delete_after()
{
		struct node *q,*old;
		int val;
		q=p;
		old=q;
		printf("enter the value to be dele");
		scanf("%d",&val);
		while(old->data!=val)
		{
			old=q;
			q=q->link;
		}
		old->link=q->link;
		printf("value del succ");
}




	


	
	
	
		