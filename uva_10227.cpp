/*
* Can also be solved by Union - Find
* Note: People who havent heard the sound of tree, come under a different opinion.
*
*/

#include<bits/stdc++.h>

using namespace std ;

int main()
{
// #ifndef ONLINE_JUDGE
//   freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout) ;
// #endif

  int testcase ;
  string inp ;
  scanf("%d",&testcase) ;

  int P,T,u,v ;

  scanf("\n");
  while(testcase--)
  {

  	getline(cin,inp) ;
  	stringstream s(inp) ;
  	s>>P; s>>T;


  	vector<vector<int> > adj(P+1, vector<int>(0)) ;
  	while(1)
  	{
  		getline(cin,inp) ;
  		if(inp.empty())  break;

  		stringstream s(inp) ;
  		s>>u; s>>v ;
  		adj[u].push_back(v) ;
  	}
  	//SORT
  	int flag_set = 0 ;  // people who dont have any opinion come under this

  	for(int i=1;i<=P;i++)
  	{
  		if(adj[i].size()==0&&!flag_set)  flag_set = 1 ;

  		sort(adj[i].begin(),adj[i].end()) ;
  		vector<int>:: iterator ip = unique(adj[i].begin(),adj[i].end()) ;

  		adj[i].resize(distance(adj[i].begin(), ip) );
  	}

  	sort(adj.begin(),adj.end()) ;

  	vector<vector<int> >::iterator it = unique(adj.begin(),adj.end()) ;

  	int new_size = distance(adj.begin(), it) ;

  	adj.resize(new_size);



  	int res = 0 ;
  	
  	for(int i=0;i<new_size; i++) 
  		{
  			if(adj[i].size()!=0)  res++ ;
  		}

	cout<<res+flag_set<<endl;

  	if(testcase!=0)   cout<<endl;
  }

  return 0;
}