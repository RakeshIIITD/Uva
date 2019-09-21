#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std ; 

int main()
{	
	while(1)
	{
		long n ;
		scanf("%ld",&n);
			if(n==0)  break ;
		int a[2000001] = {0} ;
		int c[2000001] ={0} ;
		int b[101] = {0} ;
	
		for(long i=0;i<n;i++)
		{
			scanf("%d",&a[i]) ;
			b[a[i]]++ ;
		}
		for(int i=1 ; i<101 ; i++ )
		{
			b[i]+=b[i-1] ;
		}
		
		for(long i=n-1 ; i>-1 ; i-- )
		{
			c[b[a[i]]] = a[i] ;
			b[a[i]]-- ;
		}
		for(long i=1 ; i<=n ;i++)
		{
			printf("%d",c[i] ) ;
			if(i<n) printf(" ") ;
		}
		printf("\n") ;
	}
	return 0 ;
}
