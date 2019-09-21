// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>

using namespace std ;

int a[501][6] ;
int n ;
int L[501][101] ;
int dp[501][7] ;

int C(int face , int j)
{
	if(j==n) return 1 ;  
	if(L[j][face]!=0)    return L[j][face] ;
	int ans = -999999 ;
	for(int i=0;i<6;i++)
	{
		if(a[j][i]==face)
		ans = max(ans, 1+C(( i%2==0?a[j][i+1]:a[j][i-1]) , j+1 ) ) ;
	    ans = max(ans , C(face , j+1)) ;
	    dp[j][i] = max(ans , dp[j][i]) ;
	}
	return L[j][face] = ans ;
}

int main()
{
	while(1)
	{
		memset(L,0,sizeof(L)) ;
		memset(dp,0,sizeof(dp)) ;
		scanf("%d",&n) ;
		
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4],&a[i][5]) ;
		}
		int min  = -99999 , k ,len ;
		for(int i=0;i<6;i++)
		{
			k = C( a[0][i] , 1 ) ;
			if(k>min)    min = k ;
		}
		cout<<min<<endl ;
		len = min ;
		for(int i = 0 ; i<=n ; i++ )
		{
			for(int j=0;j<6 ; j++ )
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl ;
		}
		
	}
	return 0 ;
}

