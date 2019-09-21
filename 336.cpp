// `roCKy FireBirD

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
	
		int testcase , v1 ,v2 ,t = 1 ;
		scanf("%d",&testcase) ;
		
		if(testcase==0)  break ;
		
		vector< vector<int> >v(100) ;
		map<int,int>m ;
		
		while( testcase-- )
		{
			scanf("%d%d",&v1,&v2 ) ;
			v[v1].push_back(v2) ;
			v[v2].push_back(v1) ;
			m[v1]=-1 ;
			m[v2]=-1 ;
		}
		
		int source , ttl , s , time_to_live ;
		 
		queue<int>q ;
				
		while(1)
		{   
			scanf("%d%d",&source,&ttl) ;
			
			time_to_live = ttl ;
			
			if( source==0&&ttl==0 )   break ;
			
			/* BFS */ 
			q.push(source) ;
			m[source] = 0 ;   // source visited
			
			while( q.empty()!=1 )
			{
			   s = 	q.front() ;  q.pop() ;
			   
			   if( time_to_live==-1 )   break ;
			   
			   int size = v[s].size() ;
			   for(int i=0;i<size ; i++ )
			   {  
			      if(m[s]==ttl-1)
			        {
			        	time_to_live = -1 ;
			        	break ;
			        }
			   	  if(m[v[s][i]]==-1)
			   	    {
			   		    m[v[s][i]] = m[s]+1 ;
			   		    q.push(v[s][i]) ;
			        }
			   }
			}
			map<int,int>::iterator itr ;
			int count = 0 ;
			for( itr = m.begin() ; itr!=m.end() ; itr++ )
			if(( itr->second)==-1 ) count++ ;
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n" ,t++ , count , source , ttl ) ;
		}
	}
	return 0 ;
}
