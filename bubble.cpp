#include<stdio.h>
#include<time.h>
#include<stdlib.h>


#define ARRAY_SIZE 4000


int main()
{
	clock_t start , end ;
    double time_used ;
    time_t t1 ;
    
    int a[ARRAY_SIZE] ,i , j ;
    
    srand( ( unsigned )time(&t1) ) ;     //seeding
    
    for(i=0 ; i<ARRAY_SIZE ; i++ )
    {
      a[i] = rand()%10000 ;
    }
    
    start = clock();
    
    for(i=0 ; i<ARRAY_SIZE ; i++ )
    {
    	for( j=0 ; j<ARRAY_SIZE-i ; j++ )
    	{
    		if( a[j]>a[j+1] )
    		{
    			int temp = a[j] ;
    			a[j] = a[j+1] ;
    			a[j+1] = temp ;
    		}
    	}
    }
     end = clock() ;
     
    for(i=0 ; i<ARRAY_SIZE ; i++ )
    {
      printf("%d ", a[i] ) ;
    }
    
    printf("\n\nTIME TAKEN : %lf" , ( (double)((end - start )/CLOCKS_PER_SEC) ) ) ;
    return  0 ;
}
