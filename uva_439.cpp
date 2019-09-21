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
#include<queue>

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

int visited[9][9] ;
bool isSafe(int i ,int j)
{
	if(i<=8&&j<=8&&i>0&&j>0)   return 1 ;
	else return 0 ;
}
int bfs(int s0,int s1 ,int d0 ,int d1)
{
	//cout<<s0<<s1<<d0<<d1 ;
	queue< ii > q ;
	int l,m ;
	l = d0 ;
	m = d1 ;
	q.push(make_pair(s0,s1)) ;
	visited[s0][s1] = 0 ;
	ii s ;
	int i,j;
	while(q.empty()!=1)
	{
		s = q.front() ; q.pop() ;
		if((i=(s.F+2))&&(j=(s.S+1))&&isSafe(i,j)&&visited[i][j]==-1)  { visited[i][j] = visited[s.F][s.S]+1 ; q.push(make_pair(i,j)) ; if(i==l&&j==m) return visited[i][j] ;}
		if((i=(s.F-2))&&(j=(s.S+1))&&isSafe(i,j)&&visited[i][j]==-1)  { visited[i][j] = visited[s.F][s.S]+1 ; q.push(make_pair(i,j)) ; if(i==l&&j==m) return visited[i][j] ;}
		if((i=(s.F-2))&&(j=(s.S-1))&&isSafe(i,j)&&visited[i][j]==-1)  { visited[i][j] = visited[s.F][s.S]+1 ; q.push(make_pair(i,j)) ; if(i==l&&j==m) return visited[i][j] ;}
		if((i=(s.F+2))&&(j=(s.S-1))&&isSafe(i,j)&&visited[i][j]==-1)  { visited[i][j] = visited[s.F][s.S]+1 ; q.push(make_pair(i,j)) ; if(i==l&&j==m) return visited[i][j] ;}
		if((i=(s.F+1))&&(j=(s.S+2))&&isSafe(i,j)&&visited[i][j]==-1)  { visited[i][j] = visited[s.F][s.S]+1 ; q.push(make_pair(i,j)) ; if(i==l&&j==m) return visited[i][j] ;}
		if((i=(s.F-1))&&(j=(s.S+2))&&isSafe(i,j)&&visited[i][j]==-1)  { visited[i][j] = visited[s.F][s.S]+1 ; q.push(make_pair(i,j)) ; if(i==l&&j==m) return visited[i][j] ;}
		if((i=(s.F+1))&&(j=(s.S-2))&&isSafe(i,j)&&visited[i][j]==-1)  { visited[i][j] = visited[s.F][s.S]+1 ; q.push(make_pair(i,j)) ; if(i==l&&j==m) return visited[i][j] ;}
		if((i=(s.F-1))&&(j=(s.S-2))&&isSafe(i,j)&&visited[i][j]==-1)  { visited[i][j] = visited[s.F][s.S]+1 ; q.push(make_pair(i,j)) ; if(i==l&&j==m) return visited[i][j] ;}
	}
}
void init()
{
    FOR(i,1,8)
    FOR(j,1,8)
    visited[i][j] = -1 ;
}

int main()
{
	char s[3] ,d[3] ;
	
	while(scanf("%s %s",s,d)!=EOF)
	{
			init() ;
		//	cout<<s ;
		    int i = int(s[0]-'a'+1) ;
		     int j = int(s[1]-'0') ;
		     int k = int(d[0]-'a'+1) ;
		     int z = int(d[1]-'0') ;
		     //cout<<i<<j<<k<<z ;
		     //return  0;
		     int dis ;
			 if(i==k&&j==z)   dis = 0 ; 
			else              dis = bfs( i, j  , k , z) ;
			
			printf("To get from %s to %s takes %d knight moves.\n",s,d,dis) ;
	}
//	return 0 ;
}

