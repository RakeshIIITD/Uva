// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string.h>
#include<algorithm>
#include<limits.h>

using namespace std ;

int max(int x,int y)
{
	return x>y?x:y ;
}

int a[] = {4,-10,-20,7} ;

int L1[101][101] ;
int L2[101][101] ;

int C(int j , int n , int bit)
{
	if(j==n)    return a[j] ;
	if(L1[j][n]!=0&&!bit)   return L1[j][n] ;
	if(L2[j][n]!=0&&bit)    return L2[j][n] ;
		
	int ans1 = INT_MIN ;
	int ans2 = INT_MIN ;
	
	for(int i=j;i<=n;i++)
	{
		if(!bit) ans1 = max(ans1,max(a[i]+C(i+1,n,0) ,max(a[i]+C(i+1,n,1),max(a[n]+C(i,n-1,0),a[n]+C(i,n-1,1))))) ;
		if(bit)  ans2 = max(ans2,max(a[i]+C(i+1,n,0) ,max(a[i]+C(i+1,n,1),max(a[n]+C(i,n-1,0),a[n]+C(i,n-1,1))))) ;
	}
	if(!bit)   return L1[j][n] = ans1 ;
	else       return L2[j][n] = ans2 ;
}
int main()
{
	int t ;
	memset(L1,0,sizeof(L1));
	memset(L2,0,sizeof(L2)) ;
	int n = 3 ;
	cout<<C(0,n,0) ;
	
	
 	return 0;
}

