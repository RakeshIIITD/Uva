//
// Created by rakesh on 23/5/18.
//


/*               8-queens            */
#include<bits/stdc++.h>

using namespace std ;

const int n = 15 ;
int r1[n]  = {0};
int r2[2*n+1] = {0};
int r3[2*n+1] = {0};
int count_ ;

void backtrack(int y)
{
    if(y==n)
    {
        count_++ ;
        return ;
    }

    for( int x=0 ; x<n ; x++ )
    {
        if(r1[x]||r2[x+y]||r3[x-y+(n-1)]) continue;

        r1[x] = r2[x+y] = r3[x-y+(n-1)] = 1 ;

        backtrack(y+1) ;

        r1[x] = r2[x+y] = r3[x-y+(n-1)] = 0 ;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif
    count_ = 0 ;
  backtrack(0) ;
  cout<<count_;

    return 0;
}