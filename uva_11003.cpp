//TimeLimit Exceeded
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<limits.h>

// `roCKy FireBirD

using namespace std ;

int max(int x,int y){	return x>y?x:y ;  }

int w[1001] ;
int m[1001] ;
int n ;
int L[100001][1001] ;

int C(int W,int j)
{
	if(W-w[j+1]>m[j+1]&&j!=n-1)   return -1;
	if(j==-1)  return 0 ;
   	if(L[W][j]!=0)   return L[W][j] ;
	int ans = INT_MIN ;
	for(int i=j;i>=0;i--) 
	  ans = max( ans, 1+C(W+w[i] , i-1) ) ;
	return L[W][j] = ans ;
}

int main()
{
	int t ;
	while(1)
	{
		scanf("%d",&t) ;
		if(t==0)    break ;
		memset(L,0,sizeof(L));
		n =  t;
		for(int i=0;i<t;i++)	scanf("%d %d",&w[i],&m[i]) ;	
		printf("%d\n",C(0,t-1)) ;	
	}
 	return 0;
}
