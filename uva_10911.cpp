// `roCKy FireBirD
// incomplete
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<set>
#include<map>
#include<vector>

using namespace std ;

double min(double x ,double y)
{
	return x>y?y:x ;
}

double dist[21][21] ;

double memo[1<<16]  = {-1};
int n ;

double C(int bitmask)
{	
	if(memo[bitmask]>-0.5)   return memo[bitmask] ;
	
	if(memo[bitmask]== (1<<2*n)-1)    return memo[bitmask] = 0 ;
	
	double d = 32767*32767;
	
	for(int i=0;i<2*n ; i++)
	{
		if(!(bitmask&(1<<i)))
		{
			for(int j=i+1;j<2*n;j++)
			{
				if(!(bitmask&(1<<j)))
				{
					d = min(d , dist[i][j] + C(bitmask|(1<<i)|(1<<j))) ;
				}
			}
		}
			break ;
	}
	return memo[bitmask] = d ;
}

int main()
{
	int x[20] , y[20] ;
	while(1)
	{
	//	memset(memo , -1 ,sizeof(memo)) ;
		char ch[25] ;
		scanf("%d",&n) ;
		if(!n)   break ;
		
		for(int i=0;i<2*n;i++)
		{
			//scanf("%s",ch) ;
			scanf("%d%d",&x[i],&y[i]) ;
		}
		
		for(int i=0;i<2*n ; i++)
		{
			for(int j=0;j<2*n ; j++ )
			{
				dist[i][j] = sqrt((double)(y[i]-y[j])*(y[i]-y[j]) + (x[i]-x[j])*(x[i]-x[j])) ;
			}
		}
		printf("%.2lf\n",C(0)) ;
		
	}
 	return 0;
}

