#include<stdio.h>
#include<malloc.h>
struct node {
	int data;
	struct node *l,*r;
	};
struct node *root,*parent,*succ;
int found=0;
void insert(struct node*,struct node*);
void delete1(struct node*,int);
void display(struct node*,int);


int main()
{
	int op,x;
	root=NULL;
	struct node *temp;
	do{
		printf("\n*** MENU ***\n");
		printf("1.add\n");
		printf("2.display\n");
		printf("3.delete\n");
		printf("4.exit\n");
		printf("enter your choice:\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("enter the value to be added:\n");
				scanf("%d",&x);
				temp=(struct node*)malloc(sizeof(struct node));
				temp->data=x;
				temp->l=NULL;
				temp->r=NULL;
				if(root==NULL)
				{
					root=temp;
				}
				else
				insert(root,temp);
				break;
			
			
			case 2:
				printf("Sub menu\n");
				printf("1.preorder\n");
				printf("2.inorder\n");
				printf("3.postorder\n");
				printf("enter option\n");
				scanf("%d",&op);
				if(root==NULL)
				printf("tree does nt exist\n");
				else
				display(root,op);
				break;
			
			case 3:
				if(root==NULL)
				printf("tree does nt exist\n");
				else
				{
					printf("enter the value to be deleted\n");
					scanf("%d",&x);
					delete1(root,x);
				}
				break;
				
			case 4:
			break;
			default:printf("invalid choice");
			break;
			
				
		}
	}while(op!=4);
return 0;
}
void insert(struct node *q,struct node *temp)
{
	if(temp->data<q->data)
	{
		if(q->l==NULL)
		{
			q->l=temp;
			return;
		}
		else
		insert(q->l,temp);
	}
	else{
		
		if(q->r==NULL)
		{
			q->r=temp;
			return;
		}
		else
		insert(q->r,temp);
	}
}
void display(struct node *q,int op)
{
	if(q!=NULL)
	{
		switch(op)
		{
			case 1:
			printf("%d\t",q->data);
			display(q->l,op);
			display(q->r,op);
			break;
			
			case 2:
			display(q->l,op);
			printf("%d\t",q->data);
			display(q->r,op);
			break;
			
			case 3:
			display(q->l,op);
			display(q->r,op);
			printf("%d\t",q->data);
			break;
		}
	}
}
void search(struct node *p,int x)
{
	while(p!=NULL)
	{
		if(p->data==x)
		{
			found=1;
			succ=p;
			return;
		}
		else if(x>p->data)
			{
				parent=p;
				p=p->r;
				
			}
		else{
				parent=p;
				p=p->l;
			}
				
		
	}
}
void delete1(struct node *p,int x)
{
	struct node *temp,*temp1=NULL;
	parent=NULL;
	succ=NULL;
	search(p,x);
			if(found==0)
				printf("value not found\n");
	
			else if((succ->l==NULL )&&(succ->r==NULL)) //node to be deleted has no child
			{
				if(parent->l==succ)
					parent->l=NULL;
				else
					parent->r=NULL;
			}
			else if((succ->l!=NULL )&& (succ->r==NULL)) //node to be deleted has only left child
			{
				if(parent->l==succ)
					parent->l=succ->l;
				else
					parent->r=succ->l;
			}
			else if((succ->l==NULL)&&(succ->r!=NULL)) //node to be deleted has only right child
			{
				if(parent->l==succ)
					parent->l=succ->r;
				else
					parent->r=succ->r;
				
			}
			else if((succ->l!=NULL)&&(succ->r!=NULL))  //it has both children
			{
				temp=succ->r;
				while(temp->l!=NULL)
				{
					temp1=temp;
					temp=temp->l;
				}
				succ->data=temp->data;
				temp1->l=NULL;
				
			}
			printf("value deleted successfully\n");
		
}
		
		


	
	
	
		
		
		
	

			
			
			
			