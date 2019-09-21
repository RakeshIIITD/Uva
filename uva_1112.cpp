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
  int testcase ,source,timer;

  scanf("%d",&testcase) ;
  

  while(testcase--)
  {
        scanf("\n") ;
        scanf("%d",&n);
        scanf("%d",&source) ;
        scanf("%d",&timer); 
        scanf("%d",&m);


        vector<vector< pair<int,int> > > v(n+4) ;

        int _count = 0 ;

        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            v[y].push_back(make_pair(x,w)) ;
        }
    

        priority_queue<pair<int,int> , vector<pair<int,int> >, greater< pair<int,int> > > pq ;

        vector<int> distance(n+4,INF) ;
        
        
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

        for(int i=1;i<=n;i++) 
        {
            if(distance[i]<=timer)  _count++ ;
        }

        printf("%d\n",_count);
        if(testcase!=0)  printf("\n");
   }

    
    return 0 ;
}