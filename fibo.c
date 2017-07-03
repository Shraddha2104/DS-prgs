#include<stdio.h>
int fibo(int);
int main()
{
	int n,ans;
	printf("enter the value:\n");
	scanf("%d",&n);
	ans=fibo(n);
	printf("ans is %d",ans);
return 0;
}
int fibo(int n)
{
	int x,y;
	if(n<=1)
	return n;
	x=fibo(n-1);
	y=fibo(n-2);
	return (x+y);
}