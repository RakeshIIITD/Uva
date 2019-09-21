//Accepted

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;
vector<int>v ;

int BS(int low , int high,int query)
{
	if(low>high)     return 0 ;
		int mid = (low+high)/2 ;
	
		if(v[mid]==query)    
		{
			while(mid!=0&&v[mid-1]==query)
			{
				mid-- ;
			}
		   return (mid+1);
	    }
		if(v[mid]<query)  BS(mid+1,high,query) ;
		else              BS(low,mid-1,query) ;
}
int main()
{
	int n , q ;
	int c = 0 ;
	while(1)
	{
		c++ ;
		int k , query ;
		scanf("%d%d",&n,&q) ;
		if(n==0&&q==0)   break ;
		
		for(int i=0;i<n;i++)
		{
			scanf("%d",&k) ;
			v.push_back(k) ;
		}
		printf("CASE# %d:\n",c) ;
		sort(v.begin() , v.end()) ;
		
		for(int i = 0 ; i<q ; i++)
		{
			scanf("%d",&query) ;
			int f = BS(0,n-1,query) ;
			if(f)    printf("%d found at %d\n",query,f) ;
			else     printf("%d not found\n",query) ;
		}
		v.clear() ;
	}
	return 0 ;
}
