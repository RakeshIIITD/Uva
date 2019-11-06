#include<bits/stdc++.h>

using namespace std ;
 int val[] = {9,7,2,9,6,5,5,4,6,8,9,9};
vector<vector<int> > adj(12);

 int _max =-99999 ;

void dfs(int u,int res,int _count, int visited[])
{
    visited[u] = 1 ;
    if(res>_max)
    {
      _max = res ;
      cout<<_max<<endl;
    }
    if(_count==5)   return ;

 for(int i=0; i< adj[u].size();i++)
  {
    int v = adj[u][i] ;

      if(visited[v]==0)
      {
          dfs(v,res+val[v],_count+1,visited) ;
      }
  }
}


int main()
{

  // graph 
  
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout) ;
#endif
  int n = 18 ; 
  int a,b;
  for( int i=0 ; i<n ; i++ )
  {
      cin>>a>>b;
      //cout<<a<<" "<<b<<endl;
      adj[a].push_back(b) ;
      adj[b].push_back(a) ;
  }

  for(int u = 0;u<12; u++)
  {
     int visited[12] = {0} ;
     dfs(u,val[u],1,visited) ;
  }

  cout<<"Max Value : "<<_max<<endl ;

  return 0 ;
}
