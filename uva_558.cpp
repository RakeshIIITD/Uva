// `roCKy FireBirD
// Accepted
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
//================================================================================
#define INF 10000000
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)					// for
#define LL signed long long int
#define fre 	freopen("0.in","r",stdin);freopen("0.out","w",stdout)
#define print(x) printf("%d\n",x)											//printf
#define printll(x) printf("%lld\n",x)
#define scanll(x) scanf("%lld",&x)
#define scan(x) scanf("%d",&x)												// scanf
#define ln  scanf("\n")														//consume \n
#define SS(a) stringstream ss(a)
#define ii pair<int,int>
#define F first
#define S second
#define abs(x) ((x)>0?(x):-(x))
#define RESET(arr,val) memset(arr, val, sizeof(arr))
#define ret return
#define ITERM(v) for(map<int,int>::iterator it = v.begin() ; it!=v.end() ; it++ )
#define ITERV(v)  for(vector<int>::iterator it = v.begin() ; it!=v.end() ; it++ )
#define VPUSH(v,b) v.push_back(b)												// push_back()
#define VI vector<int>
//=================================================================================
vector< vector< ii > > Adj ;
int d[2005] ;
int bellman_ford(int source , int n)
{
	FOR(i,0,n-1)    d[i] = INF ;
	d[source] = 0 ;
	
	FOR(i,0,n-1)
		FOR(u,0,n-1)
			FOR(j,0,Adj[u].size()-1)
				d[(Adj[u][j]).S] = min( d[(Adj[u][j]).S] , d[u] + (Adj[u][j]).F )	;		// pair is (weight,node)
	
	FOR(i,0,n-1)
		FOR(u,0,n-1)
			FOR(j,0,Adj[u].size()-1)
				if(d[(Adj[u][j]).S]>d[u] + (Adj[u][j]).F)   return 0 ;
	return 1 ;			
}

int main()
{
	int testcase , n ,m,x,y,r;
	scan(testcase ) ;
	
	while(testcase--)
	{
		scanf("%d %d",&n,&m) ;
		Adj.resize(n) ;
		FOR(i,0,m-1)
		{
		 scanf("%d %d %d",&x,&y,&r) ;
		 Adj[x].push_back(make_pair(r,y)) ;
		}
		int f = bellman_ford(0,n) ;
		if(!f)   printf("possible\n") ;
		else 	printf("not possible\n") ;
		Adj.clear() ;
	}
	return 0 ;
}

