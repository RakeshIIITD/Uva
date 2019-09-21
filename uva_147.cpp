// `roCKy FireBirD
//Accepted
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>

using namespace std ;

int a[] = {2000,1000,400,200,100,40,20,10,4,2,1};

long long L[6002] ;

void C( int size)
{
	L[0] = 1 ;	
	
	for(int i=0;i<=size ; i++)
	{
		for(int j = a[i] ; j<6002; j++ )
		{
			L[j]+=L[j-a[i]] ;
		}
	} 
}

int main()
{
	memset(L,0,sizeof(L)) ;
	C(10) ;
	float n ;
	while(1)
	{
		scanf("%f",&n) ;
		if(!n)   break ;
		unsigned k = (unsigned)((n + 0.001) * 20);
		printf("%6.2f%17lld\n",n,L[k]) ;
    }
 	return 0;
}

