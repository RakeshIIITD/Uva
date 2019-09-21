// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<limits.h>

using namespace std ;

int min(int x ,int y)
{
	return x>y?y:x ;
}

int L[10001] ;
int a[101] ;

int C(int W,int n)
{
	if(W==0)    return 0 ;
	
	if(L[W]!=0)     return L[W] ;
	int ans = INT_MAX ;
	for(int i=n-1;i>=0;i--)
	{
		ans = min(ans , 1+C(W-a[i],n,cat)) ; 		
	}
	return L[W] = ans ;
}

int main()
{
	int t ,amount;
	scanf("%d",&t);
	while(t--)
	{
		memset(L,0,sizeof(L)) ;
		scanf("%d",&amount) ;
		int coins ;
		scanf("%d",&coins) ;
		int mini = INT_MAX ;
		for(int i=0;i<coins ; i++)
		{
			scanf("%d",&a[i]) ;
			if(a[i]<mini)   mini = a[i] ;
		}
		printf("%d\n",C(amount,coins)) ;
	}
	
 	return 0;
}

