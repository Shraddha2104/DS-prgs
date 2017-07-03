#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAX 10

int a[MAX],compare[MAX];

int countDigit(int n){
	int c = 0;
	while(n>0){
		n/=10;
		c++;
	}
	return c;
}

void sort(int n, int dig){
	int i,j,temp,p,c = 0;
	while(dig>0){
		for(i = 0 ; i<n ; i++){
			compare[i] = a[i]/(pow(10,c));
			compare[i] = compare[i]%10;
		}
		c++;
		dig--;
		for(i = 0 ; i<n-1 ; i++)
		{
			
			for(j = i+1 ; j<n ; j++){
				if(compare[i]>compare[j])
				{
					temp=compare[i];
					compare[i]=compare[j];
					compare[j]=temp;
				}
				p=a[i];
				a[i]=a[temp];
				a[temp]=p;
			}
		}
	}
}
				
				

int main(){
	int n,i = 0,max,dig;
	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Enter elements of array:");
	scanf("%d",&a[i]);
	max = a[0];
	for(i = 1 ; i< n ; i++){
		scanf("%d",&a[i]);
		if(a[i]>max)
			max = a[i];
	}
	dig = countDigit(max);
	sort(n,dig);
	printf("Sorted array:");
	for(i = 0 ; i<n ; i++)
		printf("%d ", a[i]);
	return 0;
}