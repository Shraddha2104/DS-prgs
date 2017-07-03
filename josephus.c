#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *link;
};
int main()
{
	struct node *p=NULL;
	int n,i,j,k;
	struct node *temp,*q,*pre;
	printf("Enter the number of players: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=i;
		if(p==NULL)
		{
			p=temp;
			temp->link=p;
		}
		else
		{
			q=p;
			while(q->link!=p)
			{
				q=q->link;
			}
			q->link=temp;
			temp->link=p;
		}
	}
	printf("Enter the value of k hops: ");
	scanf("%d",&k);
	q=p;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			pre=q;
			q=q->link;
		}
		pre->link=q->link;
		q=q->link;
	}
	printf("person tht survives is %d",q->data);
return 0;
}
			
				
	
				
