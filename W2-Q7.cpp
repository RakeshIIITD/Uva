#include<stdio.h>
#define n 6
int a[] = {2,1,3,4,5,6 };
int b[6] = {0} ;

int main()
 {   int k=1;
	 for( int i=0 ; i<n ; i++ )
	 {
	 	k=k*a[i];
	 }
	 
	 printf("%d  ",k);
	 for( int i=0 ; i<n ; i++ )
	 {
	 	b[i] = k^a[i] ;
	 	printf("%d  ",b[i] ) ;
	 }
	 
	 
	 return 0 ;
 }

