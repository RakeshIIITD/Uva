#include<stdio.h>
#define n 6
int a[] = {2,1,3,4,7,6,0 };
int b[6] = {0} ;

int main()
 {   int k=0;
	 for( int i=0 ; i<n+1 ; i++ )
	 {
	 	k=k^((i+1)^a[i]);
	 }
	 
	 printf("%d  ",k);
	 
	 
	 
	 return 0 ;
 }

