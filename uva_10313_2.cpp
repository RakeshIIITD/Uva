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

int a[300] ;

long long L[6002][1001] ;

void C( int size)
{
 
L[0][1] = 1 ;	
	int c = 1 ;
	
	for(int i=0;i<size ; i++)
	{
		for(int j = a[i] ; j<801; j++ )
		{
			for(int c=1;c<301 ; c++)   L[j][c+1]+=L[j-a[i]][c] ;
			
		}
	} 
}

int main()
{
	memset(L,0,sizeof(L)) ;
	for(int i=1;i<=300;i++) a[i-1] = i ;
	
	C(300) ;
	
	int sum = 0 ;
	int i=2;
	while(i!=37)
	sum += L[12][i++];
	cout<<sum ;
	return 0;
}

