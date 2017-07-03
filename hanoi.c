#include<stdio.h>
void towers(int n,char frompeg,char topeg,char auxpeg)
{
	if(n==1)
	{
		printf("Move disk 1 from %c to %c \n" , frompeg , topeg) ; 
		return ; 
	}
	//move top (n-1) discs from a to b using c as auxpeg
	towers(n-1,frompeg,auxpeg,topeg);
	
	 // move remaining disk from a to c  
	printf("Move disk %d from %c to %c \n" , n , frompeg , topeg);
	
	// move n-1 disks from b to c using a as auxillary  
    towers(n-1 , auxpeg , topeg ,frompeg) ; 
}
int main()
{
	int n;
	printf("enter the number of discs\n");
	scanf("%d",&n);
	printf("Solution for %d disks is as shown: \n",n) ; 
	towers(n,'A','C','B') ; 
	return 0;
}
	