// `roCKy FireBirD
//Contains nCr calculation
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
typedef long long ll ;

ll C(int n , int k)
{
	if(n-k<k)  k= n-k ;
	ll mul = 1 ;
	for(int i=1;i<=k ; i++ )     mul = mul*(n-k+i)/i ;
	return mul ;
}

int main()
{
	int n ,k ;
	while(1)
	{
		scanf("%d %d",&n,&k) ;
		if(n==0&&k==0) break ;
		
		printf("%lld\n",C(n,k)) ;
	}
	return 0 ;
}

