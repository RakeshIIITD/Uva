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
long long last(long long a)
{
	while(a%10==0)
	{
		a = a/10 ;
	}
	return a;
}

int main()
{
   long n , m ;
   
   while(scanf("%ld %ld",&n,&m)!=EOF)
   {
   	long res = 1 ;
   	for(int i=1;i<=m;i++)
   	{
   		res = (res*last(n-m+i)) ;
   		res = last(res) ;    
   	}
   	printf("%d\n",res%10) ;
   }
	return 0 ;
}

