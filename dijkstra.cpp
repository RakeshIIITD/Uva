//
// Created by rakesh on 3/6/18.
//


/* Dijkstra's Algorithm for SSSP */
#include<bits/stdc++.h>

using namespace std ;
#define INF 99999

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
        }
    

        priority_queue<pair<int,int> , vector<pair<int,int> >, greater< pair<int,int> > > pq ;

        vector<int> distance(110,INF) ;
        
        int source = 2 ;
        int u ;

        pq.push(make_pair(0,source)) ; 
        distance[source]  = 0 ;

        while(pq.empty()!=1)
        {
            u = pq.top().second ;  w = pq.top().first ; pq.pop() ;
                
            if(distance[u]>=w)             // if w is greater than assigned value ,then ignore
            {
                for(int i=0;i<v[u].size();i++)
                {
                    int d = v[u][i].first ;
                    int value = v[u][i].second ;     // (u,d)
                                       
                    if((distance[u]+value ) < distance[d])
                    {
                        distance[d] = distance[u]+value;
                        pq.push(make_pair(distance[d],d)) ;
                    }
                }
            }  
        }

        printf("distance %d -> %d",source,distance[3]);
   }

    
    return 0 ;
}