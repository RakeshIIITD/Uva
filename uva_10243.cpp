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
//================================================================================
#define INF 100000000
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

vector< vector<int> > Adj ;
int L[1001][2] ;
int visited[1001] ;
int C(int v ,int select )									// maximum independent set weighted
{
	if(L[v][select]!=select)   return L[v][select] ;
	
	FOR(ch,0,Adj[v].size()-1)
	{
		
		if(select) 
		{
		  if(!visited[Adj[v][ch]]) 
		  {
		  	visited[Adj[v][ch]]++ ;
		    L[v][1]+=C(Adj[v][ch],0) ;
			visited[Adj[v][ch]]-- ;
		  }
	    }
		else 
		{
		  if(!visited[Adj[v][ch]]) 
		  {
		  	visited[Adj[v][ch]]++ ;
		    L[v][0]+=max( C(Adj[v][ch],0) , C(Adj[v][ch],1)) ;
			visited[Adj[v][ch]]-- ;
		  }
	    }      
	}
	return L[v][select] ;
}

int main()
{
	int n ,t , y ;
	while(scan(n)&&n!=0)
	{
		Adj.resize(n+1) ;
		RESET(visited,0) ;
		FOR(i,1,n)
		{
			scan(t) ;
			FOR(j,1,t)  
			{
				scan(y) ;
				VPUSH(Adj[i],y) ;	
			}
		}
		FOR(i,0,n)   
		{
		  L[i][0] = 0 ;
		  L[i][1] = 1 ;
		}
		printf("%d\n",n-max(C(1,0),C(1,1))) ;
		Adj.clear() ;
	}
	return 0 ;
}

