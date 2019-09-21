// `roCKy FireBirD
// incomplete
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std ;
int visited[150] ;
vector<vector<int> >v(28) ;

void dfs(int u)
{
	visited[u] = 1 ;
	for(int i=0;i<(v[u]).size() ; i++) 
		if(visited[v[u][i]]==0)        dfs(v[u][i]) ;
}

int main()
{
	int t ;
	scanf("%d\n",&t) ;
	while(t--)
	{
		int count = 0 ;
		
		memset(visited,0,sizeof(visited)) ;
		
		char a,b ;
		scanf("%c\n",&a);
		int size = a+1-65 ;
		while(1)
		{
			string line ;
			getline(cin,line) ;
		 	if(line.empty()==1)  break ;

		 		 a =line[0];
				 b =line[1];
				v[a-65].push_back(b-65) ;
				v[b-65].push_back(a-65) ;
		}
		
		for(int i=0;i<size;i++)
		
		if(visited[i]==0)  
		{
	   		dfs(i) ;
			count++ ;
    	}
   	 printf("%d\n",count) ;
   	 for(int i=0;i<size ; i++)
   	     v[i].clear() ;
   	 if(t>0) printf("\n") ;
   }
	return 0 ;
}
