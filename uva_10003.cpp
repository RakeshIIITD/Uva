//Accepted
// DP- recursive
// roCKy `FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<climits>
#include<set>
#include<map>
#include<vector>

using namespace std ;
int min(int x , int y)
{
	return x>y?y:x ;
}
int L[55][55] ;
int a[55] ; 

int size ;

int C( int n , int m )
{
    
	if(n+1==m)   return 0;
	if(L[n][m]!=-1)    return L[n][m] ; 
	int min_cost = INT_MAX ;
	
	for(int i = n+1 ; i<m ; i++)
		min_cost = min( min_cost , (a[m]-a[n])+C(n,i)+C(i,m) ) ;
	return L[n][m] = min_cost ;	
}

int main()
{
	while(1)
	{
		int length , l;
		scanf("%d",&length) ;
		if(length==0)   break ;
		a[0] = 0 ;
		scanf("%d",&l) ;
		for(int i = 1 ; i<=l ; i++)
		{
			scanf("%d",&a[i]) ;
		}	
		a[l+1] = length ;
	
		memset(L,-1,sizeof(L)) ;
		printf("The minimum cutting is %d.\n",C(0,l+1)) ; 
	}
 	return 0;
}

