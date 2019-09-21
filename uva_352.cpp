// `roCKy FireBirD
// Accepted
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

int visited[26][26] ;
int arr[26][26] ;
int d ;
bool safe(int i,int j)
{
	if(i<0||j<0||j>d||i>d)   return 0 ;
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
	int n ;
	int testcase = 0 ;
	while(scanf("%d",&n)!=EOF)
	{
		char s[26] ;
		testcase++ ;
		d = n-1 ;
		int count = 0 ;
		memset(visited , 0 ,sizeof(visited)) ;
		for(int i=0;i<n ; i++)
		{
			scanf("%s",s) ;
			for(int j=0;j<n;j++)
			{
				if(s[j]=='1') arr[i][j] = 1 ;
				else arr[i][j] = 0 ;
			}
		}
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(visited[i][j]==0&&arr[i][j])
				{
					count++ ;
					dfs(i,j) ;
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n",testcase,count) ;
	}
	return 0 ;
}

