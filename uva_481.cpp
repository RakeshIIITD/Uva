// `roCKy FireBirD
// Contains procedure to retrieve LIS
//Accepted
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<limits.h>
#include<set>
#include<map>
#include<vector>

using namespace std ;
vector<long long>v ;
vector<long long>L ;
vector<long long>a ;

int findLargest(int x)   // log(N) ;
{
	int res =  lower_bound(L.begin(),L.end(),x)-L.begin() ;	
	return res ;
}
 
int C(int n)
{
	for(int i=1;i<=n;i++) 
	{
	  L.push_back(LLONG_MAX) ;
    }
	L[0] = LLONG_MIN;
 
	int len=-1;
	for(int i=0;i<n;i++)
	{
		int k = findLargest(v[i]) ;
		if(L[k]>v[i])
		{
			L[k] = v[i] ;
		}
		if(k>len)  len = k ;
		a.push_back(k) ;
	}
	return len ;	
}
 
int main()
{
	long long n ;
	while(scanf("%lld",&n)!=EOF)
	{
		v.push_back(n) ;
	}
	int len = C(v.size()) ;
	printf("%d\n-\n",len) ;
	int i = a.size()-1 ;
	a.push_back(LLONG_MAX) ;
	vector<long long>b(len) ;
	do
	{										// start from downward while decreasing length
		if(a[i]==len&&a[i+1]!=a[i])
		{
			 b[len-1] = v[i] ;
			 len-- ;
	    }
		i-- ; 
	}while(len!=0) ;
	
	for(int i=0;i<b.size() ; i++)
	printf("%d\n",b[i]) ;
 	return 0;
}

