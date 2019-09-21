//
// Created by rakesh on 3/6/18.
//

#include<bits/stdc++.h>

using namespace std ;

int pset[200005] = {0};

void initSet(int _size) {    for(int i=0;i<_size;i++)    pset[i] = i ;  }

int findSet(int i) {   return pset[i]==i? i : pset[i]=findSet(pset[i]) ; }

bool isSamSet(int i,int j) {   return findSet(i)==findSet(j) ;  }

void unionSet(int i,int j) {  pset[findSet(i)] = findSet(j) ; }


int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout) ;
#endif
   int n,m;
   while(1)
   {

    scanf("%d%d",&n,&m);

    if(n==0&&m==0)  break;

    initSet(n+1) ;

     int x,y,w ,total=0;
     vector<pair<int,pair<int,int> > > v ;

    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        total+=w ;
        v.push_back(make_pair(-w,make_pair(x,y))) ;
    }

    sort(v.begin(),v.end()) ;       // O(E)

    int minCost = 0 ;

    while(v.empty()!=1)
    {
        pair<int,pair<int,int> > edge = v[v.size()-1] ;
        v.pop_back() ;
       
        if(!isSamSet(edge.second.first,edge.second.second))
        {
            unionSet(edge.second.first,edge.second.second) ;
            minCost+=(-edge.first) ;
        }
    }

    printf("%d\n",total-minCost) ;
  }
    return 0 ;
}