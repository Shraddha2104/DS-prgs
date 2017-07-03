#include<stdio.h>
struct queue{
	int items[10];//max of 9 vertices
	int f,r;
};
struct queue q;
void insert(int);
int removedata();
void creategraph();
void bfs(int,int);
int adj[10][10],visited[10];
int main()
{
	q.f=-1;
	q.r=-1;
	creategraph();
return 0;	
}
void insert(int c)
{
	if(q.r==9)
		printf("full\n");
	else{
			q.r++;
			q.items[q.r]=c;
		}
}
int removedata()
{
	
	if(q.r==-1)
	{
		printf("underflow\n");
		return 0;
	}
	else{
		return q.items[q.f++];
	}
}

void creategraph()
{
	int i,j,v,initial_node;
	printf("enter the number of vertices\t"); //max 9 vertices
	scanf("%d",&v);
	for(i=1;i<=v;i++)
		for(j=1;j<=v;j++)
			{
				printf("Is vertex %d adjacent to vertex %d ? \t",j,i) ;
				printf("Enter 1 if yes and 0 if no.\t ") ;
				scanf("%d",&adj[i][j]) ;
			}
	//making all vertices as unvisited		
	for(i=1 ; i<=v ; i++)
		visited[i]=0 ;
	
	printf("displaying the adjacency matrix\n");
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
			printf("%d\t",adj[i][j]);
		printf("\n");
	}
	printf("enter the initial node\n");
	scanf("%d",&initial_node);
	bfs(initial_node,v);
}
void bfs(int initial_node,int n)
{
	int u,i;
	
	visited[initial_node]=1;
	printf("bfs traversal of the graph\n");
	printf("%d\t",initial_node);
	insert(initial_node);
	while(q.f<=q.r)
	{
		u=removedata();
		for(i=1;i<=n;i++)
		{
			if(adj[u][i]==1 && visited[i]==0 )
			{
				insert(i);
				visited[i]=1;
				printf("%d\t",i);
				
			}
		}
	}
}

