// `roCKy FireBirD
//Accepted
//Can be also done with rmq and interval tree
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
using namespace std ;

int b[10001] ;
int L[10001] ;
int inc[10001]={0};
int decr[10001] = {0} ;

int findLargest(int x,int n)   // log(N) ;
{
	int res  =  lower_bound(L,L+n,x)-L ;
	return res ;
}
 
int C(int n,int type)
{
	for(int i=1;i<n;i++) 
	{
	  L[i] = 999999 ;
    }
	L[0] = -999999;
 
	int len=-1;
	int c = 1 ;
	if(type==0)
	for(int i=0;i<n;i++)
	{
		int k = findLargest(b[i],n) ;
		if(L[k]>b[i])
		{
			L[k] = b[i] ;
		}
		if(k>len)  len = k ;
		inc[c] = k>inc[c-1]?k:inc[c-1] ;
		c++ ;
	}
	if(type==1)
	{
		for(int i=n-1;i>0;i--)
		{
			int k = findLargest(b[i],n) ;
			if(L[k]>b[i])
			{
				L[k] = b[i] ;
			}
			if(k>len)  len = k ;
			decr[c] = k>decr[c-1]?k:decr[c-1] ;
			c++ ;
		}	
	}
	return len ;	
}

int main()
{
	int n   ;
	
	while(scanf("%d",&n)!=EOF)
	{
		int len1 ,len2 ;
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&b[i]) ;
		}
		len1 = C(n,0) ;
		len2 = C(n,1) ;
		int p=1;
		for(int i=1;i<n;i++)
		{
			if(inc[i]==decr[n-i+1])
			{
				if(inc[i]>p)
				{
					p = inc[i] ;
				}
			}
			else 
			{
				int m = inc[i]>decr[n-i+1]?decr[n-i+1]:inc[i];
				if(m>p)    p = m ;
			}
		}
		printf("%d\n",2*p-1) ;
	}
	
 	return 0;
}

