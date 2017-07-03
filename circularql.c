#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
struct node *p,*f,*r;
void add();
void del();
void display();
int main()
{
	int op;
	p=NULL;
	f=NULL;
	r=NULL;
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
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the val to be added:\n");
	scanf("%d",&x);
	temp->data=x;
	temp->link=NULL;
	if(f==NULL)
	{
		p=temp;
		f=p;
		r=p;
		r->link=p;
	}
	else
	{
		r->link=temp;
		r=temp;
		r->link=p;
	}
}
void del()
{
	if(f==NULL)
	printf("empty\n");
	else{
			if(f==r)
			{
				f=NULL;
				r=NULL;
				p=NULL;
			}
			else{
				printf("val deleted is %d\n",f->data);
				p=f->link;
				f=p;
				r->link=p;
			}
		}
}
void display()
{
	struct node *q;
	if(f==NULL)
	printf("its empty\n");
	else{
		q=p;
		while(q->link!=p)
		{
			printf("%d\t",q->data);
			q=q->link;
		}
		printf("%d\t",r->data);
	}
}
		
	
	
