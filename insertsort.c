#include<stdio.h>
void insert(int a[],int n);

int main()
{
	int i,n,a[20];
	printf("enter the number of values\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter value:\n");
		scanf("%d",&a[i]);
	}
	insert(a,n);
	printf("sorted array is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
return 0;
}
void insert(int a[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0 && temp<a[j])
		{
			a[j+1]=a[j];
			j--;
			
		}
		a[j+1]=temp;
	}
}
