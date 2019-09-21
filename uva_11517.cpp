// `roCKy FireBirD
// error prone
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>

using namespace std ;

int a[101] ;
int L1[10001] ;
int L2[10001] ;

int C2(int W , int n)
{
	L2[0] = 0 ;
	
	for(int i = 0 ; i<n ; i++ )
	{
		for(int j = a[i] ; j<=W ; j++ )
		{	
				L2[j] = min( L2[j] , 1+L2[j-a[i]] );
		}
	}
	return L2[W] ;
}

int C1(int W , int n)
{
	if(W<=0)   return W ;
	if(L1[W]!=INT_MIN)   return L1[W] ;
	
	int ans = INT_MIN ;
	for(int i=0;i<n;i++)
	{
		ans = max( ans , C1(W-a[i], n ) ) ;
	}
	return L1[W] = ans ;
}

int main()
{
	int t ;
	scanf("%d",&t) ;
	
	while(t--)
	{
		int amount , n ;
		memset(L2,999999,sizeof(L2)) ;
		
		scanf("%d%d",&amount,&n) ;
		for(int i=0;i<=amount;i++)
		L1[i] = INT_MIN ;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]) ;
		}
		int k ;
		k = -1*C1(amount,n) ;
		k = k+amount ;
		printf("%d ",k) ;
		printf("%d\n",C2(k,n)) ;
	}
	return 0 ;
}

