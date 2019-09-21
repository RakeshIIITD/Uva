#include <stdio.h>

int pour( int qA , int  qB , int a , int b , int c , int count )
{ if( a==c||b==c )
   printf( "%d\n" , count ) ;
  else // 5 3 2
    { 
		count++ ;
	}
}

int main(){
	int testcase ; 
	scanf("%d",&testcase ) ;
	while( testcase-- )
	{
		 int quantityA , quantityB , int C ;
		 scanf("%d%d%d" , &quantityA , &quantityB ,&C ) ;
		 if( c>quantityA&&c>quantityB )
		 printf("-1\n");
		 else 
		   pour( quantityA , quantityB  , 0 , 0 , C , 0 ) ;
		 
	}
	return 0;
}
