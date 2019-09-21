//
// Created by rakesh on 2/6/18.
//

#include<bits/stdc++.h>

using namespace std ;

bool biparitite ;

#define UNVISITED -1

void bfs(vector<vector<int> > v , int visited[])
{
	int source =0 , u ;

	queue<int> q;

	q.push(source) ;

	visited[source] = 1 ;
	while(q.empty()!=1)
	{
		u = q.front() ; q.pop() ;

		for(int i=0;i<v[u].size() ; i++ )
		{
			if(visited[v[u][i]]==UNVISITED)
			{
				visited[v[u][i]] = 1 - visited[u] ;
				q.push(v[u][i]);
			}
			else if(visited[v[u][i]]==visited[u])
			{
				biparitite = 0 ;
				break;
			}
		}
		if(!biparitite) break ;
	}

}

int main()
{


    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout) ;
    #endif

    	int x,y ;

    int n,m;

    while(1)
    {
    	scanf("%d",&n);

    	if(n==0)  break ;

    	scanf("%d",&m);


    	vector<vector<int> > v(n+1) ;

    	for(int i=0;i<m;i++)
    	{
    		scanf("%d%d",&x,&y);

    		v[x].push_back(y);
    		v[y].push_back(x);
    	}

    	int visited[210] ;

    	for(int i=0;i<n;i++)  visited[i] = UNVISITED ;

    	biparitite = 1 ;

    	bfs(v,visited) ;

    	if(biparitite)  printf("BICOLORABLE.\n");
    	else            printf("NOT BICOLORABLE.\n");
    }

        return 0;
}