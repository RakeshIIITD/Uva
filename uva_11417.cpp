// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std ;
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)
int gcd(int a ,int b){ return b==0?a:gcd(b,a%b) ; }

int h[502][502] ;
int main()
{
	int N ;
	memset(h,0,sizeof(h)) ;
	while(scanf("%d",&N)&&N)
	{
	long	G=0;
	int i,j ,k ;
	for(i=1;i<N;i++)
	for(j=i+1;j<=N;j++)
	{
		if(h[i][j]==0)  
		{
		 k = gcd(i,j);
		 G+=k ;
		 h[i][j] = k ;
		}
		else G+=h[i][j] ;
	}
	printf("%ld\n",G) ;
	}
	return 0 ;
}

