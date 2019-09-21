//`roCKy FireBirDS
// COrrect , Accepted
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
#include<utility>

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
map< string , vector<string> > m ;
map<string,int> visited ;
vector<string> v ;
int distance(string str1 , string str2)
{
	int count = 0 ,len1 ,len2 ;
	len1 = str1.size() ;
	len2 = str2.size() ;
	int i=0,j=0;
	
	while(i!=len1&&j!=len2)
	{
		if(str1[i++]!=str2[j++])   count++ ;
	}
	return abs(len1-len2) + count ;
}

int bfs(string source ,string dest)
{
	queue<string> q ;
	q.push(source) ;
	visited[source] = 0 ;
	string s ;
	int flag = 0 ;
	while(q.empty()!=1)
	{
		if(flag ==1) break;
		s = q.front() ; q.pop() ;
		
		FOR(i,0,m[s].size()-1)
		{
			if(visited[m[s][i]]==-1)
			{
				visited[m[s][i]] = visited[s]+1 ;
				q.push(m[s][i]) ;
			}
			if(m[s][i]==dest)
			{
				flag = 1 ;
				break ;
			}
		}
	}
	return	visited[dest] ;
}
void init()
{
    FOR(i,0,v.size()-1)
    visited[v[i]] = -1 ;
}
int main()
{
		int testcase ;
		scan(testcase) ;
		while(testcase--)
		{
			string str ;
			ln ;
			
			while(getline(cin,str)&&str!="*")
			{
						v.push_back(str) ;
						m[str] ;
			}
            init();
            
			FOR(i,0,v.size()-1)
			{
				FOR(j,0,v.size()-1)
				{
					if(i!=j)
					{
						if(distance(v[i],v[j])==1)     m[v[i]].push_back(v[j]) ;
					}
				}
			}
			while(getline(cin,str)&&str.empty()!=1)
			{
				SS(str) ;
				string w1,w2 ;
				ss>>w1 ;
				ss>>w2 ;
				int d = bfs(w1,w2) ;
				cout<<w1<<" "<<w2<<" "<<d<<endl ;
				init() ;
				
			}
			m.clear() ;
			visited.clear() ;
			v.clear() ;
			if(testcase>0)  cout<<endl ;
		}
	return 0 ;
}

