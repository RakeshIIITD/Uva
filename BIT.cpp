// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std ;
#define INF 100000000
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)
int a[1001] ;
int BIT[1001] = {0} ;

void update(int r,int k,int len)				// r is index ; k is addition value
{
	while(r<=len)
	{
		BIT[r]+= k;							// BIT[r] = min(BIT[r],k)
		r = r+(r&(-r)) ;
	}
}

int add(int r)
{
	int ans = 0 ;						// ans = INF
	while(r>0)
	{
		ans+=BIT[r] ;					// ans = min(ans,BIT[r])
		r = r-(r&(-r)) ;
	}
	return ans ;
}

int main()
{
	int n ;
	cin>>n ;
	for(int i=1;i<=n;i++)    cin>>a[i] ;
	
	for(int i=1;i<=n;i++)   update(i,a[i],n) ;
	
	for(int i=1;i<=n;i++)   cout<<BIT[i]<<" ";
	return 0 ;
}

