// `roCKy FireBirD
//  Incomplete
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<math.h>
#include<algorithm>

using namespace std ;

int a[101] ;
int n  ;
int L[10001][100]  ;
int C(int W , int j)
{
	if(W==0)    return W ;
	if(W<0&&W+a[j-1]>=0)   return W+a[j-1] ;
	if(j==n)  return W ;
	if(L[W][j]!=99999)   return L[W][j] ;
	int ans = INT_MAX ;
	
	for(int i = j ; i<n ; i++ )
	{
		ans = min(ans , C(W-a[i] , i+1)) ;	
	}
	return L[W][j] = ans ;
}

int main()
{
	int t ;
	scanf("%d",&t) ;
	while(t--)
	{
		int sum = 0 ;
		scanf("%d",&n) ;
		for(int i=0;i<n ; i++)
		{
			scanf("%d",&a[i]) ;
			sum+=a[i] ;
		}
		for(int i=0;i<=sum;i++)
		{
			for(int j=0;j<=n;j++)
				L[i][j] = 99999 ;
		}
		int k = sum/2 ;
		int h1 = 0 ,h2 ;
		if(sum%2==0)   h2 = C(k,0) ;
		else
		{
			h1 = C(k,0) ;
			h2 = 1+C(k+1 , 0 ) ;
		}    
   		printf("%d\n",h2-h1) ;
	}
	return 0 ;
}

