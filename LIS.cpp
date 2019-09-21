#include<stdio.h>
#define UNKNOWN -1
int backtrack(int,int);

int max(int a,int b)
{
	return (a>b?a:b);
}
int a[]={0,3,2,6,4,5,1};
int L[7];
int main()
{
	
	for(int i=0;i<7;i++)     //memo initialization
	L[i]=UNKNOWN;
	printf("%d",backtrack(0,0));
return 0;
}

int backtrack(int i,int j)
{int q;
	if(a[i]>a[j]&&j>i)
	return L[i];
	if(i==1)    return 1;
	q=UNKNOWN;
	for(int i=1;i<=7;i++)
	{
	q=max(q,1+backtrack(i,7-i));
	L[i]=q;
   }
   return q;
}
