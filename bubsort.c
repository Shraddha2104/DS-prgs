#include<stdio.h>
int main()
{
	int a[100],i,j,temp,n;
	printf("enter the number of values\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	
		printf("enter value:\t");
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
		}
	}
	printf("sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	return 0;
}
	