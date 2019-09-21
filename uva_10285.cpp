#include<bits/stdc++.h>

using namespace std ;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
    #endif

    int n ;

    int count = 1 ;

    while(scanf("%d",&n)>0)
    {
        if(count>1) printf("\n");
        int c[17] = {0} ; c[1] = 1 ;


        printf("Case %d:\n",count++) ;
        b[0] = 1 ;
        C(1,n , c) ;

        


    }
    return 0;
}