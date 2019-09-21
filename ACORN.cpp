// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<vector>

using namespace std ;

int Hash[20][200] ;

int a[3][10] = {{3,1,4,10,-1,-1,-1,-1,-1,-1},{8,3,3,5,5,7,8,9,9,-1},{5,3,4,5,6,9,-1,-1,-1,-1}} ;

int max(int x ,int y)
{
	return x>y?x:y ;
}

int tree ;
int f ; 


//return max(Hash[t][h]+C(t-1,h-f) , max(Hash[t][h]+C(t,h-1) , max(Hash[t][h]+C(t+1,h-f) ,max(Hash[t][h]+C(t+2,h-f),Hash[t][h]+C(t-2,h-f)))) ) ;


int C(int t , int h)
{
	if(t<0)   return -99999;
	if(t>tree)    return -99999 ;
	if(h<0)   return -99999 ;
	if(h==0)   return 0 ;
	int acorn = -999999 ;
	
	for( int i = 0 ; i<=tree ; i++ )
	acorn = max( acorn , max( Hash[t][h] + C(i,h-f) , Hash[t][h] + C(t,h-1) )) ;
	return acorn ;	
}

int main()
{
	int t ;
	scanf("%d",&t);
	while(t--)
	{
		tree = 2 ;
		f=2 ;
		memset(Hash,0,sizeof(Hash)) ;
		for(int i=0;i<=tree;i++)
		{
			for(int j=1;j<=a[i][0];j++)
			{
				Hash[i][a[i][j]]++ ;
			}
		}
	
		cout<<C(1,10) ;
	}
	
 	return 0;
}

