//
// Created by rakesh on 3/6/18.
//

#include<bits/stdc++.h>

using namespace std ;


int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout) ;
#endif   

  int x,y,w ;
  int n,m;

  while(1)
  {

        scanf("%d%d",&n,&m);
        vector<vector< pair<int,int> > > v(n+1) ;

        if(m==0&&n==0) break;
        int total =0;

        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            v[x].push_back(make_pair(y,w)) ;
            v[y].push_back(make_pair(x,w)) ;

            total+=w;
        }
    

        priority_queue<pair<int,int> > pq ;

        int visited[200005] ={0} ;

        int minCost = 0 ;
        int u = 0 ;


            for(int i=0;i<v[u].size();i++)
            {
                if(visited[v[u][i].first]!=1)
                {
                    pq.push(make_pair(-v[u][i].second,v[u][i].first));
                }
            }

            visited[u] = 1 ;

        while(pq.empty()!=1)
        {

                u = pq.top().second ;
                w = pq.top().first ;
                pq.pop() ;

            if(visited[u]==0)
            {
                minCost+=(-w);
                visited[u] = 1 ;

                for(int i=0;i<v[u].size();i++)
                {
                    if(visited[v[u][i].first]!=1)
                    {
                        pq.push(make_pair(-v[u][i].second,v[u][i].first));
                    }
                }
            }

            
        }

            printf("%d\n",total-minCost) ;
   }

    
    return 0 ;
}