//
// Created by rakesh on 3/6/18.
//

#include<bits/stdc++.h>

using namespace std ;

int pset[110] = {0};

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
   
    initSet(100) ;

    vector<pair<int,pair<int,int> > > v ;

    int x,y,w ;

    while(1)
    {
        scanf("%d%d%d",&x,&y,&w);

        if(x==0)  break;
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

    printf("%d\n",minCost) ;
    return 0 ;
}