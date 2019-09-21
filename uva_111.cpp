// `roCKy FireBirD
// Longest Increasing Subsequence O(NlogN) implementation
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
 
using namespace std ;
 
int a[22] ;
int b[22] ;
int L[22] ;
int h[22] ;
 
int findLargest(int x,int n)   // log(N) ;
{
	int res =  lower_bound(L,L+n,x)-L ;	
	return res ;
}
 
int C(int n)
{
	for(int i=1;i<n;i++) 
	{
	  L[i] = 999999 ;
    }
	L[0] = -999999;
 
	int len=-1;
	for(int i=0;i<n;i++)
	{
		int k = findLargest(b[i],n) ;
		if(L[k]>b[i])
		{
			L[k] = b[i] ;
		}
		if(k>len)  len = k ;
	}
	return len ;	
}
 
int main()
{
	int n ,d;
	scanf("%d",&n);
	string str ;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&d) ;
		h[d] = i+1 ;
	}
	scanf("\n");
	while(1)
	{
		getline(cin,str);
		if(str.empty())   break ;
		stringstream ss(str) ;
		for(int i=0;i<n;i++)
		{
		   ss>>d ;
	       b[i] = h[d] ;
		}
 
		printf("%d\n",C(n)) ;
	}
 
 	return 0;
}
