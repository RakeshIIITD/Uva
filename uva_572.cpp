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
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)

int visited[101][101] ;
int arr[101][101] ;
int depth , width ;
bool safe(int i,int j)
{
	if(i<0||j<0||j>width||i>depth)   return 0 ;
	else return 1 ;
}

void dfs(int i ,int j)
{
	visited[i][j]=1 ;
		
	if(safe(i,j+1)&&arr[i][j+1]&&!visited[i][j+1])   dfs(i,j+1) ;
	if(safe(i+1,j)&&arr[i+1][j]&&!visited[i+1][j])   dfs(i+1,j) ;
	if(safe(i,j-1)&&arr[i][j-1]&&!visited[i][j-1])   dfs(i,j-1) ;
	if(safe(i-1,j)&&arr[i-1][j]&&!visited[i-1][j])   dfs(i-1,j) ;
	if(safe(i-1,j+1)&&arr[i-1][j+1]&&!visited[i-1][j+1])   dfs(i-1,j+1) ;
	if(safe(i+1,j+1)&&arr[i+1][j+1]&&!visited[i+1][j+1])   dfs(i+1,j+1) ;
	if(safe(i+1,j-1)&&arr[i+1][j-1]&&!visited[i+1][j-1])   dfs(i+1,j-1) ;
	if(safe(i-1,j-1)&&arr[i-1][j-1]&&!visited[i-1][j-1])   dfs(i-1,j-1) ;
}

int main()
{
	int l , h ;
	while(1)
	{
		char s[101] ;
		scanf("%d %d",&h ,&l) ;
		if(h==0)     break ;
		memset(visited,0,sizeof(visited)) ;
		depth = h - 1;
		width = l - 1;
		for(int i=0;i<=depth;i++)
		{
			scanf("%s",s) ;
			for(int j=0;j<=width ; j++)
			{
				if(s[j]=='*')    arr[i][j] = 0 ;
				else arr[i][j] = 1 ;
			}
		}
		
		int count = 0 ;
		for(int i=0;i<=depth ; i++ )
		{
			for(int j=0;j<=width ; j++ )
			{
				if(visited[i][j]==0&&arr[i][j])
				{
					count++;
					dfs(i,j) ;
				}
			}
		}
		printf("%d\n",count) ;
	}
	return 0 ;
}

