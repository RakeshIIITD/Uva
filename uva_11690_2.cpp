// dfs solution
#include<iostream>
#include<bits/stdc++.h>

using namespace std ;

vector<int> _sum ;
vector<vector<int> > adj ;
vector<int> visited ;

void dfs(int u, int *total)
{
	visited[u] = 1 ;
	*total+=_sum[u] ;

	for(int i=0;i<adj[u].size() ; i++)
	{
		if(visited[adj[u][i]]==0)   dfs(adj[u][i], total) ;
	}
}

int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout) ;
#endif
  
	int testcase,n,m, temp,u,v ;

	cin>>testcase ;
	
	while(testcase--)
	{
		cin>>n>>m;

		visited.assign(n,0) ;
		adj.assign(n,vector<int>(0));
		for(int i=0;i<n;i++)
		{
			cin>>temp ;
			_sum.push_back(temp) ;
			
		}
		

		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			adj[u].push_back(v) ;
			adj[v].push_back(u) ;
		}

		int total = 0;
		int flg = 1 ;
		for(int i=0;i<n;i++)
		{
			if(visited[i]==0)
			{
				dfs(i,&total) ;

				if(total!=0) 
					{
						flg = 0 ;
						cout<<"IMPOSSIBLE"<<endl;
						break ;
					}
			}
		}

		if(flg)  cout<<"POSSIBLE"<<endl ;

		adj.clear() ;
		_sum.clear() ;
		visited.clear() ;

	}

	return 0 ;
}