//
// Created by rakesh on 2/6/18.
//

#include<bits/stdc++.h>

using namespace std ;

#define VISITED 1
#define UNVISITED 0

vector<int> order ;
int n ;
void topologicalSort(int u,vector<vector<int> > v , int visited[])
{
    visited[u] = VISITED ;
    order.push_back(u);
    if(order.size()==n)
    {
        for(int i=0;i<order.size();i++)
        {
            printf("%d",order[i]);
            if(i+1!=order.size())  printf(" ");
        }
        printf("\n");
        return ;
    }
    for(int i=0;i<v[u].size() ; i++ )
    {
        if(visited[v[u][i]]==UNVISITED )
        {
            topologicalSort(v[u][i],v,visited) ;
        }
    }
    visited[u] = UNVISITED ;
  order.pop_back();
}

int main()
{


#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout) ;
#endif
    int m ;

    while(1)
    {
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)  break ;

        int x,y ;
        vector<vector<int> > v(n+1) ;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);

            v[x].push_back(y);
        }

        int visited[110] = {0} ;
        order.clear() ;



        for(int i=1;i<=n;i++)
        {
            if(visited[i]==UNVISITED)
            {
                topologicalSort(i,v,visited) ;
            }
        }

       // for(int i=order.size()-1;i>=0;i--)   cout<<order[i]<<" ";

    }
    return 0;
}