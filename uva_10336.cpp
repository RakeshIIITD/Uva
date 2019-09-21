// `roCKy FireBirD
// Accepted inspite of tricky cases 
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
#include<utility>

using namespace std ;
#define FOR(i,a,b)  for( int i = int(a) ; i<=int(b) ; i++)
int d ,w ;
char arr[100][100] ;
int visited[100][100] ;
int h[27] ;
vector<pair<char,int> >v ;
bool safe(int i ,int j)
{
	if(i<0||j<0||i>d-1||j>w-1)   return false ;
	else                         return true ;
}
bool sortByPair1(const pair<char,int>& firstElem , const pair<char,int>& secondElem)
{
	return firstElem.first<secondElem.first ;
}

bool sortByPair2(const pair<char,int>& firstElem , const pair<char,int>& secondElem)
{
	return firstElem.second>secondElem.second ;
}

void dfs(int i ,int j , char c)
{
	visited[i][j]=1 ;
	if(safe(i,j+1)&&arr[i][j+1]==c&&!visited[i][j+1])   dfs(i,j+1,c) ;
	if(safe(i+1,j)&&arr[i+1][j]==c&&!visited[i+1][j])   dfs(i+1,j,c) ;
	if(safe(i,j-1)&&arr[i][j-1]==c&&!visited[i][j-1])   dfs(i,j-1,c) ;
	if(safe(i-1,j)&&arr[i-1][j]==c&&!visited[i-1][j])   dfs(i-1,j,c) ;
}
int main()
{
	int testcase ;
	char s[1000] ;
	scanf("%d",&testcase) ;
	int t= 0;
	while(testcase--)
	{
		int k[27] = {0} ;
		memset(visited,0,sizeof(visited)) ;
		t++ ;
		scanf("%d %d",&d,&w) ;
		for(int i=0;i<d; i++)
		{
			scanf("%s",s) ;
			for(int j = 0 ;j<w ; j++ )
			{
				arr[i][j] = s[j] ;
			}
		}
		for(int i=0;i<d; i++)
		{
			for(int j=0;j<w ; j++)
			{
				if(visited[i][j]==0)
				{
					dfs(i,j,arr[i][j]) ;
					k[int(arr[i][j]-'a')]+= 1 ;
				}
			}
		}
		for(int i=0;i<27 ; i++)
		{
			if(k[i]>0)     v.push_back(make_pair((char)(i+'a') , k[i] ) );
		}
		
		stable_sort(v.begin(), v.end() , sortByPair1) ;
		stable_sort(v.begin(), v.end() , sortByPair2) ;
		printf("World #%d\n",t) ;
		
		for(int i=0;i<v.size() ; i++)
		{
			printf("%c: %d\n",(v[i]).first , (v[i]).second) ;
		}
		
		v.clear() ;
	}
	return 0 ;
}

