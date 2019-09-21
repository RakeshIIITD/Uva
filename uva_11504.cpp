//
// Created by rakesh on 2/6/18.
//

#include<bits/stdc++.h>

using namespace std ;
int counter ;
int domino ;
int numChild ;

void C(int u,vector<vector<int> >v,int num[],int low[],int parent[])
{
	num[u]=low[u] = ++counter ;

	for(int i=0;i<v[u].size() ; i++)
	{
		if(num[v[u][i]]==0)
		{
			parent[v[u][i]]=u ; 

			C(v[u][i],v,num,low,parent);

			low[u] = min(low[u],low[v[u][i]]) ;
		}
		else if(parent[u]!=v[u][i])
		{
			low[u] = min(low[u],num[v[u][i]]) ;
		}
	}
}

int main()
{


    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout) ;
    #endif

    	int testcase ;

    	scanf("%d",&testcase) ;

    		int n,m ,x,y;

    	while(testcase--)
    	{	
    		scanf("%d%d",&n,&m);

    		vector<vector<int> >v(n+1) ;

    		for(int i=0;i<m;i++)
    		{
    			scanf("%d%d",&x,&y);

    			v[x].push_back(y) ;
    		}

    		int low[100002] ={0} ;
    		int num[100002] = {0} ;
    		int parent[100002] = {0} ;

    		counter = 0 ;
    		domino = 0 ;
    		numChild = 0 ;

    		for(int i=1;i<=n;i++)
    		{
    			if(num[i]==0)
    				
    				{
    					C(i,v,num,low,parent) ;
    					domino++;
    				}
    		}

    		// for(int i=1;i<=n;i++)
    		// {
    		// 	if(num[i]==low[i]&&num[i]!=0) domino++;
    		// }

    		printf("%d\n",domino);

    	}

    return 0 ;
}