#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std ;
int a[23] ;
long long L[10000] ;

void C(int n)
{
    L[0] = 1 ;
    for(int i=0;i<n;i++)
    for(int j = a[i];j<10000 ; j++)
    L[j]+=L[j-a[i]] ;
}

int main()
{
    int n ;
    memset(L,0,sizeof(L)) ;
    
    for(int i=1;i<23 ; i++)     a[i-1] = i*i*i ;
    C(22) ;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",L[n]) ;
    }
    return 0 ;
}
