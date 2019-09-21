// `roCKy FireBirD
// Accepted
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>

using namespace std ;
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)

int main()
{
	long b ,p , m ;	
	while(scanf("%ld\n%ld\n%ld",&b,&p,&m)!=EOF)
	{
		long n = p ;
		long long x  = b ;
		long long res = 1 ;
		while(n)
		{
			if(n%2==1)  res = (res*x)%m ;
			x = ((x)*(x))%m ;
			
			n/=2 ;	
		}
		printf("%lld\n",res) ; 
		scanf("\n");    	
	}
	return 0 ;
}

