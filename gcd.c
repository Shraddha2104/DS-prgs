#include<stdio.h>
int gcd(int,int);
int main()
{
	int a,b,ans;
	printf("enter two values");
	scanf("%d %d",&a,&b);
	ans=gcd(a,b);
	printf("ans is %d",ans);
	return 0;
}
int gcd(int a,int b)
{

	if(a%b==0)
	return b;
	else
	gcd(b,a%b);
	
	}