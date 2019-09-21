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
int L[10005][7] ;
int h[10005] ;

int C(int v ,int select )									// maximum independent set weighted
{
	if(L[v][select]!=-1)   return L[v][select] ;   // correction in case of weights
	L[v][select]=select;
	int m=INF;
	FOR(ch,0,Adj[v].size()-1)
	{
		FOR(i,1,6)   if(i!=select)  m=min( m , C(Adj[v][ch],i));
		L[v][select]+=m;										
	}
	return L[v][select];
}

int main()
{
	int root = 0 ;
	int n ,x;
	string t ;
	char c ;
	while(scan(n)&&n!=0)
	{
		ln;
		Adj.resize(n) ;
		string str ;
		FOR(i,0,n-1)  h[i] = 0 ;
		FOR(i,0,n-1)
			{
				getline(cin,str) ;
				SS(str) ;
				ss>>t ;
				
				while(ss>>x)		{  VPUSH(Adj[i],x) ;
									h[x]++; }			  
			}
			
			FOR(v,0,n-1)   
			{
		  		
				L[v][1] = -1;
				L[v][2] = -1 ;
		  		L[v][3] = -1 ;
		  		L[v][4] = -1 ;
		  		L[v][5] = -1;
		  		L[v][6] = -1 ;
			}
			int root ;
			FOR(i,0,n-1)  if(h[i]==0)  root = i ;
		//	cout<<root<<endl ;
			int mwis = INF ;
			
			FOR(i,1,6)
			mwis = min(mwis,C(root,i) );
			printf("%d\n\n",mwis) ;
	}
	return 0 ;
}
