#include<stdio.h>
int main()
{
	int a[100],i,j,k,temp,n;
	printf("enter the number of values\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	
		printf("enter value:\t");
		scanf("%d",&a[i]);
	}
	for(i=n/2;i>0;i=i/2)
	{
		for(j=i;j<n;j++)
		{
			for(k=j-i;k>=0;k=k-i)
			{
				if(a[k+i]>=a[k])
				break;
				else
				{
					temp=a[k];
					a[k]=a[k+i];
					a[k+i]=temp;
				}
			}
		
		}
	}
	printf("sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	return 0;
}