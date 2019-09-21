/*
created by : rakesh
28/5/2018
*/
#include<bits/stdc++.h>

using namespace std ;

#define WHITE 1
#define BLACK 2
#define UNVISITED 0

int n ;
int max_black ;
vector<int> final;
int count_ ;

void C(int i,int prev ,int black ,vector<vector<int> > v , int visited[],vector<int> sol)
{
	
	if(prev==BLACK && visited[i]==BLACK && count_==n)
	{
		return ;
	}

	if(count_==n-1)
	{
		visited[i] = BLACK ;

		int flag = 1 ;

		for(int j=0;j<v[i].size();j++)
		{
			if(visited[i]==BLACK&&visited[v[i][j]]==BLACK) flag = 0 ;
		}

		if(flag) black++ ;
		
		if(black>max_black)
		{
			max_black = black ;
			final = sol ;
		}
		
		return ;
	}

	if(visited[i]!=UNVISITED)   return ;
		
	count_++ ;
    if(prev==WHITE)
    {
    	visited[i] = BLACK ;

    	sol.push_back(i) ;

    	for(int j=0;j<v[i].size();j++)
    	{
    		C(v[i][j],BLACK,black+1,v,visited,sol) ;
    	}

    	sol.pop_back() ;

    }

    	visited[i] = WHITE ;

    	for(int j=0;j<v[i].size();j++)
    	{
    		C(v[i][j],WHITE,black,v,visited,sol) ;
    	}

	visited[i] = UNVISITED ;
	count_--;
	
}

int main()
{

	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout) ;
    #endif


    int testcase,m ,x,y;

	scanf("%d",&testcase) ;

    while(testcase--)
    {
    	scanf("%d%d",&n,&m);

    	vector<vector<int> > v(n+1) ;

    	for(int i=0;i<m;i++)
    	{
    		scanf("%d%d",&x,&y);
    		v[x].push_back(y) ;
    		v[y].push_back(x);
    	}

    	int visited[105] = {0} ;
      

    	vector<int> sol ;
    	max_black = 0;
    	count_ = 0 ;
    	C(1,WHITE,0,v,visited,sol) ;


    	//cout<<v[2][2] ;

    	printf("%d\n",max_black);

    	for(int i=0;i<final.size();i++)
    	{
    		printf("%d",final[i]);

    		if(i+1!=final.size()) printf(" ");
    	}

    	printf("\n");
    }
	return 0 ;
}