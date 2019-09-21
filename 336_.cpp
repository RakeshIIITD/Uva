#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>

using namespace std ;

int main()
{
	while(1)
	{
	  int testcase  , t=1 ;
	  scanf("%d",&testcase ) ;
	  if( testcase==0 )   break ;
	  
	  vector< vector<int> >adj(100) ;
	  int visited[100] ;
	  
	  for(int i=0;i<100;i++)
	  visited[i] = -2 ;
	  
	  for( int i=0 ;  i<testcase ; i++ )
	  {
	  	int v1,v2 ;
	  	scanf("%d%d",&v1,&v2 ) ;
	  	adj[v1].push_back(v2) ;
	  	adj[v2].push_back(v1) ;
	  	visited[v1] = -1 ;
	  	visited[v2] = -1 ;
	  }
	  int source , ttl , s ;
	  
	  
	  while(1)
	  {
	  	scanf("%d%d",&source,&ttl) ;
	  	
	  	if( source==0&&ttl==0 )  break ;
	  	
	  	queue<int>q ;
	  	q.push(source) ;
	  	visited[source] = 0 ;
	  	
	  	int flag = 0 ;
	  	
	  	    /* BFS */
	  	   while( q.empty()!=1 )
	  	 	{
	  			s = q.front() ;
	  			q.pop() ;
	  	   		//	visited[s] = 0 ;
	  		
	  			if(flg) break ;
	  		
	  			for( int i=0 ; i<adj[s].size() ; i++ )
	  		 	{ 
	  				if( visited[s]==ttl )  
	  				{
	  					flg++ ;
	  					break ;
	  				}
	  				if(visited[adj[s][i]]==-1 )
	  		    	{
	  		     		visited[adj[s][i]] = visited[s]+1 ;
	  			    	q.push( adj[s][i] ) ;
					}	
	  		 	}
	  		}
	  		int count = 0 ;
	  		for(int i=0;i<100 ; i++ )
	  		{
	  		//	 if(visited[i]!= -2)  cout<<i<<" - "<<visited[i]<<" "<<endl ;
			  	if(visited[i]== -1)   count++ ;
	  		}
	    	
	  		printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n" ,t++ , count , source , ttl ) ;
	  	
	  		for(int i=0;i<100 ; i++ )
	  		{
	  	    	if( visited[i]!= -2 )	visited[i] = -1 ;
	  		}
	  		
	  }	
	}
	return 0 ;
}
