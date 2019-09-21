// `roCKy FireBirD
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

int DC(int n)					// number of divisors 
{
	int count = 1 ;
	int sqt = (int)sqrt(n) ;
	for(int i=2 ; i<=sqt ; i = ( i==2?3:i+2 ))
	{
		int pow = 0 ;
		
		while(n%i==0)
		{
			pow++ ;
			n/=i ;
		}
		
		if(pow!=0)
		{
			count*=pow+1 ;
		    sqt = (int)sqrt(n) ;
		}
	}
	if(n!=1)   count*=1+1 ;
	return count ;
}

int main()
{
	int testcase ;
	scanf("%d",&testcase) ;
	
	while(testcase--)
	{
		int U,L ;
		scanf("%d  %d",&L,&U) ;
		int max_i ,n;
		int max=-999 ;
		for(int i = L ; i<=U ; i++)
		{
			n = DC(i) ;
			if(n>max)
			{
				max=n;
				max_i = i ;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,max_i,max) ;
	}
	return 0 ;
}

