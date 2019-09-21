// `roCKy FireBirD
// Accepted
// DP - recursive

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<vector>

using namespace std ;

int max(int x , int y)
{
	return x>y?x:y;
}

int a[21][21] = {0} ;
int L[210][21] ;
int g ;
int M ;

int C(int cost , int j )
{
	if(cost<0)    return -1000000 ;
	if(j==g)    return M-cost ;
	
	if(L[cost][j]!=-1)    return L[cost][j] ;
	
	int max_cost = -1000000 ;
	
	for(int i=1;i<=a[j][0];i++)
	  max_cost = max(max_cost,C(cost -a[j][i] , j+1 )) ;
	  
	return L[cost][j] = max_cost ;
}

int main()
{
	int t ;
	scanf("%d",&t);
	
	while(t--)
	{
		int c;
		scanf("%d%d",&M,&c) ;
		g= c ;
		
		memset(L, -1, sizeof(L));
	
		for(int i=0;i<c;i++)
		{
			scanf("%d",&a[i][0]) ;
			for(int j=1;j<=a[i][0];j++)   scanf("%d",&a[i][j]) ;
		}
		
		int sol = C(M ,0) ;
		if(sol<0)   printf("no solution\n") ; 
		else        printf("%d\n",sol) ;
	}	
 	return 0;
}
