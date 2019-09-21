// `roCKy FireBirD
// Accepted 
// Optimization Failed
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
int arr[100][100] ;
//int L[100][100] ;
int depth , width ;

bool safe(int i , int j)
{
	if(i<0||j<0||j>width||i>depth)   return 0 ;
	else 							 return 1 ;
}
int area ;

void dfs(int i ,int j)
{
	visited[i][j]=1 ;
	if(arr[i][j]) area++ ;                            	
	if(safe(i,j+1)&&arr[i][j+1]&&!visited[i][j+1])   dfs(i,j+1) ;
	if(safe(i+1,j)&&arr[i+1][j]&&!visited[i+1][j])   dfs(i+1,j) ;
	if(safe(i,j-1)&&arr[i][j-1]&&!visited[i][j-1])   dfs(i,j-1) ;
	if(safe(i-1,j)&&arr[i-1][j]&&!visited[i-1][j])   dfs(i-1,j) ;
	if(safe(i-1,j+1)&&arr[i-1][j+1]&&!visited[i-1][j+1])   dfs(i-1,j+1) ;
	if(safe(i+1,j+1)&&arr[i+1][j+1]&&!visited[i+1][j+1])   dfs(i+1,j+1) ;
	if(safe(i+1,j-1)&&arr[i+1][j-1]&&!visited[i+1][j-1])   dfs(i+1,j-1) ;
	if(safe(i-1,j-1)&&arr[i-1][j-1]&&!visited[i-1][j-1])   dfs(i-1,j-1) ;
	//L[i][j] = area ;
}

int main()
{
	int testcase ;
	scanf("%d\n",&testcase) ;
	int t=0 ,x,y,len;
	while(testcase--)
	{
		//scanf("\n") ;
		//memset(visited , 0 ,sizeof(visited)) ;
		//memset(L,0,sizeof(L)) ;
		int k = 0 ;
		
		while(1)
		{
			string s ;
			getline(cin,s) ;
			if(s.empty())   break ;
			
			if( s[0]=='W'||s[0]=='L' )
			{
				len = s.size()-1 ;
				
				width = len ;
			     for(int i=0;i<=len ; i++)
			     {
			     	if(s[i]=='W')   arr[k][i] = 1 ;
			     	else            arr[k][i] = 0 ;
			     }
			     depth = k ;
			     k++ ;
			}
			else
			{
				stringstream ss(s) ;
				ss>>x;
				ss>>y ;
				memset(visited,0,sizeof(visited)) ;
					area = 0 ;
					dfs(x-1,y-1) ;
				
				printf("%d\n",area) ;
			}				
		}		
		if(testcase>0)    printf("\n") ;
		
	}
	return 0 ;
}
