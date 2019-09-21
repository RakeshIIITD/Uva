#include<bits/stdc++.h>

using namespace std ;

int a[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0} ;


/*   2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31    */
int b[18] ;


void C(int j , int n , int c[])
{

 if(j==n && a[b[j-1] + b[0]])    
 {
    for(int i=0;i<n;i++)
    {

      printf("%d",b[i]);
      if(i!=n-1)  printf(" ");
     }
      printf("\n");
 }

 for(int i=2;i<=n;i++)
 {
    if(a[b[j-1]+i] && c[i]==0 )
    {
        b[j] = i ;
        c[i] = 1 ;
        C(j+1,n,c) ;
        c[i] = 0 ;
    }
 }
}

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