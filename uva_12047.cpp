//
// Created by rakesh on 3/6/18.
//

#include<bits/stdc++.h>

using namespace std ;
#define INF 99999


void dijkstra(int source,vector<vector< pair<int,int> > > v,vector<int> &distance)
{

    int u ,w;

    priority_queue<pair<int,int> , vector<pair<int,int> >, greater< pair<int,int> > > pq ;

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
}

int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout) ;
#endif   

  int x,y,w ;
  int n,m,s,t,p;
  int testcase ;
  scanf("%d",&testcase);
  while(testcase--)
  {
        scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);
        vector<vector< pair<int,int> > > v(n+1) ;
        vector<vector< pair<int,int> > > z(n+1) ;
        vector<pair<pair<int,int>,int> > edge ;

        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            v[x].push_back(make_pair(y,w)) ;
            z[y].push_back(make_pair(x,w)) ;

            edge.push_back(make_pair(make_pair(x,y),w));
        }
    
        vector<int> distanceF(n+5,INF) ;    
        vector<int> distanceB(n+5,INF) ;
        
        dijkstra(s,v,distanceF);
        dijkstra(t,z,distanceB);

        int d ;
        int max_=-1;

        for(int i=0;i<edge.size();i++)
        {
            x = edge[i].first.first ;
            y = edge[i].first.second ;
            w = edge[i].second ;
            
            if(distanceF[x]+w+distanceB[y]<=p && w>max_)
            {
                    max_ = w ; 
            }
        }
        printf("%d\n",max_);

   }
   
    return 0 ;
}