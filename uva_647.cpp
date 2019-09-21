// `roCKy FireBirD
//Accepted
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<set>
#include<map>

using namespace std ;

int a[] = {50,25,10,5,1};

long long L[7900] ;

void C( int size)
{
	L[0] = 1 ;	
	
	for(int i=0;i<=size ; i++)
	{
		for(int j = a[i] ; j<=7489 ; j++ )
		{
			L[j]+=L[j-a[i]] ;
		}
	} 
}

int main()
{
	memset(L,0,sizeof(L)) ;
	C(4) ;
	int n ;
	string str ;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",L[n]) ;
    }
 	return 0;
}

