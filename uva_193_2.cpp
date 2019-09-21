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

using namespace std ;

vector< vector<int> > vii(200);

int color[200] ;
int visited[200] ;
int c ;
vector<int>black;
vector<int>max_b ;

void dfs(int node)
{
	int size = vii[node].size() ;
	visited[node] = 1 ;
	
	for(int i = 0 ; i<size ; i++ )
	{
		if(visited[vii[node][i]]==1&&color[node]&&color[vii[node][i]])  c-- ;
		if(visited[vii[node][i]]==0&&color[vii[node][i]]==0)
		{
			if(color[node]==0) 								
			{
			  color[vii[node][i]] = 1 ;
			  black.push_back(vii[node][i]) ;
			  c++ ;
		    }
			dfs(vii[node][i]) ;
		}
	}
}

int main()
{
     int n,a,b ,node ,edge ;
     scanf("%d",&n) ;
     
     while(n--)
     {
     	scanf("%d %d",&node ,&edge) ;
     	vii.resize(node+1) ;
     	for(int i=0;i<edge ; i++ )
     	{
     		scanf("%d %d",&a,&b) ;
     		vii[a].push_back(b) ;
     		vii[b].push_back(a) ;
     	}
     	int max=0;
     	for(int i = 1 ;i<=node ; i++ )
     	{
     		c = 0 ;
     		memset(color,0,sizeof(color)) ;
     		memset(visited,0,sizeof(visited)) ;
     		color[i] = 0 ; 
     		dfs(i) ;
     		if(c>max) 
			 {
			   max = c ;
			   max_b.clear() ;
			   int s = black.size() ; ;
			   for(int i = 0 ; i<s ; i++ )
			   {
			   	max_b.push_back(black[i]) ;
			   }
			}
			black.clear() ;
     	}
     	for(int i = 1 ;i<=node ; i++ )
     	{
     		c = 0 ;
     		memset(visited,0,sizeof(visited)) ;
     		memset(color,0,sizeof(color)) ;
     		color[i] = 1 ; 
     		dfs(i) ;
     		if(c>max){
     					max = c ;
     					max_b.clear() ;
			   			int s = black.size() ; ;
			   			for(int i = 0 ; i<s ; i++ )
			   			{
			   				max_b.push_back(black[i]) ;
			   			}
     				}
     		black.clear() ;
     	}
     	printf("%d\n",max) ;
     	sort(max_b.begin() , max_b.end()) ;
     	int size = max_b.size() ;
     	for(int i=0;i<size ;i++ )
     	{
     		printf("%d",max_b[i]) ;
     		if(i!=size-1)  printf(" ");
     	}
     	printf("\n") ;
		 vii.clear() ;
		 if(n>0)  scanf("\n") ;
     }
	return 0 ;
}

