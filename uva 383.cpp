// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>

using namespace std ;
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)
map<string,vector<string> > m ;
map<string,int> visited ;

void init_map()
{
	for(map<string,vector<string> >::iterator it = m.begin() ; it!=m.end() ; it++ )
	{
		visited[it->first] = -1 ;
	}
}

int main()
{
	int testcase ,c = 0 ;
	scanf("%d",&testcase) ;
	printf("SHIPPING ROUTES OUTPUT\n\n") ;
	while(testcase--)
	{
		int k,n,p ;
		c++ ;
		
		
		scanf("%d %d %d",&k,&n,&p) ;
		string s , s1 , s2 ;
		
		for(int i = 0 ; i<k ; i++ )
		{
			cin>>s ;
			m[s] ;				
		}
			
		
		for(int i=0;i<n ; i++ )
		{
			cin>>s1>>s2 ;
			m[s1].push_back(s2) ;
			m[s2].push_back(s1) ;
		}
		printf("DATA SET  %d\n\n",c) ;
		int d ;
		
		for(int i=0;i<p;i++)
		{
			init_map() ;
			int flag = 0 ;
			cin>>d>>s1>>s2 ;
			
			queue<string>q ;
			
			q.push(s1) ;
			
			visited[s1] = 0 ;
			
			while(q.empty()!=1)
			{
				s = q.front() ; q.pop() ;
				
				for(int i = 0 ; i<m[s].size() ; i++ )
				{
					if(visited[m[s][i]]==-1)
					{
						visited[m[s][i]] = visited[s]+1 ;
						q.push(m[s][i]) ;
					}
					if(m[s][i]==s2)     
					{
					  flag= 1 ;
					   break ;
				    }
				}
				if(flag)  break ;
			}
			 if(visited[s2]==-1)   printf("NO SHIPMENT POSSIBLE\n");
			 else       		   printf("$%d\n",visited[s2]*100*d) ;
		}
		m.clear() ;
		printf("\n");
	}
	printf("END OF OUTPUT\n") ;
	return 0 ;
}

