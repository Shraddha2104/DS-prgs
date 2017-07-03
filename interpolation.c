#include<stdio.h>
int main()
{
	int a[100],found=0,i,n,x,high,mid,low,index;
	printf("enter the number of values:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter value:\n");
		scanf("%d",&a[i]);
	}
	low=0;
	high=n-1;
	printf("enter the value to be searched:\n");
	scanf("%d",&x);
	while(low<=high)
	{
		mid=(low+(high-low)*((x-a[low])/(a[high]-a[low])));
		if(a[mid]==x)
		{
			found=1;
			index=mid;
			break;
		}
		else
		{
			if(x<a[mid])
			high=mid-1;
			else
			low=mid+1;
		}
	}
	if(found==1)
	printf("value found at %d\n",index);
	else
	printf("value not found\n");
return 0;
}
