// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<limits.h>

using namespace std ;
int L[1003] ;
int w[1003] ;
int m[1003] ;
int sum[1003] ;

int findLargest(int x,int n)   // log(N) ;
{
	int res =  lower_bound(L,L+n,x)-L ;	
	return res ;
}
 
int C(int n)
{
	for(int i=1;i<n;i++) 
	{
	  L[i] = INT_MAX ;
	}
	L[0] = INT_MIN;
 	sum[0] = 0 ;
	int len=-1;
	for(int i=n-1;i>=0;i--)
	{
		int k = findLargest(m[i],n) ;
		if(m[i]>=sum[k-1])
		{
			sum[k] = sum[k-1]+w[i];
			L[k] = m[i] ;
		}
		if(k>len)  len = k ;
	}
	return len ;	
}

int main()
{	
	int n ;
	while(1)
	{
	  scanf("%d",&n);
	  if(!n)   break ;
	  for(int i=0;i<n;i++)	scanf("%d%d",&w[i],&m[i]) ;
	  cout<<L[0] ;
	  printf("%d\n",C(n));
	}
 	return 0;
}

