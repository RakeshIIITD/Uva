// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string.h>
#include<algorithm>
#include<math.h>

using namespace std ;

int a[] = {50,25,10,5,1};

long long L[30001] ;

void C( int size)
{
	L[0] = 1 ;	
	
	for(int i=0;i<=size ; i++)
	{
		for(int j = a[i] ; j<30001; j++ )
		{
			L[j]+=L[j-a[i]] ;
		}
	} 
}

int main()
{
	memset(L,0,sizeof(L)) ;
	int k ;
	long long n ;
	C(4);
	
	while(scanf("%d",&k)!=EOF)
	{	
		n = L[k] ;
		if(n==1) printf("There is only 1 way to produce %d cents change.\n",k);
		else printf("There are %lld ways to produce %d cents change.\n", n , k );
	}
 	return 0;
}

