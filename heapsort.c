#include<stdio.h>


void maxheap(int a[],int i,int n)
{
	int r,l,max,temp;
	l=2*i;
	r=2*i+1;
	if((l<=n) && (a[l]>a[i]))
		max=l;
	else
		max=i;
	if((r<=n) && (a[r]>a[max]))
		max=r;
	if(max!=i)
	{
		temp=a[i];
		a[i]=a[max];
		a[max]=temp;
		maxheap(a,max,n);
	}
}
void buildmaxheap(int a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		maxheap(a,i,n);
	}
}
void heapsort(int a[],int n)
{
	int i,temp;
	buildmaxheap(a,n);
	for(i=n;i>=2;i--)
	{
		temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		maxheap(a,1,i-1);
	}
}
int main()
{
	int a[50],i,n;
	printf("Enter the size of array : ");
	scanf("%d",&n);
	printf("Enter the elements of array \n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	printf("sorted array is \n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
return 0;
}
	
	