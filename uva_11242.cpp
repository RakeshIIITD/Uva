//Accepted
#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	int R ,F ;
	while(1)
	{
		int f[10] ;
		int r[10] ;
		vector<double>d ;
		int n ; 
		scanf("%d",&F) ;
		
		if(F==0)  break ;

		scanf("%d",&R) ;
				
		for(int i = 0 ;i<F ; i++)
		{
			scanf("%d",&n);
			f[i] = n ;
		}
		for(int i = 0 ; i<R ; i++)
		{
			scanf("%d",&n) ;
			r[i] = n ;
		}
		
		for(int i = 0 ;i<F ; i++)
		{
			for(int j = 0 ; j<R ; j++ )
			{
				d.push_back(double(r[j])/f[i]) ;
			}
		}
		
		double max_spread = -9999 , b ;
		
		sort(d.begin(),d.end()) ;
		
		for(int i = 0 ; i<d.size()-1 ; i++ )
		{
			b = d[i+1]/d[i] ;
			
			if(b>max_spread)
			max_spread = b ;
		}
		
		printf("%.2lf\n",max_spread) ;
	}
	return 0 ;
}
