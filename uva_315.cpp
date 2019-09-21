//
// Created by rakesh on 1/6/18.
//

#include<bits/stdc++.h>

using namespace std;

#define WHITE 0
int counter ;
int root ;
int numChild ;


void  articulationPoint(int u , vector<vector<int> >v , int num[],int low[],int parent[],int articulationPoints[])
{
    num[u]=low[u] = counter++ ;

    for(int i=0;i<v[u].size();i++)
    {
        if(num[v[u][i]]==WHITE)   // if not visited
        {
            parent[v[u][i]] = u ;
            if(u==root)  numChild++ ;

            articulationPoint(v[u][i],v,num,low,parent,articulationPoints) ;

            if(low[v[u][i]]>=num[u])     articulationPoints[u] = true ; 
            
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

    int n ,tmp;
    char c ;
    while(1)
    {
        scanf("%d",&n);

        if(n==0) break ;

        int u ;

        vector<vector<int> > v(n+1) ;
        while(1)
        {
            scanf("%d",&u);

            if(u==0) break;

            while(scanf("%d%c",&tmp,&c))
            {
                v[u].push_back(tmp);
                v[tmp].push_back(u) ;
                if(c=='\n') break;
            }
        }
        int num[110] = {0};
        int low[110] = {0};
        int parent[110] = {0};

        counter = 0 ;
        root = 1;
        numChild = 0 ;
        int articulationPoints[110] ;
        articulationPoint(1,v,num,low,parent,articulationPoints) ;
        int articulationCount = 0 ;

        articulationPoints[root] = (numChild>1) ;

        for(int i=1;i<=n;i++)
        {
            
                if(articulationPoints[i])  articulationCount++ ;
             
        }
        printf("%d\n",articulationCount);
    }
}