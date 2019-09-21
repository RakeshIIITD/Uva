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
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)

map<int,vector<int> > v ;
map<int,int>m ;
int main()
{
	int t =0,n,v1,v2;
	while(1)					// testcase
	{
		if(t!=0)   scanf("\n");
		scanf("%d",&n) ;
		if(n==0)   break ;
		
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&v1,&v2) ;
			v[v1].push_back(v2) ;
			v[v2].push_back(v1) ;
			m[v1] = -1 ;
			m[v2] = -1 ;
		}
		int source ,ttl,s,tt  ;
		while(1)					// source
		{
			
				scanf("%d %d",&source,&ttl) ;
				if(source==0&&ttl==0)   break ;
				
				queue<int>q ;
				q.push(source) ;
				int flag = 1 ;
				m[source] = 0 ;
				tt = ttl ;
				while(q.empty()!=1)
				{
					if(flag==0)  break ;
					s = q.front() ; q.pop();
					tt-- ;
					int size = v[s].size() ;
					
					for(int i=0;i<size ; i++ )
					{
						if(tt==-1)
						{
							flag = 0 ;
							break ;
						}
						
						if(m[v[s][i]]==-1)
						{
							m[v[s][i]] = m[s]+1 ;
							q.push(v[s][i]) ;
						}
					}
				}
				int count =0;
				for(map<int,int>::iterator it = m.begin() ; it!=m.end() ; it++ )
				{
					if((it->second)==-1)   count++ ;
				}
				
				for(map<int,int>::iterator it = m.begin() ; it!=m.end() ; it++)   it->second = -1 ;
				t++ ;
				printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n" ,t , count , source , ttl) ;
			//	m.clear() ;
			
		}
		v.clear() ;
		m.clear() ;
		//scanf("\n") ;
	}
	return 0 ;
}

