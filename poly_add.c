#include<stdio.h>
#include<malloc.h>
struct node{
	int exp;
	int coeff;
	struct node *link;
	};
struct node *p1,*p2,*p3,*p4;

struct node *create(struct node *);
struct node *display(struct node*);
struct node *add_poly(struct node*,struct node*,struct node*);
struct node *sub_poly(struct node*,struct node*,struct node*);
struct node *add_node(struct node*,int,int);
int main()
{
	p1=NULL;
	p2=NULL;
	p3=NULL;
	p4=NULL;
	int op;
	do
	{
	printf("\n**** menu ****\n");
	printf("\n1.enter first poly\n");
	printf("2.display first poly\n");
	printf("3.enter second poly\n");
	printf("4.display second poly\n");
	printf("5.add the polys\n");
	printf("6.display the result\n");
	printf("7.subtract the polys\n");
	printf("8.display the result\n");
	printf("9.exit\n");
	printf("enter your choice:\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:p1=create(p1);
		break;
		
		case 2:p1=display(p1);
		break;
		
		case 3:p2=create(p2);
		break;
		
		case 4:p2=display(p2);
		break;
		
		case 5:p3=add_poly(p1,p2,p3);
		break;
		
		case 6:p3=display(p3);
		break;
		
		case 7:p4=sub_poly(p1,p2,p4);
		break;
		
		case 8:p4=display(p4);
		break;
		
		case 9:break;
		
	}
	}while(op!=9);
return 0;
}
struct node *create(struct node *p)
{
	int c,n;
	struct node *temp,*q;
	printf("enter -1 to end\n");
	printf("enter exp\n");
	scanf("%d",&n);
	printf("enter coeff:\n");
	scanf("%d",&c);
	while(n!=-1)
	{	
		temp=(struct node *)malloc(sizeof(struct node));
		temp->exp=n;
		temp->coeff=c;
		temp->link=NULL;

		if(p==NULL)
		{
			p=temp;
		}
		else{
			q=p;
			while(q->link!=NULL)
				q=q->link;
			q->link=temp;
		}
		printf("enter exp:\n");
		scanf("%d",&n);
		if(n==-1)
		break;
		printf("enter coeff:\n");
		scanf("%d",&c);
	}
return p;
}
struct node *display(struct node *p)
{
	struct node *q;
	q=p;
	while(q!=NULL)
	{
		printf("%d^%d  +  ",q->coeff,q->exp);
		q=q->link;
	}
return p;
}

struct node* add_poly(struct node *p1,struct node *p2,struct node *p3)
{
	struct node *q1,*q2;
	int sum=0,c;
	q1=p1;
	q2=p2;
	while(q1!=NULL && q2!=NULL)
	{
		if(q1->exp==q2->exp)
		{
			sum=q1->coeff+q2->coeff;
			p3=add_node(p3,q1->exp,sum);
			q1=q1->link;
			q2=q2->link;
		}
		else if(q1->exp>q2->exp)
		{
			p3=add_node(p3,q1->exp,q1->coeff);
			q1=q1->link;
		}
		else if(q1->exp<q2->exp)
		{
			p3=add_node(p3,q2->exp,q2->coeff);
			q2=q2->link;
		}
	}
	if(q1==NULL)
	{
		while(q2!=NULL)
		{
			p3=add_node(p3,q2->exp,q2->coeff);
			q2=q2->link;
			
			
		}
	}
	if(q2==NULL)
	{
		while(q1!=NULL)
		{
			p3=add_node(p3,q1->exp,q1->coeff);
			q1=q1->link;
		}
	}
	printf("add success");
return p3;
}
struct node* add_node(struct node *p,int exp,int coeff)
{
	struct node *temp,*q;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->exp=exp;
	temp->coeff=coeff;
	temp->link=NULL;	
	
	if(p==NULL)
	{
		p=temp;
	}
	else{
		q=p;
		while(q->link!=NULL)
			q=q->link;
		q->link=temp;
		
	}
	return p;
}
struct node *sub_poly(struct node *p1,struct node *p2,struct node *p4)
{
	struct node *q1,*q2;
	int sub,c;
	q1=p1;
	q2=p2;
	do{
		if(q1->exp==q2->exp)
		{
			sub=q1->coeff-q2->coeff;
			p4=add_node(p4,q1->exp,sub);
			q1=q1->link;
			q2=q2->link;
		}
		else if(q1->exp>q2->exp)
		{
			p4=add_node(p4,q1->exp,q1->coeff);
			q1=q1->link;
		}
		else if(q1->exp<q2->exp)
		{
			p4=add_node(p4,q2->exp,q2->coeff);
			q2=q2->link;
		}
		
		
	}while(q1!=NULL || q2!=NULL);
	if(q1==NULL)
	{
		while(q2!=NULL)
		{
			p4=add_node(p4,q2->exp,q2->coeff);
			q2=q2->link;
			
			
		}
	}
	if(q2==NULL)
	{
		while(q1!=NULL)
		{
			p4=add_node(p4,q1->exp,q1->coeff);
			q1=q1->link;
		}
	}
	printf("sub success");
	return p4;
	
}
	
		