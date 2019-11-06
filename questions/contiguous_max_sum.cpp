#include<bits/stdc++.h>

using namespace std ;
 int val[] = {9,7,2,9,6,5,5,4,6,8,9,9};
vector<vector<int> > adj(12);

 int _max =-99999 ;
vector<int> max_path ;

void dfs(int u,int res,int _count, int visited[], vector<int>& path)
{
    
    
    if(res>=_max&&_count==5)
    {
      _max = res ;
      max_path = path ;

        cout<<"Max Value : "<<_max<<"\nMax Path : " ;

        for(int i=0;i<max_path.size();i++)  cout<<max_path[i]<<" ";
          cout<<endl;

        return ;
    }
    if(_count==5)   return ;

 for(int i=0; i< adj[u].size();i++)
  {
    int v = adj[u][i] ;

      if(visited[v]==0)
      {
          path.push_back(v) ;
          visited[u] = 1 ;
          dfs(v,res+val[v],_count+1,visited,path) ;
          path.pop_back() ;
          visited[u] = 0 ;
      }
  }
  //path.pop_back() ;
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

  for(int u = 0 ;u<12; u++)
  {
    vector<int> path ;
    path.push_back(u) ;
     int visited[12] = {0} ;
     dfs(u,val[u],1,visited,path) ;
  }

  //cout<<"Max Value : "<<_max<<endl<<"Max Path : \n" ;

  //for(int i=0;i<max_path.size();i++)  cout<<max_path[i]<<" ";


  return 0 ;
}