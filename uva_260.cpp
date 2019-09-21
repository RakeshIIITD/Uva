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

int visited[201][201] ;
int arr[201][201] ;
int d ,result;
bool safe(int i,int j)
{
	if(i<0||j<0||j>d||i>d)   return 0 ;
	else return 1 ;
}

void dfs(int i ,int j)
{
	visited[i][j]=1 ;
	if(i==d&&arr[i][j])   result = 1 ;	
	if(safe(i,j+1)&&arr[i][j+1]&&!visited[i][j+1])   dfs(i,j+1) ;
	if(safe(i+1,j)&&arr[i+1][j]&&!visited[i+1][j])   dfs(i+1,j) ;
	if(safe(i,j-1)&&arr[i][j-1]&&!visited[i][j-1])   dfs(i,j-1) ;
	if(safe(i-1,j)&&arr[i-1][j]&&!visited[i-1][j])   dfs(i-1,j) ;
	if(safe(i+1,j+1)&&arr[i+1][j+1]&&!visited[i+1][j+1])   dfs(i+1,j+1) ;
	if(safe(i-1,j-1)&&arr[i-1][j-1]&&!visited[i-1][j-1])   dfs(i-1,j-1) ;
}

int main()
{
	int n ;
	int testcase = 0 ;
	char s[201] ;
	while(1)
	{
		testcase++ ;
		memset(visited,0,sizeof(visited)) ;
		scanf("%d",&n) ;
		if(n==0) break ;
		d = n-1 ;
		for(int i=0;i<n ; i++)
		{
			scanf("%s",s) ;
			for(int j=0;j<n;j++)
			{
				if(s[j]=='b')    arr[i][j] = 1 ;
				else arr[i][j] = 0 ;
			}
		}
		int k ;
		result = 0 ;
		for(int i=0;i<n ; i++)
		{
			if(arr[0][i]==1)
			 {
			   dfs(0,i) ;
			   if(result==1)    break;
		     }
		}
		if(result)
		{
			printf("%d B\n",testcase) ;
		}
		else
		{
			printf("%d W\n",testcase) ;	
		}
	}
	return 0 ;
}

