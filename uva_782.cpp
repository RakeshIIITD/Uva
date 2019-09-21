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
int d ,max_width ;
int safe(int i,int j)
{
	if(i<0||j<0||j>max_width||i>d)   return 0 ;
	else 					 return 1 ;
}

void dfs(int i ,int j)
{
	visited[i][j] = 1 ;
		
	if(safe(i,j+1)&&arr[i][j+1]==' '&&!visited[i][j+1])   dfs(i,j+1) ;
	if(safe(i+1,j)&&arr[i+1][j]==' '&&!visited[i+1][j])   dfs(i+1,j) ;
	if(safe(i,j-1)&&arr[i][j-1]==' '&&!visited[i][j-1])   dfs(i,j-1) ;
	if(safe(i-1,j)&&arr[i-1][j]==' '&&!visited[i-1][j])   dfs(i-1,j) ;
}

int main()
{
	int n ;
	string s ;
	scanf("%d\n",&n) ;
	
	while(n--)
	{
		int x,y ,size;
		max_width = -1 ;
		memset(visited,0,sizeof(visited)) ;
		int k=0 ;
		while(1)
		{
			getline(cin,s) ;
			if(s[0]=='_')   break ;
			size = s.size()-1 ;
			if(size>max_width)   max_width = size ;
			for(int i=0;i<=size ; i++)
			{
				if(s[i]=='*')
				{
					x = k ;
					y = i ;
					s[i] = ' ' ;
				}
			}
			d = k ;
			k++ ;
			arr.push_back(s) ;
		}
		//cout<<max_width ;
		dfs(x,y) ;

		for(int i=0;i<=d ; i++)
		{
			for(int j=0;j<arr[i].size();j++)
			{
				if(arr[i][j]>='A'&&arr[i][j]<='Z') 
				{
					//if(safe(i+1,j)) cout<<i+1<<"  "<<j<<" "<<arr[i+1][j]<<"visited"<<visited[i+1][j]<<endl ;
					if(safe(i+1,j)&&(arr[i+1][j]==' ')&&visited[i+1][j]==1)   arr[i+1][j] = '#' ;
					if(safe(i-1,j)&&(arr[i-1][j]==' ')&&visited[i-1][j]==1)   arr[i-1][j] = '#' ;
					if(safe(i,j+1)&&(arr[i][j+1]==' ')&&visited[i][j+1]==1)   arr[i][j+1] = '#' ;
					if(safe(i,j-1)&&(arr[i][j-1]==' ')&&visited[i][j-1]==1)   arr[i][j-1] = '#' ;	
				}
 			}
		}
		
		for(int i=0;i<=d ; i++)
		{
			for(int j=0;j<arr[i].size();j++)
			{
					printf("%c",arr[i][j]) ;
 			}
 			printf("\n") ;
		}
		arr.clear() ;
		printf("__________\n") ;
	}
	return 0 ;
}
