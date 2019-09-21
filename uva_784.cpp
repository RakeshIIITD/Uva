// `roCKy FireBirD
// Not submitted due to diff in I/O
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
int visited[100][100] ;
vector<string>arr;
int d ;

void dfs(int i ,int j)
{
	visited[i][j]=1 ;
		
	if(arr[i][j+1]==' '&&!visited[i][j+1])   dfs(i,j+1) ;
	if(arr[i+1][j]==' '&&!visited[i+1][j])   dfs(i+1,j) ;
	if(arr[i][j-1]==' '&&!visited[i][j-1])   dfs(i,j-1) ;
	if(arr[i-1][j]==' '&&!visited[i-1][j])   dfs(i-1,j) ;
}

int main()
{
	int n ;
	string s ;
	scanf("%d\n",&n) ;
	
	while(n--)
	{
		int x,y ;
		memset(visited,0,sizeof(visited)) ;
		int k=0 ;
		int flag = 0 ;
		while(1)
		{
			getline(cin,s) ;
			if(s[0]=='-')   break ;
			
			if(!flag)
			for(int i=0;i<s.size() ; i++)
			{
				if(s[i]=='*')
				{
					x = k ;
					y = i ;
					flag = 1 ;
					s[i] = ' ' ;
				}
			}
			d = k ;
			k++ ;
			arr.push_back(s) ;
		}
		dfs(x,y) ;
		
		for(int i=0;i<=d ; i++)
		{
			for(int j=0;j<arr[i].size();j++)
			{
				if(arr[i][j]>='A'&&arr[i][j]<='Z')   printf("%c",arr[i][j]);
				if(arr[i][j]==' '&&visited[i][j]==1)   printf("#") ;
				if(arr[i][j]==' '&&visited[i][j]==0)   printf(" ") ;
 			}
 			printf("\n") ;
		}
		arr.clear() ;
		printf("-----\n") ;
	}
	return 0 ;
}

