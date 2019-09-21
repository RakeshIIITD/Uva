// `roCKy FireBirD
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std ;
int visited[27] ;
typedef pair<int,int> ii ;
typedef vector<ii > vii ;
vii v ;
void dfs(int u)
{
	visited[u] = 1 ;
	for(vii::iterator it = v.begin() ; it!=v.end() ; it++) 
		if(visited[it->first]==0)        dfs(it->first) ;
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
		scanf("%c\n",&a) ;
		int size = a-65+1 ;
		while(1)
		{
			string line ;
			getline(cin,line) ;
		 	if(line.empty())  break ;
				v.push_back(make_pair(a-65,b-65) ;
				v.push_back(make_pair(b-65,a-65) ;
	 		
		}
		
		for(int i=0;i<size;i++)
		
		if(visited[i]!=1)  
		{
	   		dfs(i) ;
			count++ ;
    	}
   	 printf("%d\n",count) ;
   	 v.clear() ;
   }
	return 0 ;
}
