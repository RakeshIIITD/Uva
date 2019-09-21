// `roCKy FireBirD
//Accepted
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

bool cmp(int n,int k){
	return n>k;
}

vector<int>v ;
vector<int>L ;
int findLargest(int x)   // log(N) ;
{
	int res =  upper_bound(L.begin(),L.end(),x,cmp)-L.begin() ;	
	return res ;
}
 
int C(int n)
{
	for(int i=0;i<=n;i++) 
	{
	  L.push_back(-9999999) ;
    }
	L[0] = 9999999;
 
	int len=-1;
	for(int i=0;i<n;i++)
	{
		int k = findLargest(v[i]) ;
		if(L[k]<v[i])
		{
			L[k] = v[i] ;
		}
		if(k>len)  len = k ;
	}
	return len ;	
}

int main()
{
	int testcase = 0 ;
	int n ;
	while(1)
	{
		testcase++ ;
		while(1)
		{
			scanf("%d",&n);
			if(n==-1)   break ;
			v.push_back(n) ;
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n",testcase,C(v.size())) ;
		v.clear() ;
		L.clear() ;
		scanf("%d",&n);
		if(n==-1)   break ;
		v.push_back(n) ;
		printf("\n");
	}
 	return 0;
}

