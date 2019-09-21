//
// Created by rakesh on 24/5/18.
//

#include<bits/stdc++.h>

using namespace std ;
int w,n ;
int k ;

void dfs(int i,vector<vector<int> > v , int visited[],int count,vector<int> c)
{

    if(c.size()==w+1)
    {
        printf("(");

        for(int s = 0 ; s<c.size();s++)
        {
            printf("%d",c[s]);
            if(s+1!=c.size()) printf(",") ;
        }

        printf(")\n");
       
        return;
    }

    visited[i] = 1 ;
    c.push_back(i);

    
    

    for(int j = 0;j<v[i].size() ; j++ )
    {
        if(visited[v[i][j]]==0)
           { 
            dfs(v[i][j],v,visited , count+1,c);
            

           }

    }

                c.pop_back();
    visited[i] = 0 ;

            
      
}


int main()
{


     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout) ;
    #endif
    int t ,tmp;

    while(scanf("%d",&t)>0)
    {
        vector<vector<int> > v ;
        if(t==-9999)  scanf("%d",&t) ;
        cout<<t;
        n = t ;
        scanf("%d",&w) ;


        v.resize(t+1) ;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&tmp) ;
                if(tmp)    v[i].push_back(j) ;
            }
        }


        k = 1 ;
        int visited[15] ={0} ;
        vector<int> c;
       // c.push_back(1);
       // for(int i)
        dfs(1,v,visited,0,c);
    }
    return 0 ;
}